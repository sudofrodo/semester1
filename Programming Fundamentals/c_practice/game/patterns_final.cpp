#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include<algorithm>
#include<vector>
#include<string>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <map>
using namespace std;

#define SUITS 4
#define FACES 13
#define CARDS 52

int start_card = 11;
int end_card = 0;
int total_cards = 42;

vector<vector<int>> playing_cards;
vector<vector<int>> discard_pile;
vector<vector<int>> player_pile;
vector<vector<int>> computer_pile;

vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;
vector<vector<int>> to_add_cards;
vector <int> three_of_a_kind;
vector <int> five_faces;

vector<vector<int>> discard_vector;
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


std::map<std::string, std::string> suitSymbols = {
    {"Hearts", "♥"},
    {"Diamonds", "♦"},
    {"Clubs", "♣"},
    {"Spades", "♠"}
};

// Map face index (0-12) to string rank for ASCII art display
// This converts your int face_idx to "A", "2", "10", "J", etc.
std::string getRankString(int face_idx) {
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
        default: return "?"; // Should not happen with valid indices
    }
}

// Map suit index (0-3) to string name for ASCII art display
// This converts your int suit_idx to "Hearts", "Diamonds", etc.
std::string getSuitString(int suit_idx) {
    switch (suit_idx) {
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
        default: return "Unknown"; // Should not happen with valid indices
    }
}

// Map face index to full rank name for summary text below cards
std::map<int, std::string> fullRankNames = {
    {0, "Ace"}, {1, "Two"}, {2, "Three"}, {3, "Four"},
    {4, "Five"}, {5, "Six"}, {6, "Seven"}, {7, "Eight"},
    {8, "Nine"}, {9, "Ten"}, {10, "Jack"}, {11, "Queen"},
    {12, "King"}
};

// --- Screen Clearing Function ---
// Call this function where you want to "clear" the console output.
// For example, at the start of a new round or turn.
void clear_screen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Linux/macOS
#endif
    // Alternative (platform-independent, scrolls old content off screen):
    // for(int i = 0; i < 50; ++i) std::cout << "\n";
}


// --- ASCII Art Card Drawing Functions ---

// buildCard function:
// This function creates the 8 lines of ASCII art for a single card.
// It takes string representations of rank ("A", "10", "J") and suit name ("Hearts", "Clubs").
// You will get these strings from your int face/suit indices using getRankString and getSuitString.
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
    if (rank_str == "J" || rank_str == "Q" || rank_str == "K" || rank_str == "A") {
        // Face cards and Ace: Rank in corners, suit symbol in the middle
        card[2] = EMPTY_LINE_INNER;
        card[3] = "|      " + suitSymbol + "      |"; // 6 spaces, symbol, 6 spaces
        card[4] = EMPTY_LINE_INNER;
        card[5] = EMPTY_LINE_INNER;
    } else {
        // Numbered cards: patterns based on rank
        int count = std::stoi(rank_str); // Convert string "2" to int 2, etc.

        switch (count) {
            case 2: // Top-left, Bottom-right
                card[2] = "| " + suitSymbol + "           |";
                card[3] = EMPTY_LINE_INNER;
                card[4] = EMPTY_LINE_INNER;
                card[5] = "|           " + suitSymbol + " |";
                break;
            case 3: // Top-left, Middle, Bottom-right
                card[2] = "| " + suitSymbol + "           |";
                card[3] = "|      " + suitSymbol + "      |";
                card[4] = EMPTY_LINE_INNER;
                card[5] = "|           " + suitSymbol + " |";
                break;
            case 4: // Four corners
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[3] = EMPTY_LINE_INNER;
                card[4] = EMPTY_LINE_INNER;
                card[5] = "| " + suitSymbol + "         " + suitSymbol + " |";
                break;
            case 5: // Four corners, Middle
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[3] = EMPTY_LINE_INNER;
                card[4] = "|      " + suitSymbol + "      |";
                card[5] = "| " + suitSymbol + "         " + suitSymbol + " |";
                break;
            case 6: // Two columns of three
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[3] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[4] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[5] = EMPTY_LINE_INNER;
                break;
            case 7: // Two columns of three, plus top center
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[3] = "| " + suitSymbol + "   " + suitSymbol + "   " + suitSymbol + " |";
                card[4] = "| " + suitSymbol + "         " + suitSymbol + " |";
                card[5] = EMPTY_LINE_INNER;
                break;
            case 8: // Two columns of four
                card[2] = "| " + suitSymbol + " " + suitSymbol + "       " + suitSymbol + " " + suitSymbol + " |";
                card[3] = EMPTY_LINE_INNER;
                card[4] = "| " + suitSymbol + " " + suitSymbol + "       " + suitSymbol + " " + suitSymbol + " |";
                card[5] = EMPTY_LINE_INNER;
                break;
            case 9: // 3x3 grid minus center row, plus center
                card[2] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |";
                card[3] = "|      " + suitSymbol + "      |";
                card[4] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |";
                card[5] = EMPTY_LINE_INNER;
                break;
            case 10: // Two columns of five
                card[2] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |";
                card[3] = EMPTY_LINE_INNER;
                card[4] = EMPTY_LINE_INNER;
                card[5] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |";
                break;
            default: // Fallback for invalid ranks
                card[2] = EMPTY_LINE_INNER;
                card[3] = "|      ?      |";
                card[4] = EMPTY_LINE_INNER;
                card[5] = EMPTY_LINE_INNER;
                break;
        }
    }
    return card;
}

