#include <iostream>
#include <string>
using namespace std;

// ANSI escape codes
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string RED = "\033[31m";
const string WHITE = "\033[37m";

// Map suit to symbol and color
struct Suit {
    string name;
    string symbol;
    string color;
};

Suit suits[] = {
    {"hearts", "♥", RED},
    {"diamonds", "♦", RED},
    {"clubs", "♣", WHITE},
    {"spades", "♠", WHITE}
};

string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

// Style rank: bold + underline for face cards and Ace
string styleRank(const string& rank) {
    if(rank == "A" || rank == "J" || rank == "Q" || rank == "K")
        return BOLD + UNDERLINE + rank + RESET;
    return rank;
}

// Style suit symbol: bold + colored
string styleSuit(const string& suitSymbol, const string& color) {
    return BOLD + color + suitSymbol + RESET;
}

// Print card with fancy border and styles
void printCard(const string& rank, const Suit& suit) {
    string rankStyled = styleRank(rank);
    string suitStyled = styleSuit(suit.symbol, suit.color);

    cout << "╔════════════╗\n";
    cout << "║ " << rankStyled << "       " << suitStyled << " ║\n";
    cout << "║ " << suitStyled << "   " << suitStyled << "   " << suitStyled << " ║\n";
    cout << "║     " << suitStyled << "      ║\n";
    cout << "║ " << suitStyled << "   " << suitStyled << "   " << suitStyled << " ║\n";
    cout << "║ " << suitStyled << "       " << rankStyled << " ║\n";
    cout << "╚════════════╝\n";
}

int main() {
    cout << "Welcome to ASCII Playing Card Viewer!\n";

    while(true) {
        cout << "\nAvailable suits:\n";
        for(int i=0; i<4; i++)
            cout << i+1 << ": " << suits[i].name << endl;

        cout << "Select suit (1-4) or 0 to quit: ";
        int suitChoice;
        cin >> suitChoice;
        if(suitChoice == 0) break;
        if(suitChoice < 1 || suitChoice > 4) {
            cout << "Invalid suit choice. Try again.\n";
            continue;
        }

        cout << "\nAvailable ranks:\n";
        for(int i=0; i<13; i++)
            cout << i+1 << ": " << ranks[i] << ( (i<12) ? ", " : "\n" );

        cout << "Select rank (1-13): ";
        int rankChoice;
        cin >> rankChoice;
        if(rankChoice < 1 || rankChoice > 13) {
            cout << "Invalid rank choice. Try again.\n";
            continue;
        }

        cout << "\nHere is your card:\n\n";
        printCard(ranks[rankChoice-1], suits[suitChoice-1]);
    }

    cout << "Goodbye!\n";
    return 0;
}
