<?php
	@require_once("core.php");
	if ($_REQUEST["increase"]){
		increaseDownload($_REQUEST["increase"]);
		echo "updated";
	}
?>