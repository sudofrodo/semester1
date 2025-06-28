#include <iostream>
#include <iomanip>
using namespace std;
void asteriksquare(int num);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << "Press -1 to quit." << endl;
int num;
do{
cout << "Input the number for asterik square : ";
cin >> num;
cout << endl;
asteriksquare(num);
cout << endl;
} while (num != -1);
return 0;
}
void asteriksquare(int num) {

    int i = 0;
    int j = 0;
    for (i ; i < num ; i++) {
        for(j = 0; j < num ; j++) {
                cout << '*';
        }
        cout << endl;
    }
}
