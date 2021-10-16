#include "functiiV.h"
#include "citiri.h"
#include <graphics.h>
#include <fstream>
#define DELAY 50
std::ofstream h("dateiesireV.txt");
int y =100;

void afisareVC(Vector &v, int i, int j){
    char ns[MAXV]; y=y+35;
    for(int k=0; k<v.n; k++){
        itoa(v.elem[k],ns,10);
        settextstyle(10,HORIZ_DIR,1);
        evidentiaza(v.elem[k],k,1,GREEN);
        rectangle(400+80*k,y+5,400+80*(k+1),40+y);
        if(k==i || k==i+1){setcolor(RED); outtextxy(410-numarcifre(v.elem[k])+75*k+47, y+28,ns); delay(DELAY);}
        outtextxy(410-numarcifre(v.elem[k])+75*k+47, y+28,ns); delay(DELAY);
    }
}

//suma elementelor vectorului
void SelemV(Vector& v){
    int s=0;
    int margine=300;
    char ns[MAXV];
    settextstyle(10,HORIZ_DIR,2);
    outtextxy(690,50,"Suma elementelor vectorului este:");
    afisareGraficaV(v,WHITE,1);
    for(int i=0; i<v.n; i++){
        s=s+v.elem[i];
        itoa(v.elem[i],ns,10);
        settextstyle(10,HORIZ_DIR,1);
        evidentiaza(v.elem[i],i,1,LIGHTGREEN);
        outtextxy(margine,100,ns);
        margine+=10+7*numarcifre(v.elem[i]);
        delay(DELAY);
        if(i!=v.n-1 && i<v.n){
            outtextxy(margine,100,"+");
            margine+=15+15*numarcifre(v.elem[i+1])/3;
            delay(DELAY);
        }
        if(i==v.n-1){
            outtextxy(margine,100,"=");
            delay(DELAY);
            itoa(s,ns,10);
            settextstyle(10,HORIZ_DIR,2);
            setcolor(CYAN);
            outtextxy(margine+50,100,ns);
        }
    }
    h<<"Suma elementelor vectorului este: "<<s<<'\n';
}

//produsul elementelor din fisier
void PelemV(Vector& v){
    int p=1;
    int margine=300;
    char ns[MAXV];
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(690,50,"Produsul elementelor vectorului este:");
    afisareGraficaV(v,WHITE,1);
    for(int i=0; i<v.n; i++){
        p=p*v.elem[i];
        itoa(v.elem[i],ns,10);
        settextstyle(10,HORIZ_DIR,1);
        evidentiaza(v.elem[i],i,1,LIGHTGREEN);
        outtextxy(margine,100,ns);
        margine+=10+7*numarcifre(v.elem[i]);
        delay(DELAY);
        if(i!=v.n-1 && i<v.n){
            outtextxy(margine,100,"*");
            margine+=15+15*numarcifre(v.elem[i+1])/3;
            delay(DELAY);
        }
        if(i==v.n-1){
            outtextxy(margine,100,"=");
            delay(DELAY);
            itoa(p,ns,10);
            settextstyle(10,HORIZ_DIR,2);
            setcolor(CYAN);
            outtextxy(margine+50,100,ns);
        }
    }
    h<<"Produsul elementelor vectorului este: "<<p<<'\n';
}

//inmultire cu scalara
void Pscalar(Vector& v){
    char ns[MAXV];
    int nr;
    afisareGraficaV(v,BLACK,1);
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(680,50,"Inmultire cu scalar:");
    citesteSir("Introduceti scalarul cu care vreti sa inmultiti vectorul, nr=",ns,680,80,false);
    nr=atoi(ns);
    print(nr,10,12,RED);
    for(int i=0;i<v.n;i++){
        setcolor(BLUE);
        delay(DELAY);
        line(90+120,30*i+95,690,395);
        delay(DELAY);
        line(760,395,1190,30*i+95);
        delay(DELAY);
        settextstyle(10,HORIZ_DIR,1);
        print(v.elem[i]*nr,i,22,BLUE);
        settextstyle(10,HORIZ_DIR,4);
        v.elem[i]*=nr;
    }
    h<<"Vectorul dupa inmultirea cu scalarul a devenit: "<<'\n';
    for(int i=0;i<v.n;i++)
        h<<v.elem[i]<<" ";
    h<<'\n';
}

//Bubble Sort crescator - grafic
void BSCgrafic(Vector &v){
    char ns[MAXV];
    afisareGraficaV(v,BLUE,6);
    settextstyle(10,HORIZ_DIR,1);
    setcolor(BLACK);
    outtextxy(getmaxx()/2,50,"Sortare crescatoare prin metoda bulelor:");
    BubbleSortC(v);
}

