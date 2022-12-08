#ifndef Organ_hpp
#define Organ_hpp

#include "Doku.hpp"



class Organ
{

public:
    Organ();
    ~Organ();
    void dokuEkle(Doku* yeniDoku);
    Doku* sonDokuGetir();
    Doku* ilkDoku;
    Organ* sonraki;
    int dokuSayisi;
};




#endif