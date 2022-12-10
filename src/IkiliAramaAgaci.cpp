#include "../include/IkiliAramaAgaci.hpp"
#include <iomanip>
#include<iostream>
#include<cmath>
#include "../include/Kuyruk.hpp"
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok= 0;
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{

}
bool IkiliAramaAgaci::varmi(int veri) 
{
    varmi(veri,kok);
}
void IkiliAramaAgaci::ekle(Doku* eklenecek)
{
    if(kok==0)
        kok= eklenecek;
    else
        ekle(eklenecek,kok);
}
void IkiliAramaAgaci::sil(int veri) 
{
	sil(veri,kok); 
}
int IkiliAramaAgaci::yukseklik() 
{
	return yukseklik(kok);
}
void IkiliAramaAgaci::preOrder() {
    preOrder(kok);
    cout<<endl;
}
void IkiliAramaAgaci::postOrder() {
	postOrder(0);
}
void IkiliAramaAgaci::inOrder() {
    inOrder(0);
}

 
void IkiliAramaAgaci::preOrder(Doku* aktif) 
{
	if(aktif)
    {
        cout<<aktif->ortanca->dnaSayisi<<"  ";
        preOrder(aktif->sol);
        preOrder(aktif->sag);
    }
}
void IkiliAramaAgaci::postOrder(Doku* aktif) 
{
	if(aktif)
    {
        
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout<<aktif->ortanca->dnaSayisi<<"  ";
    }	
}
void IkiliAramaAgaci::inOrder(Doku* aktif) 
{
	if(aktif)
    {
        
        inOrder(aktif->sol);
        cout<<aktif->ortanca->dnaSayisi<<"  ";        
        inOrder(aktif->sag);
        
    }	
}
int IkiliAramaAgaci::yukseklik(Doku* aktifDugum) 
{
	if(aktifDugum)
    {
        aktifDugum->yukseklik= 1+max(   yukseklik(aktifDugum->sol),
                        yukseklik(aktifDugum->sag));
        return aktifDugum->yukseklik;
    }
    return -1;
}
void IkiliAramaAgaci::ekle(Doku* eklenecek,Doku* aktifDoku) 
{
	if(aktifDoku->ortanca->dnaSayisi >= eklenecek->ortanca->dnaSayisi)
    {
        if(aktifDoku->sol)
            ekle(eklenecek,aktifDoku->sol);
        else 
            aktifDoku->sol = eklenecek;
    }
    else if(aktifDoku->ortanca->dnaSayisi < eklenecek->ortanca->dnaSayisi)
    {
        if(aktifDoku->sag)
            ekle(eklenecek,aktifDoku->sag);
        else
            aktifDoku->sag= eklenecek;
    }
    else
        return;
}

void IkiliAramaAgaci::silDonguile(Doku* aktif,Doku* ebeveyn) 
{
    
    Doku* yeniDugum;
    if(!aktif->sag&&!aktif->sol)
    {
        yeniDugum = 0;
    }    
	else if(!aktif->sol) //sadece sağ düğüm var ise
    {
        yeniDugum = aktif->sag;
    }
    else if(!aktif->sag)
    {
        yeniDugum = aktif->sol;
    }
    else
    {
        Doku* ebeveyn= aktif;

        Doku* enbuyuk = aktif->sol;

        while(enbuyuk->sag!=0)
        {
            ebeveyn = enbuyuk;
            enbuyuk = enbuyuk->sag;
        }
        aktif->ortanca->dnaSayisi = enbuyuk->ortanca->dnaSayisi;

        ebeveyn->sag = enbuyuk->sol;
       
        delete enbuyuk;
        return ;
    }

    if(aktif==ebeveyn->sol)
        ebeveyn->sol = yeniDugum;
    else if(aktif==ebeveyn->sag)
    {
        ebeveyn->sag = yeniDugum;
    } 
    delete aktif;
}
void IkiliAramaAgaci::sil(int aranan,Doku* &aktif) 
{
    if(aktif==0)        return;
	if(aktif->ortanca->dnaSayisi>aranan)
        sil(aranan,aktif->sol);
    else if(aktif->ortanca->dnaSayisi<aranan)
        sil(aranan,aktif->sag);
    else
    {
        if(aktif->sag&&aktif->sol)
        {
            aktif->ortanca->dnaSayisi = maxDeger(aktif->sol);
            sil(aktif->ortanca->dnaSayisi,aktif->sol);
        }
        else
        {
            Doku* silinecek= aktif;
            if(aktif->sol==0)
                aktif= aktif->sag;
            else if(aktif->sag==0)
                aktif = aktif->sol;
            else 
                aktif =0;
            delete silinecek;      
        }
    }
}
int IkiliAramaAgaci::maxDeger(Doku* aktif) 
{
    if(aktif->sag)
        return maxDeger(aktif->sag);
    
    return aktif->ortanca->dnaSayisi;
}
void IkiliAramaAgaci::boslukBirak(int adet) {
     int baslangicBosluk = pow(2,adet)-1;
     for(int i=0;i<baslangicBosluk;i++)
	    cout<<"  ";
}
bool IkiliAramaAgaci::varmi(int aranan,Doku* aktif)
{
    if(aktif->ortanca->dnaSayisi<aranan)
    {
        if(aktif->sag)
            return varmi(aranan,aktif->sag);
        else
            return 0;
    }
    else if(aktif->ortanca->dnaSayisi>aranan)
    {
        if(aktif->sol)
            return varmi(aranan,aktif->sol);
        return 0;
    }
    else
    {
        return aktif;
    }
}


