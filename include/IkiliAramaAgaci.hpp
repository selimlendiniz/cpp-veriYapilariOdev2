#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp
#include<iostream>
#include "Doku.hpp"
using namespace std;

class IkiliAramaAgaci
{
public:

	IkiliAramaAgaci();

	~IkiliAramaAgaci();
	bool varmi(int veri);
	void ekle(Doku* eklenecek);
	void sil(int veri);
    friend ostream& operator<<(ostream& os,IkiliAramaAgaci& kuyruk);
	int yukseklik();
	void preOrder();
	void postOrder();
	void inOrder();
	
private:
	void levelOrder(Doku* aktif,int level);
	void levelOrder();
	void preOrder(Doku* aktif);
	void postOrder(Doku* index);
	void inOrder(Doku* index);
	int yukseklik(Doku* aktifDugum);
	void ekle(Doku* eklenecek,Doku* aktifDugum);
	bool varmi(int aranan,Doku* aktif);
	void silDonguile(Doku* aktif,Doku* Ebeveyn);
	void sil(int aranan,Doku* &aktif);
	int maxDeger(Doku* aktif);
	int agacYukseklik;
	void boslukBirak(int adet);
	Doku* kok;
};
//diger fonksiyonlar eklenecek
#endif