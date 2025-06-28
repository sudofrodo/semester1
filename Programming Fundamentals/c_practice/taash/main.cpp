#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include<algorithm>
#include<vector>
#include<string>
#include "declarations.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

vector<vector<int>> discard_vector;
using namespace std;

int main() {
const char *suit[SUITS] = {"Hearts" , "Diamonds" , "Clubs" , "Spades"};
const char *face[FACES] = { "Ace", "Deuce", "Three", "Four",
"Five", "Six", "Seven", "Eight",
"Nine", "Ten", "Jack", "Queen", "King" };

int turn_count = 0;
int player_score = 0 , computer_score = 0;
string pattern;
int deck[SUITS][FACES] = {0};
srand (time(NULL));
shuffle(deck);
cout << "Computer's hand : " << endl;
computer_hand(deck, face, suit);
cout << endl;
cout << "Player's hand : " << endl;
player_hand(deck, face , suit);
computer_hand_evaluater(computer_cards,computer_score,deck);
while (total_cards > 0){
cout << endl;
cout << "Cards Left : "<< total_cards<<  endl;
cout << "Computer's Point : " ;
computer_hand_evaluater(computer_cards,computer_score,deck);
display_player_hand(player_cards,face,suit);
cout << "What's your Pattern : ";
cin >> pattern;
player_hand_evaluater(player_cards,player_score,deck,pattern);

cout << endl;

}
cout << "Your score : " << player_score;
cout << "Computer score : " << computer_score;
//cout << "hand before evaluation : " << endl;
//for(int i = 0; i < computer_cards.size(); i++) {
//    cout << computer_cards[i][0] << " " << computer_cards[i][1] << endl;
//
//}
//
//hand_evaluater(computer_cards, computer_score, deck);
//cout << "hand after evaluation : " << endl;
//cout << endl <<"Size of Vector " << computer_cards.size() << endl;
//for(int i = 0; i < computer_cards.size(); i++) {
//    cout << computer_cards[i][0] << " " << computer_cards[i][1] << endl;
//}
//cout << "new cards" << endl;
//
//for(int i = 0; i < to_add_cards.size(); i++) {
//    cout << to_add_cards[i][0] << " " << to_add_cards[i][1] << endl;
//}
//
//hand_evaluater(computer_cards, computer_score, deck);
//cout << "after adding new cards" << endl;
//for(int i = 0; i < computer_cards.size(); i++) {
//    cout << computer_cards[i][0] << " " << computer_cards[i][1] << endl;
//}
//cout << endl;
//cout << "player cards" << endl;
//player_hand(deck, face, suit);
return 0;

}

void shuffle(int wDeck[][FACES
             ]) {

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
                computer_cards.push_back({row, column});
                cout << wFace[column] << " of " << wSuit[ row ] << endl;
                i++;
            }
        }
    }
}
}

void display_player_hand(const vector<vector<int>>& current_hand, const char* wFace[], const char* wSuit[]) {
    cout << "Your Cards :" << endl;
    for (const auto& card : current_hand) {
        int suit = card[0];
        int face = card[1];
        cout << wFace[face] << " of " << wSuit[suit] << endl;
    }

}


