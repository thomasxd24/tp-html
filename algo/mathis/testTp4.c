#include "tp4.h"

// fonctions tests
void testCoutLogement(void)
{
	char type,pension;
	int nbPers,retour;
	float cout;

	retour = saisirLogement(&type,&nbPers,&pension);
	if (retour == 0)
	{
		cout = coutLogement(type,nbPers,pension);
		printf("Le cout est de : %.2f \n",cout);
	}

}
// fonction main()
int main(void) 
{

	testCoutLogement();
	return 0;
}