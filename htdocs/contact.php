<?php
	@require_once("core.php");
	@require_once("incl/header.php");
	$error = "Thank you for contacting us !";

	//SETUP PHP.INI 

	if(isset($_POST['contact_name']) && isset($_POST['contact_email']) && isset($_POST['contact_text'])){
		$contact_name = $_POST['contact_name'];
		$contact_email = $_POST['contact_email'];
		$contact_text = $_POST['contact_text'];

		if(!empty($contact_name) && !empty($contact_email) && !empty($contact_text)){
			$to = $adminMail;
			$subject = "Contact form submitted.";
			$body = $contact_name."\n".$contact_text;
			$headers = "From: ".$contact_email;

			if(mail($to, $subject, $body, $headers)){
				$error = "Thanks";
			}
			else{
				$error = "Sorry, problem";
			}
		}
		else{
			$error = "All fields are required";
		}
		
	}
?>

<div class="fatalError">
	<p class="fatalErrorColor"><?php echo $error;?></p>
</div>
<form action="contact.php" method="POST">
	Name :</br> <input type="text" name="contact_name"></br></br>
	Email address:</br> <input type="text" name="contact_email"></br></br>
	Message: </br>
	<textarea name="contact_text" rows="6" cols="30"></textarea></br></br>
	<input type="submit" name="submit" value="Sent">
</form>

<?php
	@require_once("incl/footer.php");
?>