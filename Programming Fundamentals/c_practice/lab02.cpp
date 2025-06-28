#include <iostream>
using namespace std;
int main() {

int total_marks = 100;


    float phy;
    cout << "Your number in Physics: ";
    cin  >> phy;
    float chem;
    cout << "Your number in Chemistry: ";
    cin >> chem;
    float bio;
    cout << "Your number in Biology: ";
    cin >> bio;
    cout << endl;
    cout << "Total marks in Phy: " << total_marks << endl;
    cout << "Total marks in Chem: " << total_marks << endl;
    cout << "Total marks in Bio: " << total_marks << endl;
    cout << endl;
    cout << "Obtained marks in Phy: " << phy << endl;
    cout << "Obtained marks in Chem: " << chem << endl;
    cout << "Obtained marks in Bio: " << bio << endl;
    cout << endl;
    cout << "Percentage in Phy: " << (phy / total_marks) * 100 <<endl;
    cout << "Percentage in Chem: " << (chem / total_marks) * 100 << endl;
    cout << "Percentage in Bio: " << (bio / total_marks) * 100 << endl;
    float obtained_total = phy + bio + chem;
    cout << endl;
    cout << "Average marks = " << obtained_total / 3 << endl;
}
//float percentage_calculator(phy,chem,bio) {
//    int total_marks = 100;
//    cout << "Total marks in Phy: " << total_marks << endl;
//    cout << "Total marks in Chem: " << total_marks << endl;
//    cout << "Total marks in Bio: " << total_marks << endl;
//    cout << "Obtained marks in Phy: " << phy << endl;
//    cout << "Obtained marks in Chem: " << chem << endl;
//    cout << "Obtained marks in Bio: " << bio << endl;
//
//}



