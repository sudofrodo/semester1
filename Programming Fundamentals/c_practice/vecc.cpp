#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include<algorithm>
#include<vector>
#include<string>
#include <allcards.h>
using namespace std;

#define SUITS 4
#define FACES 13
#define CARDS 52

vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;
vector <int> three_of_a_kind;
vector <int> alpha;

const int majestic_flush[5] = {1,10,11,12,13};

int consecutive_check(int arr[5]);
void shuffle(int wDeck[][FACES]);
void computer_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);

int high_card_check(const vector<vector<int>>& current_hand); //every card has unique face
int one_pair_check(const vector<vector<int>>& current_hand); // contains two same faces of different suits
int two_pair_check(const vector<vector<int>>& current_hand); // contains two pairs of same faces of different suits
int three_face_check(const vector<vector<int>>& current_hand); // contains three same faces of different suits
int straight_check(const vector<vector<int>>& current_hand); // consecutive faces of different suits
int flush_check(const vector<vector<int>>& current_hand); // all faces of same suits
int housefull_check(const vector<vector<int>>& current_hand); // pair of same faces and three same faces from different suits
int four_face_check(const vector<vector<int>>& current_hand); // contains four same faces of different suits
int straight_flush_check(const vector<vector<int>>& current_hand); // consecutive faces of same suit
int royal_flush(const vector<vector<int>>& current_hand); // 10 , Jack , Queen , King , Ace all of same suit
void player_hand_evaluator(const vector<vector<int>>& current_hand, const string& pattern, int& player_score); //evaluates player hand's rank
void hand_evaluater(const vector<vector<int>>& current_hand, int& computer_score); //evaluates rank of computer's hand;

int main() {
const char *suit[SUITS] = {"Hearts" , "Diamonds" , "Clubs" , "Spades"};
const char *face[FACES] = { "Ace", "Deuce", "Three", "Four",
"Five", "Six", "Seven", "Eight",
"Nine", "Ten", "Jack", "Queen", "King" };
int i = 0;
int player_score = 0;
int computer_score = 0;
int deck[SUITS][FACES] = {0};

srand (time(NULL));
shuffle(deck);
cout << endl;

cout << "Computer Hand : " << endl;
computer_hand(deck , face , suit);
cout << computer_cards[0][1];
cout << endl;
hand_evaluater(computer_cards, computer_score);
cout << endl;
cout << "Players Hand : " << endl;
player_hand(deck, face, suit);
cout << endl;
string pattern;
cout << "What's your pattern : ";
getline(cin , pattern);
player_hand_evaluator(player_cards ,pattern ,player_score);

cout << "Computer Score ";
cout << computer_score;
cout << endl;
cout << "Your Score ";
cout << player_score;
return 0;

}
void shuffle(int wDeck[][FACES]) {

    int row , column , card;
    for (card = 1; card <= CARDS ; ++card) {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(wDeck[row][column] != 0);
    wDeck[row][column] = card;
    }

}
void computer_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {

int card_count = 0;
// Iterate through the deck to pick the first 5 cards found (ranks 1-52)
for (int row = 0 ; row < SUITS && card_count < 5 ; ++row) {
    for (int column = 0 ; column < FACES && card_count < 5 ; ++column) {
        if (wDeck[row][column] >= 1 && wDeck[row][column] <= 5) { // Original logic picked cards 1-5

            computer_cards[card_count].push_back(row);
            computer_cards[card_count].push_back(column);
            cout << wFace[column] << " of " << wSuit[ row ] << endl;
            card_count++;
        }
    }
}
}
void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {

int card_count = 0;
// Iterate through the deck to pick the next 5 cards found (ranks 6-10)
for (int row = 0 ; row < SUITS && card_count < 5 ; ++row) {
    for (int column = 0 ; column < FACES && card_count < 5 ; ++column) {
        if (wDeck[row][column] >= 6 && wDeck[row][column] <= 10) { // Original logic picked cards 6-10

            player_cards[card_count].push_back(row);
            player_cards[card_count].push_back(column);
            cout << wFace[column] << " of " << wSuit[ row ] << endl;
            card_count++;
        }
    }
}
}



int high_card_check(const vector<vector<int>>& current_hand) {
    if (one_pair_check(current_hand)) {
        return 0;
    }
    return 1;
}
int one_pair_check(const vector<vector<int>>& current_hand) {
    int card;
    for (card = 0 ; card  <= 4 ; card++) {
        int key[2] = {current_hand[card][0] , current_hand[card][1]};
        for (int c_card = card + 1 ; c_card <= 4 ; c_card++) {
            if (key[1] == current_hand[c_card][1]) {
                return 1;
            }
        }

    }
    return 0;
}
int two_pair_check(const vector<vector<int>>& current_hand) {

    int freq[13] = {0};
    for (int i = 0 ; i < 5 ; i++) {
        freq[current_hand[i][1]]++;
    }
    int pairs = 0;
    for (int i = 0; i < 13 ; i++) {
        if (freq[i] == 2) pairs++;
    }
    return pairs == 2;
}
int three_face_check(const vector<vector<int>>& current_hand) {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            three_of_a_kind.push_back(freq[i]);
            return 1;
        }
    }
    return 0;

}
int four_face_check(const vector<vector<int>>& current_hand) {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 4) return 1;
    }
    return 0;


}