void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {

int row, column , card;
int i = 0;
for (card = 6 ; card <= 10 ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                player_cards.push_back({row, column});
                i++;
                cout << wFace[column] << " of " << wSuit[ row ] << endl;

            }
        }
    }
}
}
void new_cards(int wDeck[][FACES],int start_card, int end_card, vector<vector<int>> &new_vector) {
int row, column , card;
int i = 0;
for (card = start_card ; card <= end_card ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                new_vector.push_back({row, column});
                i++;
            }
        }
    }
}
}
void discard_cards(vector<vector<int>>& current_hand,vector<vector<int>>& discard_vector ) {
vector<vector<int>> to_remove;
for (const auto& dcard : discard_vector) {
    for (const auto& ccard : current_hand) {
        if (ccard[1] == dcard[1]) {
            to_remove.push_back(ccard);
        }
    }
}
for (const auto& card : to_remove) {
    current_hand.erase(remove(current_hand.begin(), current_hand.end(), card), current_hand.end());
}

}
void add_card(vector<vector<int>>& current_hand,vector<vector<int>>& add_vector ) {

for (size_t card = 0 ; card < add_vector.size() ; card++) {
    current_hand.push_back(add_vector[card]);

}
}
using namespace std;
int high_card_check(const vector<vector<int>>& current_hand) {
    if (one_pair_check(current_hand)) {
        return 0;
    };
    discard_vector.push_back(current_hand[0]);
    return 1;
}
int one_pair_check(const vector<vector<int>>& current_hand) {
    for (int card = 0; card < 4; ++card) {
        for (int c_card = card + 1; c_card < 5; ++c_card) {
            if (current_hand[card][1] == current_hand[c_card][1]) {
                discard_vector.push_back(current_hand[card]);
                discard_vector.push_back(current_hand[c_card]);
                return 1;
            }
        }
    }
    return 0;
}
int two_pair_check(const vector<vector<int>>& current_hand) {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
    }

    int pairs = 0;
    vector<int> pair_ranks;
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 2) {
            pairs++;
            pair_ranks.push_back(i); //stores rank only if it appears two times.
        }
    }
    if (pairs == 2) {
        for (int i = 0; i < 5; i++) {
            int rank = current_hand[i][1];
            if (rank == pair_ranks[0] || rank == pair_ranks[1]) {
                discard_vector.push_back(current_hand[i]);
            }
        }
        return 1;
    }

    return 0;
}

int three_face_check(const vector<vector<int>>& current_hand) {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            three_of_a_kind.push_back(freq[i]);
            for (int j = 0 ; j < 5 ; j++) {
                if(current_hand[j][1] == i) {
                    discard_vector.push_back(current_hand[j]);
                }
            }
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
        if (freq[i] == 4) {
            for (int j = 0 ; j < 5 ; j++) {
                if(current_hand[j][1] == i) {
                    discard_vector.push_back(current_hand[j]);
                }
            }
        return 1;
        }

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
        five_faces.push_back(current_hand[i][1]);
    }
    for (int i = 0 ; i < 5; i++) {
        for(int j = 0 ; j < 5; j++) {
            if (majestic_flush[i] == five_faces[j]) {
                matches++;
            }
        }
    }
    if (matches == 5) {
        return 1;
    }
    }
    return 0;
}


