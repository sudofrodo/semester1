#include <iostream>
#include <iomanip>
using namespace std;
struct salaryInfo{
int employeeId;
string salaryMonth;
int basicSalary;
double houseRent;
double medicalAllowance;
double tax;
double grossSalary;
};
// initializes records for 3 months
void starter(salaryInfo month1[], salaryInfo month2[], salaryInfo month3[]);
//display employee salary data
void showData(salaryInfo month[]);
//perform monthly analysis of salary
void monthlyAnalysis(salaryInfo month[]);
//summary of total salary paid before and after tax deduction for each employee
void summary(salaryInfo month1[], salaryInfo month2[], salaryInfo month3[]);
int main() {
cout << "Name : Muhammad Athar Abbas" << endl;
cout << "Reg_no : SP25-BSE-082" << endl;
cout << "Section : SP25-A" << endl;
cout << setw(27) << setfill('=') << "=" << endl;
salaryInfo month1[5], month2[5], month3[5];
//initilaizing
starter(month1, month2, month3);
cout << endl;
//displaying data for relevant months
showData(month1);
cout << endl;
showData(month2);
cout << endl;
showData(month3);
cout << endl;
summary(month1, month2, month3);
}

void starter(salaryInfo month1[], salaryInfo month2[], salaryInfo month3[]) {
int i = 0;
for (i = 0 ; i < 5 ; i++) {
    month1[i].salaryMonth = "Janaury";
    month1[i].basicSalary = (i + 1) * 11000;
    month1[i].employeeId = i + 1;
    month1[i].houseRent = month1[i].basicSalary * 0.75;
    month1[i].medicalAllowance = month1[i].basicSalary * 0.45;
    month1[i].tax = month1[i].basicSalary * 0.05;
    double addition = month1[i].houseRent + month1[i].medicalAllowance;
    month1[i].grossSalary = month1[i].basicSalary + addition - month1[i].tax;
    }
for (i = 0 ; i < 5 ; i++) {
    month2[i].salaryMonth = "February";
    month2[i].basicSalary = (i + 1) * 12000;
    month2[i].employeeId = i + 1;
    month2[i].houseRent = month2[i].basicSalary * 0.75;
    month2[i].medicalAllowance = month2[i].basicSalary * 0.45;
    month2[i].tax = month2[i].basicSalary * 0.05;
    double addition = month2[i].houseRent + month2[i].medicalAllowance;
    month2[i].grossSalary = month2[i].basicSalary + addition - month2[i].tax;
    }
for (i = 0 ; i < 5 ; i++) {
    month3[i].salaryMonth = "March";
    month3[i].basicSalary = (i + 1) * 13000;
    month3[i].employeeId = i + 1;
    month3[i].houseRent = month3[i].basicSalary * 0.75;
    month3[i].medicalAllowance = month3[i].basicSalary * 0.45;
    month3[i].tax = month3[i].basicSalary * 0.05;
    double addition = month3[i].houseRent + month3[i].medicalAllowance;
    month3[i].grossSalary = month3[i].basicSalary + addition - month3[i].tax;
    }
}

void showData(salaryInfo month[]) {
cout << "\n============Salary Details for " << month[0].salaryMonth << "============\n\n";
cout << "ID     " << "Month       " << "    Basic    " << "    House Rent    " << "Medical   " << "    Tax   " << "       Gross Salary" << endl;
cout << setw(90) << setfill('-') << '-' << endl;
for (int i = 0 ; i < 5 ; i++) {
    cout << month[i].employeeId << " ";
    cout <<setw(12) << setfill(' ') << month[i].salaryMonth << "  ";
    cout <<setw(12) << setfill(' ') << month[i].basicSalary << "  ";
    cout <<setw(12) << setfill(' ') << month[i].houseRent << "  ";
    cout <<setw(12) << setfill(' ') << month[i].medicalAllowance<< "  ";
    cout <<setw(10) << setfill(' ') << month[i].tax << "   ";
    cout <<setw(12) << setfill(' ') << month[i].grossSalary<< endl;
}
cout << endl;
monthlyAnalysis(month);
}

void monthlyAnalysis(salaryInfo month[]) {
double total_gross_salary;
double total_tax;
for (int i = 0; i < 5; i++) {
    total_gross_salary += month[i].grossSalary;
    total_tax += month[i].tax;
}
cout << "Monthly Analysis for " << month[0].salaryMonth << ":\n";
cout << "  Total Salary paid before Tax : " << total_gross_salary - total_tax << endl;
cout << "  Total Tax Deducted :           " << total_tax << endl;
}

void summary(salaryInfo month1[], salaryInfo month2[], salaryInfo month3[]) {
cout << "\n=======3-Month Summary for Each Employee =========\n\n";
cout << "ID     Total Salary(Before Tax)       Total Tax Deducted\n";
  cout << setw(55) << setfill('-') << '-' << endl;
for (int i = 0 ; i < 5 ; i++) {
    double totalSalary = month1[i].grossSalary + month2[i].grossSalary + month3[i].grossSalary;
    double totalTax = month1[i].tax + month2[i].tax + month3[i].tax;

    cout << i + 1 << "      " << totalSalary - totalTax << "                          "<< totalTax << endl;
}
}
