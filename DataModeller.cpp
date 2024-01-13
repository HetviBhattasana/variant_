#include "DataModeller.h"

DataModeller::DataModeller(VType v, const std::vector<float>& prices)
     : _goodsPrices(prices), _instance(std::move(v))
{
}

void DataModeller::operator()()
{
    if(_goodsPrices.empty()){
        throw std::runtime_error("\nNot Found");
    }
    float total = 0.0f;

    for(float val : _goodsPrices){
        total += val;
    }

    std::cout<<"\nAverage value is: "<< total/ _goodsPrices.size() << "\n";

}
