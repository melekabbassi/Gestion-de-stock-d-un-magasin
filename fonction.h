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
            printf("Categorie inexistante \n");
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

/************   Debut Fonction qui Vérifie l'existance d'un type   **********/
int ExistanceType(Type TabType[50], int idType, char nomType[20]){
    int exist = -1;
    for (int i = 0; i < 50; i++){
        if (TabType[i].idType == idType && !strcmp(TabType[i].NomType, nomType)){
            return i;
        }        
    }
    return exist;
}
/************   Fin Fonction qui Vérifie l'existance d'un type   **********/

void AjouterPdt(Produit Stock[100][50], int TabQuantite[50], Type TabType[50]){
    Produit Pdt;
    InitPdt(&Pdt);
    int p = ExistanceType(TabType, Pdt.Typ.idType, Pdt.Typ.NomType);
    if(p < 0){
        printf("Type inexistant \n");
    }else{
        int n = TabQuantite[p];
        if(n < 100){
            Stock[n][p] = Pdt;
            TabQuantite[p] = n +1;
            printf("Produit ajoutee \n");
        }else{
            printf("Espace insuffisant \n");
        }
    }
}

void SupprimerPdt(Produit Stock[100][50], int TabQuantite[50], Produit Pdt, int NbType){
    if(NbType == 0){
        printf("Pas de Produit \n");
    }else{
        int exist = 0;
        int position;
        for(int i = 0; i < NbType; i++){
            if(Stock[TabQuantite[i]][i].id == Pdt.id){
                exist = 1;
            }else{
                for(int j = 0; j < TabQuantite[i]; j++){
                    if(Stock[j][i].id == Pdt.id){
                        exist = 1;
                        position = i;
                        for (int k = j; k < TabQuantite[i]; k++){
                            Stock[k][i] = Stock[k+1][i];                            
                        }
                    }
                }
                if (exist != 0){
                    break;
                }
            }
        }
        if(exist == 0){
            printf("Produit inexistant \n");
        }else{
            TabQuantite[position] = TabQuantite[position]-1;
        }
    }
}

// Vente d'un Produit

/************   Debut Fonction qui Compare deux dates   **********/
int ComparerDate(MaDate D1, MaDate D2){
    if(D1.AA > D2.AA && D1.MM > D2.MM && D1.JJ > D2.JJ){
        return 1;
    }
    if(D1.AA < D2.AA && D1.MM < D2.MM && D1.JJ < D2.JJ){
        return 0;
    }
    // Cas de la même date
    return 1;
}
/************   Fin Fonction qui Compare deux dates   **********/

void VendrePdt(Produit Stock[100][50], int TabQuantite[50], Type TabType[50], int NbTyp, int idTyp, char nomType[20]){
    int position = ExistanceType(TabType, idTyp, nomType);
    if(position < 0){
        printf("Produit Inexistant \n");
    }else{
        if(TabQuantite[position] < 0){
            printf("Rupture de Stock \n");
        }else{
            Produit Pdt= Stock[0][position];
            for(int i = 1; i < TabQuantite[position]; i++){
                int CmprDate = ComparerDate(Pdt.Date_expiration, Stock[i][position].Date_expiration);
                if(CmprDate == 1){
                    Pdt = Stock[i][position];
                }
            }
            SupprimerPdt(Stock, TabQuantite, Pdt, NbTyp);
            printf("Produit a ete vendu: %s, %d \n", Pdt.Nom, Pdt.Date_expiration.AA);

            time_t T= time(NULL);
            struct tm tmp = *localtime(&T);
            MaDate Date;
            Date.JJ = tmp.tm_mday;
            Date.MM = tmp.tm_mon + 1;     /* Month.   [0-11]  */ 
            Date.AA = tmp.tm_year + 1900; /* Year - 1900.     */

            Vente V;
            V.Pdt = Pdt;
            V.DateVente = Date;

        FILE *fptr = fopen("Traces.txt", "w");
        fprintf(fptr,"%d %s %d %s %d %s  %d/%d/%d", V.Pdt.id, V.Pdt.Nom, V.Pdt.Typ.idType, V.Pdt.Typ.NomType, V.Pdt.Typ.Cat.idCat, V.Pdt.Typ.Cat.NomCat, V.DateVente.JJ, V.DateVente.MM, V.DateVente.AA);
        fclose(fptr);
        }
    }
}

