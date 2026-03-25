#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Project.h"
using namespace std;

class Employee 
{
protected:
    int id;
    string name;
    double worktime;
    double payment;

public:
    Employee(int id, const string& name);
    virtual ~Employee() {}
    void setWorkTime(double time) { worktime = time; }
    virtual void calc() = 0;
    virtual void printInfo() const = 0;

    int getId() const { return id; }
    string getName() const { return name; }
    double getPayment() const { return payment; }
    double getWorkTime() const { return worktime; }
};