#ifndef Sistem_hpp
#define Sistem_hpp

#include "Organ.hpp"


class Sistem
{
public:
    Sistem();
    ~Sistem();
    Organ* ilkOrgan;
    Sistem* sonrakiSistem;
};






#endif