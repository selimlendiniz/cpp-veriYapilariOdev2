#include "../include/Organ.hpp"
#include "../include/IkiliAramaAgaci.hpp"


Organ::Organ(){
    ilkDoku = 0;
    sonraki = 0;
    dokuSayisi = 0;
    dengeliMi = false;
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

void Organ::agacOlustur()
{
    Doku* gec = ilkDoku;
    IkiliAramaAgaci* agac = new IkiliAramaAgaci();
    

    while (gec != 0)
    {
        agac->ekle(gec);
        gec = gec->sonraki;
    }
    


}

void Organ::agacSifirla()
{
    Doku* gec = ilkDoku;
    while (gec != 0)
    {
        gec->sag = 0;
        gec->sol = 0;
        
        gec = gec->sonraki;
    }

}



bool Organ::dengeKontrolu(Doku* aktif)
{
    if (aktif)
    {
        bool solAktifMi = dengeKontrolu(aktif->sol);
        bool sagAktifMi = dengeKontrolu(aktif->sag);

        if (solAktifMi && sagAktifMi)
        {
            if (abs(yukseklik(aktif->sol)-yukseklik(aktif->sag)) <= 1)
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
     
        
    }

    return true;
    
}

int Organ::yukseklik(Doku* aktifDugum) 
{
	if(aktifDugum)
    {
        aktifDugum->yukseklik= 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
        return aktifDugum->yukseklik;
    }
    return -1;
}

void Organ::mutasyonaUgra()
{
    
    bool deneme = false;
    if (ilkDoku->ortanca->dnaSayisi % 50 == 0)
    {
        deneme = true;
        Doku* dokuGec = ilkDoku;
        while (dokuGec != 0)
        {
            Hucre* hucreGec = dokuGec->ilkHucre;

            while (hucreGec != 0)
            {

                if (hucreGec->dnaSayisi % 2 == 0)
                {
                    hucreGec->dnaSayisi = hucreGec->dnaSayisi / 2;
                }


                hucreGec = hucreGec->sonraki;
            }

            dokuGec->ortancaGuncelle();


            dokuGec = dokuGec->sonraki;
        }
    }

    if (deneme)
    {
        agacSifirla();
        agacOlustur();
        dengeliMi = dengeKontrolu(ilkDoku);
        
    }
    

    
    

    return;
    
}