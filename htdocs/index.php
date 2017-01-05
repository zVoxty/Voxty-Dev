<?php
	@require_once("core.php");
	$pageTitle = "Farming simulator 17 Mods";
	$currentCategory = "Farming Simulator 17' Mods";
	$section = "Farming Simulator 17' Mods";

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
	$paginationQuery = mysql_query("SELECT * FROM `fs17all`");
	$totalItems = mysql_num_rows($paginationQuery);
	$numberOfPages = $totalItems / $modsPerPage;
	$numberOfPages = ceil($numberOfPages);
	if($numberOfPages == 0){
		$numberOfPages = 1;
	}
	$previousPage = $page - 1;
	$nextPage = $page + 1;
	// END PAGINATION

	@require_once("incl/header.php")
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
		<a href="index.php?page=1"<?php if($page == 1){echo "style='display:none;'";}?>><< First </a>
		<a href="index.php?page=<?php echo $previousPage;?>" <?php if($page == 1){echo "style='display:none;'";}?>> << </a>
		<?php
			for ($i=1; $i <= $numberOfPages; $i++) { 
				?>
					<a href="index.php?page=<?php echo $i; ?>"><?php echo $i;?></a>
				<?php
			}
		?>
		<a href="index.php?page=<?php echo $nextPage;?>" <?php if($page == $numberOfPages){echo "style='display:none;'";}?>> >> </a>
		<a href="index.php?page=<?php echo $numberOfPages;?>" <?php if($page == $numberOfPages){echo "style='display:none;'";}?>>Last >></a>
	</div>
</div>

<?php @require_once("incl/footer.php")?>