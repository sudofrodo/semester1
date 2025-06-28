#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Map suit names to symbols
map<string, string> suitSymbols = {
    {"Heart", "♥"},
    {"Diamond", "♦"},
    {"Club", "♣"},
    {"Spade", "♠"}
};

// Build a single card as a vector of strings (ASCII art)
vector<string> buildCard(const string& rank, const string& suitName) {
    string suitSymbol = suitSymbols[suitName];
    vector<string> card(8);
    card[0] = "+-------------+";

    // Handle rank alignment (add extra space if rank is single char)
    string leftRank = "| " + rank + (rank.size() == 1 ? " " : "") + "          |";
    string rightRank = "|          " + rank + (rank.size() == 1 ? " " : "") + "|";
    card[1] = leftRank;
    card[6] = rightRank;

    if (rank == "J" || rank == "Q" || rank == "K" || rank == "A") {
        // Face cards and Ace: single large symbol in the middle
        card[2] = "|             |";
        card[3] = "|     " + suitSymbol + "       |";
        card[4] = "|             |";
        card[5] = "|             |";
    } else {
        // Numbered cards: show the number of suit symbols equal to rank
        int count = stoi(rank);
        // Line 2: up to 5 symbols
        string line2 = "| ";
        int symbolsInLine = (count > 5) ? 5 : count;
        for (int i = 0; i < symbolsInLine; ++i) {
            line2 += suitSymbol + " ";
        }
        line2 += string(13 - line2.size(), ' ') + "|";
        card[2] = line2;

        // Line 3: remaining symbols if count > 5
        if (count > 5) {
            string line3 = "| ";
            for (int i = 5; i < count; ++i) {
                line3 += suitSymbol + " ";
            }
            line3 += string(13 - line3.size(), ' ') + "|";
            card[3] = line3;
        } else {
            card[3] = "|             |";
        }

        // Lines 4 and 5 empty for spacing
        card[4] = "|             |";
        card[5] = "|             |";
    }

    card[7] = "+-------------+";
    return card;
}

// Display multiple cards in a single row side by side
void displayCardsInRow(const vector<vector<string>>& cards) {
    if (cards.empty()) return;

    // All cards have the same number of lines, safe to use cards[0].size()
    size_t linesCount = cards[0].size();

    for (size_t line = 0; line < linesCount; ++line) {
        for (const auto& card : cards) {
            cout << card[line] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    vector<vector<string>> cards = {
        buildCard("A", "Heart"),
        buildCard("10", "Diamond"),
        buildCard("7", "Club"),
        buildCard("Q", "Spade"),
        buildCard("3", "Heart")
    };

    displayCardsInRow(cards);

    return 0;
}
