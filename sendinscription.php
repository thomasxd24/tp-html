<?php
if(!isset($_POST['submit']))
{
	echo 'Vous n\'etes pas censé etre ici!';
}
else
{
	if(empty($_POST['namevisitor']) || empty($_POST['email']) || empty($_POST['acti']) || empty($_POST['first']) || empty($_POST['horaire']))
	{
		echo 'Un des champs sont vide!';
	}
	else
	{
		echo 'C\'est tres bien';
	}
}