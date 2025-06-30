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

struct state{
    vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;
int start_card = 11;
int end_card = 0;
int total_cards = 42;
int deck[SUITS][FACES];


};

vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;

void shuffle(int wDeck[][FACES]);
void computer_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]);
void cards_adder(vector<vector<int>>& current_hand, int wDeck[][FACES] , int start_card, int end_card);
void discarder(vector<vector<int>>& current_hand, string check_pattern);
int score_checker(const vector<vector<int>>& current_hand, string check_pattern);
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


int main() {
const char *suit[SUITS] = {"Hearts" , "Diamonds" , "Clubs" , "Spades"};
const char *face[FACES] = { "Ace", "Deuce", "Three", "Four",
"Five", "Six", "Seven", "Eight",
"Nine", "Ten", "Jack", "Queen", "King" };

display_ascii_art_logo();
cout << endl;
display_intro_and_rules();
int player_score = 0 , computer_score = 0;
string pattern;
int deck[SUITS][FACES] = {0};
srand (time(NULL));
shuffle(deck);
computer_hand(deck, face, suit);
player_hand(deck, face , suit);
//
//vector <vector<int>> t_hand = {{2,13},{2,12},{1,11},{3,11},{2,9}};
//cout << "Size of vector : " << t_hand.size() << endl;
//cout << "Cards : " << t_hand[0][0] << "  " << t_hand[0][1] << endl;
//computer_hand_evaluater(t_hand,player_score,deck);
//cout << "Size of vector : " << t_hand.size() << endl;
//for (int i = 0 ; i <= 4 ; i++) {
//    cout << "Card[" << i << "] " << t_hand[i][0] << "  " << t_hand[i][1] << endl;
//}
//cout << "Cards : " << t_hand[0][0] << "  " << t_hand[0][1] << "  2nd card  "<< t_hand[1][0] << "  " << t_hand[1][1] << endl;
while (total_cards > 0){
card_art();

cout << endl;

cout << "Cards Left : "<< total_cards<<  endl;
cout << "Computer's Point : " ;
computer_hand_evaluater(computer_cards,computer_score,deck);

display_hand_ascii_art(player_cards, "Player Cards");
cout << "What's your Pattern (e.g., 'royalflush', 'straightflush', 'fourofakind', 'fullhouse', 'flush', 'straight', threeofakind', 'twopair', 'onepair', 'highcard') : ";
cin >> pattern;
player_hand_evaluater(player_cards,player_score,deck,pattern);
clear_screen();
cout << endl;

}
cout << "Result : " << endl;
cout << "Your score : " << player_score << endl;
cout << "Computer score : " << computer_score << endl;
if (player_score > computer_score) {
    cout << "YOU WON!!!" << endl;
} else if (computer_score == player_score) {
     cout << "Its a Draw!" << endl;
} else {
    cout << "You lost!" << endl;
}
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
for (card = 1 ; card <= 5 ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                computer_cards.push_back({row, column});
            }
        }
    }
}
}


void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {

int row, column , card;
for (card = 6 ; card <= 10 ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                player_cards.push_back({row, column});
            }
        }
    }
}
}


int high_card_check(const vector<vector<int>>& current_hand) {
    if (one_pair_check(current_hand)) {
        return 0;
    };
    return 1;
}
int one_pair_check(const vector<vector<int>>& current_hand) {
    for (int card = 0; card < 4; ++card) {
        for (int c_card = card + 1; c_card < 5; ++c_card) {
            if (current_hand[card][1] == current_hand[c_card][1]) {
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
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 2) {
            pairs++;
        }
    }
    if (pairs == 2) {
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
    int i = 0  , sum = 0;
    for (i= 0 ; i < 4 ; i++) {
        if ((face_arr[i + 1] - face_arr[i]) == 1) {
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
    int key = 0;
    int freq[13] = {0};
    for (int i = 0 ; i < 5 ; i++) {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            int key = freq[i];
        }
    }
    int pairs = 0;
    for (int i = 0; i < 13 ; i++) {
        if (freq[i] != key && freq[i] == 2) pairs++;
    }
    if (pairs == 1) {
        return 1;
    }
    return 0;
    }
    return 0;
}


int royal_flush(const vector<vector<int>>& current_hand) {
    vector <int> five_faces;
    const int majestic_flush[5] = {0,10,11,12,13};
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
        five_faces.clear();
        return 1;
    }
    }
    five_faces.clear();
    return 0;
}
void discarder(vector<vector<int>>& current_hand, string check_pattern) {
vector<vector<int>> discard_vector;
if (check_pattern == "highcard") {
    int _max = 0;
    for (int card = 0; card < 5; ++card) {
        if (current_hand[card][1] > _max) {
            _max = current_hand[card][1];
        }
}
     for (int card = 0; card < 5; ++card) {
            if (_max == current_hand[card][1]) {
                discard_vector.push_back(current_hand[card]);
            }
      }
}

if (check_pattern == "onepair") {
    for (int card = 0; card < 4; ++card) {
      for (int c_card = card + 1; c_card < 5; ++c_card) {
            if (current_hand[card][1] == current_hand[c_card][1]) {
                discard_vector.push_back(current_hand[card]);
                discard_vector.push_back(current_hand[c_card]);
            }
      }
    }

}
if (check_pattern == "twopair") {
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
}

}
if (check_pattern == "fourofakind") {
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
}
}
}
if (check_pattern == "threeofakind") {
    int freq[13] = {0};
    for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 3) {
            for (int j = 0 ; j < 5 ; j++) {
                if(current_hand[j][1] == i) {
                    discard_vector.push_back(current_hand[j]);
                }
            }
}
}
}
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

