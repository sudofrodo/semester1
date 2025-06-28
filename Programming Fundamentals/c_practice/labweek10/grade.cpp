#include <iostream>
#include <iomanip>
using namespace std;
char grade(int marks);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << "Press -1 to quit." << endl;
int num;
while (num != -1) {
cout << "Input marks (0-100)" << endl;
cin >> num;
    while (num > 100 || num < -1) {
        cin.clear();
        cin.ignore();
        cout << "Input marks (0-100)" << endl;
        cin >> num;
    }

cout << "Grade :
     "<< grade(num) << endl;
} ;
return 0;
}
char grade(int marks) {

    if (marks >= 0 && marks <= 49 ) {
        return 'F';
    }
    else if (marks >= 50 && marks <= 60){
        return 'E';
    }
    else if (marks >= 61 && marks <= 70) {
        return 'D';
    }
    else if (marks >= 71 && marks <= 80) {
        return 'C';
    }
    else if (marks >= 81 && marks <= 90) {
        return 'B';
    }
    else if (marks >= 91 && marks <= 100){
        return 'A';
    };

}
