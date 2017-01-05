<?php
	@require("core.php");

	$pageTitle = "Details Admin";
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
	$ans = fetchModAdmin($mod);
	while($row = mysql_fetch_assoc($ans)){
		if ($_SERVER["REQUEST_METHOD"] == "POST"){
			if (isset($_POST["submit"])) {
				$title = $_GET["name"];
				$query = "INSERT INTO `fs17all` (category, title, modDesc, author, downloadLink, photoLink1, photoLink1BLOB, photoLink2, photoLink2BLOB, photoLink3, photoLink3BLOB, releaseDate, numberOfDownloads) SELECT category, title, modDesc, author, downloadLink, photoLink1, photoLink1BLOB, photoLink2, photoLink2BLOB, photoLink3, photoLink3BLOB, releaseDate, numberOfDownloads FROM admin WHERE `title` = '$title'";

				if(mysql_query($query)){
					$query1 = "DELETE FROM `admin` WHERE `title` = '$title'";
					if(mysql_query($query1)){
						header("location: /");
					}
					else{
						die("Cannot Perform Query Level: delete from admin mods ".mysql_error());
					}
				}
				else{
					die("Cannot Perform Query Level: upload to main ".mysql_error());
				}
			}
		}
		?>	
			<style>
			.mySlides {display:none}
			.w3-left, .w3-right, .w3-badge {cursor:pointer}
			.w3-badge {height:13px;width:13px;padding:0}
			</style>
			<div class="detailsPage">
				<h1><span class = "detailModTitle"><?php echo $row['title'];?></span></h1>
			
				<div class="w3-content w3-display-container" style="max-width:800px">
				<img class="mySlides" src="showimageAdmin.php?id=<?php echo $row['id'];?>&source=img1" style="width:100%">
				<?php if($row["photoLink2"] != ""){?>
					<img class="mySlides" src="showimageAdmin.php?id=<?php echo $row['id'];?>&source=img2" style="width:800px;height:500px;">
				<?php } ?>
				<?php if($row["photoLink3"] != ""){?>
					<img class="mySlides" src="showimageAdmin.php?id=<?php echo $row['id'];?>&source=img3" style="width:800px;height:500px;">
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
				</script>
				<h2><span id = "detailModDetails">Details:</span></h2>
				<span class = "detailModDescription" id="modDescriptionDetail">Details:</br> <?php echo $row['modDesc'];?></span><br><br>
				<span class = "detailModDescription" id="modAuthorDetail">Author:</br> <?php echo $row['author'];?></span><br><br>
				<form action="<?php echo $row['downloadLink'];?>" type="POST">
					<span class = "detailModDescription" id="modDownloadLinkDetail">Download link :</br> <input type="submit" target="_blank" style="color: black;" name="downloadMod" value="Download Mod"></input></span><br><br>
				</form>
				<form action="#" method="POST">
					<input style="color: black;"  title="<?php echo $row['downloadLink'];?>" type="submit" name="submit" value="Submit Mod" />
				</form>
			</div>
		<?php
	}
?>
<?php
	@require("incl/footer.php");
?>