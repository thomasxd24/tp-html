#include "tp6.h"

int chargeFichier(int tMat[], int tCoef[], int tMax)
{
    FILE *fs;
    int mat,coef,i=0;
    fs=fopen("matiere.don","r");
    if (fs == NULL)
    {
        printf("Erreur\n");
        exit(1);
    }
    fscanf(fs,"%d%d",&mat,&coef);
    while(!feof(fs))
    {
        
        if(i >= tMax)
        {
            printf("Erreur, Tableau Plein\n");
            exit(-1);
        }
        tMat[i] = mat;
        tCoef[i] = coef;
        i++;
        fscanf(fs,"%d%d",&mat,&coef);
    }
    fclose(fs);
    return i;
}

int afficherMenu(void)
{
    int choix;
    printf("Gestion des matières\n");
    printf("1\t Affichage\n");
    printf("2\t Modification du coefficient d'une matière\n");
    printf("3\t Création d'une matière\n");
    printf("4\t Suppression d'une matière\n");
    printf("9\t Quitter\n");
    scanf("%d",&choix);
    return choix;
}

void afficher(int tMat[], int tCoef[], int nbMat)
{
    printf("N° matière\tcoefficient\n");
    for (int i = 0; i < nbMat; ++i)
    {
       printf("%d\t\t%d\n",tMat[i],tCoef[i]); 
    }
}

void modifCoef(int tMat[], int tCoef[], int nbMat)
{
    int pos, trouve, nvmat, nvcoef;

    printf("Saisie de la matière\n");
    scanf("%d", &nvmat);

    pos=recherchePos(tMat,nbMat, nvmat, &trouve);

    if(!trouve)
    {
        printf("Matiere non trouvé dans le tableau\n");
        exit(1);
    }
    else
    {
        printf("Saisie du nouveau coefficient\n");
        scanf("%d",&nvcoef);
        tMat[pos] = nvmat;
        tCoef[pos] = nvcoef;
    }

    
}

int creaMat(int tMat[], int tCoef[], int nbMat)
{
    int pos, trouve, nvmat, nvcoef;

    printf("Saisie de la nouvelle matière et du coefficient\n");
    scanf("%d%d", &nvmat, &nvcoef);

    pos=recherchePos(tMat,nbMat, nvmat, &trouve);

    if(trouve)
    {
        printf("Matiere déja dans le tableau\n");
        exit(1);
    }
    for (int i = nbMat+1; i > pos; i--)
    {
        tMat[i] = tMat[i-1];
        tCoef[i] = tCoef[i-1];
    }
    tMat[pos] = nvmat;
    tCoef[pos] = nvcoef;
    return nbMat+1;
}

int supprMat(int tMat[], int tCoef[], int nbMat)
{
    int pos, trouve, nvmat, nvcoef;

    printf("Saisie de la matière à supprimer\n");
    scanf("%d", &nvmat);

    pos=recherchePos(tMat,nbMat, nvmat, &trouve);

    if(!trouve)
    {
        printf("Matiere non trouvée dans le tableau\n");
        exit(1);
    }
    for (int i = pos; i < nbMat; i++)
    {
        tMat[i] = tMat[i+1];
        tCoef[i] = tCoef[i+1];
    }

    return nbMat-1;
}

int recherchePos(int tInt[], int tSize, int nbRecherche , int *trouve)
{
    int point;
    for (int i = 0; i < tSize; ++i)
    {
        if(nbRecherche < tInt[i] )
        {
            *trouve = 0;
            return i;           
        }
        else if (nbRecherche == tInt[i])
        {
            *trouve = 1;
            return i;
        }
    }
    *trouve = 0;
    return tSize;
}


void sauvegarder(int tMat[],int tCoef[],int nb)
{
    FILE *fs;
    int mat,coef;   
    fs=fopen("matiere.don","w");
    if (fs == NULL)
    {
        printf("Erreur\n");
        exit(1);
    }
    for (int i = 0; i < nb; ++i)
    {
        mat = tMat[i];
        coef = tCoef[i];
        fprintf(fs,"%d\t%d\n",mat,coef);
    }

    fclose(fs);
}

void global(void)
{
    int choix, tMat[100], tCoef[100], nb;
    nb=chargeFichier(tMat,tCoef,100);
    choix = afficherMenu();
    while (choix != 9)
    {
        switch(choix)
        {
            case 1: afficher(tMat,tCoef,nb); break;
            case 2: modifCoef(tMat,tCoef,nb); break;
            case 3: nb = creaMat(tMat,tCoef,nb); printf("%d\n",nb ); break;
            case 4: nb = supprMat(tMat,tCoef,nb); printf("%d\n",nb ) ; break;
        }
        choix= afficherMenu();
    }
    sauvegarder(tMat,tCoef,nb);
}
