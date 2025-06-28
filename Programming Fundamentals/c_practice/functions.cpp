#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void message();
int roll_no_generator(int students , int division);
int n_abs(int x);
int main() {

roll_no_generator (154,3);
message();
cout << n_abs(-2) << endl;
return 0;}
void message() {
cout << "Hello world" << endl;
}
int n_abs(int x) {
if ( x < 0){
    return -x;
} else{
        return x;
}
}
int roll_no_generator(int students , int division) {
int i = 0;
int nlist = 0;
for (i = 1 ; i<= students ; i=i+3) {
    cout << setw(3) << setfill('0') << i << endl;
    nlist += i;
}
return nlist;

}


