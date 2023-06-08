#include <string>
#include <iostream>
#include "SimpleVehicle.hpp"

Vehicle::Vehicle(string make, string model, int year)
    :make(make), model(model), year(year) {}

string Vehicle::getMake()
{
    return this->make;
}

string Vehicle::getModel()
{
    return this->model;
}

void Vehicle::print()
{
    cout << year << ' ' << make << ' ' << model << endl;
}




DodgeRam::DodgeRam(int year)
    :Vehicle("Dodge", "Ram", year) {}




HondaCivic::HondaCivic(int year)
    :Vehicle("Honda", "Civic", year) {}