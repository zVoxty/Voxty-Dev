<?php ob_start();?>
<?php
	$find_counts = mysql_query("SELECT * FROM counts");
	while($row = mysql_fetch_assoc($find_counts)){
		$current_counts = $row['counter'];
		$new_count = $current_counts + 1;
		$update_count = mysql_query("UPDATE `fs17` . `counts` SET `counter` = $new_count");
	}
?>
<!DOCTYPE html>
<html>
<head>
	<title><?php echo $pageTitle;?></title>
	<meta name="description" content="voxmods.com - updated frequently farming simulator 2017, FS 2017, LS 2017 modifications,Farming Simulator 2017 mods, farmingssimulator 2017 mods." />
	<meta property="og:type" content="blog" />
	<meta property="og:title" content="Farming simulator 2017 mods" />
	<meta property="og:description" content="voxmods.com - updated frequently farming simulator 2017, FS 2017, LS 2017 modifications,Farming Simulator 2017 mods, farmingssimulator 2017 mods." />
	<meta property="og:url" content="http://voxmods.com/" />
	<meta property="og:site_name" content="Farming simulator 2017 mods" />
	<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	<link rel="stylesheet" type="text/css" href="css/font-awesome.min.css">
	<script type="text/javascript" src="../js/jquery-3.1.0.min.js"></script>	
	<script type="text/javascript" src="../js/bootstrap.min.js"></script>
	<script type="text/javascript" src="../js/voxty.js"></script>
	<link rel="stylesheet" type="text/css" href="css/style.css">
	<style>
 	.carousel-inner > .item > img,
 	.carousel-inner > .item > a > img {
    	width: 20%;
    	margin: auto;
 	}
  	</style>

  	<!--/Start async trafic.ro/-->
	<script type="text/javascript" id="trfc_trafic_script">
	//<![CDATA[
	t_rid = 'voxmods-com';
	(function(){ t_js_dw_time=new Date().getTime();
	t_js_load_src=((document.location.protocol == 'http:')?'http://storage.':'https://secure.')+'trafic.ro/js/trafic.js?tk='+(Math.pow(10,16)*Math.random())+'&t_rid='+t_rid;
	if (document.createElement && document.getElementsByTagName && document.insertBefore) {
	t_as_js_en=true;var sn = document.createElement('script');sn.type = 'text/javascript';sn.async = true; sn.src = t_js_load_src;
	var psn = document.getElementsByTagName('script')[0];psn.parentNode.insertBefore(sn, psn); } else {
	document.write(unescape('%3Cscri' + 'pt type="text/javascript" '+'src="'+t_js_load_src+';"%3E%3C/sc' + 'ript%3E')); }})();
	//]]>
	</script>
	<noscript><p><a href="http://www.trafic.ro/statistici/voxmods.com"><img alt="voxmods.com" src="http://log.trafic.ro/cgi-bin/pl.dll?rid=voxmods-com" /></a> <a href="http://www.trafic.ro/">Web analytics</a></p></noscript>
	<!--/End async trafic.ro/-->

</head>
<body>

