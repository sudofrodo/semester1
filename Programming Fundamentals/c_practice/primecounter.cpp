#include <iostream>
using namespace std;
int main() {
int num , prime_counter , bigger_prime , prime_number;
prime_counter = 0;
bigger_prime = 0;
prime_number = 0;
do {
    cout << "Enter the number ";
    cin >> num;
    while (num < 0) {
        cin.clear();
        cin.ignore();
        cout << "Enter the number ";
        cin >> num;
    }
    int factors = 0;
    for (int divider = 1 ; divider <= num ; divider++) {
    if (num % divider == 0) {
        factors++;
    }
}
    if (factors == 2) {
        prime_counter++;
        prime_number = num;
    }
    if (prime_number > bigger_prime) {
        bigger_prime = prime_number;
    }
} while ( num != 0 );
if (prime_counter != 0) {
cout << endl;
cout << "Total Numbers of Prime is  " << prime_counter << endl;
cout << "The largest prime is " << bigger_prime << endl;
}
else {
    cout << endl;
    cout << "No prime number was entered.";
}

return 0;
}
