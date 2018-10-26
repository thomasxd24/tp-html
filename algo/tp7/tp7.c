#include "tp7.h"
#include <stdlib.h>

int chargeFichier(int tMat[], int tCoef[], int tMax)
{
    FILE *fs;
    int mat, coef, i = 0;
    fs = fopen("matiere.don", "r");
    if (fs == NULL)
    {
        printf("Erreur\n");
        exit(1);
    }
    fscanf(fs, "%d%d%*c", &mat, &coef);
    while (!feof(fs))
    {

        if (i == tMax)
        {
            printf("Erreur, Tableau Plein\n");
            exit(-1);
        }
        tMat[i] = mat;
        tCoef[i] = coef;
        i++;
        fscanf(fs, "%d%d%*c", &mat, &coef);
    }
    fclose(fs);
    return i;
}

int afficherMenu(void)
{
    int choix;
    system("clear");
    printf("\n\n\n\n\n\t\tGestion des matières\n");
    printf("1\t Affichage\n");
    printf("2\t Modification du coefficient d'une matière\n");
    printf("3\t Création d'une matière\n");
    printf("4\t Suppression d'une matière\n");
    printf("5\t Moyenne des notes dans chaque matiére\n");
    printf("6\t Moyennes d'un étudiant\n");
    printf("9\t Quitter\n\n");
    printf("\t\t\tOption choisie  : ");
    scanf("%d%*c", &choix);
    return choix;
}

void afficher(int tMat[], int tCoef[], int nbMat)
{
    printf("N° matière\tcoefficient\n");
    for (int i = 0; i < nbMat; ++i)
    {
        printf("%d\t\t%d\n", tMat[i], tCoef[i]);
    }
}

void modifCoef(int tMat[], int tCoef[], int nbMat)
{
    int pos, trouve, nvmat, nvcoef;

    printf("Saisie de la matière\n");
    scanf("%d%*c", &nvmat);

    pos = recherchePos(tMat, nbMat, nvmat, &trouve);

    if (!trouve)
    {
        printf("Matiere non trouvé dans le tableau\n");
        exit(1);
    }
    else
    {
        printf("Saisie du nouveau coefficient\n");
        scanf("%d%*c", &nvcoef);
        tMat[pos] = nvmat;
        tCoef[pos] = nvcoef;
    }
}

int creaMat(int tMat[], int tCoef[], int nbMat)
{
    int pos, trouve, nvmat, nvcoef;

    printf("Saisie de la nouvelle matière et du coefficient\n");
    scanf("%d%d%*c", &nvmat, &nvcoef);

    pos = recherchePos(tMat, nbMat, nvmat, &trouve);

    if (trouve)
    {
        printf("Matiere déja dans le tableau\n");
        exit(1);
    }
    for (int i = nbMat + 1; i > pos; i--)
    {
        tMat[i] = tMat[i - 1];
        tCoef[i] = tCoef[i - 1];
    }
    tMat[pos] = nvmat;
    tCoef[pos] = nvcoef;
    return nbMat + 1;
}

int supprMat(int tMat[], int tCoef[], int nbMat)
{
    int pos, trouve, nvmat, nvcoef;

    printf("Saisie de la matière à supprimer\n");
    scanf("%d%*c", &nvmat);

    pos = recherchePos(tMat, nbMat, nvmat, &trouve);

    if (!trouve)
    {
        printf("Matiere non trouvée dans le tableau\n");
        exit(1);
    }
    for (int i = pos; i < nbMat; i++)
    {
        tMat[i] = tMat[i + 1];
        tCoef[i] = tCoef[i + 1];
    }

    return nbMat - 1;
}

