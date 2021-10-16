#include "interfata.h"
#include <graphics.h>
#include <MMSystem.h>

int main()
{
    initwindow(getmaxwidth(), getmaxheight(),"BIBMAT");
    mciSendString("play song.mp3 repeat", NULL, 0, NULL); // PORNESTE muzica
    meniu1();
    mciSendString("close song.mp3", NULL, 0, NULL); // OPRESTE muzica
    getch();
    closegraph();
    return 0;
}



///ECHIPA 5
///SARGHE ANDREI-VLAD
///VINTILA STEFANA

///Din oficiu: 1p
///Structurile de date folosite, fisiere: 1p
///Implementarea functiilor de operare cu tablouri uni- si bidimensionale: 3p
///Animatia: 3p
///Elemente suplimentare (alte functii, meniu, setari, culori, sunete, etc): 1p
///Elemente de creativitate și competitivitate: 1p
