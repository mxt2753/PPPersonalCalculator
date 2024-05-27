#include <iostream>
#include <string>
#include <regex>
#include <sstream>
bool isValidInput(const std::string& UserIn) 
{
    std::regex design(R"(^\d+\s*[\+\-\*\/xX]\s*\d+$)");
    return std::regex_match(UserIn,design);
}
double calculateResult(const std::string& UserIn)
{
    std::istringstream iss(UserIn);
    double NumOne;
    double NumTwo;
    char CharOP;
    iss>>NumOne>>CharOP>>NumTwo;
    switch(CharOP)
    {
        case '+':
            return NumOne+NumTwo;
        case '-':
            return NumOne-NumTwo;
        case '*':
        case 'x':
        case 'X':
            return NumOne*NumTwo;
        case '/':
            if(NumTwo==0) 
            {
                std::cerr<<"Error: Division by zero."<<std::endl;
                exit(1);
            }
            return NumOne/NumTwo;
        default:
            std::cerr<<"Invalid operator"<<std::endl;
            exit(1);
    }
}
int main()
 {
    std::string UserIn;
    std::cout<<"Welcome to Calculator App"<<std::endl;
    std::cout<<"Enter a math problem (e.g., 719 x 412), or type 'exit' to quit:"<<std::endl;
    while (true) 
    {
        std::getline(std::cin,UserIn);
        if(UserIn=="exit") 
        {
            break;
        }
        if(isValidInput(UserIn)) 
        {
            double Outcome=calculateResult(UserIn);
            std::cout<<"Result: "<<Outcome<<std::endl;
        } 
        else 
        {
            std::cout<<"Invalid input. Please enter a math problem that's valid."<<std::endl;
        }
        std::cout<<"\nEnter math problem or type 'exit' to quit:"<<std::endl;
    }
    return 0;
}
