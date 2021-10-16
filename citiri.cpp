#include "citiri.h"
#include <winbgim.h>
#include <fstream>
#define MAX 100
#define DELAY 50

int numarcifre(int element){
    int n=0;
    while(element){
        n+=1;
        element/=10;
    }
    return n;
}

void citesteSir(char text[MAX], char s[MAX], int x, int y, bool stergere){
    strcpy(s,"");
    char s1[MAX];
    char t[2];
    char tasta;
    char text2[MAX];
    t[0]=tasta; t[1]='\0';
    strcat(s,t);
    strcpy(s1,s); strcat(s1,"_");
    setcolor(BLACK);
    strcpy(text2,text);
    strcat(text2,s1);
    outtextxy(x,y,text2);
    do {
        tasta=getch();
                if (tasta==8) // backspace
        {
            if (strlen(s)>0)
                {
                    setcolor(LIGHTGRAY);
                    strcpy(s1,s); strcat(s1,"_");
                    strcpy(text2,text);
                    strcat(text2,s1);
                    outtextxy(x,y,text2);
                    s[strlen(s)-1]='\0';
                    strcpy(s1,s); strcat(s1,"_");
                    strcpy(text2,text);
                    strcat(text2,s1);
                    outtextxy(x,y,text2);
                    setcolor(BLACK);
                    strcpy(text2,text);
                    strcat(text2,s1);
                    outtextxy(x,y,text2);
                }
            }
        else
        {
            t[0]=tasta; t[1]='\0';
            strcat(s,t);
            strcpy(s1,s); strcat(s1,"_");
            setcolor(BLACK);
            strcpy(text2,text);
            strcat(text2,s1);
            outtextxy(x,y,text2);
        }
    } while (tasta!=13);
    t[0]=tasta; t[1]='\0';
    strcat(s,t);
    strcpy(s1,s); strcat(s1,"_");
    strcpy(text2,text);
    strcat(text2,s1);
    setcolor(LIGHTGRAY); outtextxy(x,y,text2);
    if (!stergere)
    {
        strcpy(text2,text);
        strcat(text2,s);
        setcolor(BLACK); outtextxy(x,y,text2);
    }
}

Matrice citireMFis1(){
    std::ifstream f("Matrice1.txt");
    Matrice a;
    f>>a.l>>a.c;
    for(int i=0;i<a.l;i++)
        for(int j=0;j<a.c;j++)
            f>>a.elem[i][j];
    return a;
    f.close();
}

Matrice citireMFis2(){
    std::ifstream f("Matrice2.txt");
    Matrice b;
    f>>b.l>>b.c;
    for(int i=0;i<b.l;i++)
        for(int j=0;j<b.c;j++)
            f>>b.elem[i][j];
    return b;
    f.close();
}

Matrice citireGraficaM1(){
    Matrice a;
    int i,j,y=120;
    char ns[MAX],s[10]; //nr elemente vector
    char tt[MAX],ss[MAX],ss1[MAX];
    setcolor(LIGHTBLUE);
    setbkcolor(LIGHTGRAY);
    settextstyle(10,HORIZ_DIR,1);
    citesteSir("Numarul de linii este, l=",ns,200,60,false);
    a.l=atoi(ns);
    citesteSir("Numarul de coloane este, c=",ns,200,80,false);
    a.c=atoi(ns);
    for (i=0;i<a.l;i++)
    {
        for(j=0; j<a.c; j++)
        {
            itoa(i,ss,10); strcpy(tt,"a["); //itoa converteste din int in sir
            strcat(tt,ss); strcat(tt,"]");
            itoa(j,ss1,10); strcat(tt,"[");
            strcat(tt,ss1); strcat(tt,"]=");
            citesteSir(tt,ns,80,y+30*i,false); y=y+25;
            a.elem[i][j]=atoi(ns);
            printM(a.elem[i][j],i,j, BLACK);
        }
    }
    return a;
}

