#include <iostream>
using namespace std;
int main() {
//Hours , minutes , seconds in seconds
int hours , minutes , seconds;
cout << "Input the time\n";
cout << "Enter Hours ";
cin >> hours;
cout << "Enter minutes ";
cin >> minutes;
cout << "Enter seconds ";
cin >> seconds;
int time_min = (hours * 60) + minutes;
int time_sec = (time_min * 60 ) + seconds;
cout <<"Time in seconds = " << time_sec << endl;
// Seconds in Hours , minutes  , seconds
int sec2;
cout << "Enter seconds " << endl;
cin >> sec2;
int hours2 = sec2 / 3600;
int minutes2 = (sec2 % 3600) / 60;
int seconds2 = sec2 % 60;
cout << hours2 << ":" << minutes2 << ":" << seconds2 << endl;
return 0;
}
