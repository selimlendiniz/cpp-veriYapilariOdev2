#include <iostream>

#include "Doku.hpp"

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
    


}