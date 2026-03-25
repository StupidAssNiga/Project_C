#include "Personal.h"
#include <iostream>
using namespace std;

Personal::Personal(int id, const string& name, double rate, Project* proj)
    : Employee(id, name, rate, proj) 
{
}

double Personal::calcBase() const
{
    return rate * worktime;
}

double Personal::calcBonus() const
{
    return 0;
}

void Personal::calc() 
{
    payment = calcBase() + calcBonus();
}

string Personal::getPosition() const 
{
    return "Personal";
}

Cleaner::Cleaner(int id, const string& name, double rate, Project* proj)
    : Personal(id, name, rate, proj) 
{

}

string Cleaner::getPosition() const
{
    return "Cleaner";
}

Driver::Driver(int id, const string& name, double rate, Project* proj)
    : Personal(id, name, rate, proj), nightHours(0), nightRate(0) 
{

}

void Driver::setNightHours(double hours) 
{
    nightHours = hours;
    nightRate = rate * 0.5;
}

double Driver::calcBonus() const
{
    return nightHours * nightRate;
}

string Driver::getPosition() const 
{
    return "Driver";
}