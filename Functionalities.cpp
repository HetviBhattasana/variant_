#include "Functionalities.h"
#include "Employee.h"
#include <memory>
#include<variant>
#include "DataModeller.h"


using BusinessPointer = std::unique_ptr<Business>;
using EmpPointer = std::unique_ptr<Employee>;

void CreateObjects(Container& data)
{
    data.emplace_back(
    std::make_unique<DataModeller>(
    // instance    
        std::make_unique<Employee>(
            "Hetvi",
            EmployeeType::REGULAR,
            780000.0f),
            // vector of floats
            std::vector<float> {19.21f, 145.31f, 204.5f}
    ));

    data.emplace_back(
        std::make_unique<DataModeller>(
            std::make_unique<Business>(
                1000000.0f,
                2000000.0f,
                "XYZ Corporation",
                BusinessType::MNC
            ),
            std::vector<float>{19.21f, 145.31f, 204.5f}
        )
    );

}

/*
    this function will accept a container of datamodeller pointer

    for each pointer, perform the following

    - capture the insatnce reference
    - use holds_alternative to verify which type of pointer is present in the _instance
    - if pointer is of tye Bussiness
        -use std::get ro fetch Business (this will be safe becaus if has been checked)
        - use the fetched pointer in business to calculate tax for business
        
    else when pointer is of type employee

        -use std::get to fetch employeepointer
        - use the fetched pointer to fetch type of employee
        - if type is REGULAR tax is 10% else it should 20% of salary
*/

void CalculateTaxPayable(const Container &data)
{
    for(const dataPointer& ptr : data){
        
        const VType& val = ptr->instance();

        if(std::holds_alternative<BusinessPointer>(val)){
            const BusinessPointer& p = std::get<BusinessPointer>(val);
            std::cout<< 0.1f * (p->revenue() - p->expense() );
        }
        else {

            const EmpPointer& p = std::get<EmpPointer>(val);
            if(p->type() == EmployeeType::REGULAR){
                std :: cout <<"\n Tax is 10%: "<< 0.1f * p->salary() << "\n";
            }else {

                std :: cout <<"\n Tax is 20%: "<< 0.2f * p->salary() << "\n";
            }
        }
    }
}


void CallParenOperator(const Container& data){
    if(data.empty()){
        throw std::runtime_error("\nData is Empty");
    }    
    else{
        for(const dataPointer& ptr : data){
            ptr->operator()();
        }
    }
}