<?php
	@require("core.php");
	$pageTitle = "Farming Simulator 17' Mods";
	$currentCategory = "Farming Simulator 17' Mods";
	$section = null;

	if(isset($_GET["cat"])){
		if($_GET["cat"] == "buildings"){
			$pageTitle = "Mods - Buildings";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=buildings'>Buildings</a>";
			$section = "buildings";
		}
		else if($_GET["cat"] == "cars"){
			$pageTitle = "Mods - Cars";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=cars'>Cars</a>";
			$section = "cars";
		}
		else if($_GET["cat"] == "combines"){
			$pageTitle = "Mods - Combines";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=combines'>Combines</a>";
			$section = "combines";
		}
		else if($_GET["cat"] == "cutters"){
			$pageTitle = "Mods - Cutters";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=cutters'>Cutters</a>";
			$section = "cutters";
		}
		else if($_GET["cat"] == "developerTools"){
			$pageTitle = "Mods - DevTools";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=developerTools'>DevTools</a>";
			$section = "developerTools";
		}
		else if($_GET["cat"] == "forkliftsExcavators"){
			$pageTitle = "Mods - Forklifts & Excavators";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=forkliftsExcavators'>Forklifts & Excavators</a>";
			$section = "forkliftsExcavators";
		}
		else if($_GET["cat"] == "implementsTools"){
			$pageTitle = "Mods - Implements & Tools";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=implementsTools'>Implements & Tools</a>";
			$section = "implementsTools";
		}
		else if($_GET["cat"] == "maps"){
			$pageTitle = "Mods - Maps";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=maps'>Maps</a>";
			$section = "maps";
		}
		else if($_GET["cat"] == "objects"){
			$pageTitle = "Mods - Objects";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=objects'>Objects</a>";
			$section = "objects";
		}
		else if($_GET["cat"] == "packs"){
			$pageTitle = "Mods - Packs";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=packs'>Packs</a>";
			$section = "packs";
		}
		else if($_GET["cat"] == "textures"){
			$pageTitle = "Mods - Textures";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=textures'>Textures</a>";
			$section = "textures";
		}
		else if($_GET["cat"] == "tractors"){
			$pageTitle = "Mods - Tractors";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=tractors'>Tractors</a>";
			$section = "tractors";
		}
		else if($_GET["cat"] == "trailers"){
			$pageTitle = "Mods - Trailers";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=trailers'>Trailers</a>";
			$section = "trailers";
		}
		else if($_GET["cat"] == "trucks"){
			$pageTitle = "Mods - Trucks";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=trucks'>Trucks</a>";
			$section = "trucks";
		}
		else if($_GET["cat"] == "vehicles"){
			$pageTitle = "Mods - Vehicles";
			$currentCategory = "<a href='/'>Farming Simulator 17' Mods</a> &gt <a href='category.php?cat=vehicles'>Vehicles</a>";
			$section = "vehicles";
		}
	}

	// PAGINATION
	if(!isset($_GET["page"])){
		$page = 1;
	}
	else{
		$page = $_GET["page"];
	}
	if($page == "" || $page == "1"){
		$page1 = 0;
	}else{
		$page1 = ($page*$modsPerPage) - $modsPerPage;
	}
	$paginationQuery = mysql_query("SELECT * FROM `fs17all` WHERE `category` = '".$section."'");
	$totalItems = mysql_num_rows($paginationQuery);
	$numberOfPages = $totalItems / $modsPerPage;
	$numberOfPages = ceil($numberOfPages);
	if($numberOfPages == 0){
		$numberOfPages = 1;
	}
	$previousPage = $page - 1;
	$nextPage = $page + 1;
	// END PAGINATION

	@require("incl/header.php");
?>

<?php	
	$ans = fetchModCategory($section, $page1, $modsPerPage);
	while($row = mysql_fetch_assoc($ans)){
			$time = $row["releaseDate"];
		?>
			<div title="<?php echo $row["title"];?>" id="mod">
				<a href="details.php?name=<?php echo $row["title"];?>&cat=<?php echo $row["category"];?>" class="pureA">
					<div id = "modImage">
						<img  src="showimage.php?id=<?php echo $row['id'];?>&source=img1">
					</div>
					<div id = "modInfo">
						<div id = "modName">
							<span><?php echo ucfirst($row["title"]);?></span>
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
?>

<div id = "pagination">
	<div id = "textPage">
		<span><i class="fa fa-file" aria-hidden="true"></i>  Page: <?php if(!isset($page)){echo '1';}else{echo $page;}?> | <?php echo $numberOfPages;?></span>
	</div>
	<div id = "paginationContent">
		<a href="category.php?cat=<?php echo $_GET['cat'];?>&page=1"<?php if($page == 1){echo "style='display:none;'";}?>><< First </a>
		<a href="category.php?cat=<?php echo $_GET['cat'];?>&page=<?php echo $previousPage;?>" <?php if($page == 1){echo "style='display:none;'";}?>> << </a>
		<?php
			for ($i=1; $i <= $numberOfPages; $i++) { 
				?>
					<a href="category.php?cat=<?php echo $_GET['cat'];?>&page=<?php echo $i; ?>"><?php echo $i;?></a>
				<?php
			}
		?>
		<a href="category.php?cat=<?php echo $_GET['cat'];?>&page=<?php echo $nextPage;?>" <?php if($page == $numberOfPages){echo "style='display:none;'";}?>> >> </a>
		<a href="category.php?cat=<?php echo $_GET['cat'];?>&page=<?php echo $numberOfPages;?>" <?php if($page == $numberOfPages){echo "style='display:none;'";}?>>Last >></a>
	</div>
</div>

<?php
	@require("incl/footer.php");
?>