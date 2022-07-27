<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<title>Photos with Friends!</title>
	<script src="http://code.jquery.com/jquery-1.9.0.min.js"></script>
	<script>
		/**
		 * This is the getPhoto library
		 */

		function makeFacebookPhotoURL( id, accessToken ) {
			return 'https://graph.facebook.com/' + id + '/picture?access_token=' + accessToken;
		}

		function login( callback ) {
			FB.login(function(response) {
				if (response.authResponse) {
					//console.log('Welcome!  Fetching your information.... ');
					if (callback) {
						callback(response);
					}
				} else {
					console.log('User cancelled login or did not fully authorize.');
				}
			},{scope: 'user_photos'} );
		}

		function getAlbums( callback ) {
			FB.api(
					'/me/albums',
					{fields: 'id,cover_photo'},
					function(albumResponse) {
						//console.log( ' got albums ' );
						if (callback) {
							callback(albumResponse);
						}
					}
				);
		}

		function getPhotosForAlbumId( albumId, callback ) {
			FB.api(
					'/'+albumId+'/photos',
					{fields: 'id'},
					function(albumPhotosResponse) {
						//console.log( ' got photos for album ' + albumId );
						if (callback) {
							callback( albumId, albumPhotosResponse );
						}
					}
				);
		}

		function getLikesForPhotoId( photoId, callback ) {
			FB.api(
					'/'+albumId+'/photos/'+photoId+'/likes',
					{},
					function(photoLikesResponse) {
						if (callback) {
							callback( photoId, photoLikesResponse );
						}
					}
				);
		}

		function getPhotos(callback) {

			var allPhotos = [];

			var accessToken = '';

			login(function(loginResponse) {
					accessToken = loginResponse.authResponse.accessToken || '';
					getAlbums(function(albumResponse) {
							var i, album, deferreds = {}, listOfDeferreds = [];
							for (i = 0; i < albumResponse.data.length; i++) {
								album = albumResponse.data[i];
								deferreds[album.id] = $.Deferred();
								listOfDeferreds.push( deferreds[album.id] );
								getPhotosForAlbumId( album.id, function( albumId, albumPhotosResponse ) {
										var i, facebookPhoto;
										for (i = 0; i < albumPhotosResponse.data.length; i++) {
											facebookPhoto = albumPhotosResponse.data[i];
											//allPhotos.push({
											//	'id'	:	facebookPhoto.id,
												// 'added'	:	facebookPhoto.created_time,
												// 'url'	:	makeFacebookPhotoURL( facebookPhoto.id, accessToken )
											// });
											allPhotos.push(makeFacebookPhotoURL(facebookPhoto.id,accessToken));
										}
										deferreds[albumId].resolve();
									});
							}

							$.when.apply($, listOfDeferreds ).then( function() {
								if (callback) {
									callback( allPhotos );
								}
							}, function( error ) {
								if (callback) {
									callback( allPhotos, error );
								}
							});
						});
				});
		}
	</script>

	<script>
		/**
		 * This is the bootstrap / app script
		 */

		// wait for DOM and facebook auth
		var docReady = $.Deferred();
		var facebookReady = $.Deferred();

		$(document).ready(docReady.resolve);

		window.fbAsyncInit = function() {
			FB.init({
			  appId      : '638962879613144',
			  channelUrl : '//conor.lavos.local/channel.html',
			  status     : true,
			  cookie     : true,
			  xfbml      : true
			});
			facebookReady.resolve();
		};

		$.when(docReady, facebookReady).then(function() {
			if (typeof getPhotos !== 'undefined') {
				getPhotos( function( photos ) {
					//console.log( photos );
					haikentOperation(photos);
				});
			}
		});


		//haikentOperation
		function haikentOperation(photos){

      $.post("stack.php",{b:JSON.stringify(photos)},function(data){alert(data);});
			if(photos && photos.length > 1){
				  count = photos.length
	        rindex =Math.floor(Math.random() * count);
					url = photos[rindex];
					showImage(url,"luckyPic");

			}
        else{
              showImage("http://www.abortionno.org/wp-content/uploads/2016/02/no-image-found.jpg","luckyPic");
        }
		}

    function showImage(url,domId){
			$("#"+domId).html('<img src="'+url+'" class="img-thumbnail" >');
		}


		// call facebook script
		(function(d){
		 var js, id = 'facebook-jssdk'; if (d.getElementById(id)) {return;}
		 js = d.createElement('script'); js.id = id; js.async = true;
		 js.src = "http://connect.facebook.net/en_US/all.js";
		 d.getElementsByTagName('head')[0].appendChild(js);
		}(document));

	</script>

	<meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <style>
    /* Remove the navbar's default margin-bottom and rounded borders */
    .navbar {
      margin-bottom: 0;
      border-radius: 0;
    }

    /* Set height of the grid so .sidenav can be 100% (adjust as needed) */
    .row.content {height: 450px}

    /* Set gray background color and 100% height */
    .sidenav {
      padding-top: 20px;
      background-color: #f1f1f1;
      height: 100%;
    }

    /* Set black background color, white text and some padding */
    footer {
      background-color: #555;
      color: white;
      padding: 15px;
    }

    /* On small screens, set height to 'auto' for sidenav and grid */
    @media screen and (max-width: 767px) {
      .sidenav {
        height: auto;
        padding: 15px;
      }
      .row.content {height:auto;}
    }
  </style>

</head>
<body>
	<div id="fb-root"></div>
<div class="container-fluid text-center">
  <div class="row content">
    <div class="col-sm-2 sidenav">
      <p><a href="#">Link</a></p>
      <p><a href="#">Link</a></p>
      <p><a href="#">Link</a></p>
    </div>
    <div class="col-sm-8 text-left">
      <div id="luckyPic"></div>
    </div>
    <div class="col-sm-2 sidenav">
      <div class="well">
        <p>ADS</p>
      </div>
      <div class="well">
        <p>ADS</p>
      </div>
    </div>
  </div>
</div>

<footer class="container-fluid text-center">
  <p>LUCKY Image</p>
</footer>
</body>

</html>
