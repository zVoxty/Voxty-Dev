<?php
	ob_start("ob_gzhandler");
	@require("essentials/settings.php");
	@require("essentials/databaseConnection.php");

	function fetchNumberOfModsFromCategory($category){
		if($category == 1){
			$query = "SELECT * FROM `fs17all` WHERE 1";
		}else{
			$query = "SELECT * FROM `fs17all` WHERE `category` = '".$category."'";
		}

		if($result = mysql_query($query)){
			$ans = mysql_num_rows($result);
			return $ans;
		}
	}

	// TODO : MAKE A FUNCTION WHICH WILL RETURN IF NAME OF MOD WHICH WAS BEEN UPLOADED ALREADY EXIST IN DATABASE

	function fetchLastElementFromDatabase($id){
		$query = "SELECT * FROM `fs17all` ORDER BY `id` DESC LIMIT 1";
		if($result = mysql_query($query)){
			$fetchResult = mysql_fetch_assoc($result);
			$numberOfInstances = $fetchResult["id"];
			$temp = $numberOfInstances - $id;
			$query1 = "SELECT * FROM `fs17all` WHERE `id` = '$temp'";
			if($result1 = mysql_query($query1)){
				return $result1;
			}
		}
	}

	function fetchFromDatabase($select, $from, $where, $value){
		$query = "SELECT `$select` FROM `$from` WHERE `$where` = '$value'";
		if($query_run = mysql_query($query)){
			$fetch = mysql_fetch_assoc($query_run);
			return $fetch[$select];
		}
		else{
			echo 'Cannot Perform Query !';
		}
	}

	function increaseDownload($name){
		$number = fetchFromDatabase("numberOfDownloads", "fs17all", "title", $name);
		$number++;
		$query = "UPDATE `fs17all` SET `numberOfDownloads` = '$number' WHERE `title` = '$name'";
		if(mysql_query($query)){
			return true;
		}
		else{
			return false;
		}
	}
	function fetchModCategory($category, $page1, $modsPerPage){
		if($category == "Farming Simulator 17' Mods"){
			$query = "SELECT * FROM `fs17all` WHERE 1 ORDER BY  `id` DESC LIMIT $page1, $modsPerPage";
		}
		else{
			$query = "SELECT * FROM `fs17all` WHERE `category` = '".$category."' ORDER BY  `id` DESC LIMIT $page1, $modsPerPage";
		}	
		if($result = mysql_query($query)){
			return $result;
		}
		else{
			echo "query Problem fetchModCategory";
		}
	}

	function fetchModCategoryAdmin($category){
		if($category == "Farming Simulator 17' Mods"){
			$query = "SELECT * FROM `admin` WHERE 1 ORDER BY  `id` DESC";
		}
		else{
			$query = "SELECT * FROM `admin` WHERE `category` = '".$category."' ORDER BY  `id` DESC";
		}	
		if($result = mysql_query($query)){
			// while($row = mysql_fetch_array($result)){
			// 	return $row;
			// }
			return $result;
		}
		else{
			echo "query Problem fetchModCategory";
		}
	}
	function fetchMod($mod){
		$query = "SELECT * FROM `fs17all` WHERE `title` = '".mysql_real_escape_string($mod)."'";
		if($result = mysql_query($query)){
			return $result;
		}
		else{
			echo "Cannot perform query";
			echo mysql_error(); 
		}
	}
	function fetchModAdmin($mod){
		$query = "SELECT * FROM `admin` WHERE `title` = '".mysql_real_escape_string($mod)."'";
		if($result = mysql_query($query)){
			return $result;
		}
		else{
			echo "Cannot perform query";
			echo mysql_error(); 
		}
	}
	function alreadyExistInDatabase($modName){
		$query = "SELECT * FROM `fs17all` WHERE `title` = '".mysql_real_escape_string($modName)."'";
		if($result = mysql_query($query)){
			$numRows = mysql_num_rows($result);
			if($numRows == 0){
				return false;
			}
			else{
				return true;
			}
		}
	}
	function test_input($data) {
	    $data = trim($data);
		$data = stripslashes($data);
		$data = htmlspecialchars($data);
		return $data;
	}
?>