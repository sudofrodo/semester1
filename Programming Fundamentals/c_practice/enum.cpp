#include <iostream>
using namespace std;
enum months { JAN = 1 , FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP , OCT , NOV, DEC };
int main( void) {
enum months month;
const char *monthName[] = {
    "", "January" , "February" , "March" , "April" , "May" , "June"
    , "July" , "August" , "September" , "October" , "November" , "December" };
for (int month = JAN; month <= DEC ; month++) {
    cout << month << "   " << monthName[ month ] << endl;
}
return 0;
}
