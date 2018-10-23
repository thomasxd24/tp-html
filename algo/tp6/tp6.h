#include <stdio.h>
#include<math.h>
#include <stdlib.h>

int chargeFichier(int tMat[], int tCoef[], int tMax);
int afficherMenu(void);
int recherchePos(int tInt[], int tSize, int nbRecherche , int *trouve);
int creaMat(int tMat[], int tCoef[], int nbMat);
void afficher(int tMat[], int tCoef[], int nbMat);	
void global(void);