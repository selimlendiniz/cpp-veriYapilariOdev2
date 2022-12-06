#ifndef Organizma_hpp
#define Organizma_hpp

#include "Sistem.hpp"

class Organizma
{
private:
    
public:
    Organizma(/* args */);
    ~Organizma();
    void sistemEkle();
    Sistem* sonSistemGetir();
    Sistem* ilkSistem;
    int sistemSayisi;
};




#endif