#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
int main() {
string name;
cout << "Input Name" << endl;
getline(cin,name);
float gross_pay;
cout << "Input Gross pay" << endl;
cin >> gross_pay;
cout << endl << endl;
float federal_tax = gross_pay  * 0.15;
float state_tax = gross_pay  * 0.035;
float social_security_tax = gross_pay  * 0.0575;
float medicare_tax = gross_pay  * 0.0275;
float pension_plan = gross_pay  * 0.05;
float health_insurance = 75.00;
float total_cut = federal_tax + state_tax + social_security_tax + medicare_tax + pension_plan + health_insurance;
cout << name << endl;
cout << setw(27) << left << setfill('.') << "Gross Amount: " << right << setw(2)  << setfill(' ') << '$'<< fixed << setprecision(2)<<setw(7) << gross_pay << endl;
cout << setw(27) << left << setfill('.') << "Federal Tax: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << federal_tax<< endl;
cout << setw(27) << left << setfill('.') << "State Tax: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << state_tax<< endl;
cout << setw(27) << left << setfill('.') << "Social Security Tax: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << social_security_tax<< endl;
cout << setw(27) << left << setfill('.') << "Medicare/Medicaid Tax: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << medicare_tax<< endl;
cout << setw(27) << left << setfill('.') << "Pension Plan: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << pension_plan<< endl;
cout << setw(27) << left << setfill('.') << "Health Insurance: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << health_insurance<< endl;
cout << setw(27) << left << setfill('.') << "Net Pay: " << right << setw(2) << setfill(' ') << '$'<<setw(7) << gross_pay - total_cut << endl;
}
