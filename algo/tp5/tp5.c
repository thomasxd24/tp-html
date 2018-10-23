#include "tp5.h"

void sasirEmployeNbreFormation(int *idEmp,int *nbForm)
{
    printf("Identité:");
    scanf("%d",idEmp);
    while(*idEmp >9999 || *idEmp < 1000)
    {
        printf("Il doit être de 4 chiffres, Re-saisir :");
        scanf("%d",idEmp);
    }

    printf("Nombre de formations:");
    scanf("%d",nbForm);
    while(*nbForm > 10 || *nbForm < 0 )
    {
        printf("Il doit être entre 0 et 10 compris, Re-saisir :");
        scanf("%d",nbForm);
    }
}
int saisieControleeIemeFormation(int i)
{
    int idForm,chiffre1,chiffre2;
        printf("Identifiant de la %dème formation:", i);
        scanf("%d",&idForm);
        chiffre1 = idForm/10;
        chiffre2 = idForm-(chiffre1*10);
        printf("%d\n",chiffre2 );
        printf("%d\n",chiffre1 );
        while(chiffre2>8 || chiffre2<1 || chiffre1>5 || chiffre1<1 || idForm >99  || idForm < 11)
        {
            printf("Identifiant de la %dème formation incorrect, Re-saisir :", i);
            scanf("%d",&idForm);
            chiffre1 = idForm/10;
            chiffre2 = idForm-(chiffre1*10);
            
        }
    return idForm;
}
// Activite ski
int enregistrementEmployes(void)
{

    int idEmp,nbForm,idForm,i=1,continuer=1;
    char choixcontinuer;
    FILE *fs;
    fs = fopen("donneesEmployes.txt","w");
    if(fs == NULL)
        exit(1);
    while(continuer)
    {
        sasirEmployeNbreFormation(&idEmp,&nbForm);
    fprintf(fs,"%d \t%d ",idEmp,nbForm );
    while(i<=nbForm)
    {
        idForm = saisieControleeIemeFormation(i);
        printf("%d\n",idForm );
        fprintf(fs,"\t\t%d ",idForm );
        i++;
    }
    fprintf(fs,"\n");
    printf("Voulez-vous resaisir un employé? :");
    scanf("%*c%c",&choixcontinuer);
    if(choixcontinuer == 'n')
    {
        continuer = 0;
        break;
    }
    i=1;
        
    }
    
    
    
}
int traitementFichiersEmployes(int form)
{
    int idEmp,nbForm,idForm,i=1,continuer=1,max=0,nbEmp=0,nbVide=0,bonEmp=0,nbTotal=0;
    float moy;
    FILE *fs;
    fs = fopen("donneesEmployes.txt","r");
    if(fs == NULL) 
        return -1;   
        while(1) 
        {
            bonEmp = 0;
            fscanf(fs,"%d",&idEmp );
        fscanf(fs,"%d",&nbForm);
        if(nbForm == 0)
            {
                nbVide = nbVide +1;
            }
        if(nbForm>max)
            max = nbForm;
        nbTotal=nbTotal+nbForm;
        while(i<=nbForm)
        {
            fscanf(fs,"%d",&idForm );
            if(feof(fs))
                break;
            if(idForm == form)
            {
                if (bonEmp != 1)
                {
                printf("employé n %d\n",idEmp );
                bonEmp = 1;
                }
                

                
            }

            i++;
        }
        if(feof(fs))
                break;
        nbEmp++;    

        
        i=1;
        
        }
        moy = nbTotal/nbEmp;
        printf("Nombre max de formations suivi par employé :%d\n",max);
        printf("Nombre max de formations suivi par employé :%d\n",nbVide);
        printf("Nombre max de formations suivi par employé :%.2f\n",moy);
    return 1;

}
// Coute de l'ensemble de vacances
void global(void)
{
    
}
