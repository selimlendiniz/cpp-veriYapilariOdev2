#ifndef Sistem_hpp
#define Sistem_hpp

#include "Organ.hpp"


class Sistem
{
public:
    Sistem();
    ~Sistem();
    void organEkle();
    Organ* sonOrganGetir();
    Organ* ilkOrgan;
    Sistem* sonrakiSistem;
    int organSayisi;
};






#endif