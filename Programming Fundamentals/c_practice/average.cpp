#include <iostream>
using namespace std;
int main(){

    cout << "Your first number " << endl;
    int first_number;
    cin >> first_number;
    cout << "Your second number " << endl;
    int second_number;
    cin >> second_number;
    cout << "Your third number " << endl;
    int third_number;
    cin >> third_number;
    cout << "Your average is " << (first_number + second_number + third_number) / 3 << endl;
    return 0;
    }
