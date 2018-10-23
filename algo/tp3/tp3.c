#include "tp3.h"

//Thomas (Chun Hei) Tse | Mathis Picard

/*
	Titre: coutSalle
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
float coutSalle(char categ, char deco)
{
	float catA = 1500,catB = 1000,catC = 700,montantT;
	if(categ == 'A' || categ == 'a')
		montantT = catA;
	else if(categ == 'B' || categ == 'b')
	{
		montantT = catB;
	}
	else if(categ == 'C' || categ == 'c')
	{
		montantT = catC;
	}
	else
	{
		printf("Erreur de saisie\n");
		montantT = 0;
	}
	
	if(deco == 'O' || deco == 'o')
	montantT = montantT + montantT*(10.0/100);

	return montantT;
}




/*
	Titre: coutApero
	Finalité: calculer le montant nécessaire pour l'apéritif
	Description: 
				 Si on prend le buffet, on calcule le prix à l'aide de la formule en fonction du nombre de personne
				 Sinon on multiplie le nombre de personne par le prix à l'unité
				 On ajoute le forfait service
				 Afficher le prix à l'écran
	
	Variables: choix: character: choix de la formule
			   montant: float: prix final
			   nbP: int: nombre de personne
*/

float coutApero(char choix, int nbP)
{
	float montant;

	if (choix == 'B')
	{
		if (nbP <= 50)
			montant = 300 + 50;
		else if (nbP <= 100)
			montant = 500 + 50;
		else montant = 800 + 50;
	}

	else montant = 12 * nbP + 50;

	return montant;
}



/*
	Titre: global
	Finalité: faire un récapitulatif de tous les programmes précédant
	Description: Choisir si on prend un apéritif
				 Appeler les fonctions correspondantes
				 Afficher le prix à l'écran
	
	Variables: aperi: character: choix d'un apéritif
*/

void global(void)
{
	char choix,aperi,deco,categ;
	int nbP;
	float montantS,montantA,montantT;
	printf("Catégorie de salle(A/B/C): ");
	scanf("%c%*c", &categ);
	printf("Décoration(O/N): ");
	scanf("%c", &deco);
	montantS = coutSalle(categ,deco);
	printf("Voulez-vous un apéritif (O/N):");
	scanf("%*c%c",&aperi);
	if(aperi == 'O' || aperi == 'o')
	{
		printf("Unité ou buffet(U/B):");
		scanf("%c%*c", &choix);
		printf("Nombre de personnes pour apéritif:");
		scanf("%d", &nbP);
		montantA = coutApero(choix,nbP);
	}
	montantT=montantA+montantS;
	afficherResultat(montantA,montantS,montantT);


}

void afficherResultat(float montantA,float montantS,float montantT)
{
	printf("********************************************************\n");
	printf("			Resultats \n");
	printf("********************************************************\n");
	printf("\tLocation de Salle   	:\t%.2f \n",montantS );
	printf("\tApéritif		:\t%.2f \n",montantA );
	printf("\tTotal			:\t%.2f \n",montantT );
}