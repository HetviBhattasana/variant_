#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include"DataModeller.h"

using dataPointer = std::unique_ptr<DataModeller>;
using Container = std::vector<dataPointer>;

void CreateObjects(Container&);

void CalculateTaxPayable(const Container& data);


void CallParenOperator(const Container& data);

#endif // FUNCTIONALITIES_H
