#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void print_intro(void);
void tosser(char);
void gameplay_player(void);
void gameplay_computer(void);
int toss_result , player_score = 0 , computer_score = 0 , innings;
int main() {
srand(time(NULL));
char toss;
print_intro();
cin >> toss;
tosser(toss);
cout << endl << endl;
cout << "                                PLAY" << endl;
if (toss_result == 1) {
 gameplay_player();
 cout << endl;
 innings = 2;
 gameplay_computer();

} else {
    gameplay_computer();
    cout << endl;
    innings = 2;
    gameplay_player();
}
return 0;
}
void print_intro(void) {
cout << "                  ============Cricket on Keys=============                 " << endl;
cout << "       Welcome to Cricket on Keys. Following are the rules for this game.      " << endl;
cout << "1.First step toss . You chose Heads or tails . Winner sets the target." << endl;
cout << "2.If its your turn. You can input a number between 1 and 6. This will be added in your score " << endl
<< "3.A computer will generate number between 1 and 6. If your score equals computer's. Your innings over. " << endl;
cout << "4.Your score is target for computer. If you put the same point as computer. Computer's innings over." << endl;
cout << "5.If your score is greater than computer , you win and vice versa." << endl << endl;

cout << "                  ======== Let the Game begin ==========                 " << endl;
cout << "                                   TOSS" << endl;
cout << "Heads (h) or Tails (t) . Your call ?" << endl;
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
    toss == 'h' ? cout << "Coin says : Heads" << endl : cout << "Coin says : Tails" << endl;
    cout << "You lost the toss. Computer will set the target." << endl;
    toss_result = 0;
}
else if (inp == toss){
    toss == 't' ? cout << "Coin says : Tails" << endl : cout << "Coin says : Heads" << endl;
    cout << "You won the toss. You will set the target.";
    toss_result = 1;
}

}
void gameplay_player(void) {
    int player_point , computer_point;
    do {
    cout << "Your Point : ";
    cin >> player_point;
    computer_point = 1 + rand() % 6;
    cout << "Computer's Point : ";
    cout << computer_point;
    cout << endl << endl;
    player_score += player_point;
    if (innings == 2) {
        if (player_score > computer_score + 1) {
            cout << "You Won" << endl;
            break;
        }
    }
    } while (computer_point != player_point);
    if (computer_point == player_point) {
        player_score -= player_point;
    }
    cout << "Your score is " << player_score << endl;
    if (toss_result == 1) {
    cout << "Computer needs " << player_score + 1 << " to win." << endl;
    }
    if (player_score < computer_score) {
        cout << "You lost." << endl;
    }
    if (computer_score == player_score) {
        cout << "Match Drawn." << endl;
    }
}
void gameplay_computer() {
    int player_point , computer_point;
    do {
    cout << "Your Point : ";
    cin >> player_point;
    computer_point = 1 + rand() % 6;
    cout << "Computer's Point : ";
    cout << computer_point;
    cout << endl << endl;
    computer_score += computer_point;
    if (innings == 2) {
        if (computer_score > player_score + 1) {
            cout << "Computer Won" << endl;
            break;
        }
    }
    } while (computer_point != player_point);
    if (computer_point == player_point) {
        computer_score -= computer_point;
    }
    cout << "Computer's score is " << computer_score << endl;
    if (toss_result == 0) {
        cout << "You need " << computer_score + 1 << " to win." << endl;
    }
    if (computer_score < player_score)
    {
        cout << "You won." << endl;
    }
    if (computer_score == player_score) {
        cout << "Match Drawn." << endl;
    }
}
