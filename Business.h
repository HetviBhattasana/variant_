#ifndef BUSINESS_H
#define BUSINESS_H

#include<iostream>
#include"BusinessType.h"

class Business
{
private:
    float _expense;
    float _revenue;
    std::string _registerBusinessName;
    BusinessType _type;

public:
    
    Business() = delete;

    Business(Business&) = delete;
    Business& operator=(Business&) = delete;

    Business(Business&&) = delete;
    Business& operator=(Business&&) = delete;

    ~Business() = default;

    Business(float expense, float revenue, std::string name, BusinessType type);

    float expense() const { return _expense; }

    float revenue() const { return _revenue; }

    std::string registerBusinessName() const { return _registerBusinessName; }

    BusinessType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Business &rhs);
};

#endif // BUSINESS_H
