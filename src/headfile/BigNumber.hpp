#pragma once
#include <vector>
#include <string>
class BigNumber
{
private:
    void set_BigNumber(std::string);

public:
    BigNumber &checkCarry();
    BigNumber &checkScale(int setted_scale);
    bool negative_;
    std::vector<int> digits_;
    int dotpos_;
    void show();
    std::string to_string();
    BigNumber();
    BigNumber(std::string number);
    BigNumber(int number);
};
int BigNumberAbsCmp(BigNumber num1, BigNumber num2);
int BigNumberCmp(BigNumber num1, BigNumber num2);
BigNumber BigNumberAbsAdd(BigNumber num1, BigNumber num2, bool negative);
BigNumber BigNumberAbsSub(BigNumber num1, BigNumber num2, bool negative);
BigNumber BigNumberAbsMul(BigNumber num1, BigNumber num2, bool negative);
BigNumber BigNumberAbsDiv(BigNumber num1, BigNumber num2, bool negative, bool isDiv);
bool operator<(BigNumber num1, BigNumber num2);
bool operator<=(BigNumber num1, BigNumber num2);
bool operator==(BigNumber num1, BigNumber num2);
bool operator!=(BigNumber num1, BigNumber num2);
bool operator>=(BigNumber num1, BigNumber num2);
bool operator>(BigNumber num1, BigNumber num2);
BigNumber operator+(BigNumber num1, BigNumber num2);
BigNumber operator+=(BigNumber &num1, BigNumber num2);
BigNumber operator-(BigNumber num1, BigNumber num2);
BigNumber operator-=(BigNumber &num1, BigNumber num2);
BigNumber operator*(BigNumber num1, BigNumber num2);
BigNumber operator*=(BigNumber &num1, BigNumber num2);
BigNumber operator/(BigNumber num1, BigNumber num2);
BigNumber operator/=(BigNumber &num1, BigNumber num2);
BigNumber operator%(BigNumber num1, BigNumber num2);
BigNumber operator%=(BigNumber &num1, BigNumber num2);
BigNumber trunc(BigNumber num);
BigNumber floor(BigNumber num);
BigNumber ceil(BigNumber num);
BigNumber sqrt(BigNumber num);
BigNumber exp(BigNumber num);
BigNumber ln(BigNumber num);
BigNumber fac(BigNumber num);
BigNumber sin(BigNumber num);
BigNumber cos(BigNumber num);
BigNumber tan(BigNumber num);
BigNumber arctan(BigNumber num);
BigNumber arccot(BigNumber num);
BigNumber arcsin(BigNumber num);
BigNumber arccos(BigNumber num);
BigNumber operator^(BigNumber num1, BigNumber num2);
BigNumber operator^=(BigNumber &num1, BigNumber num2);