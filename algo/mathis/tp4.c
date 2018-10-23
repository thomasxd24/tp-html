#include "tp4.h"

int saisirLogement (char *type, int *nbPers, char *pension)
{
	printf ("Type de logement (A/B):\n");
	scanf ("%c%*c", type);
	printf ("Nombre de personnes:\n");
	scanf ("%d", nbPers);
	if (*type == 'B')
	{
		printf("Pension (D/C):\n");
		scanf ("%c", pension);
	}
	else if (*nbPers>6)
	{
		printf("Nb de personne non cohérent\n");
		return 1;
	}

	return 0;

}

float coutLogement(char type, int nbPers, char pension)
{
	float coutLogement;
	int nbChambre;
	
	if (nbPers%3 == 0)
		 nbChambre = nbPers/3;
	else
		nbChambre = (nbPers / 3)+1;
	if (type == 'A')
	{
		coutLogement = 800;
		if ( nbPers > 4)
			coutLogement = 800 + (nbPers - 4) * (0.1*800);
	}
	else 
		if ( pension == 'D')
			coutLogement = 230 * nbChambre + 120 * nbPers;
		else
			coutLogement = 210 * nbChambre + 210 * nbPers; 
	return coutLogement;
}

