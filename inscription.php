<?php
include('partials/header.php');
?>
<header class="headphoto">

</header>
<div class="content">
	<h1>Inscription</h1>
	<?php
	include('sendinscription.php');
	if(isset($error))
	{
		?>
	<div class="alert">
	<strong><?php echo $error; ?></strong>

	</div>
		<?php
	}
	if($showForm)
	{
		?>
<form action="inscription.php" method="POST">
		<p>
			<label>Votre Nom</label>
			<input type="text" name="namevisitor" value="<?php echo $_POST['namevisitor'] ?>" >
		</p>
		<p>
			<label>Email</label>
			<input type="email" name="email" value="<?php echo $_POST['email'] ?>">
		</p>
		<p>
			<label>Numéro de téléphone</label>
			<input type="tel" name="tel" class="" value="<?php echo $_POST['tel'] ?>">
		</p>

		<p>
			<label>Activité</label><br>
			<select name="acti">
				<option value="qui">Quidditch</option>
				<option value="quicom">Quidditch Compétition</option>
			</select>
		</p>
		<p>
			<label>Créneau horaire</label><br>
			<select name="horaire">
				<option disabled="true">-Débutant-</option>
				<option value="de#mon#1819">Lundi 18h-19h</option>
				<option value="de#mar#1819">Mardi 18h-19h</option>
				<option value="de#mer#1819">Mercedi 18h-19h</option>
				<option disabled="true">-Intermédaire-</option>
				<option value="int#jeu#1819">Jeudi 18h-19h</option>
				<option value="int#ven#1819">Vendredi 18h-19h</option>
				<option value="int#sam#1819">Samedi 18h-19h</option>
				<option disabled="true">-Avancé-</option>
				<option value="avan#mon#1921">Lundi 19h-21h</option>
				<option value="avan#mar#1921">Mardi 19h-21h</option>
				<option value="avan#mer#1921">Mercedi 19h-21h</option>
			</select>
		</p>
		<p>
			<div>Premiere demande</div>
			<label>Oui</label>
			<input type="radio" name="first" value="true">
			<label>Non</label>
			<input type="radio" name="first" value="false">
		</p>
		<p>
			<label>Votre message</label>
			<textarea type="text" name="message"></textarea>
		</p>
		<p>
			<button type="submit" name="submit" class="lien" >Envoyer l'inscription</button>
		</p>
	</form>
		<?php
	}
	?>
	
</div>
<?php
if(isset($error))
	{
		?>
	<script>
	var x = document.getElementsByName("<?php echo $errorName; ?>");
	x[0].classList.add("error");
	</script>
		<?php
	}
include('partials/footer.php');
?>
