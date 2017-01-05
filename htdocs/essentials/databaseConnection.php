<?php
	@require("settings.php");
	
	if($databaseConnection = mysql_connect($siteAddress, $databaseUsername, $databasePassword,$databaseName)){
		if(mysql_select_db($databaseName)){
			
		}
		else{
			die("Connection to database failed, maybe $databaseName is the wrong name or this database doesn't exist !");
		}
	}
	else{
		die("Connection to MySQL failed");
	}
?>