void cards_adder(vector<vector<int>>& current_hand, int wDeck[][FACES] , int start_card, int end_card){
vector<vector<int>> new_vector;
int row, column , card;
for (card = start_card ; card <= end_card ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                new_vector.push_back({row, column});
            }
        }
    }
}
for (size_t card = 0 ; card < new_vector.size() ; card++) {
    current_hand.push_back(new_vector[card]);
}
}

int score_checker(const vector<vector<int>>& current_hand, string check_pattern) {
int score = 0;
int freq[13] = {0};
for (int i = 0; i < 5; i++) {
        freq[current_hand[i][1]]++;
    };
if (check_pattern == "highcard") {
    vector<int> five_faces = {current_hand[0][1], current_hand[1][1], current_hand[2][1], current_hand[3][1], current_hand[4][1]};
    score  += *max_element(five_faces.begin(), five_faces.end());
}
if (check_pattern == "onepair" || check_pattern == "threeofakind" || check_pattern == "fourofakind") {
for (int i = 0; i < 13; i++) {
        if (freq[i] == 2 || freq[i] == 3 || freq[i] == 4) {
            score += i + 1;
            break;
}
}
}
if (check_pattern == "twopair") {
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 2) {
            score += i + 1;
        }
}
}
if (check_pattern == "houseful") {
    for (int i = 0; i < 13; i++) {
        if (freq[i] == 2 || freq[i] == 3) {
            score += i + 1;
        }
}
}
if (check_pattern == "flush" || check_pattern == "straightflush" || check_pattern =="royalflush" || check_pattern == "straight") {
    int sum = 0;
    for (int i = 0 ; i < current_hand.size(); i++) {
        sum += current_hand[i][1] + 1;
    }
    score = sum;
}

return score;
}
void computer_hand_evaluater(vector<vector<int>>& current_hand, int& computer_score, int wDeck[][FACES]) {


if (royal_flush(current_hand)) {
    cout << "ROYAL FLUSH" << endl;
    int add_score = score_checker(current_hand, "royalflush") + 10;//priority points
    computer_score += add_score;

    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    cards_adder(current_hand,wDeck,start_card,end_card);
    start_card = end_card + 1;
}
else if (straight_flush_check(current_hand)) {
    cout << "Straight Flush" << endl;
    int add_score = score_checker(current_hand, "straightflush") + 9;
    computer_score += add_score;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
}
else if (four_face_check(current_hand)) {
    cout << "Four of a Kind" << endl;
    int add_score = score_checker(current_hand, "fourofakind") + 8;
    computer_score += add_score;
    total_cards -= 4;
    discarder(current_hand,"fourofakind");
    end_card = start_card + 3;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
}
else if (housefull_check(current_hand)) {
    cout << "Houseful" << endl;
    int add_score = score_checker(current_hand, "houseful") + 7;
    computer_score += add_score;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
}
else if (flush_check(current_hand)) {
    cout << "Flush" << endl;
    int add_score = score_checker(current_hand, "flush") + 6;
    computer_score += add_score;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
}
else if (straight_check(current_hand)) {
    cout << "Straight" << endl;
    int add_score = score_checker(current_hand, "straight") + 5;
    computer_score += add_score;
    total_cards -= 5;
    current_hand.clear();
    end_card = start_card + 4;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
}
else if (three_face_check(current_hand)) {
    cout << "Three of a Kind" << endl;
    int add_score = score_checker(current_hand, "threeofakind") + 4;
    computer_score += add_score;
    discarder(current_hand,"threeofakind");
    end_card = start_card + 2;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
    total_cards -= 3;

}
else if (two_pair_check(current_hand)) {
    cout << "Two Pair" << endl;
    int add_score = score_checker(current_hand, "twopair") + 3;
    computer_score += add_score;
    discarder(current_hand,"twopair");
    end_card = start_card + 3;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
    total_cards -= 4;


}
else if (one_pair_check(current_hand)) {
    cout << "One Pair" << endl;
    int add_score = score_checker(current_hand, "onepair") + 2;
    computer_score += add_score;
    discarder(current_hand,"onepair");
    end_card = start_card + 1;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
    total_cards -= 2;


}
else if (high_card_check(current_hand)) {
    cout << "High Card" << endl;
    int add_score = score_checker(current_hand, "highcard") + 1;
    computer_score += add_score;
    discarder(current_hand,"highcard");
    end_card = start_card;
    cards_adder(current_hand, wDeck,start_card,end_card);
    start_card = end_card + 1;
    total_cards -= 1;


}
else {
    throw "error";
}
}

