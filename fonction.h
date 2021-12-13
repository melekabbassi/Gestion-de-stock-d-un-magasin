#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Initialisation Catégorie
void InitCat(Categorie* Cat){
    printf("idCat: ");
    scanf("%d", &Cat->idCat);

    printf("NomCat: ");
    scanf("%s", Cat->NomCat);

    printf("\n");
}

// Initialisation Type
void InitType(Type* Typ){
    printf("idType: ");
    scanf("%d", &Typ->idType);

    printf("NomType: ");
    scanf("%s", Typ->NomType);

    InitCat(&Typ->Cat);
    printf("\n");
}

// Initialisation Date
void InitDate(MaDate* Date){
    do
    {
        printf("JJ: ");
        scanf("%d", &Date->JJ);
    }while (Date->JJ < 0 || Date->JJ > 31);

    do
    {
        printf("MM: ");
        scanf("%d", &Date->MM);
    }while (Date->MM < 0 || Date->MM > 12);
    
    do
    {
        printf("AA: ");
        scanf("%d", &Date->AA);
    } while (Date->AA < 1000 || Date->AA > 9999);
    printf("\n");
}

// Initialisation Produit
void InitPdt(Produit* Pdt){
    printf("idPdt: ");
    scanf("%d", &Pdt->id);

    printf("NomPdt: ");
    scanf("%s", Pdt->Nom);

    InitType(&Pdt->Typ);
    InitDate(&Pdt->Date_expiration);
}

// Affichage du Stock
void AfficherStock(Produit Stock[100][50], int TabQuantite[50], int Nbtype){
    for (int i = 0; i < 43; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("* Etat du stock:                          *\n");
    printf("*                                         *\n");
    printf("* Categorie Type   Qte id-Pdt  date_exp   *\n");
    printf("* --------------------------------------- *\n");
    for(int j=0; j < Nbtype; j++){
        for (int k=0; k < TabQuantite[j]; k++){
            printf("* %s         %s    %d   %d     %d/%d/%d *\n", Stock[k][j].Typ.Cat.NomCat, Stock[k][j].Typ.NomType, TabQuantite[j], Stock[k][j].id, Stock[k][j].Date_expiration.JJ, Stock[k][j].Date_expiration.MM, Stock[k][j].Date_expiration.AA );
        }
    }
    printf("* --------------------------------------- *\n");
}

// Ajouter et Supprimer une Catégorie
void AjouterCat(Categorie TabCat[20], int* NbCat){
    int p = *NbCat;
    Categorie Cat;
    InitCat(&Cat);
    int i = 0;
    int exist = 0;
    while(i < p){
        if(Cat.idCat == TabCat[i].idCat || !strcmp(Cat.NomCat, TabCat[i].NomCat)){
            exist = 1;
            printf("La Categorie existe\n");
            break;
        }else{
            i++;
        }
    }
    if(!exist){
        TabCat[p] = Cat;
        p++;
        *NbCat = exist;
    }
}

void SupprimerCat(Categorie TabCat[20], int *NbCat, int idCat){
    int pNbCat = *NbCat;
    if(pNbCat == 0){
        printf("Pas de Categorie \n");
    }else{
        int exist = 0;

        if(TabCat[pNbCat].idCat == idCat){
            exist = 1;
        }else{
            for(int i=0; i < pNbCat; i++){
                if(TabCat[i].idCat == idCat){
                    exist = 1;
                    for(int j = i; j < pNbCat; j++){
                        TabCat[j] = TabCat[j+1];
                    }
                    break;
                }
            }
        }
        if(exist != 0){
            pNbCat--;
            *NbCat = pNbCat;
            printf("La Categorie %d est supprimee \n", idCat);
        }else{
            print("Categorie inexistante \n");
        }
    }
}

// Ajouter et Supprimer un Type

void AjouterTyp(Type TabType[50], int *NbType, Categorie TabCat[20],int NbCat){
    Type Typ;
    InitType(&Typ);
    int p = *NbType;
    int i = 0;
    int exist = 0;

    while(i < NbCat){
        if(Typ.Cat.idCat == TabCat[i].idCat && !strcmp(Typ.Cat.NomCat, TabCat[i].NomCat)){
            exist = 1;
            printf("La Categorie existe\n");
            break;
        }else{
            i++;
        }
    }
    if(p < 50 && exist){
        TabType[p] = Typ;
        p++;
        *NbType = p;
    }else{
        printf("La Categorie n'existe pas OU vous avez plus que 50 type \n");
    }
}

void SupprimerTyp(Type TabType[50], int *NbType, int idType){
    int pNbType = *NbType;
    if(pNbType == 0){
        printf("Pas de Types\n");
    }else{
        int exist = 0;
        if(TabType[pNbType].idType == idType){
            exist = 1;
        }else{
            for(int i = 0; i < pNbType; i++){
                exist = 1;
                for(int j = i; j < pNbType-2; j++){
                    TabType[j] = TabType[j+1];
                }
                break;
            }
        }
        if(exist != 0){
            pNbType--;
            *NbType = pNbType;
            printf("Le Type %d est supprimee \n", idType);
        }else{
            printf("Type inexistant \n");
        }
    }
}

// Ajouter et Supprimer un Produit