<?php
/**
 * @Author: PankajGoyal7
 * @Date:   2016-09-20 13:09:15
 * @Last Modified by:   PankajGoyal7
 * @Last Modified time: 2016-10-19 10:53:16
 */

namespace Rest\Utils;
use Phalcon\Mvc\User\Plugin;

/*
 * Util to check wheather product is duplicate or not same seller
 */

class utilDuplicateProduct extends Plugin  {

	public function __construct(){

	}

	/**
	 * Check wether product is duplicate or not
	 * @param  [Array]   $product       [Request Product Data Array]
	 * @param  [string]  $mode          [Mode of product Creation/Updation]
	 * @return [Array]   $is_duplicate  [if product is duplicate Return Array of error details otherwise empty array]
	 */
	public function isDuplicateProduct($product){
		$is_duplicate = array();
			// for single mode(one by one)/ clone mode (clone panel)
		$is_duplicate = $this->fn_check_duplicate_product($product);
			//insert error in table for future reference and notification visibility
		if((!empty($is_duplicate)) && ($product['SOURCE'] == 'Creation')){
			//check if source is product creation
			$this->logCreationErrorData($is_duplicate,$product);
		}
		unset($product);
		return  $is_duplicate;
	}


	private function logCreationErrorData($error,$request){
		if(!empty($error)){
			$sql = "INSERT INTO clues_product_notifications (ref_error_data,error,data,creation_source,channel,flag,latest)
			values('".$error['product_id']."','".mysql_real_escape_string(serialize(json_encode($error)))."','".mysql_real_escape_string(serialize(json_encode($request)))."','".$request['DISPATCH']."','Soa',1,1)";
			db_query($sql);

		}
	}

