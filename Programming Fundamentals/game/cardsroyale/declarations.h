#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED

#define SUITS 4
#define FACES 13
#define CARDS 52

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




#endif // DECLARATIONS_H_INCLUDED
