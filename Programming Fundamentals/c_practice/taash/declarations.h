#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED
#include <iostream>
using namespace std;
#define SUITS 4
#define FACES 13
#define CARDS 52

int start_card = 11;
int end_card = 0;
int total_cards = 42;

vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;
vector<vector<int>> to_add_cards;
vector <int> three_of_a_kind;
vector <int> five_faces;


void discard_cards(vector<vector<int>>& current_hand,vector<vector<int>>& discard_vector ) ;
void add_card(vector<vector<int>>& current_hand,vector<vector<int>>& add_vector );
void new_cards(int wDeck[][FACES] , int start_card, int end_card, vector<vector<int>> &new_vector);
void display_player_hand(const vector<vector<int>>& current_hand, const char* wFace[], const char* wSuit[]);

const int majestic_flush[5] = {0,10,11,12,13};



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

void computer_hand_evaluater(vector<vector<int>>& current_hand, int& computer_score, int wDeck[][FACES]); //evaluates rank of computer's hand;
void player_hand_evaluater(vector<vector<int>>& current_hand, int& player_score, int wDeck[][FACES], string pattern);
void check();



#endif // DECLARATIONS_H_INCLUDED
