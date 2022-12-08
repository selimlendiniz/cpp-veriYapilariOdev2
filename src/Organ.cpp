#include "../include/Organ.hpp"


Organ::Organ(){
    ilkDoku = 0;
    sonraki = 0;
    dokuSayisi = 0;
}

void Organ::dokuEkle(Doku* yeniDoku){

    

    if (ilkDoku == 0)
    {
        ilkDoku = yeniDoku;
    }else
    {

        sonDokuGetir()->sonraki = yeniDoku;
        
    }

    ++dokuSayisi;
    
    

}

Doku* Organ::sonDokuGetir(){
    Doku* gec = ilkDoku;

    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }


    return gec;

}