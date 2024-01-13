#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"EmployeeType.h"

class Employee
{
private:
    std::string _name;
    EmployeeType _type;
    float _salary;
public:
    Employee() = delete;

    Employee(Employee&) = delete;
    Employee& operator=(Employee&) = delete;

    Employee(Employee&&) = delete;
    Employee& operator=(Employee&&) = delete;

    ~Employee() = default;

    Employee(std::string name, EmployeeType type, float salary);

    std::string name() const { return _name; }

    EmployeeType type() const { return _type; }

    float salary() const { return _salary; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
