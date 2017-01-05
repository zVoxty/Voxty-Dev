<?php

	@require_once("core.php");
	if ($_REQUEST["search"]){
		$valueForSearch = mysql_real_escape_string($_REQUEST["search"]);
		$query = "SELECT * FROM `fs17all` WHERE `modDesc` LIKE '%".$valueForSearch."%'";
		$return = mysql_query($query);
		while($row = mysql_fetch_array($return)){
			if($row == ""){
				echo "No search Results.";
			}
			else{
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
		}
	}
?>