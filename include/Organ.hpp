#ifndef Organ_hpp
#define Organ_hpp

#include "Doku.hpp"



class Organ
{

public:
    Organ();
    ~Organ();
    void dokuEkle(Doku* yeniDoku);
    void agacOlustur();
    Doku* sonDokuGetir();
    Doku* ilkDoku;
    Organ* sonraki;
    int dokuSayisi;
    bool dengeliMi;
    bool dengeKontrolu();
    int yukseklik(Doku* aktifDugum);
    bool dengeKontrolu(Doku* aktif);


};




#endif