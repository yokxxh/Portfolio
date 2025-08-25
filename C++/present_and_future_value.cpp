#include <iostream>
#include <cmath>
#include <string>
#include <string_view>


double getin(std::string_view a)
{
 double temp{};
 while(true){
 std::cout << " Enter " << a << ": ";
 std::cin >> temp;

if (temp >= 0){  break;}
else{ std::cout << "Please enter non negative integers!\n";}
 }

return temp;
}

bool choice()
{
    bool tmp{};
    std::cout << "What do you want to calculate Present Value or Future Value?\n";
    std::cout << "For Present value enter 0 , for Future value enter 1: ";
    std::cin >> tmp;

    return tmp;
}

double calc(double c, double r, int t, bool cond)
{            // c=capital, r=interest rate, t=time period, cond=isFutureValue 
if(cond)
{
    return c * (pow((1 + r), t));
}
else
{
    return c / (pow((1 + r), t));
}
}

int main(){

    double capital{getin("Capital Amount")};
    double rate(getin("Interest Rate"));
    rate /= 100;
    int time(static_cast<int>(getin("Time Period")));
    bool ch = choice();

    std::cout << "\nThe value is " << calc(capital,rate,time,ch);

    return 0;


}
