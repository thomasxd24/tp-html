#include "tp1.h"

//Thomas (Chun Hei) Tse | Mathis Picard

/*
	Titre: afficheBonjour1
	Finalité: Afficher bonjour avec l'année
	Description: saisir l'année au clavier
		     afficher le mot "bonjour" suivi de l'année
	
	Variables: annee: entier: correspond à l'année
*/

void afficheBonjour1(void) {
	int annee;
	printf("Annee:");
	scanf("%d",&annee);
	printf("Bonjour %d \n",annee);

}


void afficheBonjour(void) {
	printf("Bonjour\n");

}

/*
	Titre: prixMarchandise
	Finalité: Déduire à partir d'un prix et d'un taux de réduction le prix final
	Description: saisir le prix du produit et le pourcentage de réduction
		     afficher le prix réduit
	
	Variables: prix: float: prix initial du produit
		   pourcent: float: pourcentage de réduction
		   prixReduc: float: prix après la réduction
*/


void prixMarchandise(void) {
	float prix,pourcent,prixReduc;
	printf("prix:");
	scanf("%f",&prix);
	printf("\n Pourcentage de reduction");
	scanf("%f",&pourcent);	
	prixReduc = prix-(prix*(pourcent / 100));
	printf("\n Prix apres reduc: %.2f \n",prixReduc);

}

/*
	Titre: viennoiseries
	Finalité: Déduire à partir du nombre de viennoiseries demandées par le client le prix à payer et d'éventuelles promotions
	Description: saisir le nombre de viennoiseries demandées
		     calculer le nombre de pack de 5 et de 12 viennoiseries
		     calculer à partir de ça le prix à payer et le nombre de viennoiseries rendues
		     afficher le résultat
	
	Variables: prixPayer: float: prix à payer
		   nb5: entier: nombre de pack de 5
		   nb12: entier: nombre de pack de 12
		   nbInit: entier: nombre de viennoiseries demandées par le client
		   nbFin: entier: nombre de viennoiseries rendues
		   nbGratuit: entier: nombre de viennoiseries gratuites
		   nbReste: entier: nombre de viennoiseries restantes en enlevant les packs de 5

*/

void viennoiseries(void) {
	// initalisation
	float prixPayer;
	int nb5,nbInit, nbFin,nbGratuit,nbReste;

	printf("Nombre de viennoiseries demandees par le client");
	scanf("%d",&nbInit);
	


	nbGratuit = nbInit/12;
	nb5 = nbInit/5;
	nbReste = nbInit-nb5*5;
	prixPayer = nb5*2+nbReste*0.5;
	nbFin = nbInit + nbGratuit;
	

	printf("Prix %.2f \n", prixPayer);
	printf("Vien %d \n", nbFin);
}



void caraceteres(void) {
	char carac;
	printf("sasir un unique caractere 'carac' en minusules: \n");
	carac = getchar();
	printf("le caractere 'carac' est :%c\n",carac);
	printf("la valeur ASCII de 'carac' est %d\n", carac);
}


/*
	Titre: caraceteresMaj
	Finalité: Trouver la majuscule d'une lettre à partir de sa minuscule 
	Description: saisir une minuscule
		     déduire la valeur correspondante
		     soustraire 32
		     en déduire la valeur de la majuscule
		     afficher la majuscule
	
	Variables: carac: character: lettre minuscule
		   caracMaj: character: lettre majuscule

*/

void caraceteresMaj(void) {
	char carac;
	char caracMaj;
	printf("sasir un unique caractere 'carac' en minusules: \n");
	carac = getchar();
	printf("le caractere 'carac' est :%c\n",carac);
	printf("la valeur ASCII de 'carac' est %d\n", carac);
	caracMaj = carac-32;
	printf("le caractere majuscule de 'carac' est :%c et le ASCII de ce caractere est: %d \n",caracMaj,caracMaj);
	
}