// Statistique Mois

void StatMois(int AA, int MM, Categorie TabCat[20], int NbCat){
    FILE *fptr = fopen("Traces.txt", "r");
    Produit Pdt;
    int NumMois = -1;
    int NumAnnee = -1;
    while(!feof(fptr)){
        fscanf(fptr,"%d %s %d %s %d %s  %d/%d/%d", &Pdt.id, Pdt.Nom, &Pdt.Typ.idType, Pdt.Typ.NomType, &Pdt.Typ.Cat.idCat, Pdt.Typ.Cat.NomCat, &Pdt.Date_expiration.JJ, &Pdt.Date_expiration.MM, &Pdt.Date_expiration.AA);
        if(Pdt.Date_expiration.MM == MM){
            if(Pdt.Date_expiration.AA == AA){
                NumAnnee++;
            }
            NumMois++;
        }
    }
    fclose(fptr);
    printf("Nombre de vente en %d/%d: %d\n", MM, AA, NumAnnee);
    printf("Nombre de vente totale du mois %d: %d\n", MM, NumMois);
    for(int i = 0; i < NbCat; i++){
        printf("Categorie: %s", TabCat[i].NomCat);
        int nbVenteCat = -1;
        fptr = fopen("Traces.txt","r");
        while(!feof(fptr)){
            fscanf(fptr,"%d %s %d %s %d %s  %d/%d/%d", &Pdt.id, Pdt.Nom, &Pdt.Typ.idType, Pdt.Typ.NomType, &Pdt.Typ.Cat.idCat, Pdt.Typ.Cat.NomCat, &Pdt.Date_expiration.JJ, &Pdt.Date_expiration.MM, &Pdt.Date_expiration.AA);
            if(Pdt.Typ.Cat.idCat == TabCat[i].idCat){
                nbVenteCat++;
            }
        }
        fclose(fptr);
        printf("Nombre de vente de Categorie: %d\n", nbVenteCat);
    }
}

void StatAnnee(int AA, Categorie TabCat[20], int NbCat){
    FILE *fptr = fopen("Traces.txt", "r");
    Produit Pdt;
    int NbVente = -1;
    int NumAnnee = -1;
    while(!feof){
        fscanf(fptr,"%d %s %d %s %d %s  %d/%d/%d", &Pdt.id, Pdt.Nom, &Pdt.Typ.idType, Pdt.Typ.NomType, &Pdt.Typ.Cat.idCat, Pdt.Typ.Cat.NomCat, &Pdt.Date_expiration.JJ, &Pdt.Date_expiration.MM, &Pdt.Date_expiration.AA);
        if(Pdt.Date_expiration.AA == AA){
            NumAnnee++;
        }
        NbVente++;
    }
    fclose(fptr);
    printf("Nombre de vente totale: %d\n", NbVente);
    printf("Nombre de vente totale de l'annee %d: %d\n", AA, NumAnnee);
    for(int i = 0; i < NbCat; i++){
        printf("Categorie: %s", TabCat[i].NomCat);
        int nbVenteCat = -1;
        fptr = fopen("Traces.txt", "r");
        while(!feof(fptr)){
            fscanf(fptr,"%d %s %d %s %d %s  %d/%d/%d", &Pdt.id, Pdt.Nom, &Pdt.Typ.idType, Pdt.Typ.NomType, &Pdt.Typ.Cat.idCat, Pdt.Typ.Cat.NomCat, &Pdt.Date_expiration.JJ, &Pdt.Date_expiration.MM, &Pdt.Date_expiration.AA);
            if(Pdt.Typ.Cat.idCat == TabCat[i].idCat){
                nbVenteCat++;
            }
        }
        fclose(fptr);
        printf("Nombre de ventre de categorie: %d\n", nbVenteCat);
    }
}