	private function fn_check_duplicate_product($product){
		$duplicate_product = array();
		if(!empty($product)){
			$product_md5 = $this->fn_get_product_mdsum_csv($product);
			if(((!isset($product['VENDOR'])) || (is_null($product['VENDOR']))) && (is_numeric($product['PRODUCT-CODE']))){
				$product['VENDOR']=db_get_field("select company_id from cscart_products where product_id=".$product['PRODUCT-CODE']);
			}
			if(!isset($product['VENDOR']) || is_null($product['VENDOR'])){
				$product['VENDOR'] = 0;
			}

            //product statuses for which duplicate check will not be performed like deleted state
			$statuses = $this->getDI()->get('config')->blocked_status_for_duplicate_check;
			$default_duplicate_values = $this->getDI()->get('config')->default_duplicate_values;
			$sql = "SELECT product_id,is_wholesale_product,is_factory_outlet_product,product_group,status FROM cscart_products where ";
			if(($product['product_id']) && (is_numeric($product['product_id']))){
				$sql .= " product_id != ".$product['product_id']." AND ";
			}
			if(!empty($statuses)){
				$sql .= " status NOT IN (".$statuses.") AND ";
			}
			if(!empty($product_md5)){
				$sql .= " md5_content='".$product_md5."' AND company_id=".$product['VENDOR'];
				$duplicate_product = db_get_array($sql);
			}
			if(!empty($duplicate_product)){
				$image_data = $this->get_images_md5($product);
				if(!empty($image_data)){
					foreach ($duplicate_product as $dps) {
						if((is_numeric($dps['product_id'])) &&
							($default_duplicate_values['is_wholesale_product'] == $dps['is_wholesale_product']) &&
							($default_duplicate_values['is_factory_outlet_product'] == $dps['is_factory_outlet_product']) &&
							($default_duplicate_values['product_group'] == $dps['product_group'])){
							if(isset($image_data)){
								foreach ($image_data as $image_url => $md5_image) {
									if(!empty($md5_image)){
										$product_id = db_get_field("SELECT
											object_id
											FROM
											cscart_images_links
											WHERE
											object_type='product' AND md5_image='".$md5_image."' AND object_id=".$dps['product_id']);
										if(!empty($product_id)){
											$image_error['product_id']  = isset($image_error['product_id']) ? ($image_error['product_id'] .",".$dps['product_id']):$dps['product_id'];
											$image_error['status']      = isset($image_error['status']) ? ($image_error['status'] .",".$dps['status']):$dps['status'];
											$image_error['url']    = isset($image_error['url']) ? addslashes($image_error['url'] .",".$image_url):addslashes($image_url);
											$image_error['reason'] = 'Duplicate Product';
											break;
										}
									}
								}
							}
						}
					}
				}
				if(!empty($image_error)){
					return $image_error;
				}
			}
		}
		return false;
	}

	private function fn_get_product_mdsum_csv($product){
		$md5_product = NULL;
		$feature_str = NULL;
		if(!empty($product)){
			if(isset($product['FEATURES'])){
				$final_str = $this->fn_modifiy_user_features($product);
			}elseif(is_numeric($product['PRODUCT-CODE'])){
				if((!isset($product['PRODUCT-NAME'])) && (is_numeric($product['PRODUCT-CODE']))){
					$product['PRODUCT-NAME'] = db_get_field("select product from cscart_product_descriptions where product_id=".$product['PRODUCT-CODE']);
				}
				$features_arr = $this->fn_get_product_features_for_csv_format($product['PRODUCT-CODE']);
				if(!empty($features_arr)){
					$feature_str  = $this->fn_generate_product_feature_string_for_csv_format($features_arr);
				}
				$p_f_str    = $product['PRODUCT-NAME'].$feature_str;
				$final_str    = preg_replace("/[^a-zA-Z0-9]/","",$p_f_str);
			}
			$final_str = strtolower($final_str);
			$md5_product = md5($final_str);
		}
		return $md5_product;
	}

	private function get_images_md5($data){
		$return =  array();
		if((isset($data['DETAILED-IMAGE'])) && (!empty($data['DETAILED-IMAGE']))){
			$return[$data['DETAILED-IMAGE']] = $this->fn_generate_md5($data['DETAILED-IMAGE']);
		}
		if((isset($data['ADDITIONAL-IMAGE'])) && (!empty($data['ADDITIONAL-IMAGE']))){
			foreach ($data['ADDITIONAL-IMAGE'] as $image_url) {
				$return[$image_url] = $this->fn_generate_md5($image_url);
			}
		}
		return $return;
	}

	/**
     * Convert applied features into required feature variant string for md5
     * @param  [Array]  $product    [csv data array]
     * @return [String] $final_str  [product feature string]
     */
	public function fn_modifiy_user_features($product){
		$final_str = "";
		if((!empty($product)) &&  (isset($product['FLAG'])) && (!empty($product['FLAG']))){
			if(((isset($product['FEATURES'])) ||
				(isset($product['PRODUCT-NAME'])) ||
				(isset($product['CATEGORY'])))){
				if(isset($product['PRODUCT-CODE'])){
					if(is_numeric($product['PRODUCT-CODE'])){
						if(!isset($product['PRODUCT-NAME'])){
							$product['PRODUCT-NAME']=db_get_field("select product from cscart_product_descriptions where product_id='".$product['PRODUCT-CODE']."'");
						}
						$product['OLD_CATEGORY']=db_get_field("select category_id from cscart_products_categories where link_type='M' AND product_id='".$product['PRODUCT-CODE']."'");
					}
					$fe_string = "";
					$all_fe = $this->fn_get_product_features($product);
					if(!empty($all_fe)){
						$fe_string=$this->fn_generate_product_feature_string_for_csv_format($all_fe);
					}
					$final_str = $product['PRODUCT-NAME'].$fe_string;
					$final_str  = preg_replace("/[^a-zA-Z0-9]/","",$final_str);
				}
			}
			return $final_str;
		}else{
			return false;
		}
	}

	private function fn_get_product_features($product){

		$all_fe = array();
		$features =  array();
		if(((isset($product['CATEGORY'])) && ($product['CATEGORY'] !=0) && (!empty($product['CATEGORY'])) && (!is_numeric($product['PRODUCT-CODE']))) || ($product['CATEGORY'] != $product['OLD_CATEGORY'])){
			$all_fe = $this->fn_get_product_features_category_wise($product['CATEGORY']);
			foreach ($product['FEATURES'] as $feature_id => $value) {
				if(array_key_exists($feature_id,$all_fe)){
					$variant = null;
					$var="select vd.variant from cscart_product_feature_variant_descriptions vd inner join cscart_product_feature_variants v on v.variant_id=vd.variant_id
					and v.feature_id='".$feature_id."' where v.variant_id='".$value."'";
					$variant=db_get_field($var);
					if(!empty($variant)){
						$features[$feature_id][] = $variant;
					}else{
						$features[$feature_id][] = $value;
					}
				}
			}
			if(!empty($features)){
				foreach ($features as $feature_id => $variants) {
					$sort_variants = null;
					sort($variants, SORT_NATURAL | SORT_FLAG_CASE);
					$sort_variants = implode("///",$variants);
					$all_fe[$feature_id]=$sort_variants;
				}
			}
		}else{
			$all_fe = $this->fn_get_product_features_for_csv_format($product['PRODUCT-CODE']);
		}
		return $all_fe;

	}
	/**
	 * Log Error data in table for notifications on product page
	 * @param  [Array]    $product [Request Product Data]
	 * @param  [Array]    $data    [Error data]
	 * @param  [Interger] $flag    [flag]
	 */
	private function logErrorData($product,$data,$flag){
		if(!empty($data)){
			db_query("UPDATE clues_product_notifications SET latest=0 WHERE flag=".$flag." AND product_id=".$product['product_id']);
			$sql = "INSERT 	INTO
			clues_product_notifications
			(product_id,ref_error_data,error,data,flag,latest)
			values(".$product['product_id'].",'".$data['product_id']."','".mysql_real_escape_string(serialize(json_encode($data))).
			"','".mysql_real_escape_string(serialize(json_encode($product)))."',1,1)";
			db_query($sql);
		}
	}

	/**
	 * Remove Notification of product by setting latest 0
	 * @param  [Integer] $product_id [product_id]
	 * @param  [string]    $flag       [flag type of error]
	 */
	private function removeErrorNotification($product_id,$flag = ''){


		$sql ="UPDATE clues_product_notifications SET latest=0 WHERE product_id=".$product_id;
		if(!empty($flag)){
			$sql .= " AND flag in  (".$flag.")";
		}
		db_query($sql);

	}

	/**
	 * To Get string of all errors corrosponding to a product
	 * @param  [Integer] $product_id [Product Id]
	 * @param  [String]  $flag       [flag for type of notifications comma seprated integers like "1,2,3"]
	 * @return [String]  $errStr     [String of all errors]
	 */
	public function getErrorNotificatons($product_id,$flag = ''){
		$errors = array();
		$errStr = NULL;
		if(is_numeric($product_id)){
			$sql = "SELECT
			pnd.description,pn.ref_error_data
			FROM
			clues_product_notifications pn
			INNER JOIN
			clues_product_notification_descriptions pnd
			ON
			pn.flag=pnd.flag
			WHERE latest=1  AND pn.product_id=".$product_id;
				//check for particular flag otherwise it return all errors
			if(is_numeric($flag)){
				$sql .= " AND pn.flag in (".$flag.")";
			}
			$errors = db_get_array($sql);
			foreach ($errors as $value) {
				$errStr .= "Product is already in your catalog with product ids ".$value['ref_error_data']."<br/>";
			}
			unset($errors);
			return $errStr;
		}
	}

	private function generateProductmd5($product_id){
		if(is_numeric($product_id)){
			/*to generate mdsum of product*/
			$product['PRODUCT-NAME'] = db_get_field("SELECT product FROM cscart_product_descriptions WHERE product_id=".$product_id);
			$this->generate_product_mdsum($product_id,$product);
		}
	}


	public function generate_product_mdsum($product_id,$product){
		if(!empty($product)){
			$feature_string = "";
			$product['PRODUCT-CODE'] = $product_id;
			$features  = $this->fn_get_product_features_for_csv_format($product_id);
			if(!empty($features )){
				$feature_string = $this->fn_generate_product_feature_string_for_csv_format($features);
			}else{
				$feature_string = "";
			}
			$str = $product['PRODUCT-NAME'].$feature_string;
			$str = strtolower($str);
			$md5_product    = md5(preg_replace("/[^a-zA-Z0-9]/","",$str));
			db_query("UPDATE cscart_products SET md5_content='".$md5_product."' where product_id=".$product_id);
            //check if md5 of any images is not exist in table and generate it
			$get_images = db_get_array("SELECT il.pair_id,
				CONCAT('http://cdn.shopclues.com/images/detailed/',floor(il.detailed_id/1000),'/',i.image_path) as image_url
				FROM
				cscart_images i
				INNER JOIN
				cscart_images_links il ON i.image_id=il.detailed_id
				WHERE
				il.object_id=".$product_id." AND il.object_type='product' AND il.md5_image is NULL");
			if(!empty($get_images)){
				foreach ($get_images as $value) {
					$md5 = $this->fn_generate_md5($value['image_url']);
					db_query("UPDATE cscart_images_links SET md5_image='".$md5."' WHERE pair_id=".$value['pair_id']);
				}
			}
		}
	}

	private function fn_generate_md5($file) {
		$md5="";
		$md5 = md5(file_get_contents($file));
		return $md5;
	}

	private function fn_generate_product_feature_string_for_csv_format($features){
		$feature_string="";
		if(!empty($features)){
			foreach($features as $id=>$variant){
				if(!empty($variant)){
					$feature_string=$feature_string.$id.$variant;
				}
			}
		}
		return $feature_string;
	}

	private function fn_get_product_features_for_csv_format($product_id){
		$features = array();
		if(is_numeric($product_id)){
			$feature_id_sql_result = array();
			$select="SELECT  pc.category_id
			FROM
			cscart_products p inner join cscart_products_categories pc on pc.product_id=p.product_id
			WHERE
			pc.link_type='M'  and p.product_id=".$product_id;
			$category_id=db_get_field($select);
			$final=array();
			$features =$this->fn_get_product_features_category_wise($category_id);
			foreach ($features as $feature_id=>$value) {
				$var="select if(v.variant_id!='',vd.variant,v.value) as variant from cscart_product_features_values v
				left join cscart_product_feature_variant_descriptions vd
				on v.variant_id=vd.variant_id
				where v.feature_id=".$feature_id." and v.product_id=".$product_id;
				$variant=db_get_fields($var);
				sort($variant, SORT_NATURAL | SORT_FLAG_CASE);
				$variants = implode("///",$variant);
				$features[$feature_id]=$variants;
			}
		}
		return $features;
	}

	private function fn_get_product_features_category_wise($category_id,$allFeatures=0){
		$features=array();
		$allFeaturesStatus = "";
		if(is_numeric($category_id)){
			$all_categories_features = array();
			$select = "select id_path from cscart_categories where category_id=".$category_id;
			$id_path=db_get_field($select);
			$ids = explode('/',$id_path);
			$feature_id_sql_result=array();
			if($allFeatures==0)
				$allFeaturesStatus = " cpf.status in ('A','H') and ";
			if(!empty($id_path)){
				foreach($ids as $key1=>$value1){
					if(!empty($value1)){
						$tmp_array  = array();
						$feature_id_sql = "select cpf.feature_id from
						cscart_product_features cpf where $allFeaturesStatus cpf.parent_id!=0
						and FIND_IN_SET($value1,cpf.categories_path)";
						$tmp_array = db_get_fields($feature_id_sql);
						$feature_id_sql_result = array_merge($feature_id_sql_result, $tmp_array);
						unset($tmp_array);
					}
				}
			}
			$all_categories_features = $this->get_all_category_feature();
			if(!empty($all_categories_features)){
				$feature_id_sql_result = array_merge($feature_id_sql_result,$all_categories_features);
			}
			unset($all_categories_features);
			foreach ($feature_id_sql_result as $value) {
				$features[$value]="";
			}
		}
		return $features;
	}

	private function get_all_category_feature(){
		$all_categories_features = array();
		$all_categories_features_sql = "select cpf.feature_id from
		cscart_product_features cpf
		where cpf.status in ('A','H') and cpf.parent_id!=0 and cpf.categories_path=''";
		$all_categories_features =db_get_fields($all_categories_features_sql);
		return $all_categories_features;
	}
}


if(true){

echo "=========================>php";

}

?>
