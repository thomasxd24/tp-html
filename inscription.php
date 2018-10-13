<?php
include('partials/header.php');
?>

<div class="content">
	<img width='100%' src="banner.png">
	<form action="sendinscription.php" method="POST">
		<p>
			<label>Votre Nom</label>
			<input type="text" name="namevisitor">
		</p>
		<p>
			<label>Email</label>
			<input type="text" name="email">
		</p>
		<p>
			<label>Numéro de téléphone</label>
			<input type="text" name="tel">
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
			<textarea type="text" name="message">
			</textarea>
		</p>
		<p>
			<button type="submit" name="submit" class="lien" >Envoyer l'inscription</button>
		</p>
	</form>
</div>
<?php
include('partials/footer.php');
?>
