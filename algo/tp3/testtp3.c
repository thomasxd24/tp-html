#include "tp3.h"


void testcoutSalle(void) {
	
	char deco,categ;
	float montantT;
	printf("Catégorie de salle: ");
	scanf("%c%*c", &categ);
	printf("Décoration: ");
	scanf("%c", &deco);
	montantT = coutSalle(categ,deco);
	printf("Catégorie:%c	Décoration:%c	Coût:%.2f",categ,deco,montantT);
}

void testcoutApero(void){
	char choix;
	float montant;
	int nbP;
	montant = coutApero(choix,nbP);

	printf("Montant pour apéritif:%.2f \n",montant );
}

void testafficherResultat(void){
	afficherResultat(20,50,70);
}



int main(void)
{
	// testcoutApero();
	global();
	// testcoutSalle();
	// testafficherResultat();
	return 0;	
}