Matrice citireGraficaM2(){
    Matrice b;
    int i,j,y=120;
    char ns[MAX],s[10]; //nr elemente vector
    char tt[MAX],ss[MAX],ss1[MAX];
    setcolor(LIGHTBLUE);
    setbkcolor(LIGHTGRAY);
    settextstyle(10,HORIZ_DIR,1);
    citesteSir("Numarul de linii este, l=",ns,200,60,false);
    b.l=atoi(ns);
    citesteSir("Numarul de coloane este, c=",ns,200,80,false);
    b.c=atoi(ns);
    for (i=0;i<b.l;i++)
    {
        for(j=0; j<b.c; j++)
        {
            itoa(i,ss,10); strcpy(tt,"a["); //itoa converteste din int in sir
            strcat(tt,ss); strcat(tt,"]");
            itoa(j,ss1,10); strcat(tt,"[");
            strcat(tt,ss1); strcat(tt,"]=");
            citesteSir(tt,ns,80,y+30*i,false); y=y+25;
            b.elem[i][j]=atoi(ns);
            printM(b.elem[i][j],i,j, BLACK);
        }
    }
    return b;
}

void afisareGraficaM(Matrice& a,int culoare, int coloana){
    int i,j;
    settextstyle(10,HORIZ_DIR,1);
    setcolor(WHITE);
    for(i=0;i<a.l;i++)
        for(j=0; j<a.c; j++)
            printM(a.elem[i][j],i,j+coloana, culoare);
}

void afisareMultipla(Matrice& a, Matrice& b, int culoarea, int culoareb){
    int i,j;
    settextstyle(10,HORIZ_DIR,1);
    setcolor(WHITE);
    for(i=0;i<a.l;i++)
        for(j=0; j<a.c; j++)
            printM(a.elem[i][j],i-1,j-3, culoarea);
    settextstyle(10,HORIZ_DIR,1);
    setcolor(WHITE);
    for(i=0;i<b.l;i++)
        for(j=0; j<b.c; j++)
            printM(b.elem[i][j],i+12,j-3, culoareb);
}

void evidentiazaM(int element, int poz, int coloana, int culoare, int CULOAREINIT){
    printM(888888,poz,coloana, LIGHTGRAY);
    printM(element,poz,coloana, culoare);
    delay(500);
    printM(element,poz,coloana, CULOAREINIT);
}

void printM(int element, int poz, int coloana, int culoare){
    char ns[MAX]; itoa(element,ns,10);
    char s[10];
    setcolor(culoare);
    settextstyle(10,HORIZ_DIR,1);
    int left,top,right,bottom;
    left=220+50*coloana;
    top=70+30*poz-10;
    right=220+50*(coloana+1);
    bottom=70+30*poz+20;
    rectangle(left,top+50,right,bottom+50);
    outtextxy(250-numarcifre(element)+50*coloana,130+30*poz,ns);
}

Vector citireVFis(){
    std::ifstream f("dateintrareV.txt");
    Vector v;
    f>>v.n;
    for(int i=0;i<v.n;i++)
        f>>v.elem[i];
    return v;
    f.close();
}

Vector citireGraficaV(){
    Vector v;
    int a[MAX];
    int i;
    char ns[MAX]; //nr elemente vector
    char tt[MAX], ss[MAX];
    settextstyle(10,HORIZ_DIR,1);
    citesteSir("Dimensiunea vectorului este, n=",ns,200,60,false);
    v.n=atoi(ns);
    for (i=0;i<v.n;i++)
    {
        itoa(i,ss,10); strcpy(tt,"a["); //itoa converteste din int in sir
        strcat(tt,ss); strcat(tt,"]=");
        citesteSir(tt,ns,80,100+30*i,false);
        v.elem[i]=atoi(ns);
        print(v.elem[i],i,2, BLACK);
    }
    return v;
}

