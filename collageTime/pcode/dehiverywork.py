/home/hitesh/Project/godam/inbound/views.py:

#-------------------hk------------------

from po.models import ProcurementOrder
from management.models import ClientStore
from pcm.models import ProductClientStore
from management.models import MasterChannel

#--------------------------------------------

#----------------hk------------------------------------
        try:
            PO=ProcurementOrder.objects.get(id=po_id) # for client_store sk using po_id
            client_store_id=ClientStore.objects.get(sk=PO.client_store_sk).id
            master_channel_id=ClientStore.objects.get(sk=PO.client_store_sk).master_channel_id
            master_channel_name=MasterChannel.objects.get(id=master_channel_id).name
            client_store_product_number=ProductClientStore.objects.get(client_store_id=client_store_id).client_store_product_number
        except Exception, e:
            a={'serial':str(7),'product_number':str(e)}
            b=[a]
            for i in range(int(received_qty)-1):
                b.append(a)
            resp.update({'merror':True,'print_data_mc':json.dumps(b)})
        else:
            a={'serial':str(client_store_product_number),'product_number':master_channel_name}
            b=[a]
            for i in range(int(received_qty)-1):
                b.append(a)
            resp.update({'merror':False,'print_data_mc':json.dumps(b)})
 #---------------------------------------------------------



 /home/hitesh/Project/godam/outbound/urls.py:

  #--------------------------hk------------------------------------
    (r'^pack/masterslip/(?P<waybill_id>\w+)/', 'masterpacking_slip'),
    (r'^pack/isExtraslip/(?P<waybill_id>\w+)/', 'isExtraslip'),
  #----------------------------------------------------------------



/home/hitesh/Project/godam/outbound/views.py:


#---------------hk------------------------------------
from pcm.models import ProductClientStore
from wms.utils import zebra_serials
from management.models import MasterChannel
from management import cache
import pdfkit
from pcm import managers
#-----------------------------------------------------


#---------------------------------------hk--------------------------------------
def isExtraslip(request,waybill_id):
     try:
        orderlines=OrderLine.objects.get(id=waybill_id)
        client_store_sk=orderlines.client_store_sk
        clinetstore=get_cs_object_cache(client_store__sk)
        condition=clientstore.extra_slips_masterchannel
     except:
        return False
     else:
        if(condition=="OUTBOUND"):
             return True
        else:
             return False

def masterpacking_slip(request,waybill_id):
    
    check=True
    error=""
    print_data=[]
    response={}
    try:
        orderlines=OrderLine.objects.get(id=waybill_id)
        prod_qty=orderlines.prod_qty  
        client_store_sk=orderlines.client_store_sk
        clientstore=get_cs_object_cache(client_store__sk)
        master_channel_name=clientstore.master_channel.name
        
        pcsCach=ProductClientStoreCacheManager()
        listis=get_product_sk_to_alias_mapping(client_store__sk)
        client_store_product_number=None
        for data in listis:
            if data['client_store']==client_store_sk:
                client_store_product_number=data['client_store_product_number']

    except Exception, e:
        check=False
        error=str(e)
        return HttpResponse("Exception="+error)
    else:
        a={'serial':str(client_store_product_number),'product_number':str(master_channel_name)}     
        
        for i in xrange(prod_qty):
                print_data.append(a)

        resp=zebra_serials(json.loads(json.dumps(print_data)))
        resp['Content-Disposition'] = 'attachment; filename="ExtraSlip.pdf"'
        return  HttpResponse(resp, mimetype="application/pdf")  
#--------------------------------------------------------------------------------



/home/hitesh/Project/godam/wms/static/js/pack_order.js:


 //------------------------hk-----------
                            $.post(url,"",function(resp){
                             
                               download(resp,"PackingSlip.pdf","application/pdf");
                            });
                           //----------------------------------------
                        }
                    });
                        
//-------------------------------hk----------------------------------------------------   
                       post_data="";
                       $.post((data.url).replace("/slip/","/isExtraslip/"),post_data, function(resp_data) {
                             
                         if(resp_data){
                             //wind = window.open((data.url).replace("/slip/","/masterslip/"),'_blank');
                             //wind.print()
                             ps_data=""
                             $.post((data.url).replace("/slip/","masterslip"),ps_data,function(resp){

                                download(resp,"ExtraMCSlip.pdf","application/pdf")
                             });
                         }       
                     });

//-------------------------------------------------------------------------------------


/home/hitesh/Project/godam/wms/static/js/receive_serializ.js:


//----------------------hk------------------

                    print_datamc=data.print_data_mc;
                    alert(print_data+" "+print_datamc);
                   
                    post_data  = {
                        "csrfmiddlewaretoken": $("[name='csrfmiddlewaretoken']").val(),
                        "post_data":print_datamc}
                     
                    $.post(print_url, post_data, function(resp_data) {

                          
                               wind=window.open("data:application/pdf," + escape(resp_data),'_blank');
                                wind.print()
                     }); 

//-------------------------------------------- 





/// -------------------------  last day work -----------------------


def masterpacking_slip(request,waybill_id):
    
    check=True
    error=""
    print_data=[]
    response={}
    try:
        orderlines=OrderLine.objects.get(id=waybill_id) 
        prod_sk=orderlines.prod_sk
        prod_qty=orderlines.prod_qty
        client_store_sk=orderlines.client_store_sk
        clientstore=get_cs_object_cache(client_store_sk)
        master_channel_name=clientstore.master_channel.name
        
        pcsCach=ProductClientStoreCacheManager()
        #pcsCach.set_cache()
        listis=pcsCach.get_product_sk_to_alias_mapping(prod_sk)
        client_store_product_number=None
        for data in listis:
            if data['client_store']==client_store_sk:
                client_store_product_number=data['client_store_product_number']

    except Exception, e:
        check=False
        error=str(e)
        return HttpResponse("Exception="+error)
    else:
        a={'serial':str(client_store_product_number),'product_number':str(master_channel_name)}
        for i in xrange(prod_qty):
                print_data.append(a)

        resp=zebra_serials(json.loads(json.dumps(print_data)))
        resp['Content-Disposition'] = 'attachment; filename="ExtraSlip.pdf"'
        return  HttpResponse(resp, mimetype="application/pdf")  







