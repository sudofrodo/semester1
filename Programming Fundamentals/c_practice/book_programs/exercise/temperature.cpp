#include <iostream>
#include <iomanip>
using namespace std;
double farenheit_celcius(int temp);
double celcius_farenheit(int temp);

int main() {
int i = 0;
int j = 0;
cout << "        Farenhiet to Celcius" << endl;
cout << "Farenheit               Celcius" << endl;
for (i = 32 ; i <= 212 ; i++) {
    cout << i << "   :   " << left << setprecision(3) << farenheit_celcius(i) << "     ";
    if (i % 8 == 0) {
        cout << endl << endl;
    }
}
cout << endl;
cout << "        Celcius to farenheit" << endl;
cout << "Celcius                 Farenheit" << endl;
for (i = 1 ; i <= 100 ; i++) {
    cout << i << "   :   " << left << setprecision(3) << celcius_farenheit(i) << "     ";
    if (i % 8 == 0) {
        cout << endl << endl;
    }
}

return 0;
}
double farenheit_celcius(int temp) {
return (temp - 32) / 1.8;
}
double celcius_farenheit(int temp) {
return (temp * 1.8) + 32;
}