void afisareGraficaDiagonale(int element,int nr, int n, int linia, int coloana, int MARG,int caz){
    settextstyle(10,HORIZ_DIR,1);
    setcolor(WHITE);
    outtextxy(getmaxx()/2,350,"Suma elementelor este:");
    setcolor(YELLOW);
    if(nr<14){
        print(element,10,MARG,GREEN);
    }
    else
        if(nr>27)
            print(element,14,MARG,GREEN);
        else
            print(element,12,MARG,GREEN);
    delay(DELAY*2);
    setcolor(YELLOW);
            switch(caz){
                case 1:{
                    if(linia==coloana){
                        if(linia<=n-1){circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);}
                        if(linia<n-1)
                            outtextxy(176+coloana*100,400,"+");
                        else{
                            if(linia==n-1)
                                outtextxy(176+coloana*100,400,"=");
                        }
                    }
                }break;

                case 2:{
                    if(linia>coloana)
                    {
                        if(linia<=n )
                            circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);
                        if(linia<n){
                                if(nr<14){
                                    outtextxy(176+MARG*50,400,"+");
                                    if(coloana==n-2)
                                        outtextxy(176+MARG*50,400,"=");
                                }
                                else{
                                    outtextxy(176+MARG*50,460,"+");
                                    if(coloana==n-2)
                                        outtextxy(176+MARG*50,460,"=");
                                }
                        }
                    }

                }break;

                case 3: {
                        if(coloana<=n-1){
                            circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);}
                        if(coloana<n){
                                if(nr<14){
                                    outtextxy(176+MARG*50,400,"+");
                                    if(linia==n-2)
                                    outtextxy(176+MARG*50,400,"=");
                                }
                                else{
                                    outtextxy(176+MARG*50,460,"+");
                                    if(linia==n-2)
                                        outtextxy(176+MARG*50,460,"=");
                                }
                        }
                }break;

                case 4:{
                    if(linia+coloana==n-1){
                         circle(96+50*linia,124+30*coloana,19); delay(DELAY*2);
                         if(coloana<=n-2)
                            {outtextxy(176+coloana*100,400,"+");}
                         else
                            {outtextxy(176+coloana*100,400,"=");}
                    }
                }break;

                case 5:{
                    if(linia+coloana>=n-1)
                    {
                        if(linia<n)
                            circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);
                        if(linia<n){
                                if(nr<14){
                                    outtextxy(176+MARG*50,400,"+");
                                    if(linia+coloana==2*n-2)
                                        outtextxy(176+MARG*50,400,"=");
                                }
                                else{
                                    outtextxy(176+MARG*50,460,"+");
                                    if(linia+coloana==2*n-2)
                                        outtextxy(176+MARG*50,460,"=");
                                }
                        }
                   }
                }break;

                case 6:{
                    if(linia+coloana<n-1)
                    {
                        if(linia<n){
                            circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);
                        }
                        if(linia<n){
                                if(nr<14){
                                    outtextxy(176+MARG*50,400,"+");
                                    if(linia==n-2)
                                        outtextxy(176+MARG*50,400,"=");
                                }
                                else{
                                    if(nr>=14){
                                        outtextxy(176+MARG*50,460,"+");
                                        if(linia==n-2)
                                            outtextxy(176+MARG*50,460,"=");
                                    }
                                }
                       }
                   }
                }break;

                case 7:{
                    if(coloana<n){circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);}
                    if(coloana<n){
                        outtextxy(176+(MARG/2)*100,400,"+");
                        if(coloana==n-1)
                            outtextxy(176+(MARG/2)*100,400,"=");
                    }
                }break;

                case 8:{
                    if(linia<n){circle(96+50*coloana,124+30*linia,19); delay(DELAY*2);}
                    if(linia<n){
                        outtextxy(176+(MARG/2)*100,400,"+");
                        if(linia==n-1)
                            outtextxy(176+(MARG/2)*100,400,"=");
                    }
                }break;
            }
}

void afisareGraficaV(Vector& v, int culoare,int coloana){
    int i;
    settextstyle(10,HORIZ_DIR,1);
    for(i=0;i<v.n;i++)
        print(v.elem[i],i,coloana, culoare);
    settextstyle(10,HORIZ_DIR,4);
}

void print(int element, int poz, int coloana, int culoare){
    char ns[MAX]; itoa(element,ns,10);
    setcolor(culoare);
    settextstyle(10,HORIZ_DIR,1);
    rectangle(90+50*coloana,90+30*poz-10,90+50*(coloana+2)-30,90+30*poz+20);
    outtextxy(101-numarcifre(element)+50*coloana+30,100+30*poz,ns);
}

void evidentiaza(int element, int poz, int coloana, int culoare){
    print(888888,poz,coloana, LIGHTGRAY);
    print(element,poz,coloana, culoare);
    delay(500);
    print(element,poz,coloana, BLACK);
}