void computer_hand_evaluater(vector<vector<int>>& current_hand, int& computer_score, int wDeck[][FACES]) {

//if (total_cards < discard_vector.size()) {
//    cout << "Not enough cards.";
//    to_exit = true;
//    return;
//}
if (royal_flush(current_hand)) {
    cout << "ROYAL FLUSH" << endl;
    computer_score += 10;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
    start_card = end_card + 1;
    add_card(current_hand,to_add_cards);

}
else if (straight_flush_check(current_hand)) {
    cout << "Straight Flush" << endl;
    computer_score += 9;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
     to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
        start_card = end_card = end_card + 1;
    add_card(current_hand,to_add_cards);
}
else if (four_face_check(current_hand)) {
    cout << "Four of a Kind" << endl;
    computer_score += 8;
    discard_cards(current_hand, discard_vector);
    end_card = start_card + 3;
     to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
        start_card = end_card + 1;

    add_card(current_hand,to_add_cards);
    total_cards -= 4;
    discard_vector.clear();
}
else if (housefull_check(current_hand)) {
    cout << "Houseful" << endl;
    computer_score += 7;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
 to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);

       start_card = end_card + 1;
    add_card(current_hand,to_add_cards);
}
else if (flush_check(current_hand)) {
    cout << "Flush" << endl;
    computer_score += 6;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
     to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
        start_card = end_card + 1;
    add_card(current_hand,to_add_cards);
}
else if (straight_check(current_hand)) {
    cout << "Straight" << endl;
    computer_score += 5;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    new_cards(wDeck,start_card,end_card,to_add_cards);
       start_card = end_card + 1;
    add_card(current_hand,to_add_cards);
}
else if (three_face_check(current_hand)) {
    cout << "Three of a Kind" << endl;
    computer_score += 4;
    discard_cards(current_hand, discard_vector);
    end_card = start_card + 2;
     to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
       start_card = end_card + 1;
    add_card(current_hand,to_add_cards);
    total_cards -= 3;
    discard_vector.clear();
}
else if (two_pair_check(current_hand)) {
    cout << "Two Pair" << endl;
    computer_score += 3;
    discard_cards(current_hand, discard_vector);
    end_card = start_card + 3;
    new_cards(wDeck,start_card,end_card,to_add_cards);
        start_card = end_card + 1;
     to_add_cards.clear();
    add_card(current_hand,to_add_cards);
    total_cards -= 4;
    discard_vector.clear();

}
else if (one_pair_check(current_hand)) {
    cout << "One Pair" << endl;
    computer_score += 2;
    discard_cards(current_hand, discard_vector);
    end_card = start_card + 1;
     to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
    start_card = end_card + 1;
    add_card(current_hand,to_add_cards);
     total_cards -= 2;
    discard_vector.clear();
}
else if (high_card_check(current_hand)) {
    cout << "High Card" << endl;
    computer_score += 1;
    discard_cards(current_hand, discard_vector);
    end_card = start_card;
    to_add_cards.clear();
    new_cards(wDeck,start_card,end_card,to_add_cards);
    start_card = end_card + 1;
    add_card(current_hand,to_add_cards);
     total_cards -= 1;
    discard_vector.clear();

}
else {
    throw "error";
}
}

void player_hand_evaluater(vector<vector<int>>& current_hand, int& player_score, int wDeck[][FACES], string pattern) {
//    if (total_cards < discard_vector.size()) {
//    cout << "Not enough cards.";
//    to_exit = true;
//    return;
//}
if (pattern == "royalflush" && royal_flush(current_hand)) {

        player_score += 10;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
    }
    else if (pattern == "straightflush" && straight_flush_check(current_hand)) {

        player_score += 9;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
    }
    else if (pattern == "fourofakind" && four_face_check(current_hand)) {

        player_score += 8;
        discard_cards(current_hand, discard_vector);
        end_card = start_card + 3;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
        total_cards -= discard_vector.size();
        discard_vector.clear();
    }
    else if (pattern == "fullhouse" && housefull_check(current_hand)) {

        player_score += 7;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
    }
    else if (pattern == "flush" && flush_check(current_hand)) {

        player_score += 6;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
    }
    else if (pattern == "straight" && straight_check(current_hand)) {

        player_score += 5;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
    }
    else if (pattern == "threeofakind" && three_face_check(current_hand)) {

        player_score += 4;
        discard_cards(current_hand, discard_vector);
        end_card = start_card + 2;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
        total_cards -= discard_vector.size();
        discard_vector.clear();
    }
    else if (pattern == "twopair" && two_pair_check(current_hand)) {

        player_score += 3;
        discard_cards(current_hand, discard_vector);
        end_card = start_card + 3;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
        total_cards -= discard_vector.size();
        discard_vector.clear();
    }
    else if (pattern == "onepair" && one_pair_check(current_hand)) {

        player_score += 2;
        discard_cards(current_hand, discard_vector);
        end_card = start_card + 1;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
        total_cards -= discard_vector.size();
        discard_vector.clear();
    }
    else if (pattern == "highcard" && high_card_check(current_hand)) {

        player_score += 1;
        discard_cards(current_hand, discard_vector);
        end_card = start_card;
        to_add_cards.clear();
        new_cards(wDeck, start_card, end_card, to_add_cards);
        start_card = end_card + 1;
        add_card(current_hand, to_add_cards);
        total_cards -= discard_vector.size();
        discard_vector.clear();
    }
    else {
        cout << "You have entered the wrong pattern , 2 points will be deducted from your score.";
        player_score -= 2;
    }
}


