#include "Business.h"

Business::Business(float expense, float revenue, std::string name, BusinessType type)
    : _expense(expense), _revenue(revenue), _registerBusinessName(name), _type(type)
{
}
std::ostream &operator<<(std::ostream &os, const Business &rhs) {
    os << "_expense: " << rhs._expense
       << " _revenue: " << rhs._revenue
       << " _registerBusinessName: " << rhs._registerBusinessName
       << " _type: " <<static_cast<int> (rhs._type);
    return os;
}
