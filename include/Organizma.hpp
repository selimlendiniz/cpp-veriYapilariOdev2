#ifndef Organizma_hpp
#define Organizma_hpp

#include "Sistem.hpp"

class Organizma
{
private:
    
public:
    Organizma();
    ~Organizma();
    void sistemEkle(Sistem* yeniSistem);
    Sistem* sonSistemGetir();
    Sistem* ilkSistem;
    int sistemSayisi;
};




#endif