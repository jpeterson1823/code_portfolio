#include <string>
using namespace std;

class Vehicle
{
protected:
    string make;
    string model;
    int year;
    
public:
    Vehicle(string make, string model, int year);
    string getMake();
    string getModel();
    string getYear();
    void print();
};

class DodgeRam : public Vehicle
{
public:
    DodgeRam(int year);
};

class HondaCivic : public Vehicle
{
public:
    HondaCivic(int year);
};