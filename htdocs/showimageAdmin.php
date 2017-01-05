<?php

	@require("core.php");

	$id = mysql_real_escape_string($_GET['id']);
	$source = mysql_real_escape_string($_GET['source']);
	$imagesSouces = array();

	if(isset($_GET['id'])){
		if($query = mysql_query("SELECT * FROM `admin` WHERE `id` = '$id'")){
			while($row = mysql_fetch_assoc($query)){
				$imageData1 = $row["photoLink1BLOB"];
				$imageData2 = $row["photoLink2BLOB"];
				$imageData3 = $row["photoLink3BLOB"];
			}
			header("content-type: image/jpeg");
			$imagesSouces[0] = $imageData1;
			$imagesSouces[1] = $imageData2;
			$imagesSouces[2] = $imageData3;
			if(isset($source) && $source == "img1"){
				echo $imagesSouces[0];
			}
			else if(isset($source) && $source == "img2"){
				echo $imagesSouces[1];
			}
			else if(isset($source) && $source == "img3"){
				echo $imagesSouces[2];
			}
 		}
		else{
			echo "query";
		}
	}
	else{
		echo "ERROR";
	}
?>