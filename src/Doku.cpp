#include <iostream>

#include "Doku.hpp"
#include "../include/Radix.hpp"

Doku::Doku(){
    hucreSayisi = 0;
    sag = 0;
    sol = 0;
    sonraki = 0;
    ortanca = 0;
    ilkHucre = 0;
}

void Doku::hucreEkle(int veri){

    Hucre* yeniHucre = new Hucre(veri);

    if (ilkHucre == 0)
    {
        ilkHucre = yeniHucre;
    }else
    {

        sonHucreGetir()->sonraki = yeniHucre;
        
    }

    ++hucreSayisi;
    
    

}

Hucre* Doku::sonHucreGetir(){
    Hucre* gec = ilkHucre;

    while (gec->sonraki != 0)
    {
        gec = gec->sonraki;
    }


    return gec;

}


void Doku::ortancaGuncelle(){

    int* sayilar = new int[hucreSayisi];

    Hucre* gec = ilkHucre;


    for (int i = 0; i < hucreSayisi; i++)
    {
        sayilar[i] = gec->dnaSayisi;
        gec = gec->sonraki;
    }

    Radix *radix = new Radix(sayilar,hucreSayisi);
    int *siraliSayilar = radix->sirala();


    gec = ilkHucre;

    for (int i = 0; i < hucreSayisi; i++)
    {
        gec->dnaSayisi = siraliSayilar[i];
        gec = gec->sonraki;
    }

    gec = ilkHucre;

    for (int i = 0; i < ((hucreSayisi-1) / 2) + 1 ; i++)
    {
        gec = gec->sonraki;
    }

    ortanca = gec;


    delete radix;
    delete[] sayilar;
    
    
    


}


Doku::~Doku()
{
   
    
}