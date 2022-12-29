#include <iostream>

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "Organizma.hpp"

void organizmaYazdir(Organizma* organizma)
{

    Sistem* sistemGec = organizma->ilkSistem;
    int sayac = 0;

    while (sistemGec != 0)
    {

        Organ* organGec = sistemGec->ilkOrgan;

        while (organGec != 0)
        {

            if (organGec->dengeliMi)
            {
                cout <<  " ";
            }else
            {
                cout << "#";
            }
            sayac++;
            organGec = organGec->sonraki;
        }
    
        if (sayac == 100)
        {
            cout << endl;
            sayac = 0;
        }             

        sistemGec = sistemGec->sonrakiSistem;
    }


}




int main()
{

    Organizma* organizma = new Organizma();
    ifstream dosyaOku("veriler.txt");
    string satir = "";
    int dokuSayac = 0;
    int organSayac = 0;
    int sistemSayac = 0;
    Doku* doku;
    Organ* organ = new Organ();;
    Sistem* sistem = new Sistem();

    //Dosyayı okuyup yöneticiListsini ve SatirListesini oluşturuyor
    if (dosyaOku.is_open()) {

        while (getline(dosyaOku, satir)) {
            
            stringstream sstream(satir);
            int temp;

            doku = new Doku();
            while (sstream >> temp)
            {
                doku->hucreEkle(temp);
            }

            doku->ortancaGuncelle();

            dokuSayac++;

            organ->dokuEkle(doku);
            
            if (dokuSayac % 20 == 0)
            {
                organ->agacOlustur();
                organ->dengeliMi = organ->dengeKontrolu(organ->ilkDoku);
                sistem->organEkle(organ);
                
                
                
            }

            if (dokuSayac % 2000 == 0)
            {
                organizma->sistemEkle(sistem);
                sistem = new Sistem();
                sistemSayac++;
            }
            

            
            if (dokuSayac % 20 == 0)
            {
                organ = new Organ();   
                organSayac++;
            }  
        }
        dosyaOku.close();
    }


    organizmaYazdir(organizma);

    if (cin.get() == '\n') {
        system("cls");
        organizma->mutasyonGecir();
        organizmaYazdir(organizma);
    }
    
    cout << "selim";

    

    
}