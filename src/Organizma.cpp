#include "../include/Organizma.hpp"


Organizma::Organizma()
{
    ilkSistem = 0;
    sistemSayisi = 0;
}

void Organizma::sistemEkle(Sistem* yeniSistem){

    

    if (ilkSistem == 0)
    {
        ilkSistem = yeniSistem;
    }else
    {

        sonSistemGetir()->sonrakiSistem = yeniSistem;
        
    }

    ++sistemSayisi;
    
    

}

Sistem* Organizma::sonSistemGetir(){
    Sistem* gec = ilkSistem;

    while (gec->sonrakiSistem != 0)
    {
        gec = gec->sonrakiSistem;
    }


    return gec;

}


void Organizma::mutasyonGecir()
{
    Sistem* gec = ilkSistem;
    while (gec != 0)
    {
        gec->organlariMustasyonaUgrat();
        gec = gec->sonrakiSistem;
        
    }
    
}