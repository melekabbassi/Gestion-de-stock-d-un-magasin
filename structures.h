#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Categorie{
    int idCat;
    char NomCat[20];
}Categorie;

typedef struct Type{
    int idType;
    char NomType[20];
    Categorie Cat;
}Type;

typedef struct MaDate{
    int JJ;
    int MM;
    int AA;
}MaDate;

typedef struct Produit{
    int id;
    char Nom[20];
    Type Typ;
    MaDate Date_expiration;
}Produit;

typedef struct Vente{
    Produit Pdt;
    MaDate DateVente;
}Vente;