<?php
	$currentCategory = "ADD MOD";
	$errorMessage = "Add modification to our website !";

	@require("core.php");
	@require("incl/header.php");
	if ($_SERVER["REQUEST_METHOD"] == "POST") {
		$category = trim(filter_input(INPUT_POST,"category",FILTER_SANITIZE_STRING));
		$title = trim(filter_input(INPUT_POST,"title",FILTER_SANITIZE_STRING));
	    $description = trim(filter_input(INPUT_POST,"description",FILTER_SANITIZE_STRING));
	    $authors = trim(filter_input(INPUT_POST,"authors",FILTER_SANITIZE_STRING));
	    $downloadLink = trim(filter_input(INPUT_POST,"downloadLink",FILTER_VALIDATE_URL));

	    $photoLink1 = addslashes($_FILES["photoLink1"]["name"]);
	    $photoLink1type = pathinfo($photoLink1,PATHINFO_EXTENSION);
	    $photoLink1size = $_FILES["photoLink1"]["size"];
	    @$photoLink1temp = addslashes(file_get_contents($_FILES["photoLink1"]["tmp_name"]));
	    $photoLink1error = $_FILES["photoLink1"]["error"];

	    $photoLink2 = addslashes($_FILES["photoLink2"]["name"]);
	    $photoLink2type = pathinfo($photoLink2,PATHINFO_EXTENSION);
	    $photoLink2size = $_FILES["photoLink2"]["size"];
	   @$photoLink2temp = addslashes(file_get_contents($_FILES["photoLink2"]["tmp_name"]));
	    $photoLink2error = $_FILES["photoLink2"]["error"];

	    $photoLink3 = addslashes($_FILES["photoLink3"]["name"]);
	    $photoLink3type = pathinfo($photoLink3,PATHINFO_EXTENSION);
	    $photoLink3size = $_FILES["photoLink3"]["size"];
	    @$photoLink3temp = addslashes(file_get_contents($_FILES["photoLink3"]["tmp_name"]));
	    $photoLink3error = $_FILES["photoLink3"]["error"];

	    if($category == ""){
	    	$errorMessage = "Please enter a category !";
	    }
	    else if($title == ""){
	    	$errorMessage = "Please enter a title !";
	    }
	    else if($description == ""){
	    	$errorMessage = "Please enter a description !";
	    }
	    else if($authors == ""){
	    	$errorMessage = "Please enter an author !";
	    }
	    else if($downloadLink == "" || !isset($downloadLink)){
	    	$errorMessage = "Invalid URL !";
	    }
	    // Photo Link1 Check
	    else if($photoLink1 == "" && $photoLink2 =="" && $photoLink3 == ""){
	    	$errorMessage = "Minim one photo is required !";
	    }
	    else if($photoLink1 != "" && ($photoLink1type != "jpg" && $photoLink1type != "png" && $photoLink1type != "jpeg")){
	    	$errorMessage = "Image 1 : This ".$photoLink1type." type is not allowed !";
	    }
	    else if($photoLink1 != "" && $photoLink1size > 6000000){
	    	$photoLink1size /= 1000;
	    	$errorMessage = "Image 1 : File is too large ".$photoLink1size."kb, maxim is 2000kb !";
	    }
	    else if($photoLink1 != "" && $photoLink1error > 0){
	    	$errorMessage = "Image 1 : There is an error code: ".$photoLink1error." !";
	    }
	    // Photo Link2 Check
	    else if($photoLink2 != "" && ($photoLink2type != "jpg" && $photoLink2type != "png" && $photoLink2type != "jpeg")){
	    	$errorMessage = "Image 2 : This ".$photoLink2type." type is not allowed !";
	    }
	    else if($photoLink2 != "" && $photoLink2size > 6000000){
	    	$photoLink2size /= 1000;
	    	$errorMessage = "Image 2 : File is too large ".$photoLink2size."kb, maxim is 2000kb !";
	    }
	    else if($photoLink2 != "" && $photoLink2error > 0){
	    	$errorMessage = "Image 2 : There is an error code: ".$photoLink2error." !";
	    }
	    // Photo Link3 Check
	    else if($photoLink3 != "" && ($photoLink3type != "jpg" && $photoLink3type != "png" && $photoLink3type != "jpeg")){
	    	$errorMessage = "Image 3 : This ".$photoLink3type." type is not allowed !";
	    }
	    else if($photoLink3 != "" && $photoLink3size > 6000000){
	    	$photoLink3size /= 1000;
	    	$errorMessage = "Image 3 : File is too large ".$photoLink3size."kb, maxim is 2000kb !";
	    }
	    else if($photoLink3 != "" && $photoLink3error > 0){
	    	$errorMessage = "Image 3 : There is an error code: ".$photoLink3error." !";
	    }
	    else if($photoLink1 == ""){
	    	$errorMessage = "You must fill first photo !";
	    }
	    else{
	    	$errorMessage = null;
	    }
	}
?>

