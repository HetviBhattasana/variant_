#include<iostream>
#include<thread>
#include"Functionalities.h"

int main(){
    Container data;
    // std::thread t1 (CreateObjects, std::ref(data));
    // t1.join();

    CreateObjects(data);
    CalculateTaxPayable(data);
    CallParenOperator(data);

    
}