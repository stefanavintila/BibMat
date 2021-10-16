#pragma once
#include "functiiV.h"
#include "functiiM.h"
#define MAX 100

void citesteSir(char text[MAX], char s[MAX], int x, int y, bool stergere);

int numarcifre(int element);

Vector citireGraficaV();
Vector citireVFis();

Matrice citireGraficaM1();
Matrice citireGraficaM2();
Matrice citireMFis1();
Matrice citireMFis2();

void afisareGraficaV(Vector& v,int culoare,int coloana);
void afisareGraficaM(Matrice& a,int culoare,int coloana);
void afisareGraficaDiagonale(int element,int nr, int n, int linia, int coloana, int MARG,int caz);
void afisareGraficaCALCUL(Matrice& x,Matrice& a, Matrice& b,char operatie,int culoare,int coloana);
void afisareMultipla(Matrice& a, Matrice& b, int culoarea, int culoareb);

void print(int element, int poz, int coloana, int culoare);
void printM(int element, int poz, int coloana, int culoare);

void evidentiaza(int element, int poz, int coloana, int culoare); //colorare casuta element
void evidentiazaM(int element, int poz, int coloana, int culoare,int CULOAREINIT);