void player_hand_evaluater(vector<vector<int>>& current_hand, int& player_score, int wDeck[][FACES], string pattern) {
vector<vector<int>> new_cards_vector;

if (pattern == "royalflush" && royal_flush(current_hand)) {
        cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 10;
        player_score +=  add_score;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;

    }
    else if (pattern == "straightflush" && straight_flush_check(current_hand)) {
    cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 9;
        player_score += add_score;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
       cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;

    }
    else if (pattern == "fourofakind" && four_face_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 8;
        player_score += add_score;
        discarder(current_hand,pattern);
        end_card = start_card + 3;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;

        total_cards -= 4;

    }
    else if (pattern == "houseful" && housefull_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 7;
        player_score += add_score;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;

    }
    else if (pattern == "flush" && flush_check(current_hand) && !straight_flush_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 6;
        player_score += add_score;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;

    }
    else if (pattern == "straight" && straight_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 5;
        player_score += add_score;
        total_cards -= 5;
        current_hand.clear();
        end_card = start_card + 4;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;

    }
    else if (pattern == "threeofakind" && three_face_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 4;
        player_score += add_score;
        discarder(current_hand,pattern);
        end_card = start_card + 2;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;
        total_cards -= 3;

    }
    else if (pattern == "twopair" && two_pair_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 3;
        player_score += add_score;
        discarder(current_hand,pattern);
        end_card = start_card + 3;
       cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;
        total_cards -= 4;

    }
    else if (pattern == "onepair" && one_pair_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 2;
        player_score +=  add_score;
        discarder(current_hand, pattern);
        end_card = start_card + 1;
cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;
        total_cards -= 2;

    }
    else if (pattern == "highcard" && high_card_check(current_hand)) {
cout << "Correct!" << endl;
        int add_score = score_checker(current_hand, pattern) + 1;
        player_score += add_score;
        discarder(current_hand, pattern);
        end_card = start_card;
        cards_adder(current_hand, wDeck,start_card,end_card);
        start_card = end_card + 1;
        total_cards -= 1;
    }
    else {
        cout << "You had entered the wrong pattern." << endl;
    }
}


std::vector<std::string> buildCard(const std::string& rank_str, const std::string& suitName) {
    std::string suitSymbol = suitSymbols[suitName];
    std::vector<std::string> card(8); // Cards are 8 lines tall

    // Define the fixed-width borders and internal spaces
    const std::string TOP_BOTTOM_BORDER = "+-------------+"; // 15 chars wide
    const std::string EMPTY_LINE_INNER = "|             |"; // 13 spaces inside
    const std::string SPACE_11 = "           "; // 11 spaces
    const std::string SPACE_10 = "          "; // 10 spaces

    card[0] = TOP_BOTTOM_BORDER;

    // Rank on top left (with padding)
    card[1] = "| " + rank_str + (rank_str.length() == 1 ? SPACE_11 : SPACE_10) + "|";

    // Bottom border
    card[7] = TOP_BOTTOM_BORDER;

    // Rank on bottom right (with padding)
    card[6] = "| " + (rank_str.length() == 1 ? SPACE_11 : SPACE_10) + rank_str + " |";

    // Inner card content (lines 2, 3, 4, 5)
    // For ALL cards, including numbered cards, we will now place a single symbol in the middle.
    card[2] = EMPTY_LINE_INNER;
    card[3] = "|      " + suitSymbol + "      |"; // 6 spaces, symbol, 6 spaces
    card[4] = EMPTY_LINE_INNER;
    card[5] = EMPTY_LINE_INNER;

    return card;
}


