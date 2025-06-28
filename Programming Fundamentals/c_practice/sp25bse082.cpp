#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << setfill('=') <<setw(56)  << '=' << endl;
    cout << "               COMSATS Admission Form" << endl;
    cout << setfill('=') <<setw(56)  << '=' << endl;
    cout << right << setfill(' ') << setw(55)               <<"_ _ _ _ _ _ _" << endl;
    cout << left << setfill('_')<< setw(40) << "Full Name:"<<" |             |" << endl;
    cout << setw(40) << "Date of Birth (DD/MM/YYYY):"      <<" |    Photo    |" << endl;
    cout << setw(40) << "Gender (M/F):" <<                   " |             |" << endl;
    cout << setw(40) << "Address:"<<                         " |_ _ _ _ _ _ _|" <<endl;

    cout << setw(56) << "        _" << endl;
    cout << setw(56) <<"Phone Number:"  << endl;
    cout << setw(56) << "Email:" << endl;
    cout << setw(56) << "Course Applied For:" <<endl;
    cout << setw(56) << "Qualification:" << endl;
    cout << setw(56) << "Guardian's Name:" << endl;
    cout << setw(56) << "Guardian's Contact:" << endl;
    cout << endl;
    cout << setfill('=') <<setw(56)  << '=' << endl;
    cout << endl;
    cout << "Previous Education Record" << endl;
    cout << endl;
    cout << setfill('=') <<setw(56)  << '=' << endl;
    cout << endl;
    cout << setfill(' ')<< '|' << " Qualification " << '|' << " Institution " << '|'<< " Year " << '|' << endl;
    cout << '|' << "---------------" << '|' << "-------------" << '|' << "------" << '|' << endl;
    cout << '|' << "               " << '|' << "             " << '|' << "      " << '|' << endl;
    cout << '|' << "               " << '|' << "             " << '|' << "      " << '|' << endl;
    cout << '|' << "               " << '|' << "             " << '|' << "      " << '|' << endl;
    cout << endl;
    cout << setw(56) << setfill('_') << "Personal Statement:" << endl;
    cout << setw(56) << "_" << endl;
    cout << setw(56) << "_" << endl;
    cout << setw(56) << "_" << endl;
    cout << endl;
    cout << setw(56) << "Signature" << endl;
    cout << setw(56) << "Date:" << endl;
    cout << endl;
    cout << "Terms and Conditions applied." << endl;
    cout<< endl;
    cout << setfill('=') <<setw(56)  << '=' << endl;
//    cout << left << setw(15) << "Pakistan" << setfill('_') << endl;

return 0;
}
