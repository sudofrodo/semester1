#include <iostream>
using namespace std;
int main() {
int basic_salary;
cout << "Input your basic salary:";
cin >> basic_salary;
float hra = basic_salary * 10 / 100;
float da = basic_salary * 90 / 100;
float total_salary = 0;
if (basic_salary >= 1500) {
    hra = 500;
    da = basic_salary * 98 / 100;
    total_salary = basic_salary + hra + da;
    cout << "Gross salary = " << total_salary;
}
else{
    total_salary = basic_salary + hra + da;
    cout << "Gross salary = " << total_salary;
}

return 0;
}
