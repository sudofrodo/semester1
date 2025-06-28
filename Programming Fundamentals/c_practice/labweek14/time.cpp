#include <iostream>
using namespace std;
struct TimeStruct_t {
    int hours;
    int minutes;
    string meridiem;
};
void get_time(TimeStruct_t *user_time);
void display_time(TimeStruct_t user_time);
void tic(TimeStruct_t *tptr);
int main() {
typedef TimeStruct_t time;
time my_time;
my_time.hours = 12;
time *tptr = &my_time;
(*tptr).minutes = 34;
tptr->meridiem = "am";
//cout << my_time.hours << ":" << my_time.minutes << " ";
//cout << my_time.meridiem << endl;
time user_time;
time *uptr = &user_time;
get_time(&user_time);
display_time(user_time);
tic(&user_time);
cout << "Ticed" << endl;
display_time(user_time);
return 0;
}
void display_time(TimeStruct_t user_time) {
    cout << "Your time : " << user_time.hours << ":";
    cout << user_time.minutes << " " << user_time.meridiem << endl;
}
void get_time(TimeStruct_t *user_time) {
    cout << "Please enter hours: (12 hour format) : ";
cin >> user_time->hours;
cout << endl;
cout << "Enter minutes : ";
cin >> user_time->minutes;
cout << endl;
cout << "Enter meridiem (am/pm) : ";
cin >> user_time->meridiem;
}
void tic(TimeStruct_t *tptr) {
    if (tptr->minutes == 59) {
        if (tptr->hours == 11) {
        if (tptr->meridiem == "am") {
                tptr->meridiem = "pm";
        } else {
                tptr->meridiem = "am";
        }
        }
        tptr->minutes = 00;
        if (tptr->hours == 12) {
            tptr->hours = 1;
        }
        else {
        tptr->hours += 1;
        }
    } else {
    tptr->minutes += 1;
    }
}
