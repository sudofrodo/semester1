#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void discard_cards(vector<vector<int>>& current_hand,vector<vector<int>>& discard_vector ) {
int card = 0;
for (card = 0 ; card <= discard_vector.size() - 1 ; card++) {
    for (int c_card = 0 ; c_card <= current_hand.size() - 1;  c_card++) {
        if (current_hand[c_card][0] == discard_vector[card][0] && current_hand[c_card][1] == discard_vector[card][1]) {
            auto newEnd = remove(current_hand.begin(), current_hand.end(), current_hand[c_card]);
            current_hand.erase(newEnd, current_hand.end());
        }
    }
}
}
void add_card(vector<vector<int>>& current_hand,vector<vector<int>>& add_vector ) {
int card = 0;
for (card = 0 ; card <= add_vector.size() - 1 ; card++) {
        current_hand.push_back(add_vector[card]);
}
}
int main() {
vector<vector<int>> hand = {{1,2} , {3,4} , {5,6} , {7,8} , {9,10}};
vector<vector<int>> discard = {{1,2},{7,6}};
discard_cards(hand,discard);
for(int i = 0; i < discard.size(); i++) {
    cout << discard[i][0] << " " << discard[i][1] << endl;
}
cout << "New vector" << endl;
for(int i = 0; i < hand.size(); i++) {
    cout << hand[i][0] << " " << hand[i][1] << endl;
}
vector<vector<int>> add_vector = {{11,12},{13,14}};
cout << "added vector" << endl;
add_card(hand,add_vector);
for(int i = 0; i < hand.size(); i++) {
    cout << hand[i][0] << " " << hand[i][1] << endl;
}
return 0;
}
