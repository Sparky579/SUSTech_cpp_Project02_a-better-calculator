#include "../headfile/BigNumber.hpp"
#include "../headfile/constant.hpp"
#include "../headfile/calculator.hpp"
#include <iostream>
int main()
{
    calculator calc;
    while (true)
    {
        std::string s;
        getline(std::cin, s);
        if (s == "quit")
            break;
        calc.call(s);
    }
    return 0;
}