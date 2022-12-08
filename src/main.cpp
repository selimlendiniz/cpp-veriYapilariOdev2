#include <iostream>

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "Organizma.hpp"




int main()
{

    Organizma* organizma = new Organizma();
    ifstream dosyaOku("veriler.txt");
    string satir = "";
    int dokuSayac = 0;
    int organSayac = 1;
    int sistemSayac = 1;
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
 


            // 100 organ oldugunda (yani 2000 doku olduğunda) sistem oluşur
            if (dokuSayac % 20 == 0)
            {
                sistem->organEkle(organ);
                
                
            }

            if (dokuSayac % 2000 == 0)
            {
                organizma->sistemEkle(sistem);
                sistem = new Sistem();
            }
            

            
            if (dokuSayac % 20 == 0)
            {
                organ = new Organ();   
                organSayac++;
            }  
        }
        dosyaOku.close();
    }

    cout << endl;
}