#include <iostream>
using namespace std;
int main() {
string qualif , gender;
int yos;
cout << "Gender: ";
cin >> gender;
cout << "Years of Service: ";
cin >> yos;
cout << "Qualification: ";
cin >> qualif;
if (gender == "Male") {
    if (yos >= 10  && qualif == "Post-Graduate") {
        cout << "Salary = 15000" << endl;
    }
    else if (yos >= 10 || yos < 10 && qualif == "Graduate" || qualif == "Post-Graduate" ) {
        cout << "Salary = 10000" << endl;
    }
//    else if (yos < 10 && qualif == "Post-Graduate"){
//        cout << "Salary = 10000" << endl;
//
//    }
    else if (yos < 10 && qualif == "Graduate") {
        cout << "Salary = 7000" << endl;
    }
    }
else if (gender == "Female") {
    if (yos >= 10  && qualif == "Post-Graduate") {
        cout << "Salary = 12000" << endl;
    }
    else if (yos >= 10 && qualif == "Graduate") {
        cout << "Salary = 9000" << endl;
    }
    else if (yos < 10 && qualif == "Post-Graduate"){
        cout << "Salary = 10000" << endl;

    }
    else if (yos < 10 && qualif == "Graduate") {
        cout << "Salary = 6000" << endl;
    }

}




return 0;
}
