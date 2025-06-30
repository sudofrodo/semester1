#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <map>

using namespace std;

int start_card = 11;
int end_card = 0;
int total_cards = 42;

#define SUITS 4
#define FACES 13
#define CARDS 52


vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;

void shuffle(int wDeck[][FACES]);
void computer_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void cards_adder(vector<vector<int>>& current_hand, int wDeck[][FACES] , int start_card, int end_card);
void discarder(vector<vector<int>>& current_hand, string check_pattern);

// patterns:

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

// evaluaters:

void computer_hand_evaluater(vector<vector<int>>& current_hand, int& computer_score, int wDeck[][FACES]); //evaluates rank of computer's hand;
void player_hand_evaluater(vector<vector<int>>& current_hand, int& player_score, int wDeck[][FACES], string pattern);

string getRankString(int face_idx);
string getSuitString(int suit_idx);
void clear_screen();
std::vector<std::string> buildCard(const std::string& rank_str, const std::string& suitName);
void displayCardsInRow(const std::vector<std::vector<std::string>>& cards_art, const std::vector<std::vector<int>>& cards_data);
void display_hand_ascii_art(const std::vector<std::vector<int>>& hand, const std::string& title);
void display_intro_and_rules();
void card_art();
map<string, string> suitSymbols = {
    {"Hearts", "♥"},
    {"Diamonds", "♦"},
    {"Clubs", "♣"},
    {"Spades", "♠"}
};


std::map<int, std::string> fullRankNames = {
    {0, "Ace"}, {1, "Two"}, {2, "Three"}, {3, "Four"},
    {4, "Five"}, {5, "Six"}, {6, "Seven"}, {7, "Eight"},
    {8, "Nine"}, {9, "Ten"}, {10, "Jack"}, {11, "Queen"},
    {12, "King"}
};

void display_ascii_art_logo() {
    cout << "//                      _                                 _      " << endl;
    cout << "//                     | |                               | |     " << endl;
    cout << "//     ___ __ _ _ __ __| |___       _ __ ___  _   _  __ _| | ___ " << endl;
    cout << "//    / __/ _` | '__/ _` / __|     | '__/ _ \\| | | |/ _` | |/ _ \\" << endl;
    cout << "//   | (_| (_| | | | (_| \\__ \\     | | | (_) | |_| | (_| | |  __/" << endl;
    cout << "//    \\__\\__,_|_|  \\__,_|___/      |_|  \\___/ \\__, |\\__,_|_|\\___|" << endl;
    cout << "//                                             __/ |             " << endl;
    cout << "//                                            |___/              " << endl;
}
