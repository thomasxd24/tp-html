#include "tp4.h"

int sasirLogement(char *type,int *nbPers, char *pension)
{
    printf("Type de Logement:");
    scanf("%c",type);
    printf("Nombre de personnes:");
    scanf("%d",nbPers);
    if(*type == 'B')
    {
       printf("Pension:");
        scanf("%*c%c",pension); 
    }
    else
         if(*nbPers > 6)
            {
                printf("Problem: Nombre de personnes non coherent. Location refusee.");
                return 1;
            }
    
   
    return 0;
}
float coutLogement(char type,int nbPers, char pension)
{
    float coutLogement;
    int nbc;
    if(type == 'A')
    {
        if(nbPers <= 4)
        {
            coutLogement = 800;
        }
        else
        {
            coutLogement = 800+(800*(10.0/100))*(nbPers-4);
        }
            
    }
    else
    {
        if(pension == 'D')
        {
            nbc =nbPers/3;
	    if(nbPers%3 != 0)
		      nbc = nbc + 1;	
            coutLogement = nbc*230 + 120 * nbPers;
        }
            
        else
        {
		nbc =nbPers/3;
	    	if(nbPers%3 != 0)
			nbc = nbc + 1;	
           	coutLogement = nbc*230 + 210 * nbPers;
        }
            
    }
    return coutLogement;
}
// Activite ski
int sasirActiviteSki(int *nbPers,int *nbPack,int *nbSki)
{

    printf("Nombre de personnes:");
    scanf("%d",nbPers);
    printf("Nombre de packs:");
    scanf("%d",nbPack);
    printf("Nombre de Ski:");
    scanf("%d",nbSki);
    if(*nbPack + *nbSki > *nbPers)
    {
       printf("Problem: Nombre de personnes non coherent. Location refusee.");
       return 1;
    }

    
   
    return 0;
}
float coutActiviteSki(int nbPers, int nbPack, int nbSki, float *reduc)
{
    int reste,nbReducPack,nbReduc;

    float montant;

    if(nbPack+nbSki >= 4)
    {
        nbReduc = nbPack + nbSki - 3;

        if(nbReduc > nbSki)
        {
            *reduc = nbSki*80*(50.0/100);
            nbReducPack = nbReduc -nbSki;
        }
        else
        {
            *reduc = nbReduc*80*(50.0/100);
             nbReducPack = 0;
        }
            
        *reduc = *reduc + nbReducPack *120*(50.0/100);
        
        
    }
    else
        *reduc = 0;

    montant = nbPack*120 + nbSki*80 + 150*nbPers;
    return montant;

}
// Coute de l'ensemble de vacances
void global(void)
{
    char type,pension,ski;
    int nbPersSki,nbPersLogement, nbPack,nbSki;
    float montLogement,montActiviteSki,reduc;
    printf("Activite de Ski:");
    scanf("%c%*c", &ski);

    if(sasirLogement(&type,&nbPersLogement,&pension))
    {
        printf("Error de saisi, Terminaision du program");
        return;
    }  
    else
        montLogement = coutLogement(type,nbPersLogement,pension);
    
    if(ski == 'N')
    {
        printf("cout: %.2f \n",montLogement);
        return;
    }


    if(sasirActiviteSki(&nbPersSki,&nbPack,&nbSki))
    {
        printf("Erreur de saisie, Terminaison du programme");
        return;
    }  
    else
        montActiviteSki = coutActiviteSki(nbPersSki,nbPack,nbSki, &reduc);
    printf("Cout Logement: %.2f \n",montLogement);
    printf("Cout Activite Ski: %.2f \n",montActiviteSki);
    printf("Reduction de ski: %.2f \n",montActiviteSki-reduc);
    printf("Total: %.2f \n",montActiviteSki-reduc+montLogement);

}
