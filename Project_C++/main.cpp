#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Employee.h"
#include "Project.h"
#include "Factory.h"
#include "Personal.h" 
#include "Engineer.h" 
#include "Manager.h"
using namespace std;

void printAllStaff(const vector<Employee*>& staff);
void printStaffByProject(const vector<Employee*>& staff, const string& projectName);
void searchByPosition(const vector<Employee*>& staff, const string& position);
void searchByName(const vector<Employee*>& staff, const string& namePart);
void searchByPayment(const vector<Employee*>& staff, double amount, bool greater);
void createProject(vector<Project*>& projects);
void addEmployeeToProject(vector<Employee*>& staff, vector<Project*>& projects);
void moveEmployeeToAnotherProject(vector<Employee*>& staff, vector<Project*>& projects);
void saveToFile(const vector<Employee*>& staff, const string& filename);

int main() 
{
    setlocale(LC_ALL, ".1251");
    vector<Project*> projects;
    vector<Employee*> staff = StaffFactory::makeStaff("staff.txt", projects);

    if (staff.empty()) 
    {
        cout << "Нет данных о сотрудниках. Проверьте файл staff.txt" << endl;
        return 1;
    }

    for (auto emp : staff) 
    {
        emp->setWorkTime(160);

        if (Driver* d = dynamic_cast<Driver*>(emp))
        {
            d->setNightHours(20);
        }
        else if (Programmer* p = dynamic_cast<Programmer*>(emp))
        {
            p->setEarlyBonus(5000);
        }
        else if (Tester* t = dynamic_cast<Tester*>(emp))
        {
            t->setBugs(10, 200);
        }
        else if (TeamLeader* tl = dynamic_cast<TeamLeader*>(emp)) 
        {
            tl->setSubordinates(3);
        }
        else if (ProjectManager* pm = dynamic_cast<ProjectManager*>(emp)) 
        {
            pm->setSubordinates(5);
        }
        else if (SeniorManager* sm = dynamic_cast<SeniorManager*>(emp))
        {
            sm->setSubordinates(10);
        }
    }

    for (auto emp : staff)
    {
        emp->calc();
    }

    int choice;
    string filename = "staff.txt";

    do
    {
        cout << endl << "\tМеню:" << endl;
        cout << "1. Вывести всех сотрудников" << endl;
        cout << "2. Вывести сотрудников на проекте" << endl;
        cout << "3. Поиск по должности" << endl;
        cout << "4. Поиск по имени" << endl;
        cout << "5. Поиск по зарплате (больше/меньше суммы)" << endl;
        cout << "6. Создать новый проект" << endl;
        cout << "7. Добавить сотрудника на проект" << endl;
        cout << "8. Перевести сотрудника на другой проект" << endl;
        cout << "9. Сохранить в файл" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            printAllStaff(staff);
            break;
        case 2: 
        {
            string proj;
            cout << "Введите название проекта: ";
            cin >> proj;
            printStaffByProject(staff, proj);
            break;
        }
        case 3: 
        {
            string pos;
            cout << "Введите должность: ";
            cin >> pos;
            searchByPosition(staff, pos);
            break;
        }
        case 4: 
        {
            string name;
            cout << "Введите часть имени: ";
            cin.ignore();
            getline(cin, name);
            searchByName(staff, name);
            break;
        }
        case 5: 
        {
            double amount;
            char cmp;
            cout << "Введите сумму и знак (> или <): ";
            cin >> cmp >> amount;
            searchByPayment(staff, amount, cmp == '>');
            break;
        }
        case 6:
            createProject(projects);
            break;
        case 7:
            addEmployeeToProject(staff, projects);
            break;
        case 8:
            moveEmployeeToAnotherProject(staff, projects);
            break;
        case 9:
            saveToFile(staff, filename);
            break;
        case 0:
            cout << "Выход..." << endl;;
            break;
        default:
            cout << "Неверный выбор." << endl;;
        }
    } while (choice != 0);

    for (auto emp : staff) delete emp;
    for (auto proj : projects) delete proj;

    return 0;
}

