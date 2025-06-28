#include <iostream>
#include <string.h>
using namespace std;
int main() {
int count_emp = 0;
int num_emp = 0;
int work_hours;
string name;
int base_pay = 5000;
int pay_per_hour = 60;

cout << "Input the number of employes" << endl;
cin >> num_emp;

for (count_emp = 1 ; count_emp <= num_emp ; count_emp++){
    cout << "Input the name: " << endl;
    cin >> name;
    cout << endl;
    cout << "Input the work hours" << endl;
    cin >> work_hours;
    cout << endl;
    cout << "The salary is " << base_pay + (work_hours * pay_per_hour) << endl;
}



return 0;}
