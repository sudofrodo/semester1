#include <iostream>
#include <iomanip>
using namespace std;
void print_intro(void);
void tosser(char);
int toss_result;
int main() {
srand(time(NULL));
char toss;
int i , player_point , computer_point , computer_score = 0 , player_score = 0;
print_intro();
cin >> toss;
tosser(toss);
cout << endl;
for (int i = 1 ; i <= 2 ; i++) {
    do {
    cout << "Your Point : ";
    cin >> player_point;
    computer_point = 1 + rand() % 6;
    cout << "Computer's Point : ";
    cout << computer_point;
    cout << endl << endl;
    if (toss_result == 1 ) {
        player_score += player_point;
    } else {
        computer_score += computer_point;
    }
    } while (computer_point != player_point);
    if (toss_result == 1 ) {
    cout << "Your score is " << player_score;
    cout << "Target for computer is << " << player_score + 1;
    } else {
    cout << "Computer's score is " << computer_score << endl;
    cout << "Your target is " << computer_score + 1 << endl;
    }
    cout << endl;
    cout << "2nd Innings" << endl;
}
return 0;}
void print_intro(void) {
cout << "                  ============Cricket on Fingers=============                 " << endl;
cout << "       Welcome to cricket on fingers. Following are the rules for this game.      " << endl;
cout << "1.First step toss . You chose Heads or tails . Winner starts the play." << endl;
cout << "2.If its your turn. You can input a number between 1 and 6. This will be added in your score " << endl
<< "3.A computer will generate number between 1 and 6. If your score equals computer's. Your innings over. " << endl;
cout << "4.Your score is target for computer. If you put the same point as computer. Computer's innings over." << endl;
cout << "5.If your score is greater than computer , you win and vice versa." << endl << endl;

cout << "                  ======== Let the Game begin ==========                 " << endl;
cout << "                                   TOSS" << endl;
cout << "Heads (h) or Tails (t) ?" << endl;
}
void tosser(char inp) {
int r = 1 + rand() % 2;
char toss;
if (r == 1) {
    toss = 'h';
} else {
    toss = 't';
}
if (inp != toss)  {
    cout << "You lost the toss. Computer will play first." << endl;
    toss_result = 0;
}
else if (inp == toss){
    cout << "You won the toss. You will play first.";
    toss_result = 1;
}
}
