<?php
if(!isset($_POST['submit']))
{
$showForm = true;
}
else {
	$champs = array("Votre Nom"=>"namevisitor", "Votre Email"=>"email", "Activité"=>"acti","Premiere Demande"=>'first',"Horaire voulu"=>'horaire');
	foreach ($champs as $key => $value) {
		if(empty($_POST[$value]))
		{
			$missingchamp = $key;
			$errorName = $value;
			break;
		}
	}
	if(isset($missingchamp))
	{
		$error = "Désolé, vous n'avez pas rensigné le case {$missingchamp}";
		$showForm = true;
	}
	elseif (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
		$error = "Désolé, votre Email n'est pas valid";
		$errorName = "email";
		$showForm = true;
	}
	else {
		$hrString = "";
		$hrArray = explode("#", $_POST["horaire"]);
		$diff = array("de"=>"Débutant", "int"=>"Intermédaire", "avan"=>"Avancé");
		$jours = array("mon"=>"Lundi", "mar"=>"Mardi", "mer"=>"Mercedi","jeu"=>'Jeudi',"ven"=>'Vendredi',"sam"=>'Samedi');
		$hours = array("1819" => "18h-19h" , "1921" => "19h-21h");

		$hrString = "Difficulté: {$diff[$hrArray[0]]}";
		$hrString = "{$hrString}<br>Jour: {$jours[$hrArray[1]]}";
		$hrString = "{$hrString}<br>Horaire: {$hours[$hrArray[2]]}";

		$acti = array("qui" => "Quidditch" , "quicom" => "Quidditch Compétition");
		$actiString = $acti[$_POST['acti']];
		?>

		<h2>Recapitulatif de votre inscription</h2>
		<h4>Votre demande a été envoyé avec succes, voici la récapitulatif:</h6>
		<div>
			<span><strong>Votre Nom: </strong><br><?php echo $_POST["namevisitor"] ?></span>
		</div>
		<div>
			<span><strong>Votre Email:</strong> <br><?php echo $_POST["email"] ?></span>
		</div>
		<div>
			<span><strong>Activité Choisi: </strong><br><?php echo $actiString?></span>
		</div>
		<div>
			<span><strong>Numéro de téléphone:</strong> <br><?php echo $_POST["tel"] ?></span>
		</div>
		<div>
			<span><strong>Premiere Demande?:</strong> <br><?php echo $_POST["first"] ?></span>
		</div>
		<div>
			<span><strong>Horaire voulu: </strong><br><?php echo $hrString ?></span>
		</div>
		<div>
			<span><strong>Votre message: </strong><br><?php echo $_POST["message"] ?></span>
		</div>
		<br>
		<a class="lien" href="inscription.php">Revenir sur le formulaire</a>

		<?php
	}
}
