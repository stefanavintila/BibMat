#include "interfata.h"
#include "citiri.h"
#include <graphics.h>
#define DELAY 100

Vector v;
Matrice a,b;

void buton(unsigned int x, unsigned int y,const char *titlu,void (*functieapelata)()){
    unsigned int top, bot, right, left;
    setcolor(BLACK);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    int textWidth= textwidth((char*) titlu);
    int textHeight= textheight((char*) titlu);
    outtextxy(x,y+textHeight/4,(char*) titlu);
    rectangle(x-textWidth/2-5,y-textHeight/2,x+textWidth/2+3,y+textHeight/2);
    if(mousex()>x-textWidth/2 && mousex()<x+textWidth/2 && mousey()<y+textHeight/2 && mousey()>y-textHeight/2){
        if(ismouseclick(WM_LBUTTONDOWN)){
            clearmouseclick(WM_LBUTTONDOWN);
            if(functieapelata!=NULL)
                functieapelata();
        }
    }
}

void meniu1(){
    cleardevice();
    readimagefile("imagini/1.jpg",0,0,getmaxx(),getmaxy());
    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    while(1){
        settextstyle(10,HORIZ_DIR,8);
        buton(getmaxx()/2+355,getmaxy()/2-100,"MATRICE",meniuMatrici);
        buton(getmaxx()/2+355,getmaxy()/2+100,"VECTORI",meniuVector);
        settextstyle(10,HORIZ_DIR,6);
        buton(getmaxx()/2+355,getmaxy()/2+250,"4FUN",fereastra4Fun);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void fereastra4Fun(){
    cleardevice();
    readimagefile("imagini/22.jpg",0,0,getmaxx(),getmaxy());
    Matrice x,trans;
    x=spirala(x);
    cadrane(x);
    while(1){
        settextstyle(10,HORIZ_DIR,8);
        buton(getmaxx()/2-15,getmaxy()-100,"WOW",meniu1);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}


void meniuVector(){
    cleardevice();
    readimagefile("imagini/6.jpg",0,0,getmaxx(),getmaxy());
    while(1){
        settextstyle(10,HORIZ_DIR,6);
        buton(getmaxx()/2-130,getmaxy()/2-100,"De la tastatura",fereastraCitireV);
        buton(getmaxx()/2-130,getmaxy()/2,"Din fisier",fereastraCitireVFis);
        settextstyle(10,HORIZ_DIR,5);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniu1);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void meniuVector_op(){
    int margineD=415;
    cleardevice();
    readimagefile("imagini/7.jpg",0,0,getmaxx(),getmaxy());
    while(1){
        setlinestyle(0,0,2);
        afisareGraficaV(v,BLUE,1);
        buton(getmaxx()/2+margineD,getmaxy()/2-235,"Sortare crescatoare",fereastraBSC);
        buton(getmaxx()/2+margineD,getmaxy()/2-185,"Sortare descrescatoare",fereastraBSD);
        buton(getmaxx()/2+margineD,getmaxy()/2-135,"Shiftare la dreapta",fereastraShiftD);
        buton(getmaxx()/2+margineD,getmaxy()/2-85,"Shiftare la stanga",fereastraShiftS);
        buton(getmaxx()/2+margineD,getmaxy()/2-35,"Suma elementelor",fereastraSEV);
        buton(getmaxx()/2+margineD,getmaxy()/2+15,"Produsul elementelor",fereastraPEV);
        buton(getmaxx()/2+margineD,getmaxy()/2+65,"Inmultire cu scalar",fereastraScalar);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void meniuMatrici(){
    cleardevice();
    readimagefile("imagini/2.jpg",0,0,getmaxx(),getmaxy());
    while(1){
        settextstyle(10,HORIZ_DIR,7);
        buton(getmaxx()/2+350,getmaxy()/2-100,"O MATRICE",meniuMS);
        buton(getmaxx()/2+350,getmaxy()/2,"DOUA MATRICE",meniuMM);
        settextstyle(10,HORIZ_DIR,5);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniu1);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void meniuMS(){
    cleardevice();
    readimagefile("imagini/3.jpg",0,0,getmaxx(),getmaxy());
    while(1){
        settextstyle(10,HORIZ_DIR,6);
        buton(getmaxx()/2-130,getmaxy()/2-100,"De la tastatura",fereastraCitireMS);
        buton(getmaxx()/2-130,getmaxy()/2,"Din fisier",fereastraCitireMFisS);
        settextstyle(10,HORIZ_DIR,5);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuMatrici);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void meniuM1_op(){
    cleardevice();
    readimagefile("imagini/5.jpg",0,0,getmaxx(),getmaxy());
    setlinestyle(0,0,2);
    while(1){
        afisareGraficaM(a,BLUE,-3);
        settextstyle(10,HORIZ_DIR,3);
        buton(getmaxx()/2+400,getmaxy()/2-235,"De pe diagonala principala",fereastraSDP);
        buton(getmaxx()/2+400,getmaxy()/2-185,"De sub diagonala principala",fereastraSsubDP);
        buton(getmaxx()/2+400,getmaxy()/2-135,"De deasupra diagonalei principale",fereastraSdeasDP);
        buton(getmaxx()/2+400,getmaxy()/2-85,"De pe diagonala secundara",fereastraSDS);
        buton(getmaxx()/2+400,getmaxy()/2-35,"De sub diagonala secundara",fereastraSsubDS);
        buton(getmaxx()/2+400,getmaxy()/2+15,"De deasupra diagonalei secundare",fereastraSdeasDS);
        buton(getmaxx()/2+400,getmaxy()/2+65,"De pe o anumita linie",fereastraSumaL);
        buton(getmaxx()/2+400,getmaxy()/2+115,"De pe o anumita coloana",fereastraSumaC);
        settextstyle(10,HORIZ_DIR,5);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuMS);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);

    }
}

void meniuMM(){
    cleardevice();
    readimagefile("imagini/3.jpg",0,0,getmaxx(),getmaxy());
    while(1){
        settextstyle(10,HORIZ_DIR,6);
        buton(getmaxx()/2-130,getmaxy()/2-100,"De la tastatura",fereastraCitireMM);
        buton(getmaxx()/2-130,getmaxy()/2,"Din fisier",fereastraCitireMFisM);
        settextstyle(10,HORIZ_DIR,5);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuMatrici);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void meniuM2_op(){
    cleardevice();
    setbkcolor(LIGHTGRAY);
    readimagefile("imagini/4.jpg",0,0,getmaxx(),getmaxy());
    setlinestyle(0,0,2);
    while(1){
        afisareMultipla(a,b, BLUE, GREEN);
        settextstyle(10,HORIZ_DIR,5);
        buton(getmaxx()-355,getmaxy()/2-210,"Adunare",fereastraSumaMM);
        buton(getmaxx()-355,getmaxy()/2-110,"Diferenta",fereastraDifMM);
        buton(getmaxx()-355,getmaxy()/2-10,"Inmultire",fereastraProdMM);
        buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuMatrici);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(DELAY);
    }
}

void fereastraCitireV(){
    cleardevice();
    readimagefile("imagini/8.jpg",0,0,getmaxx(),getmaxy());
    setbkcolor(LIGHTGRAY);
    v=citireGraficaV();
    cleardevice();
    setbkcolor(LIGHTGRAY);
    meniuVector_op();
}

void fereastraCitireVFis(){
    cleardevice();
    v=citireVFis();
    cleardevice();
    meniuVector_op();
}

//fereastra Bubble Sort crescator
void fereastraBSC(){
    cleardevice();
    readimagefile("imagini/20.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaV(v, BLACK,1);
    BSCgrafic(v);
    while(1){
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra Bubble Sort descrescator
void fereastraBSD(){
    cleardevice();
    readimagefile("imagini/20.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaV(v, BLACK,1);
    BSDgrafic(v);
    while(1){
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra shiftare stanga
void fereastraShiftS(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaV(v, BLACK,1);
    shiftSgrf(v,8);
    while(1){
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra shiftare dreapta
void fereastraShiftD(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaV(v, BLACK,1);
    shiftDgrf(v,8);
    while(1){
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraSEV(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    SelemV(v);
    while(1){
    afisareGraficaV(v, BLACK,1);
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraPEV(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    PelemV(v);
    while(1){
    afisareGraficaV(v, BLACK,1);
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraScalar(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    Pscalar(v);
    while(1){
    settextstyle(10,HORIZ_DIR,5);
    buton(getmaxx()-100,getmaxy()-50,"ÎNAPOI",meniuVector_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraCitireMS(){
    cleardevice();
    readimagefile("imagini/21.jpg",0,0,getmaxx(),getmaxy());
    setbkcolor(LIGHTGRAY);
    a=citireGraficaM1();
    if(a.l==a.c){
        cleardevice();
        setbkcolor(LIGHTGRAY);
        meniuM1_op();
    }
    else
    {
        while(1){
        readimagefile("imagini/13.jpeg",0,0,getmaxx(),getmaxy());
        buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuMS);
        clearmouseclick(WM_LBUTTONDOWN);}
    }
}

void fereastraCitireMFisS(){
    cleardevice();
    a=citireMFis1();
    if(a.l==a.c){
        cleardevice();
        setbkcolor(LIGHTGRAY);
        meniuM1_op();
    }
    else
    {
        while(1){
        readimagefile("imagini/13.jpeg",0,0,getmaxx(),getmaxy());
        buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuMS);
        clearmouseclick(WM_LBUTTONDOWN);}
    }
}
//fereastra pentru suma elementelor de pe diag principala
void fereastraSDP(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    sumaDP(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de sub diag principala
void fereastraSsubDP(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    SsubDP(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de deasupra diag principale
void fereastraSdeasDP(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    SdeasDP(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de pe diag secundara
void fereastraSDS(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    sumaDS(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de sub diag secundara
void fereastraSsubDS(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    SsubDS(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de deasupra diag secundare
void fereastraSdeasDS(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    SdeasDS(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de pe o anumita linie
void fereastraSumaL(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    sumaL(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

//fereastra pentru suma elementelor de pe o anumita coloana
void fereastraSumaC(){
    cleardevice();
    readimagefile("imagini/9.jpg",0,0,getmaxx(),getmaxy());
    afisareGraficaM(a,BLUE,-3);
    sumaC(a);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM1_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraCitireMM(){
    cleardevice();
    readimagefile("imagini/10.jpg",0,0,getmaxx(),getmaxy());
    setbkcolor(LIGHTGRAY);
    a=citireGraficaM1();
    cleardevice();
    readimagefile("imagini/11.jpg",0,0,getmaxx(),getmaxy());
    setbkcolor(LIGHTGRAY);
    b=citireGraficaM2();
    cleardevice();
    meniuM2_op();
}

void fereastraCitireMFisM(){
    cleardevice();
    a=citireMFis1();
    b=citireMFis2();
    cleardevice();
    meniuM2_op();
}

void fereastraSumaMM(){
    cleardevice();
    readimagefile("imagini/18.jpg",0,0,getmaxx(),getmaxy());
    sumaMM(a,b);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM2_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraDifMM(){
    cleardevice();
    readimagefile("imagini/18.jpg",0,0,getmaxx(),getmaxy());
    diferentaMM(a,b);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM2_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

void fereastraProdMM(){
    cleardevice();
    readimagefile("imagini/18.jpg",0,0,getmaxx(),getmaxy());
    produsMM(a,b);
    while(1){
    buton(getmaxx()-90,getmaxy()-50,"INAPOI",meniuM2_op);
    clearmouseclick(WM_LBUTTONDOWN);
    }
}

