#include "../include/Sistem.hpp"

Sistem::Sistem(){
    ilkOrgan = 0;
    sonrakiSistem = 0;
    organSayisi = 0;
}


void Sistem::organEkle(Organ* yeniOrgan){


    if (ilkOrgan == 0)
    {
        ilkOrgan = yeniOrgan;
    }else
    {

        sonOrganGetir()->sonraki = yeniOrgan;
        
    }

    ++organSayisi;
    
    

}

Organ* Sistem::sonOrganGetir(){
    Organ* gec = ilkOrgan;

    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }


    return gec;

}