void displayCardsInRow(const std::vector<std::vector<std::string>>& cards_art, const std::vector<std::vector<int>>& cards_data) {
    if (cards_art.empty()) return;

    size_t linesCount = cards_art[0].size();
    const int CARD_WIDTH = 15;
    const int SPACING_BETWEEN_CARDS = 5;

    for (size_t line = 0; line < linesCount; ++line) {
        for (const auto& card_art : cards_art) {
            std::cout << card_art[line] << std::string(SPACING_BETWEEN_CARDS, ' ');
        }
        std::cout << "\n";
    }

    for (size_t i = 0; i < cards_data.size(); ++i) {
        int suit_idx = cards_data[i][0];
        int face_idx = cards_data[i][1];

        std::string full_rank_name = fullRankNames[face_idx];
        std::string suit_name = getSuitString(suit_idx);
        std::string summary = full_rank_name + " of " + suit_name;

        std::cout << std::left << std::setw(CARD_WIDTH + SPACING_BETWEEN_CARDS) << summary;
    }
    std::cout << "\n\n";
}


void display_hand_ascii_art(const std::vector<std::vector<int>>& hand, const std::string& title) {
    std::vector<std::vector<std::string>> cards_art;
    for (const auto& card_data : hand) {
        std::string rank_str = getRankString(card_data[1]);
        std::string suit_name = getSuitString(card_data[0]);
        cards_art.push_back(buildCard(rank_str, suit_name));
    }

    std::cout << title << "\n";
    displayCardsInRow(cards_art, hand);
}
string getRankString(int face_idx) {
    switch (face_idx) {
        case 0: return "A";
        case 1: return "2";
        case 2: return "3";
        case 3: return "4";
        case 4: return "5";
        case 5: return "6";
        case 6: return "7";
        case 7: return "8";
        case 8: return "9";
        case 9: return "10";
        case 10: return "J";
        case 11: return "Q";
        case 12: return "K";
        default: return "?";
    }
}

string getSuitString(int suit_idx) {
    switch (suit_idx) {
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
        default: return "Unknown";
    }
}
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void display_intro_and_rules() {
    cout << "Welcome to Cards Royale, a game where strategy meets chance in a thrilling test of wits!" << endl;
    cout << "Your goal is to outsmart your opponent by forming stronger poker hands and strategically managing your cards." << endl;
    cout << "Each round, you and the computer will be dealt a hand of five cards." << endl;
    cout << "You'll then have the chance to discard any unwanted cards and draw new ones, aiming to create the most powerful pattern." << endl;
    cout << "Master the art of the draw and the discard to claim victory!" << endl;
    cout << endl; // Empty line for separation

    cout << "Game Rules:" << endl;
    cout << "The game proceeds in rounds. In first round, both players receive five cards." << endl;
    cout << "You'll then decide the pattern, and computer will verify your given pattern and these cards will be discard" << endl;
    cout << "New cards will be drawn to replace the discarded ones." << endl;
    cout << "The game continues until the deck runs out, with the highest score winning." << endl;
    cout << endl; // Empty line for separation

    cout << "Poker Patterns:" << endl;
    cout << "* Royal Flush: The highest possible hand, consisting of A, K, Q, J, 10 of the same suit." << endl;
    cout << "* Straight Flush: Five consecutive cards of the same suit." << endl;
    cout << "* Four of a Kind: Four cards of the same rank." << endl;
    cout << "* Full House: Three cards of one rank and two cards of another rank." << endl;
    cout << "* Flush: Any five cards of the same suit, not in sequence." << endl;
    cout << "* Straight: Five consecutive cards of different suits." << endl;
    cout << "* Three of a Kind: Three cards of the same rank." << endl;
    cout << "* Two Pair: Two different pairs." << endl;
    cout << "* One Pair: Two cards of the same rank." << endl;
    cout << "* High Card: If no other pattern is formed, the hand is ranked by its highest individual card." << endl;
    cout << endl; // Empty line for separation

    cout << "Good luck, and may the best hand win! Start your journey to becoming the ultimate Cards Royale champion now!" << endl;
    cout << endl; // Final empty line
}
void card_art() {
    std::cout << "//                      _     " << std::endl;
    std::cout << "//                     | |    " << std::endl;
    std::cout << "//     ___ __ _ _ __ __| |___ " << std::endl;
    std::cout << "//    / __/ _` | '__/ _` / __|" << std::endl;
    std::cout << "//   | (_| (_| | | | (_| \\__ \\" << std::endl;
    std::cout << "//    \\__\\__,_|_|  \\__,_|___/" << std::endl;
    std::cout << "//                            " << std::endl;
    std::cout << "//                            " << std::endl;
}