int recherchePos(int tInt[], int tSize, int nbRecherche, int *trouve)
{
    int point;
    for (int i = 0; i < tSize; ++i)
    {
        if (nbRecherche < tInt[i])
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

void sauvegarder(int tMat[], int tCoef[], int nb)
{
    FILE *fs;
    int mat, coef;
    fs = fopen("matiere.don", "w");
    if (fs == NULL)
    {
        printf("Erreur\n");
        exit(1);
    }
    for (int i = 0; i < nb; ++i)
    {
        mat = tMat[i];
        coef = tCoef[i];
        fprintf(fs, "%d\t%d\n", mat, coef);
    }

    fclose(fs);
}

void calculMoyMat(int tMat[], int nbNote[], float cumulNote[], int nbMat)
{
    float moyMat;
    printf("N. matière\tMoyene\n");
    for (int i = 0; i < nbMat; i++)
    {

        if (nbNote[i] == 0)
        {
            moyMat = 0;
        }

        else
        {
            moyMat = cumulNote[i] / nbNote[i];
        }

        printf("%d\t%.2f\n", tMat[i], moyMat);
    }
}

int moyenneMat(int tMat[], int nbMat)
{
    int nbNote[100] = {0}, etud, mat, pos, trouve = 0, i = 0;
    float note, cumulNote[100] = {0};
    FILE *flot;
    flot = fopen("note.don", "r");
    if (flot == NULL)
    {
        printf("Erreur");
        return -1;
    }
    fscanf(flot, "%d%d%f%*c", &etud, &mat, &note);
    while (!feof(flot))
    {
        if (i >= 100)
        {
            printf("Depassement de taille physique de tableau, Abandon");
            return -1;
        }
        pos = recherchePos(tMat, nbMat, mat, &trouve);
        if (!trouve)
        {
            printf("Matiere non trouvéé");
        }
        else
        {
            cumulNote[pos] = cumulNote[pos] + note;
            nbNote[pos] = nbNote[pos] + 1;
        }

        i++;
        fscanf(flot, "%d%d%f%*c", &etud, &mat, &note);
    }
    fclose(flot);
    calculMoyMat(tMat, nbNote, cumulNote, nbMat);
}

void moyenneEtu(int tMat[], int nbMat, int tCoef[])
{
    int nbNote[100] = {0}, etud, mat, etudv, i = 0, trouve = 0, pos,etudExist=0,nbMoyTot=0;
    float note, cumulNote[100] = {0}, moyenneEtu,cumulNoteTot=0,moyGen;
    printf("\nSaisir numéro étudiant : ");
    scanf("%d%*c", &etudv);
    FILE *flot;
    flot = fopen("note.don", "r");
    if (flot == NULL)
    {
        printf("Erreur");
        return;
    }
    fscanf(flot, "%d%d%f%*c", &etud, &mat, &note);
    while (!feof(flot))
    {
        if (i >= 100)
        {
            printf("Depassement de taille physique de tableau, Abandon");
            return ;
        }
        pos = recherchePos(tMat, nbMat, mat, &trouve);
        if (!trouve)
        {
            printf("Matière non trouvée");
            return ;
        }
        if (etud == etudv)
        {
            etudExist=1;
            nbNote[pos] = nbNote[pos] + 1;
            cumulNote[pos] = cumulNote[pos]+note;
        }


        i++;
        fscanf(flot, "%d%d%f%*c", &etud, &mat, &note);
    }
    
    if (!etudExist) {
        printf("N° d'étudiant inconnu\n");
    }
    
    printf("\nN°matière\tMoyenne\n\n");
 
    for (int j = 0; j < nbMat; j++)
    {

        if (nbNote[j] == 0)
        {
            printf("%d\t\tpas de note\n",tMat[j]);
            continue;
        }
        nbMoyTot=nbMoyTot+tCoef[j];
        moyenneEtu = cumulNote[j] / nbNote[j];
        cumulNoteTot = cumulNoteTot + (moyenneEtu*tCoef[j]);
        printf("%d\t\t%.2f\n", tMat[j], moyenneEtu);
    }
    moyGen=cumulNoteTot/nbMoyTot;
    printf("\nMoyenne Générale:\t%.2f\n",moyGen);


    fclose(flot);
}

void global(void)
{
    int choix, tMat[100], tCoef[100], nb;
    nb = chargeFichier(tMat, tCoef, 100);
    char c;
    choix = afficherMenu();
    while (choix != 9)
    {
        switch (choix)
        {
        case 1:
            afficher(tMat, tCoef, nb);
            break;
        case 2:
            modifCoef(tMat, tCoef, nb);
            break;
        case 3:
            nb = creaMat(tMat, tCoef, nb);
            printf("%d\n", nb);
            break;
        case 4:
            nb = supprMat(tMat, tCoef, nb);
            printf("%d\n", nb);
            break;
        case 5:
            moyenneMat(tMat, nb);
            break;
        case 6:
            moyenneEtu(tMat, nb,tCoef);
            break;
        }
        printf("Appuyer sur la touche entrée pour continuer...");
        c=getchar();
        choix = afficherMenu();
    }
    sauvegarder(tMat, tCoef, nb);
}
