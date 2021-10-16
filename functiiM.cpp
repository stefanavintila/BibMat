#include "functiiM.h"
#include "citiri.h"
#include <winbgim.h>
#include <fstream>
#include <iostream>
std::ofstream g("dateiesireM.txt");
#define DELAY 100

void sumaDP(Matrice& a){
    int i=0,j=0,s=0, MARG=0;
    if(a.l==a.c){
        for(;i<a.l;i++)
            for(j=0;j<a.c;j++)
                if(i==j){
                    s=s+a.elem[i][j];
                    afisareGraficaDiagonale(a.elem[i][j],0,a.l,i,j,MARG,1); delay(50*8); MARG+=2;
                }
        }
        else
            readimagefile("imagini/13.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaDiagonale(s,0,a.l,i,j,MARG,1);
    g<<"Suma de pe diagonala principala este: "<<s<<'\n';
}

void SsubDP(Matrice& a){
    int i,j,s=0, MARG=0,nr=0;
    if(a.l==a.c){
        for(i=0;i<a.l;i++)
            for(j=0;j<a.c;j++)
                if(i>j){
                    if(nr==14)
                       MARG=0;
                    s=s+a.elem[i][j];
                    afisareGraficaDiagonale(a.elem[i][j],nr,a.l,i,j,MARG,2); delay(50*8); MARG+=2; nr++;
                }
        }
    if(nr==28)
        MARG=0;
    afisareGraficaDiagonale(s,nr,a.l,i,j,MARG,2);
    g<<"Suma de sub diagonala principala este: "<<s<<'\n';
}

void SdeasDP(Matrice& a){
    int i,j,s=0, MARG=0,nr=0;
    if(a.l==a.c){
        for(i=0;i<a.l;i++)
            for(j=0;j<a.c;j++)
                if(i<j){
                    if(nr==14)
                       MARG=0;
                    s=s+a.elem[i][j];
                    afisareGraficaDiagonale(a.elem[i][j],nr,a.l,i,j,MARG,3); delay(50*8); MARG+=2; nr++;
                }
        }
    if(nr==28)
        MARG=0;
    afisareGraficaDiagonale(s,nr,a.l,i,j,MARG,3);
    g<<"Suma elementelor aflate deasupra diagonalei principale este: "<<s<<'\n';
}

void sumaDS(Matrice& a){
    int i,j,s=0,MARG=0;
    if(a.l==a.c){
        for(i=0;i<a.l;i++)
            for(j=0;j<a.c;j++)
                if(i+j==a.l-1){
                    s=s+a.elem[i][j];
                    afisareGraficaDiagonale(a.elem[i][j],0,a.l,j,i,MARG,4); delay(50*8);  MARG+=2;
                }
        }
        else
            readimagefile("imagini/13.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaDiagonale(s,0,a.l,i,j,MARG,4);
    g<<"Suma elementelor de pe diagonala secundara este: "<<s<<'\n';
}

void SsubDS(Matrice& a){
    int i,j,s=0,MARG=0,nr=0;
    if(a.l==a.c){
        for(i=0;i<a.l;i++)
            for(j=0;j<a.c;j++)
                if(i+j>a.l-1){
                    if(nr==14)
                       MARG=0;
                    s=s+a.elem[i][j];
                    afisareGraficaDiagonale(a.elem[i][j],nr,a.l,i,j,MARG,5); delay(50*8);  MARG+=2; nr++;
                }
        }
        else
            readimagefile("imagini/13.jpg",0,0,getmaxx(),getmaxy());
    if(nr==28)
        MARG=0;
    afisareGraficaDiagonale(s,nr,a.l,i,j,MARG,5);
    g<<"Suma elementelor de sub diagonala secundara este: "<<s<<'\n';
}

void SdeasDS(Matrice& a){

    int i,j,s=0,MARG=0,nr=0;
    if(a.l==a.c){
        for(i=0;i<a.l;i++)
            for(j=0;j<a.c;j++)
                if(i+j<a.l-1){
                    if(nr==14)
                       MARG=0;
                    s=s+a.elem[i][j];
                    afisareGraficaDiagonale(a.elem[i][j],nr,a.l,i,j,MARG,6); delay(50*8);  MARG+=2; nr++;
                }
        }
    if(nr==28)
        MARG=0;
    afisareGraficaDiagonale(s,nr,a.l,i,j,MARG,6);
    g<<"Suma elementelor aflate deasupra diagonalei secundare este: "<<s<<'\n';
}

void sumaL(Matrice& a){
    int nr,i,j,s=0,MARG=0;
    char ns[MAX];
    setcolor(0);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(getmaxx()/2,50,"Suma elementelor de pe o anumita linie");
    citesteSir("Introduceti linia a caror elemente doriti sa le calculati, nr=",ns,getmaxx()/2,80,false);
    nr=atoi(ns); i=nr-1;
    if(i<a.l){
        for(j=0; j<a.c; j++){
            s=s+a.elem[i][j];
            afisareGraficaDiagonale(a.elem[i][j],0,a.l,i,j,MARG,7); delay(50*8);  MARG+=2;
        }
        afisareGraficaDiagonale(s,0,a.l,i,j,MARG,7); delay(50*8);
    }
    else
        readimagefile("imagini/14.jpg",0,0,getmaxx(),getmaxy());
    g<<"Suma elementelor de pe linia "<<nr<<" este: "<<s<<'\n';
}

void sumaC(Matrice& a){
    int c,i,j,s=0,MARG=0;
    char ns[MAX];
    setcolor(WHITE);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(getmaxx()/2,50,"Suma elementelor de pe o anumita coloana");
    citesteSir("Introduceti coloana a caror elemente doriti sa le calculati, nr=",ns,getmaxx()/2,80,false);
    c=atoi(ns); j=c-1;
    if(j<a.c){
        for(i=0; i<a.l; i++){
            s=s+a.elem[i][j];
            afisareGraficaDiagonale(a.elem[i][j],0,a.l,i,j,MARG,8); delay(50*8);  MARG+=2;
        }
        afisareGraficaDiagonale(s,0,a.l,i,j,MARG,8); delay(50*8);
    }
    else
        readimagefile("imagini/15.jpg",0,0,getmaxx(),getmaxy());
    g<<"Suma elementelor de pe coloana "<<c<<" este: "<<s<<'\n';
}



Matrice spirala(Matrice a){
    int i,j;
    a.l=a.c=7;
    int nr=1,aux=0;
    for(aux=0;aux<=std::min(a.l/2,a.c/2);aux++){
        i=1+aux;
        for(j=1+aux;j<=a.c-aux;j++){
            a.elem[i][j]=nr;
            printM(a.elem[i][j],i+5,j+6,BLACK);
            delay(DELAY);
            nr++;
        }
        j=a.c-aux;
        for(i=2+aux;i<=a.l-aux;i++){
            a.elem[i][j]=nr;
            printM(a.elem[i][j],i+5,j+6,BLACK);
            delay(DELAY);
            nr++;
        }
        i=a.l-aux;
        for(j=a.c-aux-1;j>=1+aux;j--){
            a.elem[i][j]=nr;
            printM(a.elem[i][j],i+5,j+6,BLACK);
            delay(DELAY);
            nr++;
        }
        j=1+aux;
        for(i=a.l-aux-1;i>=2+aux;i--){
            a.elem[i][j]=nr;
            printM(a.elem[i][j],i+5,j+6,BLACK);
            delay(DELAY);
            nr++;
        }
    }
    return a;
}

void cadrane(Matrice& a){
    int i,j;
    int MAN,MAS,MAE,MAV,MAD;
    for(i=1;i<=a.l;i++)
        for(j=1;j<=a.c;j++){
            //Zona Nordica
            if(i<j && i+j<a.l+1){
                MAN+=a.elem[i][j];
                printM(a.elem[i][j],i+5,j+6,BLUE);
                delay(DELAY);
            }
            //Zona sudica
            if(i>j && i+j>a.l+1){
                MAS+=a.elem[i][j];
                printM(a.elem[i][j],i+5,j+6,RED);
                delay(DELAY);
            }
            //Zona Vestica
            if(i>j && i+j<a.l+1){
                MAV+=a.elem[i][j];
                printM(a.elem[i][j],i+5,j+6,GREEN);
                delay(DELAY);
            }
            //Zona Estica
            if(i<j && i+j>a.l+1){
                MAE+=a.elem[i][j];
                printM(a.elem[i][j],i+5,j+6,YELLOW);
                delay(DELAY);
            }
            if(i==j || i+j==a.l+1)
                MAD+=a.elem[i][j];
        }
    MAN=MAN/9;
    MAS=MAS/9;
    MAE=MAE/9;
    MAV=MAV/9;
    MAD-=a.elem[4][4];
    MAD=MAD/13;
    printM(MAN,3,6,BLUE);
    delay(DELAY);
    printM(MAE,3,8,YELLOW);
    delay(DELAY);
    printM(MAS,3,10,RED);
    delay(DELAY);
    printM(MAD,3,12,BLACK);
    delay(DELAY);
    printM(MAV,3,14,GREEN);
    delay(DELAY);
}

bool verifPatratica(Matrice& a){
    if(a.l==a.c)
        return 1;
    else
        return 0;
}

bool verifNull(Matrice& a){
    for(int i=1;i<=a.l;i++)
        for(int j=1;j<=a.c;j++){
            if(a.elem[i][j]==0)
                return 1;
            else
                return 0;
        }
}



Matrice sumaMM(Matrice& a,Matrice& b){
    if(a.l==b.l && a.c==b.c){
        int i,j;
        Matrice s;
        s.l=a.l;
        s.c=a.c;
        for(int i=0;i<a.l;i++)
            for(int j=0;j<a.c;j++)
                s.elem[i][j]=a.elem[i][j]+b.elem[i][j];
        afisareMultipla(a,b,BLUE,GREEN);
        afisareGraficaCALCUL(s,a,b,'+',RED,12);
        g<<"Suma celor doua matrice este: "<<'\n';
        for(i=0;i<s.l;i++){
            for(j=0;j<s.c;j++){
                g<<s.elem[i][j]<<" ";}
            g<<'\n';
        }
        return s;
        }
        else
            readimagefile("imagini/12.jpg",0,0,getmaxx(),getmaxy());
}

Matrice diferentaMM(Matrice& a,Matrice& b){
    if(a.l==b.l && a.c==b.c){
        int i,j;
        Matrice d;
        d.l=a.l;
        d.c=a.c;
        for(int i=0;i<a.l;i++)
            for(int j=0;j<a.c;j++)
                d.elem[i][j]=a.elem[i][j]-b.elem[i][j];
        afisareMultipla(a,b,BLUE,GREEN);
        afisareGraficaCALCUL(d,a,b,'-',RED,12);
        g<<"Diferenta celor doua matrice este "<<'\n';
        for(i=0;i<d.l;i++){
            for(j=0;j<d.c;j++)
                g<<d.elem[i][j]<<" ";
            g<<'\n';
        }
        return d;
        }
        else
            readimagefile("imagini/16.jpg",0,0,getmaxx(),getmaxy());
}

Matrice produsMM(Matrice& a,Matrice& b){
    if(a.c==b.l){
        int i,j;
        Matrice p;
        p.l=a.l;
        p.c=b.c;
        for(int i=0;i<p.l;i++)
            for(int j=0;j<p.c;j++){
                p.elem[i][j]=0;
                for(int k=0;k<a.c;k++)
                    p.elem[i][j]+=a.elem[i][k]*b.elem[k][j];
        }
        afisareMultipla(a,b,BLUE,GREEN);
        afisareGraficaCALCUL(p,a,b,'*',WHITE,12);
        g<<"Produsul celor doua matrice este "<<'\n';
        for(i=0;i<a.l;i++){
            for(j=0;j<a.c;j++){
                g<<p.elem[i][j]<<" ";}
            g<<'\n';
        return p;
        }
    }
    else
        readimagefile("imagini/17.jpg",0,0,getmaxx(),getmaxy());
}
