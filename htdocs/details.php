<?php
	@require("core.php");

	$pageTitle = "Farming Simulator 17' Mods";
	$mod = null;
	$currentCategory = "noDescription";

	if(isset($_GET["name"]) && $_GET["cat"]){
		$pageTitle = $_GET["name"];
		$mod = $_GET["name"];
		$categ = $_GET["cat"];
		$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=$categ'>".ucfirst($categ)."</a> &gt <a>$mod</a>";
	}
	
	@require("incl/header.php");
?>

<?php

	$ans = fetchMod($mod);
	while($row = mysql_fetch_assoc($ans)){
		?>	
			<style>
			.mySlides {display:none}
			.w3-left, .w3-right, .w3-badge {cursor:pointer}
			.w3-badge {height:13px;width:13px;padding:0}
			</style>
			<div class="detailsPage">
				<h1><span class = "detailModTitle"><?php echo ucfirst($row['title']);?></span></h1>
				<h3 title="Downloads"><i class="fa fa-download" aria-hidden="true"></i> <?php echo $row['numberOfDownloads'];?></h3>
			
				<div class="w3-content w3-display-container" style="max-width:800px">
				<img class="mySlides" src="showimage.php?id=<?php echo $row['id'];?>&source=img1" style="width:100%">
				<?php if($row["photoLink2"] != ""){?>
					<img class="mySlides" src="showimage.php?id=<?php echo $row['id'];?>&source=img2" style="width:800px;height:500px;">
				<?php } ?>
				<?php if($row["photoLink3"] != ""){?>
					<img class="mySlides" src="showimage.php?id=<?php echo $row['id'];?>&source=img3" style="width:800px;height:500px;">
				<?php } ?>
				<div class="w3-center w3-section w3-large w3-text-white w3-display-bottomleft" style="width:100%">
				<div class="w3-left w3-padding-left w3-hover-text-khaki" onclick="plusDivs(-1)">&#10094;</div>
				<div class="w3-right w3-padding-right w3-hover-text-khaki" onclick="plusDivs(1)">&#10095;</div>
				<span class="w3-badge demo w3-border w3-transparent w3-hover-white" onclick="currentDiv(1)"></span>
				<span class="w3-badge demo w3-border w3-transparent w3-hover-white" onclick="currentDiv(2)"></span>
				<span class="w3-badge demo w3-border w3-transparent w3-hover-white" onclick="currentDiv(3)"></span>
				</div>
				</div>

				<script>
					var slideIndex = 1;
					showDivs(slideIndex);

					function plusDivs(n) {
						showDivs(slideIndex += n);
					}

					function currentDiv(n) {
						showDivs(slideIndex = n);
					}

					function showDivs(n) {
					var i;
					var x = document.getElementsByClassName("mySlides");
					var dots = document.getElementsByClassName("demo");
					if (n > x.length) {
						slideIndex = 1
					}
					if (n < 1) {
						slideIndex = x.length
					}
					for (i = 0; i < x.length; i++) {
						x[i].style.display = "none";
					}
					for (i = 0; i < dots.length; i++) {
						dots[i].className = dots[i].className.replace(" w3-white", "");
					}
					x[slideIndex-1].style.display = "block";
					dots[slideIndex-1].className += " w3-white";	
				}

				$(document).ready(function() {
			
		            $("#downloadMod").click(function(event){
						
		               $.post( 
		                  "updateDownloads.php",
		                  { increase: "<?php echo $row['title'];?>" },
		                  function(data) {
		                     
		                  }
		               );
							
		            });
						
		         });
				</script>
				<h2><span id = "detailModDetails"><i class="fa fa-commenting" aria-hidden="true"></i>  Details:</span></h2>
				<span class = "detailModDescription" id="modDescriptionDetail">Details:</br> <?php echo $row['modDesc'];?></span><br><br>
				<span class = "detailModDescription" id="modAuthorDetail"><i class="fa fa-user" aria-hidden="true"></i>  Author:</br> <?php echo $row['author'];?></span><br><br>
				<span class = "detailModDescription" id="modDownloadLinkDetail" title="<?php echo $row['downloadLink'];?>"><i class="fa fa-download" aria-hidden="true"></i>  Download link :</br><a href="<?php echo $row['downloadLink'];?>" target = "_blank"><input style="color: black;" type="button" id="downloadMod" value="Download Mod"></input></a></span><br><br>
			</div>
		<?php
	}
?>
<?php
	@require("incl/footer.php");
?>