// displayCardsInRow function:
// This function takes a vector of pre-built ASCII art cards (from buildCard)
// and the original card data, then prints them side-by-side with summaries.
void displayCardsInRow(const std::vector<std::vector<std::string>>& cards_art, const std::vector<std::vector<int>>& cards_data) {
    if (cards_art.empty()) return;

    size_t linesCount = cards_art[0].size(); // Should be 8 for all cards
    const int CARD_WIDTH = 15;              // Width of a single card's ASCII art
    const int SPACING_BETWEEN_CARDS = 5;    // Spaces between cards

    // Print each line of all cards
    for (size_t line = 0; line < linesCount; ++line) {
        for (const auto& card_art : cards_art) {
            std::cout << card_art[line] << std::string(SPACING_BETWEEN_CARDS, ' ');
        }
        std::cout << "\n";
    }

    // Print rank and suit summary below each card
    for (size_t i = 0; i < cards_data.size(); ++i) {
        int suit_idx = cards_data[i][0];
        int face_idx = cards_data[i][1];

        std::string full_rank_name = fullRankNames[face_idx];
        std::string suit_name = getSuitString(suit_idx);
        std::string summary = full_rank_name + " of " + suit_name;

        // Use setw to left-align the summary under the card's visual width.
        // Add SPACING_BETWEEN_CARDS to the width to account for the space after the card.
        std::cout << std::left << std::setw(CARD_WIDTH + SPACING_BETWEEN_CARDS) << summary;
    }
    std::cout << "\n\n"; // Two newlines for separation after each row of cards and summaries
}

// display_hand_ascii_art function:
// This is the main wrapper function you'll call to display any hand.
// It takes your existing `vector<vector<int>>` hand data.
// It iterates through the hand, converts the int indices to strings,
// calls buildCard for each, and then calls displayCardsInRow.
// 'title' is a string like "Your Hand:" or "Computer's Hand:".
void display_hand_ascii_art(const std::vector<std::vector<int>>& hand, const std::string& title) {
    std::vector<std::vector<std::string>> cards_art;
    for (const auto& card_data : hand) {
        std::string rank_str = getRankString(card_data[1]); // card_data[1] is face_idx
        std::string suit_name = getSuitString(card_data[0]); // card_data[0] is suit_idx
        cards_art.push_back(buildCard(rank_str, suit_name));
    }

    std::cout << title << "\n"; // Print the title with a newline
    displayCardsInRow(cards_art, hand);
}



vector<vector<int>> hand = {{1,0},{1,10},{1,11},{1,12},{1,13}};

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
computer_hand(deck, face, suit);
cout << endl;
player_hand(deck, face , suit);
while (total_cards > 0){
clear_screen();
cout << endl;
cout << "Cards Left : "<< total_cards<<  endl;
cout << "Computer's Point : " ;
computer_hand_evaluater(computer_cards,computer_score,deck);

display_hand_ascii_art(player_cards, "Player Cards");
cout << "What's your Pattern : ";
cin >> pattern;
player_hand_evaluater(player_cards,player_score,deck,pattern);

cout << endl;

}
cout << "Result : ";
cout << "Your score : " << player_score << endl;
cout << "Computer score : " << computer_score;

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
              //  cout << wFace[column] << " of " << wSuit[ row ] << endl;
                i++;
            }
        }
    }
}
}

//void display_player_hand(const vector<vector<int>>& current_hand, const char* wFace[], const char* wSuit[]) {
//    cout << "Your Cards :" << endl;
//    for (const auto& card : current_hand) {
//        int suit = card[0];
//        int face = card[1];
//        cout << wFace[face] << " of " << wSuit[suit] << endl;
//    }
//
//}


void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {

int row, column , card;
int i = 0;
for (card = 6 ; card <= 10 ; ++card) {
    for (row = 0 ; row < SUITS ; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
                player_cards.push_back({row, column});
                i++;
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
        cout << "You had entered the wrong pattern , 2 points will be deducted from your score.";
        player_score -= 2;
    }
}


