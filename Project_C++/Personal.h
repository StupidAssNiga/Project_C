#pragma once
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"
using namespace std;

class Personal : public Employee, public IWorkBaseTime 
{
protected:
    double hourlyRate;
public:
    Personal(int id, const std::string& name, double rate);
    double getHourlyRate() const { return hourlyRate; }

    virtual double calcBase() const override;
    virtual double calcBonus() const override;
    virtual void calc() override;
    virtual void printInfo() const override;
};