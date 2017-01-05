<?php
	@require("core.php");
	$pageTitle = "Admin Time";
	$currentCategory = "Admin";
	$section = "Farming Simulator 17' Mods";
	@require("incl/header.php");
?>

<?php
	if(isset($_GET["password"]) && $_GET["password"] == $adminPassword){
			$ans = fetchModCategoryAdmin($section);
			while($row = mysql_fetch_assoc($ans)){
					$time = $row["releaseDate"];
				?>
					<div title="<?php echo $row["title"];?>" id="mod">
						<a href="detailsadmin.php?name=<?php echo $row["title"];?>&cat=<?php echo $row["category"];?>" class="pureA">
							<div id = "modImage">
								<img  src="showimageAdmin.php?id=<?php echo $row['id'];?>&source=img1">
							</div>
							<div id = "modInfo">
								<div id = "modName">
									<span><?php echo $row["title"];?></span>
								</div>
								<div id = "modCategory">
									<span>Category : <?php echo $row["category"];?></span>
								</div>
								<div id = "releaseDate">
									<span><?php echo date('d/m/Y', $time);?></span>
								</div>
							</div>
						</a>
					</div>
				<?php
			}
	}else{
		header("location: /");
	}
?>

<?php
	@require("incl/footer.php");
?>