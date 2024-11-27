#include "SimpleVehicle.hpp"
#include <iostream>
using namespace std;

int main()
{
    DodgeRam ram = DodgeRam(2008);
    ram.print();

    HondaCivic civic = HondaCivic(2019);
    civic.print();
    
    return 0;
}