//Bubble sort descrescator - grafic
void BSDgrafic(Vector &v){
    char ns[MAXV];
    int nr;
    afisareGraficaV(v,BLUE,6);
    settextstyle(10,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(getmaxx()/2,50,"Sortare descrescatoare prin metoda bulelor:");
    BubbleSortD(v);
}

//afisarea elementelor pe rand in timpul sortarii
void afisareVB(Vector& v, int i, int j){
    char ns[MAXV];
    for(int k=0; k<v.n; k++){
        itoa(v.elem[k],ns,10);
        settextstyle(10,HORIZ_DIR,1);
        evidentiaza(v.elem[k],k,1,LIGHTBLUE);
        print(v.elem[k],k,j,BLUE);
        if(k==i || k==i+1) print(v.elem[k],k,j,RED);
    }
    delay(DELAY);
    for(int k=0; k<v.n; k++){
        delay(DELAY);
        print(888888,k,j, LIGHTGRAY);
    }
}

//sortare Bubble Sort - crescator
void BubbleSortC(Vector &v){
    int aux, sortat,j=8;
    do{
        sortat=1;
        for(int i=0; i<v.n-1; i++){
            if(v.elem[i]>v.elem[i+1]){evidentiaza(v.elem[i],i,1,RED); evidentiaza(v.elem[i+1],i+1,1,RED); delay(50);
                aux=v.elem[i];
                v.elem[i]=v.elem[i+1];
                v.elem[i+1]=aux;
                sortat=0;
                afisareVB(v,i,j);
            }
        }
    }while(!sortat);
    h<<"Vectorul ordonat crescator este: "<<'\n';
    for(int i=0;i<v.n;i++)
        h<<v.elem[i]<<" ";
    h<<'\n';
}

//sortare Bubble Sort - descrescator
void BubbleSortD(Vector &v){
    int aux, sortat, j=8;
    do{
        sortat=1;
        for(int i=0; i<v.n-1; i++){
            if(v.elem[i]<v.elem[i+1]){evidentiaza(v.elem[i],i,1,RED); evidentiaza(v.elem[i+1],i+1,1,RED); delay(50);
                aux=v.elem[i];
                v.elem[i]=v.elem[i+1];
                v.elem[i+1]=aux;
                sortat=0;
                afisareVB(v,i,j);
            }
        }
    }while(!sortat);
    h<<"Vectorul ordonat descrescator este: "<<'\n';
    for(int i=0;i<v.n;i++)
        h<<v.elem[i]<<" ";
    h<<'\n';
}

//shiftare grafica stg
void shiftSgrf(Vector &v, int j){
    char ns[MAXV];
    int nr,i, dist=100;
    for(i=0; i<v.n; i++){
        print(v.elem[i],i+1,6,BLUE);
    }
    setcolor(BLACK);
    settextstyle(10,HORIZ_DIR,2);
    outtextxy(680,50,"Shiftare la stanga:");
    citesteSir("Introduceti numarul de shiftari, nr=",ns,680,80,false);
    nr=atoi(ns);
    if(nr<=10){
    setlinestyle(0,0,2);
    setcolor(RED); line(490,j*15,460,160);
    setcolor(GREEN); line(487,100+30*i,460,(j+1)*15);
    setlinestyle(0,0,1);
    for(int i=0; i<nr; i++){
        shiftS(v,j,dist); j+=2;
        if(i<nr-2)
            dist=dist+100;
    }
    h<<"Vectorul dupa "<<nr<<" shiftari la stanga,a devenit: "<<'\n';
    for(int i=0;i<v.n;i++)
        h<<v.elem[i]<<" ";
    h<<'\n';
    }else
    readimagefile("imagini/19.jpg",0,0,getmaxx(),getmaxy());
}

//shiftare grafica dreapta
void shiftDgrf(Vector &v, int j){
    char ns[MAXV];
    int nr,i,dist=100;
    for(i=0; i<v.n; i++){
        print(v.elem[i],i+1,6,BLUE);
    }
    setcolor(BLACK);
    settextstyle(10,HORIZ_DIR,2);
    outtextxy(680,50,"Shiftare la dreapta:");
    citesteSir("Introduceti numarul de shiftari, nr=",ns,680,80,false);
    nr=atoi(ns);
    if(nr<=10){
    i--;
    setcolor(BLUE); line(490,j*15,460,125+30*i);
    for(int i=0; i<nr; i++){
        shiftD(v,j,dist); j+=2;
        if(i<nr-2)
            dist=dist+100;
    }
    h<<"Vectorul dupa "<<nr<<" shiftari la dreapta,a devenit: "<<'\n';
    for(int i=0;i<v.n;i++)
        h<<v.elem[i]<<" ";
    h<<'\n';
    }else
    readimagefile("imagini/19.jpg",0,0,getmaxx(),getmaxy());
}

//shiftare la dreapta
void shiftD(Vector& v, int j, int dist){
    int i,l,aux;
    i=v.n-2;
    aux=v.elem[v.n-1];
    for(;i>=0;i--)
        {v.elem[i+1]=v.elem[i];}
    v.elem[0]=aux;
    afisareV(v,j);
    line(490+dist,115,460+dist,125+30*(v.n-1));
}

//shiftare la stanga
void shiftS(Vector& v, int j, int dist){
    int i, aux,nr;
    aux=v.elem[0];
    setlinestyle(0,0,2);
    for(i=1;i<v.n;i++)
        v.elem[i-1]=v.elem[i];
    v.elem[v.n-1]=aux;
    afisareV(v,j);
    setlinestyle(0,0,2);
    setcolor(RED); line(490+dist,8*15,460+dist,160);
    setcolor(GREEN); line(487+dist,100+30*i,460+dist,8*15);
    setlinestyle(0,0,1);
}

//afisare elementelor pe rand in timpul shiftarilor
void afisareV(Vector& v, int j){
    char ns[MAXV];
    for(int k=0; k<v.n; k++){
        itoa(v.elem[k],ns,10);
        settextstyle(10,HORIZ_DIR,1);
        evidentiaza(v.elem[k],k,1,LIGHTBLUE);
        print(v.elem[k],k+1,j,BLUE);
    }
}
