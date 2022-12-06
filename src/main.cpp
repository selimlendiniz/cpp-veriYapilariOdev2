#include <iostream>

using namespace std;

#include "Doku.hpp"


int main()
{
    Doku* selim = new Doku();

    selim->hucreEkle(11);
    selim->hucreEkle(22);
    selim->hucreEkle(33);
    selim->hucreEkle(44);

    cout << "selim";

}