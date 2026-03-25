#pragma once
class IWorkBaseTime 
{
public:
    virtual double calcBase() const = 0;
    virtual double calcBonus() const = 0;
    virtual ~IWorkBaseTime() {}
};

class IProjectBudget 
{
public:
    virtual double calcBudgetPart() const = 0;
    virtual double calcProAdditions() const = 0;
    virtual ~IProjectBudget() {}
};

class IHeading 
{
public:
    virtual double calcHeads() const = 0;
    virtual ~IHeading() {}
};