#ifndef DATAMODELLER_H
#define DATAMODELLER_H

#include<iostream>
#include"Employee.h"
#include"Business.h"
#include<variant>
#include<vector>
#include<memory>

using BusinessPointer = std::unique_ptr<Business>;
using EmpPointer = std::unique_ptr<Employee>;
using VType = std::variant<BusinessPointer, EmpPointer>;

class DataModeller
{
private:
    VType _instance;
    std::vector<float> _goodsPrices;
public:
    DataModeller(VType v,const std::vector<float>& prices);

    void operator()();

    DataModeller() = delete;

    DataModeller(DataModeller&) = delete;
    DataModeller(DataModeller&&) = delete;

    DataModeller& operator=(DataModeller&) = delete;
    DataModeller& operator=(DataModeller&&) = delete;

    ~DataModeller() = default;

    const VType& instance() const { return _instance; }

    std::vector<float> goodsPrices() const { return _goodsPrices; }
};

#endif // DATAMODELLER_H
