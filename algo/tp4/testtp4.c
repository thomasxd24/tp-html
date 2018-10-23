#include "tp4.h"



void testCoutLogement(void)
{
    char type,pension;
    int nbPers;
    float montLogement;
    if(sasirLogement(&type,&nbPers,&pension))
    {
        printf("Error de saisi, Terminaision du program");
        return;
    }  
    else
        montLogement = coutLogement(type,nbPers,pension);
    printf("cout: %.2f \n",montLogement);
}

void testActiviteSki(void)
{
    int nbPers, nbPack,nbSki;
    float montActiviteSki,reduc;
    if(sasirActiviteSki(&nbPers,&nbPack,&nbSki))
    {
        printf("Erreur de saisie, Terminaison du programme");
        return;
    }  
    else
        montActiviteSki = coutActiviteSki(nbPers,nbPack,nbSki, &reduc);
    printf("Cout sans reduc: %.2f \n",montActiviteSki);
    printf("Reduc: %.2f \n",reduc);
    printf("Cout reduc. comprise: %.2f \n",montActiviteSki-reduc);
}

int main(void)
{
    global();
    // testCoutLogement();
    // testActiviteSki();
    return 0;
}

