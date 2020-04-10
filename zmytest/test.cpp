#include "test.hpp"
#include <iostream>

/* ************************************************************************** */
void inizio(){
std::cout << "Benvenuto!";
std::cout << "Scegliere la struttura dati:";
}

void decisione()
{
    int risposta;

    std::cin >> risposta;
    while (risposta != 2 && risposta != 1)
    {
        std::cout << "inserire solo 1 o 2 come opzione!";
    }
    if (risposta == 1)
    {
        creazioneVettore();
    }
    else
    {
        //lista
    }
}

void creazioneVettore(){

}