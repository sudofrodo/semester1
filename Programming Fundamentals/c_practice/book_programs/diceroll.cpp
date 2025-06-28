#include <iostream>
#include <iomanip>
#include <time.h>
//#include <bits/stdc++.h>
#define SIZE 7
using namespace std;
int main() {
int roll, face;
int frequecy[SIZE] = {0};
for (roll = 1 ; roll <= 600000 ; ++roll) {
    face = 1 + rand() % 6;
    ++frequecy[face];
}
cout << "Number    " << "Frequency" << endl;
for(int i = 1 ; i < SIZE ; i++){
    cout << i <<"           " <<  frequecy[i] << endl;
}
return 0;
}