void afisareGraficaCALCUL(Matrice& x,Matrice& a, Matrice& b,char operatie,int culoare,int coloana){
    int i,j,k,aux,margine,col;
    int adun;
    char ns[MAXV];
    settextstyle(10,HORIZ_DIR,1);
    setcolor(BLACK);
    outtextxy(2*getmaxx()/4,50,"Matricea calculata este:");
    if(operatie=='+'){
        for(i=0;i<x.l;i++)
            for(j=0; j<x.c; j++){
                setcolor(YELLOW);
                circle(98+50*j,95+30*i,18);
                print(a.elem[i][j],20,12,BLUE);
                delay(DELAY);
                setcolor(YELLOW);
                outtextxy(775,700,"+");
                circle(98+50*j,485+30*i,18);
                print(b.elem[i][j],20,14,GREEN);
                delay(DELAY);
                setcolor(YELLOW);
                outtextxy(875,700,"=");
                print(x.elem[i][j],20, 16, RED);
                printM(x.elem[i][j],i,j+coloana,culoare);
                delay(DELAY);
                print(888888,20,12, LIGHTGRAY);
                print(888888,20,14, LIGHTGRAY);
                print(888888,20,16, LIGHTGRAY);
            }
        print(888888,20,13, LIGHTGRAY);
        print(888888,20,15, LIGHTGRAY);
    }else
    if(operatie=='-'){
        for(i=0;i<x.l;i++)
            for(j=0; j<x.c; j++){
                setcolor(YELLOW);
                circle(98+50*j,95+30*i,18);
                print(a.elem[i][j],20,12,BLUE);
                delay(DELAY);
                setcolor(YELLOW);
                outtextxy(775,700,"-");
                circle(98+50*j,485+30*i,18);
                print(b.elem[i][j],20,14,GREEN);
                delay(DELAY);
                setcolor(YELLOW);
                outtextxy(875,700,"=");
                print(x.elem[i][j],20, 16, RED);
                printM(x.elem[i][j],i,j+coloana,culoare);
                delay(DELAY);
                print(888888,20,12, LIGHTGRAY);
                print(888888,20,14, LIGHTGRAY);
                print(888888,20,16, LIGHTGRAY);
            }
        print(888888,20,13, LIGHTGRAY);
        print(888888,20,15, LIGHTGRAY);
    }else
    if(operatie=='*'){
        for(i=0;i<x.l;i++)
            for(j=0; j<x.c; j++){
                margine=getmaxx()/2;
                for(k=0;k<a.c;k++){
                    col=10;
                    adun=677;
                    setcolor(YELLOW);
                    evidentiazaM(a.elem[i][k],i-1,k-3,YELLOW,BLUE);
                    print(a.elem[i][k],18,10,BLUE);
                    delay(DELAY);
                    setcolor(YELLOW);
                    outtextxy(677,640,"*");
                    evidentiazaM(b.elem[k][j],k+12,j-3,YELLOW,GREEN);
                    print(b.elem[k][j],18,12,GREEN);
                    delay(DELAY);
                    setcolor(YELLOW);
                    outtextxy(777,640,"=");
                    aux=a.elem[i][k]*b.elem[k][j];
                    print(aux,18, 14, RED);
                    print(aux,20,col+2*k,RED);
                    delay(DELAY);
                    setcolor(YELLOW);
                    if(k==a.c-1){
                        outtextxy(adun+100*k,700,"=");
                        print(x.elem[i][j],20,col+2*(k+1),RED);
                    }else
                        outtextxy(adun+100*k,700,"+");
                    delay(DELAY);
                    print(888888,18,10, LIGHTGRAY);
                    print(888888,18,12, LIGHTGRAY);
                    print(888888,18,14, LIGHTGRAY);
                    setcolor(LIGHTGRAY);
                    outtextxy(677,640,"*");
                    outtextxy(777,640,"=");
                    aux=0;
                }
                printM(x.elem[i][j],i,j+coloana,RED);
                for(col=10;col<=10+2*a.c;col+=2){

                    print(888888,20,col,LIGHTGRAY);
                    setcolor(LIGHTGRAY);
                    if(TRUE)
                        outtextxy(adun+100*aux,700,"=");
                    else
                        outtextxy(adun+100*aux,700,"+");
                    aux++;
                }
        }
    }
}