<div id="wrapper">
	<div id="header">
		<div id="topNavigationBar">
			<ul>
				<li><a href="#"><i class="fa fa-question-circle" aria-hidden="true"></i>  How to Download</a></li>
				<li><a href="howtoupload.php"><i class="fa fa-question-circle" aria-hidden="true"></i>  How to Upload</a></li>
				<li><a class="activeX" href="uploadMod.php"><i class="fa fa-upload" aria-hidden="true"></i>  Upload Your Mod</a></li>
				<li><a href="contact.php"><i class="fa fa-at" aria-hidden="true"></i>  Contact Us</a></li>
				<li><a href="about.php"><i class="fa fa-question-circle" aria-hidden="true"></i>  About Us</a></li>
			</ul>
		</div>
	</div>
	<div id = "carousel">
		<div id="myCarousel" class="carousel slide" data-ride="carousel">
	    <!-- Indicators -->
	    <ol class="carousel-indicators" style="display:none">                                          <!--CAROUSEL INDICATORS NOT SHOWED -->
	      <li data-target="#myCarousel" data-slide-to="0" class="active"></li>
	      <li data-target="#myCarousel" data-slide-to="0"></li>
	    </ol>

	    <!-- Wrapper for slides -->
	    <div class="carousel-inner" role="listbox">
	    	<?php

	    		for($i = 1; $i <= 3; $i++){

	    			?>	<!-- -NEW IMPLEMENTATIONS WITHOUT TWO FOR's -->
	    				<div class="item <?php if($i == 1){ echo 'active';}?>" style="height: 100%;">
				      		<div id= "carouselContainer">
				      			<?php
									if($i == 1){
										for($j = 0; $j <= 3; $j++){
											$answer = fetchLastElementFromDatabase($j);
											while ($row = mysql_fetch_array($answer)) {
												?>
													<a href="details.php?name=<?php echo $row['title'];?>&cat=<?php echo $row['category'];?>" class="carouselElement">
									      				<div id="elementContainer">
									      					<img src="showimage.php?id=<?php echo $row['id'];?>&source=img1" style="height: 100%; width: 100%;">
									      					<span id="elementName" class="carouselInfos"><?php if(strlen($row["title"]) > 20){ echo $row["title"]= substr($row["title"],0,20)." ...";}else{echo ucfirst($row["title"]);}?></span></br>
									      					<span id="elementDownloads" class="carouselInfos"><i class="fa fa-download" aria-hidden="true"></i><?php echo $row["numberOfDownloads"];?></span></br>
									      				</div>
									      			</a>
												<?php
											}
										}
									}
									if($i == 2){
										for($j = 4; $j <= 7; $j++){
											$answer = fetchLastElementFromDatabase($j);
											while ($row = mysql_fetch_array($answer)) {
												?>
													<a href="details.php?name=<?php echo $row['title'];?>&cat=<?php echo $row['category'];?>" class="carouselElement">
									      				<div id="elementContainer">
									      					<img src="showimage.php?id=<?php echo $row['id'];?>&source=img1" style="height: 100%; width: 100%;">
									      					<span id="elementName" class="carouselInfos"><?php if(strlen($row["title"]) > 15){ echo $row["title"]= substr($row["title"],0,15)." ...";}else{echo ucfirst($row["title"]);}?></span></br>
									      					<span id="elementDownloads" class="carouselInfos"><i class="fa fa-download" aria-hidden="true"></i><?php echo $row["numberOfDownloads"];?></span></br>
									      				</div>
									      			</a>
												<?php
											}
										}
									}
									if($i == 3){
										for($j = 7; $j <= 10; $j++){
											$answer = fetchLastElementFromDatabase($j);
											while ($row = mysql_fetch_array($answer)) {
												?>
													<a href="details.php?name=<?php echo $row['title'];?>&cat=<?php echo $row['category'];?>" class="carouselElement">
									      				<div id="elementContainer">
									      					<img src="showimage.php?id=<?php echo $row['id'];?>&source=img1" style="height: 100%; width: 100%;">
									      					<span id="elementName" class="carouselInfos"><?php if(strlen($row["title"]) > 15){ echo $row["title"]= substr($row["title"],0,15)." ...";}else{echo ucfirst($row["title"]);}?></br>
									      					<span id="elementDownloads" class="carouselInfos"><i class="fa fa-download" aria-hidden="true"></i><?php echo $row["numberOfDownloads"];?></span></br>
									      				</div>
									      			</a>
												<?php
											}
										}
									}
								?>	
				      		</div>
				     	 </div>
	    			<?php

	    		}

	    	?>
	      	
	    </div>

	    <!-- Left and right controls -->
	    <a class="left carousel-control" href="#myCarousel" role="button" data-slide="prev">
	      <span class="glyphicon glyphicon-chevron-left" style="margin-left: -40%; " aria-hidden="true"></span>
	      <span class="sr-only">Previous</span>
	    </a>
	    <a class="right carousel-control" href="#myCarousel" role="button" data-slide="next">
	      <span class="glyphicon glyphicon-chevron-right" style="margin-right: -40%;" aria-hidden="true"></span>
	      <span class="sr-only"> Next</span>
	    </a>
	  </div>
	</div>
	<div id="container">
		<div id = "sidebar-categoryMods">
			<div id = "follow">
				<span> <i class="fa fa-bell" aria-hidden="true"></i>Visits : <?php $res = mysql_query("SELECT * FROM `counts`"); while($row = mysql_fetch_assoc($res)){echo $row["counter"];}?> </span>
			</div>
			<div id = "categoryMod-Upload">
				<a href="uploadMod.php"><i class="fa fa-upload" aria-hidden="true"></i>  Upload Mod</a>
			</div>
			<div id = "widgetAd">
				
			</div>
			<div id = "navigationModCategory">
				<div id = "navigationModCategory-container">
					<ul id = "links">
						<li>
							<a href="/" id = "titleModCategory"><i class="fa fa-home" aria-hidden="true"></i>  Farming Simulator 17</a> <span class="totalNumberOfMods"><?php echo mysql_num_rows(mysql_query("SELECT * FROM `fs17all` WHERE 1"));?></span>
							<ul id = "linksCategory">
								<li><a href="category.php?cat=buildings"><i class="fa fa-building" aria-hidden="true"></i>  Buildings</a><?php if(fetchNumberOfModsFromCategory("buildings") != null){?><span><?php echo fetchNumberOfModsFromCategory("buildings");?></span><?php }?></li>
								<li><a href="category.php?cat=cars"><i class="fa fa-car" aria-hidden="true"></i>  Cars</a><?php if(fetchNumberOfModsFromCategory("cars") != null){?><span><?php echo fetchNumberOfModsFromCategory("cars");?></span><?php } ?></li>
								<li><a href="category.php?cat=combines"><i class="fa fa-pied-piper" aria-hidden="true"></i>  Combines</a><?php if(fetchNumberOfModsFromCategory("combines") != null){?><span><?php echo fetchNumberOfModsFromCategory("combines");?></span><?php }?></li>
								<li><a href="category.php?cat=cutters"><i class="fa fa-cogs" aria-hidden="true"></i>  Cutters</a><?php if(fetchNumberOfModsFromCategory("cutters") != null){?><span><?php echo fetchNumberOfModsFromCategory("cutters");?></span><?php }?></li>
								<li><a href="category.php?cat=forkliftsExcavators"><i class="fa fa-code-fork" aria-hidden="true"></i>  Forklifts & Excavators</a><?php if(fetchNumberOfModsFromCategory("forkliftsExcavators") != null){?><span><?php echo fetchNumberOfModsFromCategory("forkliftsExcavators");?></span><?php }?></li>
								<li><a href="category.php?cat=implementsTools"><i class="fa fa-key" aria-hidden="true"></i>  Implements & Tools</a><?php if(fetchNumberOfModsFromCategory("implementsTools") != null){?><span><?php echo fetchNumberOfModsFromCategory("implementsTools");?></span><?php } ?></li>
								<li><a href="category.php?cat=maps"><i class="fa fa-map" aria-hidden="true"></i>  Maps</a><?php if(fetchNumberOfModsFromCategory("maps") != null){?><span><?php echo fetchNumberOfModsFromCategory("buildings");?></span><?php } ?></li>
								<li><a href="category.php?cat=objects"><i class="fa fa-object-ungroup" aria-hidden="true"></i>  Objects</a><?php if(fetchNumberOfModsFromCategory("objects") != null){?><span><?php echo fetchNumberOfModsFromCategory("objects");?></span><?php }?></li>
								<li><a href="category.php?cat=packs"><i class="fa fa-cubes" aria-hidden="true"></i>  Packs</a><?php if(fetchNumberOfModsFromCategory("packs") != null){?><span><?php echo fetchNumberOfModsFromCategory("packs");?></span><?php } ?></li>
								<li><a href="category.php?cat=textures"><i class="fa fa-wpforms" aria-hidden="true"></i>  Textures</a><?php if(fetchNumberOfModsFromCategory("textures") != null){?><span><?php echo fetchNumberOfModsFromCategory("textures");?></span><?php }?></li>
								<li><a href="category.php?cat=tractors"><i class="fa fa-tachometer" aria-hidden="true"></i>  Tractors</a><?php if(fetchNumberOfModsFromCategory("tractors") != null){?><span><?php echo fetchNumberOfModsFromCategory("tractors");?></span><?php }?></li>
								<li><a href="category.php?cat=trailers"><i class="fa fa-calendar-minus-o" aria-hidden="true"></i>  Trailers</a><?php if(fetchNumberOfModsFromCategory("trailers") != null){?><span><?php echo fetchNumberOfModsFromCategory("trailers");?></span><?php }?></li>
								<li><a href="category.php?cat=trucks"><i class="fa fa-truck" aria-hidden="true"></i>  Trucks</a><?php if(fetchNumberOfModsFromCategory("trucks") != null){?><span><?php echo fetchNumberOfModsFromCategory("trucks");?></span><?php }?></li>
								<li><a href="category.php?cat=vehicles"><i class="fa fa-taxi" aria-hidden="true"></i>  Vehicles</a><?php if(fetchNumberOfModsFromCategory("vehicles") != null){?><span><?php echo fetchNumberOfModsFromCategory("vehicles");?></span><?php }?></li>
							</ul>
						</li>
					</ul>
				</div>
			</div>
		</div>
		<div id="content">
			<div id="contentCategory">
				<span><?php echo $currentCategory;?></span> <input type="text" placeholder="Search Mod ..." id="searchMod" style="float: right;color: white; background: none;padding: 3px 10px;border-radius: 10px;text-align: center;"></input>
				<script type="text/javascript">
					$(function(){
						$("#searchMod").keypress(function(event){
							if(event.which == 13){
								event.preventDefault();
								var searchFor = $(this).val();
								$.post( 
				                  	"searchMod.php",
				                 	{ search: searchFor },
				                  	function(data) {
				                     	$("#mainContent").html(data);
				                  	}
				                );
							}
						});
					});
				</script>
			</div>
			<div id="mainContent">