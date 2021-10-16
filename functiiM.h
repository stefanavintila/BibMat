#pragma once
#define MAXM 8 //nr max de linii/coloane

//Structura matricei
typedef struct{
    int l,c;
    float elem[MAXM][MAXM];
}Matrice;

bool verifPatratica(Matrice& a); //Verifica daca matricea este patratica
bool verifNull(Matrice& a); //Verifica daca matricea este nula

void sumaDP(Matrice& a); //Suma de pe diagonala principala
void SsubDP(Matrice& a); //Suma de sub diagonala principala
void SdeasDP(Matrice& a); //Suma deasupra diagonalei principale
void sumaDS(Matrice& a); //Suma de pe diagonala secundara
void SsubDS(Matrice& a);//Suma de sub diagonala secundara
void SdeasDS(Matrice& a); //Suma deasupra diagonalei secundare
void sumaL(Matrice& a);
void sumaC(Matrice& a);

Matrice spirala(Matrice a); //Genereaza o matrice cu numere crescatoare in spirala
void cadrane(Matrice& a); //Colorare 4 cadrane in matrice

Matrice sumaMM(Matrice& a,Matrice& b);  //suma 2 matrici
Matrice diferentaMM(Matrice& a,Matrice& b); //diferenta 2 matrici
Matrice produsMM(Matrice& a,Matrice& b); //produs 2 matrici
