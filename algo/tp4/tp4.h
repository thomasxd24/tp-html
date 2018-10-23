#include <stdio.h>
#include<math.h>

// Location du logement
int sasirLogement(char *type,int *nbPers, char *pension);
float coutLogement(char type,int nbPers, char pension);
// Activite ski
int sasirActiviteSki(int *nbPers,int *nbPack,int *nbSki);
float coutActiviteSki(int nbPers, int nbPack, int nbSki, float *reduc);
// Coute de l'ensemble de vacances
void global(void);