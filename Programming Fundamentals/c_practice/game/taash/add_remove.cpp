#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void discard_card(vector<vector<int>>& current_hand,vector<vector<int>>& discard_vector ) {
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
//int main() {
//
//
//return 0;
//}
