#ifndef Doku_hpp
#define Doku_hpp

#include "Hucre.hpp"

class Doku
{
public:   
    
    Doku* sag;
    Doku* sol;
    Doku* sonraki;
    Hucre* ortanca;
    Hucre* ilkHucre;
    int hucreSayisi;
    int yukseklik;

    Doku();
    void hucreEkle(int veri);
    void ortancaGuncelle();
    Hucre* sonHucreGetir();
};

#endif