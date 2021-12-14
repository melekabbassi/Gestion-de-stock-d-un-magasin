#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "fonction.h"

void main(){
    Categorie TabCat[20];
    Type TabType[50];
    Produit Stock[100][50];

    int TabQuantite[50];
    for(int z=0; z<50; z++){
        TabQuantite[z]=0;
    }

    int NbCat = 0;
    int NbTyp = 0;
    int idCat;
    int idType;
    int idTypeVente;
    int AA;
    int MM;

    char nomType[20];
    
    char choixMenuPricipal, choixMenuGestionStock, choixGestionCategorie, choixGestionType, choixGestionProduit, choixVenteStatistique, choixStatistique;

MenuPrincipal:
    for (int i=0; i<43;i++){
        printf("*");
    }
    printf("\n");
    printf("************      Bienvenue     ***********\n");
    for (int i=0; i<43;i++){
        printf("*");
    }
    printf("\n");
    printf("* Veuillez Choisir une option:            *\n");
    printf("*  1- Gestion du Stock                    *\n");
    printf("*  2- Vente et Statistique                *\n");
    printf("* >> Tapez votre Choix:                   * ");
    do{
        scanf("%c", &choixMenuPricipal);
    }while(choixMenuPricipal != '1' && choixMenuPricipal != '2' && choixMenuPricipal != '0');
    switch (choixMenuPricipal)
    {
    case '1':
        goto MenuGestionStock;
        break;
    case '2':
        goto MenuVenteStatistique;
        break;
    case '0':
        printf("____________     Au Revoire     ___________\n");
        exit(0);
        break;
    }
MenuGestionStock:
    printf("\n");
    printf("*  Menu Gestion du Stock                  *\n");
    printf("*  1- Gestion des Categories              *\n");
    printf("*  2- Gestion des Types                   *\n");
    printf("*  3- Gestion des Produits                *\n");
    printf("*  4- Affichage du Stock                  *\n");
    printf("*  5- Retour Menu Principal               *\n");
    printf("* >> Tapez votre Choix:                   * ");
    do
    {
        scanf("%c", &choixMenuGestionStock);
    } while (choixMenuGestionStock != '1' && choixMenuGestionStock != '2' && choixMenuGestionStock != '3' && choixMenuGestionStock != '4' && choixMenuGestionStock != '5' && choixMenuGestionStock != '0');
    switch (choixMenuGestionStock)
    {
    case '1':
        goto GestionCategories;
        break;
    case '2':
        goto GestionTypes;
        break;
    case '3':
        goto GestionProduits;
        break;
    case '4':
        AfficherStock(Stock, TabQuantite, NbTyp);
        break;
    case '5':
        goto MenuPrincipal;
        break;
    case '0':
        printf("____________     Au Revoire     ___________\n");
        exit(0);
        break;
    }
GestionCategories:
    printf("\n");
    printf("*  Menu Gestion du Stock/Gestion des Categories  *\n");
    printf("*  1- Ajout d'une nouvelle Categories            *\n");
    printf("*  2- Suppression d'une Categories               *\n");
    printf("*  3- Retour Menu Gestion du Stock               *\n");
    printf("*  4- Retour Menu Principal                      *\n");
    printf("* >> Tapez votre Choix:                          * ");
    do
    {
        scanf("%c", &choixGestionCategorie);
    } while (choixGestionCategorie != '1' && choixGestionCategorie != '2' && choixGestionCategorie != '3' && choixGestionCategorie != '4' && choixGestionCategorie != '0');
    switch (choixGestionCategorie)
    {
    case '1':
        AjouterCat(TabCat, &NbCat);
        break;
    case '2':
        printf("id Categorie: ");
        scanf("%d", &idCat);
        SupprimerCat(TabCat, &NbCat, idCat);
        break;
    case '3':
        goto MenuGestionStock;
        break;
    case '4':
        goto MenuPrincipal;
        break;
    case '0':
        printf("_____________       Au Revoire       _____________\n");
        exit(0);
        break;
    }
GestionTypes:
    printf("\n");
    printf("*  Menu Gestion du Stock/Gestion des Types       *\n");
    printf("*  1- Ajout d'un nouveau Type                    *\n");
    printf("*  2- Suppression d'un Type                      *\n");
    printf("*  3- Retour Menu Gestion du Stock               *\n");
    printf("*  4- Retour Menu Principal                      *\n");
    printf("* >> Tapez votre Choix:                          * ");
    do{
        scanf("%c", &choixGestionType);
    }while(choixGestionType != '1' && choixGestionType != '2' && choixGestionType != '3' && choixGestionType != '4' && choixGestionType != '0');
    switch (choixGestionType)
    {
    case '1':
        AjouterTyp(TabType, &NbTyp, TabCat, NbCat);
        break;
    case '2':
        printf("id Type: ");
        scanf("%d", &idType);
        SupprimerTyp(TabType, &NbTyp, idType);
        break;
    case '3':
        goto MenuGestionStock;
        break;
    case '4':
        goto MenuPrincipal;
        break;
    case '0':
        printf("_____________       Au Revoire       _____________\n");
        exit(0);
        break;
    }
GestionProduits:
    printf("\n");
    printf("*  Menu Gestion du Stock/Gestion des Produits    *\n");
    printf("*  1- Ajout d'un nouveau Produit                 *\n");
    printf("*  2- Suppression d'un Produit                   *\n");
    printf("*  3- Retour Menu Gestion du Stock               *\n");
    printf("*  4- Retour Menu Principal                      *\n");
    printf("* >> Tapez votre Choix:                          * ");
    do{
        scanf("%c", &choixGestionProduit);
    }while(choixGestionProduit != '1' && choixGestionProduit != '2' && choixGestionProduit != '3' && choixGestionProduit != '4' && choixGestionProduit != '0');
    switch (choixGestionProduit)
    {
    case '1':
        AjouterPdt(Stock, TabQuantite, TabType);
        break;
    case '2':
        printf("id Produit: ");
        Produit Pdt;
        scanf("%d", &Pdt.id);
        SupprimerPdt(Stock, TabQuantite, Pdt, NbTyp);
        break;
    case '3':
        goto MenuGestionStock;
        break;
    case '4':
        goto MenuPrincipal;
        break;
    case '0':
        printf("_____________       Au Revoire       _____________\n");
        exit(0);
        break;
    }
    goto MenuPrincipal;
MenuVenteStatistique:
    printf("\n");
    printf("* Menu Vente et Statistique               *\n");
    printf("*  1- Vente de Produits                   *\n");
    printf("*  2- Statistiques                        *\n");
    printf("*  3- Retour Menu Principal               *\n");
    printf("* >> Tapez votre Choix:                   * ");
    do
    {
        scanf("%c", &choixVenteStatistique);
    } while (choixVenteStatistique != '1' && choixVenteStatistique != '2' && choixVenteStatistique != '3' && choixVenteStatistique != '0');
    switch (choixVenteStatistique)
    {
    case '1':
        printf("Nom Type: ");
        scanf("%s", nomType);
        printf("id Type: ");
        scanf("%d", &idTypeVente);
        VendrePdt(Stock, TabQuantite, TabType, NbTyp, idTypeVente, nomType);
        break;
    case '2':
        goto Statistique;
        break;
    case '3':
        goto MenuPrincipal;
        break;
    case '0':
        printf("____________     Au Revoire     ___________\n");
        exit(0);
        break;
    }
Statistique:
    printf("\n");
    printf("*  Menu Vente et Statistique/Statistique  *\n");
    printf("*  1- Statistiques par mois               *\n");
    printf("*  2- Statistiques par annee              *\n");
    printf("*  3- Retour Menu Vente et Statistique    *\n");
    printf("*  4- Retour Menu Principal               *\n");
    printf("* >> Tapez votre Choix:                   * ");
    do{
        scanf("%c", &choixStatistique);
    }while(choixStatistique != '1' && choixStatistique != '2' && choixStatistique != '3' && choixStatistique != '4' && choixStatistique != '0');
    switch(choixStatistique)
    {
    case '1':
        printf("AA: ");
        scanf("%d", &AA);
        printf("MM: ");
        scanf("%d", &MM);
        StatMois(AA, MM, TabCat, NbCat);
        break;
    case '2':
        printf("AA: ");
        scanf("%d", &AA);
        StatAnnee(AA, TabCat, NbCat);
        break;
    case '3':
        goto MenuVenteStatistique;
        break;
    case '4':
        goto MenuPrincipal;
        break;
    case '0':
        printf("____________     Au Revoire     ___________\n");
        exit(0);
        break;
    }
    goto MenuPrincipal;
}