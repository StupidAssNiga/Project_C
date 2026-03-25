#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Project {
    string name;
    double budget;
    Project(const string& name, double budget) : name(name), budget(budget) {}
};