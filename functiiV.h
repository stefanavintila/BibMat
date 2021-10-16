#pragma once
#define MAXV 20 //nr max elemente vector

//Structura vector
typedef struct{
    int n;
    int elem[MAXV];
}Vector;

void SelemV(Vector& v); //suma elementelor
void PelemV(Vector& v); //produsul elementelor
void Pscalar(Vector& v); //inmultire cu scalara

void BubbleSortD(Vector &v);
void BubbleSortC(Vector &v);
void BSDgrafic(Vector &v);
void BSCgrafic(Vector &v);
void shiftD(Vector& v, int j, int dist); //shiftare vector la dreapta - algoritm
void shiftS(Vector& v, int j, int dist); //shiftare vector la stanga - algoritm
void shiftDgrf(Vector &v, int j); //shiftare grafica la dreapta
void shiftSgrf(Vector &v, int j); //shiftare grafica la stanga

void afisareV(Vector& v, int j); //afisare elementelor pe rand in timpul shiftarilor
void afisareVB(Vector& v,int i,int j); //afisarea elementelor pe rand in timpul sortarii
void afisareVC(Vector& v, int i, int j);
