#include <iostream>
#include <iomanip>
using namespace std;
int comparechars(char a , char b);
int main() {
cout << "Athar Abbas" << endl;
cout << "Sp25 - bse - 082" << endl;
cout << "Section A" << endl;
cout << setw(27) << setfill('=') << '=' << endl;
cout << endl;
cout << "Press '=' to quit. " << endl << endl;
char char1;
char char2;
do{
cout << endl;
cout << "Input first character ";
cin >> char1;
cout << "Input second character ";
cin >> char2;
cout << endl;
cout << comparechars(char1,char2) << endl;
} while (char1 != '=');
return 0;
}
int comparechars(char a , char b){

    if ((int(tolower(a)) < 97) || (int((tolower(a)) > 122 )) || ((int(tolower(b))) < 97 || (int(tolower(a)) > 122)))
   {
        return 99;
    }
    else if (tolower(a) > tolower(b)) {
        return 1;
    }
    else if (tolower(a) == tolower(b)) {
        return 0;
    }
    else if (tolower(b) > tolower(a)) {
        return -1;
}

    }

