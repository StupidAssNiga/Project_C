#pragma once
#include <iostream>
#include "Personal.h"
#include "Interfaces.h"
using namespace std;

class Engineer : public Personal, public IProjectBudget 
{

};

class Programmer : public Engineer 
{

};

class Tester : public Engineer 
{

};

class TeamLeader : public Engineer, public IHeading 
{

};