int flush_check(const vector<vector<int>>& current_hand) {
    int card;
    int suit = current_hand[0][0];
    for (card = 0 ; card  < 5 ; card++) {
            if (suit != current_hand[card][0]) {
                return 0;
            }
        }
    return 1;

}
int straight_check(const vector<vector<int>>& current_hand) {
    int face_arr[5] = {current_hand[0][1] , current_hand[1][1], current_hand[2][1], current_hand[3][1], current_hand[4][1]};
    sort(face_arr,face_arr + 5);
    int result = consecutive_check(face_arr);
    return result;

}
int consecutive_check(int arr[5]) {
    int i = 0;
    int sum = 0;
    for (i= 0 ; i < 4 ; i++) {
        if ((arr[i + 1] - arr[i]) == 1) {
            sum++;
        }
    }
    if (sum == 4) {
    return 1;
    }
    return 0;
}
int straight_flush_check(const vector<vector<int>>& current_hand) {

    if (straight_check(current_hand) && flush_check(current_hand) ) {
        return 1;
    }
    return 0;
}
int housefull_check(const vector<vector<int>>& current_hand) {
if (three_face_check(current_hand)) {
    int key = three_of_a_kind[0];
    int freq[13] = {0};
    for (int i = 0 ; i < 5 ; i++) {
        freq[current_hand[i][1]]++;
    }
    int pairs = 0;
    for (int i = 0; i < 13 ; i++) {
        if (freq[i] != key && freq[i] == 2) pairs++;
    }
    if (pairs == 1) {
        return 1;
    }
    }
    return 0;
}
int royal_flush(const vector<vector<int>>& current_hand) {
    if (flush_check(current_hand)) {
    int freq[13] = {0};
    int matches = 0;
    for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
        alpha.push_back(current_hand[i][1]);
    }
    for (int i = 0 ; i < 5; i++) {
        for(int j = 0 ; j < 5; j++) {
            if (majestic_flush[i] == alpha[j]) {
                matches++;
            }
        }
    }
    if (matches == 4) {
        return 1;
    }
    }
    return 0;
}
void hand_evaluater(const vector<vector<int>>& current_hand, int& computer_score) {
if (royal_flush(current_hand)) {
    cout << "ROYAL FLUSH" << endl;
    computer_score += 10;
}
else if (straight_flush_check(current_hand)) {
    cout << "Straight Flush" << endl;
    computer_score += 9;
}
else if (four_face_check(current_hand)) {
    cout << "Four of a Kind" << endl;
    computer_score += 8;
}
else if (housefull_check(current_hand)) {
    cout << "Houseful" << endl;
    computer_score += 7;
}
else if (flush_check(current_hand)) {
    cout << "Flush" << endl;
    computer_score += 6;
}
else if (straight_check(current_hand)) {
    cout << "Straight" << endl;
    computer_score += 5;
}
else if (three_face_check(current_hand)) {
    cout << "Three of a Kind" << endl;
    computer_score += 4;
}
else if (two_pair_check(current_hand)) {
    cout << "Two Pair" << endl;
    computer_score += 3;
}
else if (one_pair_check(current_hand)) {
    cout << "One Pair" << endl;
    computer_score += 2;
}
else {
    cout << "High Card" << endl;
    computer_score += 1;
}
}

void player_hand_evaluator(const vector<vector<int>>& current_hand, const string& pattern, int& player_score) {
    bool correct_pattern_named = false;

    if (pattern == "royalflush" && royal_flush(current_hand)) {
        player_score += 10;
        correct_pattern_named = true;
    }
    else if (pattern == "straightflush" && straight_flush_check(current_hand)) {
        player_score += 9;
        correct_pattern_named = true;
    }
    else if (pattern == "fourofakind" && four_face_check(current_hand)) {
        player_score += 8;
        correct_pattern_named = true;
    }
    else if (pattern == "fullhouse" && housefull_check(current_hand)) {
        player_score += 7;
        correct_pattern_named = true;
    }
    else if (pattern == "flush" && flush_check(current_hand)) {
        player_score += 6;
        correct_pattern_named = true;
    }
    else if (pattern == "straight" && straight_check(current_hand)) {
        player_score += 5;
        correct_pattern_named = true;
    }
    else if (pattern == "threeofakind" && three_face_check(current_hand)) {
        player_score += 4;
        correct_pattern_named = true;
    }
    else if (pattern == "twopair" && two_pair_check(current_hand)) {
        player_score += 3;
        correct_pattern_named = true;
    }
    else if (pattern == "onepair" && one_pair_check(current_hand)) {
        player_score += 2;
        correct_pattern_named = true;
    }
    else if (pattern == "highcard" && high_card_check(current_hand)){
        player_score += 1;
        correct_pattern_named = true;
    }
    else {
        cout << "You named the Wrong Pattern. 2 points will be deducted from your score." << endl;
        player_score -= 2;
    }
}

