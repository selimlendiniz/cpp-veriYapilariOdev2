#ifndef Doku_hpp
#define Doku_hpp

#include "Hucre.hpp"

class Doku
{
public:   
    
    Doku* sag;
    Doku* sol;
    Doku* sonraki;
    Doku* ortanca;
    Hucre* ilkHucre;
    int hucreSayisi;

    Doku();
    void hucreEkle(int veri);
    void ortancaGuncelle();
    Hucre* sonHucreGetir();
};

#endif