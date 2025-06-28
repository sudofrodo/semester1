#include <iostream>
#include <time.h>
using namespace std;
enum status{WON,LOST,CONTINUE};
int rolldice(void);
int main(){
int sum;
int point;
srand(time(NULL));
enum status gameStatus;
sum = rolldice();
switch (sum) {
case 7:
case 11:
    gameStatus = WON;
    break;
case 2:
case 3:
case 12:
    gameStatus = LOST;
    break;
default:
    point = sum;
    cout << endl;
    cout << "Your point to make is " << point << endl;
    gameStatus = CONTINUE;
}
while (gameStatus == CONTINUE) {
    sum = rolldice();
    if (sum == point) {
        gameStatus = WON;
    }
    else if (sum == 7){
        gameStatus = LOST;
    }
}
if (gameStatus == WON) {

    cout << "Player wins" << endl;
}
else if (gameStatus = LOST) {

    cout << "House wins" << endl;
}

return 0;
}
int rolldice(void) {
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    int worksum = die1 + die2;
    cout << "Player rolled " << die1 << " and " << die2 <<  ". Sum = " << worksum << endl;
    return worksum;
}

