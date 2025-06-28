#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include<algorithm>
#include<vector>
using namespace std;

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(int wDeck[][FACES]);
void deal(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void computer_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
int consecutive_check(int arr[5]);
int majestic_flush[5] = {1,10,11,12,13};
int computer_cards[5][2] = {0};
int player_cards[5][2] = {0};
vector <int> three_of_a_kind = {0};
vector <int> alpha = {0};

int one_pair_check(int hand[][2]); // contains two same faces of different suits
int two_pair_check(int hand[5][2]); // contains two pairs of same faces of different suits
int three_face_check(int hand[5][2]); // contains three same faces of different suits
int straight_check(int hand[][2]); // consecutive faces of different suits
int flush_check(int hand[5][2]); // all faces of same suits
int housefull_check(int hand[][2]); // pair of same faces and three same faces from different suits
int four_face_check(int hand[5][2]); // contains four same faces of different suits
int straight_flush_check(int hand[][2]); // consecutive faces of same suit
int royal_flush(int hand[][2]); // 10 , Jack , Queen , King , Ace all of same suit
void hand_evaluater(int hand[][2]); //evaluates rank of hand;
int main() {
const char *suit[SUITS] = {"Hearts" , "Diamonds" , "Clubs" , "Spades"};
const char *face[FACES] = { "Ace", "Deuce", "Three", "Four",
"Five", "Six", "Seven", "Eight",
"Nine", "Ten", "Jack", "Queen", "King" };
int deck[SUITS][FACES] = {0};
srand (time(NULL));
shuffle(deck);
cout << endl;
computer_hand(deck , face , suit);
cout << endl;
hand_evaluater(computer_cards);
cout << endl;
player_hand(deck, face, suit);
cout << endl;
hand_evaluater(player_cards);


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

int row, column , card;
int i = 0;
for (card = 1 ; card <= 5 ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                computer_cards[i][0] = row;
                computer_cards[i][1] = column;
                i++;
                cout << wFace[column] << " of " << wSuit[ row ] << endl;

            }
        }
    }
}
}
void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {

int row, column , card;
int i = 0;
for (card = 6 ; card <= 10 ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                player_cards[i][0] = row;
                player_cards[i][1] = column;
                i++;
                cout << wFace[column] << " of " << wSuit[ row ] << endl;

            }
        }
    }
}
}
int one_pair_check(int hand[5][2]) {
    int card;
    for (card = 0 ; card  <= 4 ; card++) {
        int key[2] = {hand[card][0] , hand[card][1]};
        for (int c_card = card + 1 ; c_card <= 4 ; c_card++) {
            if (key[1] == hand[c_card][1]) {
                return 1;
            }
        }

    }
    return 0;
}

int two_pair_check(int hand[5][2]) {
    int freq[13] = {0};
    for (int i = 0 ; i < 5 ; i++) {
        freq[hand[i][1]]++;
    }
    int pairs = 0;
    for (int i = 0; i < 13 ; i++) {
        if (freq[i] == 2) pairs++;
    }
    return pairs == 2;
}
int three_face_check(int hand[5][2]) {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            three_of_a_kind.push_back(freq[i]);
            return 1;
        }
    }
    return 0;

}
int four_face_check(int hand[5][2]) {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 4) return 1;
    }
    return 0;

}
int flush_check(int hand[5][2]) {
    int counter = 0 ;
    int card;
    int suit = hand[0][0];
    for (card = 0 ; card  < 5 ; card++) {
            if (suit != hand[card][0]) {
                return 0;
            }
        }
    return 1;
}
int straight_check(int hand[][2]) {
    int card;
    int face_arr[5] = {hand[0][1] , hand[1][1], hand[2][1], hand[3][1], hand[4][1]};
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
int straight_flush_check(int hand[][2]) {
    if (straight_check(hand) && flush_check(hand) ) {
        return 1;
    }
    return 0;
}
int housefull_check(int hand[][2]) {
    if (three_face_check(hand)) {
    int key = three_of_a_kind[0];
    int freq[13] = {0};
    for (int i = 0 ; i < 5 ; i++) {
        freq[hand[i][1]]++;
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
int royal_flush(int hand[][2]) {
    if (flush_check(hand)) {
    int freq[13] = {0};
    int matches = 0;
    for (int i = 0; i < 5; i++) {
        freq[hand[i][1]]++;
        alpha.push_back(hand[i][1]);
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
void hand_evaluater(int hand[][2]) {
    if (royal_flush(hand)) {
    cout << "ROYAL FLUSH" << endl;
}
else if (straight_flush_check(hand)) {
    cout << "Straight Flush" << endl;
}
else if (straight_check(hand)) {
    cout << "Straight" << endl;
}
else if (flush_check(hand)) {
    cout << "Flush" << endl;
}
else if (four_face_check(hand)) {
    cout << "Four of a Kind" << endl;
}
else if (housefull_check(hand)) {
    cout << "Houseful" << endl;
}
else if (three_face_check(hand)) {
    cout << "Three of a Kind" << endl;
}
else if (two_pair_check(hand)) {
    cout << "Two Pair" << endl;
}
else if (one_pair_check(hand)) {
    cout << "One Pair" << endl;
}
else {
    cout << "High Card" << endl;
}
cout << endl;
}