<?php 
	if(isset($_GET["status"]) && $_GET["status"] == "succes") {
		?>
			<div class="fatalError">
				<p class="fatalErrorColor"><?php echo "Your mod was beed submited!";?></p>
			</div>
			<hr>
		<?php
	} 
	else if(isset($errorMessage)) {
		?>
			<div class="fatalError">
				<p class="fatalErrorColor"><?php echo $errorMessage; ?></p>
			</div>
			<hr>
		<?php
	}
	//TRIGGER succes
	else if(!isset($errorMessage)){
		$time = time();
		mysql_connect($siteAddress, $databaseUsername, $databasePassword);
		mysql_select_db($databaseName);
		$query = "INSERT INTO `admin` (`id`, `category`, `title`, `modDesc`, `author`, `downloadLink`, `photoLink1`, `photoLink1BLOB`, `photoLink2`, `photoLink2BLOB`, `photoLink3`, `photoLink3BLOB`, `releaseDate`, `numberOfDownloads`) VALUES (NULL, '".mysql_real_escape_string($category)."', '".mysql_real_escape_string($title)."', '".mysql_real_escape_string($description)."', '".mysql_real_escape_string($authors)."', '".mysql_real_escape_string($downloadLink)."', '".mysql_real_escape_string($photoLink1)."',  '".$photoLink1temp."', '".mysql_real_escape_string($photoLink2)."', '".$photoLink2temp."', '".mysql_real_escape_string($photoLink3)."', '".$photoLink3temp."', '".mysql_real_escape_string($time)."', '1')";
		if(!mysql_query($query)){
			echo "Cannot Perform Query";
			echo mysql_error();
		}
		else{
			header("location:uploadMod.php?status=succes");
			exit;
		}
	}
?>

<?php
	if(!isset($_GET["status"])) {
?>
<form class="uploadMod" method="POST" action="uploadMod.php" enctype="multipart/form-data">
	<table style="width: 70%;">
		<tr>
			<th><label for="category" class="color" style="color:white;">Category :</label></th>
			<td><select id="category" name="category">
				<option value="Farming Simulator 17" > Farming Simulator 17' Mods</option>
				<option value="Buildings" <?php if(isset($category) && $category == "Buildings") { echo " selected"; } ?>>Buildings</option>
				<option value="Cars" <?php if(isset($category) && $category == "Cars") { echo " selected"; } ?>>Cars</option>
				<option value="Combines" <?php if(isset($category) && $category == "Combines") { echo " selected"; } ?>>Combines</option>
				<option value="Cutters" <?php if(isset($category) && $category == "Cutters") { echo " selected"; } ?>>Cutters</option>
				<option value="DeveloperTools" <?php if(isset($category) && $category == "DeveloperTools") { echo " selected"; } ?>>DeveloperTools</option>
				<option value="ForkliftsExcavators" <?php if(isset($category) && $category == "ForkliftsExcavators") { echo " selected"; } ?>>ForkliftsExcavators</option>
				<option value="ImplementsTools" <?php if(isset($category) && $category == "ImplementsTools") { echo " selected"; } ?>>ImplementsTools</option>
				<option value="Maps" <?php if(isset($category) && $category == "Maps") { echo " selected"; } ?>>Maps</option>
				<option value="Packs" <?php if(isset($category) && $category == "Packs") { echo " selected"; } ?>>Packs</option>
				<option value="Textures" <?php if(isset($category) && $category == "Textures") { echo " selected"; } ?>>Textures</option>
				<option value="Tractors" <?php if(isset($category) && $category == "Tractors") { echo " selected"; } ?>>Tractors</option>
				<option value="Trailers" <?php if(isset($category) && $category == "Trailers") { echo " selected"; } ?>>Trailers</option>
				<option value="Trucks" <?php if(isset($category) && $category == "Trucks") { echo " selected"; } ?>>Trucks</option>
				<option value="Vehicles" <?php if(isset($category) && $category == "Vehicles") { echo " selected"; } ?>>Vehicles</option>
			</select></td>
		</tr>
		<tr>
			<th><label for="title" class="color" style="color:white;">*Title :</label></th>
			<td><input type="text" style="width : 120%;" id="title" name="title" value="<?php if(isset($title)) { echo $title; } ?>"/></td>
		</tr>
		<tr>
			<th><label for="Description" class="color" style="color:white;">*Description : </label></th>
			<td><textarea id="description" style="width :  120%; height: 100px;"name="description"><?php if(isset($description)) { echo htmlspecialchars($_POST["description"]); } ?></textarea></td>
		</tr>
		<tr>
			<th><label for="Authors" class="color" style="color:white;">*Authors :</label></th>
			<td><textarea id="authors" style="width : 120%; height: 50px;"name="authors"><?php if(isset($authors)) { echo htmlspecialchars($_POST["authors"]); } ?></textarea></td>
		</tr>
		<tr>
			<th><label for="DownloadLink" class="color" style="color:white;">*DownloadLink :</label></th>
			<td><input type="text"style="width :  120%;" id="downloadLink" name="downloadLink" value="<?php if(isset($downloadLink)) { echo $downloadLink; }?>"/></td>
		</tr>
		<tr>
			<th><label for="PhotoLinks" class="color" style="color:white;">*Photo Links (<span style="color: red;">Minim One Photo</span>) :</label></th>
			<td>
			<input type="file" name="photoLink1" style="color: white;" id="photoLink1">
			<input type="file" name="photoLink2" style="color: white;" id="photoLink2">
			<input type="file" name="photoLink3" style="color: white;" id="photoLink3">
			</td>
		</tr>
	</table>
	<p style="color: red;margin-left: 164px;font-size: small;"> Allowed types: jpg, png, gif !</p>
	<input type="submit" style="height: 50px;margin-top: 30px;margin-left: 40px;" value="Submit Mod" />
</form>

<?php
	}
?>

<?php @require("incl/footer.php"); ?>
