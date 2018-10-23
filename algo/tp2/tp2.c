#include "tp2.h"

//Thomas (Chun Hei) Tse | Mathis Picard

/*
	Titre: locSalle
	Finalité: calculer le montant nécessaire à la location de la salle.
	Description: Choisir la catégorie de la salle.
				 Choisir si l'on prend une décoration.
				 Si on prend la décoration augmenter le prix de 10%.
				 Afficher le prix à l'écran.
	
	Variables: catA: float: prix de catégorie de salle
			   catB: float: prix de catégorie de salle
			   catC: float: prix de catégorie de salle
			   decor: character: choix de décor
			   cat: character: choix de catégorie

*/


void locSalle(void) {
	float catA = 1500,catB = 1000,catC = 700,montantT;
	char decor,cat;
	printf("Catégorie de salle: ");
	scanf("%c%*c", &cat);
	printf("Décoration: ");
	scanf("%c", &decor);
	if(cat == 'A' || cat == 'a')
		montantT = catA;
	else if(cat == 'B' || cat == 'b')
	{
		montantT = catB;
	}
	else if(cat == 'C' || cat == 'c')
	{
		montantT = catC;
	}
	else
		printf("Erreur de saisie\n");

	if(decor == 'O' || decor == 'o')
		montantT = montantT + montantT*(10.0/100);
	printf("Montant location: %.2f \n", montantT);
}


/*
	Titre: apero
	Finalité: calculer le montant nécessaire pour l'apéritif
	Description: Saisir le nombre de personne
				 Saisir le choix de formule
				 Si on prend le buffet, on calcule le prix à l'aide de la formule en fonction du nombre de personne
				 Sinon on multiplie le nombre de personne par le prix à l'unité
				 On ajoute le forfait service
				 Afficher le prix à l'écran
	
	Variables: choix: character: choix de la formule
			   montant: float: prix final
			   nbP: int: nombre de personne
*/

void apero(void){
	char choix;
	float montant;
	int nbP;

	printf("Nombre de personnes pour apéritif:\n");
	scanf("%d%*c", &nbP);
	printf("Unité ou buffet(U / B):\n");
	scanf("%c", &choix);

	if (choix == 'B')
	{
		if (nbP <= 50)
			montant = 300 + 50;
		else if (nbP <= 100)
			montant = 500 + 50;
		else montant = 800 + 50;
	}

	else montant = 12 * nbP + 50;

	printf("Montant pour apéritif:%.2f \n",montant );

}



/*
	Titre: banquet
	Finalité: calculer le montant nécessaire pour le banquet
	Description: Saisir le nombre de personne
				 Saisir le choix de menu
				 Si on prend des menus identiques, on doit suivre le tarif par tranche: 10 premières personnes 30€ par pers, 20 suivantes
28€ par pers etc...
				 Sinon on multiplie le prix du menu à l'unité par le nombre de personnes
				 Afficher le prix à l'écran
	
	Variables: choix: character: choix menus identiques ou différents
			   montant: float: prix final
			   nbP: int: nombre de personnes
*/

void banquet(void) {
	char choix;
	float montant;
	int nbP;

	printf("Nombre de personnes pour banquet:\n");
	scanf("%d%*c", &nbP);
	printf("Menu (I/D):\n");
	scanf("%c", &choix);

	if (choix == 'I')
	{
		if(nbP <= 10)
			montant = nbP*30;
		else
		{
			if(nbP <= 30)
				montant = 30*10 + 28*(nbP-10);
			else
			{
				if(nbP <= 80)
					montant = 30*10 + 20*28 + 27*(nbP-30);
				else
					montant = 30*10 + 20*28 + 50*27 + 26*(nbP-80);
			}
		}
	}

	else montant = 31 * nbP;

	printf("Montant pour banquet:%.2f \n",montant );
}



/*
	Titre: global
	Finalité: faire un récapitulatif de tous les programmes précédant
	Description: Choisir si on prend un apéritif ou un banquet
				 Appeler les fonctions correspondantes
				 Afficher le prix à l'écran
	
	Variables: aperi: character: choix d'un apéritif
			   banq: character: choix d'un banquet
*/

void global(void){
	
	char aperi,banq;
	printf("Voulez-vous un apéritif (O/N):\n");
	scanf("%c%*c",&aperi);
	printf("Voulez-vous un banquet (O/N):\n");
	scanf("%c%*c",&banq);



	locSalle();
	if(aperi == 'O')
	apero();
	if(banq == 'O')
	banquet();

}

/*
	Essai: global
	1. Location:1500  Apéritif: 350  Banquet: 1130
	2. Location:1500  Apéritif:650  Banquet: 270
	3. Location:1100  Apéritif:350  Banquet:300
	4. Location:700  Apéritif:550  Banquet:941
	5. Location:700  Apéritif:850  Banquet:1023
	6. Location:700  Apéritif:  Banquet: 2236
	7. Location:700  Apéritif:  Banquet:
*/