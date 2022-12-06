#ifndef Sistem_hpp
#define Sistem_hpp

#include "Organ.hpp"


class Sistem
{
public:
    Sistem(/* args */);
    ~Sistem();
    Organ* ilkOrgan;
    Sistem* sonrakiSistem;
};






#endif