#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip> // For std::left, std::setw, etc. (though we'll mostly use manual padding)

using namespace std;

// Map suit names to symbols and store rank names for summaries
map<string, string> suitSymbols = {
    {"Heart", "♥"},
    {"Diamond", "♦"},
    {"Club", "♣"},
    {"Spade", "♠"}
};

// Map face value to full rank name for summary
map<string, string> rankNames = {
    {"A", "Ace"}, {"2", "Two"}, {"3", "Three"}, {"4", "Four"},
    {"5", "Five"}, {"6", "Six"}, {"7", "Seven"}, {"8", "Eight"},
    {"9", "Nine"}, {"10", "Ten"}, {"J", "Jack"}, {"Q", "Queen"},
    {"K", "King"}
};

// Build card ASCII art as 8 lines
vector<string> buildCard(const string& rank, const string& suitName) {
    string suitSymbol = suitSymbols[suitName];
    vector<string> card(8); // Cards are 8 lines tall

    // Define the fixed-width borders and internal spaces
    const string TOP_BOTTOM_BORDER = "+-------------+"; // 15 chars wide
    const string EMPTY_LINE_INNER = "|             |"; // 13 spaces inside
    const string SPACE_11 = "           "; // 11 spaces
    const string SPACE_10 = "          "; // 10 spaces

    card[0] = TOP_BOTTOM_BORDER;

    // Rank on top left (with padding)
    // For rank "10" (2 chars), use 10 spaces. For others (1 char), use 11 spaces.
    card[1] = "| " + rank + (rank.length() == 1 ? SPACE_11 : SPACE_10) + "|";

    // Bottom border
    card[7] = TOP_BOTTOM_BORDER;

    // Rank on bottom right (with padding)
    card[6] = "| " + (rank.length() == 1 ? SPACE_11 : SPACE_10) + rank + " |";

    // Inner card content (lines 2, 3, 4, 5)
    if (rank == "J" || rank == "Q" || rank == "K" || rank == "A") {
        // Face cards and Ace: Rank in corners, suit symbol in the middle
        card[2] = EMPTY_LINE_INNER;
        card[3] = "|      " + suitSymbol + "      |"; // 6 spaces, symbol, 6 spaces
        card[4] = EMPTY_LINE_INNER;
        card[5] = EMPTY_LINE_INNER;
    } else {
        // Numbered cards: patterns based on rank
        int count = stoi(rank);

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
                card[3] = "| " + suitSymbol + "   " + suitSymbol + "   " + suitSymbol + " |"; // 1 symbol left, 1 middle, 1 right
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

// Display cards side by side, line by line
void displayCardsInRow(const vector<vector<string>>& cards, const vector<pair<string, string>>& card_details) {
    if (cards.empty()) return;

    size_t linesCount = cards[0].size(); // Should be 8 for all cards
    const int CARD_WIDTH = 15; // Width of a single card's ASCII art
    const int SPACING_BETWEEN_CARDS = 4; // Increased spaces between cards

    // Print each line of all cards
    for (size_t line = 0; line < linesCount; ++line) {
        for (const auto& card_art : cards) {
            cout << card_art[line] << string(SPACING_BETWEEN_CARDS, ' ');
        }
        cout << "\n";
    }

    // Print rank and suit summary below each card
    for (size_t i = 0; i < card_details.size(); ++i) {
        string rank_str = card_details[i].first;
        string suit_str = card_details[i].second;

        string full_rank_name = rankNames[rank_str];
        string summary = full_rank_name + " of " + suit_str;

        // Pad the summary to align it under the card.
        // It's tricky to center perfectly given variable length.
        // Let's left-align under the card's visual width.
        cout << left << setw(CARD_WIDTH) << summary << string(SPACING_BETWEEN_CARDS, ' ');
    }
    cout << "\n\n"; // Two newlines for separation after each row of cards
}

int main() {
    // Example usage:
    // Store card details (rank, suit name) to pass to displayCardsInRow
    vector<pair<string, string>> hand_details = {
        {"A", "Heart"}, {"10", "Diamond"}, {"7", "Club"}, {"Q", "Spade"}, {"3", "Heart"}
    };
    vector<vector<string>> hand_to_display;
    for(const auto& detail : hand_details) {
        hand_to_display.push_back(buildCard(detail.first, detail.second));
    }

    cout << "--- Example Hand ---" << endl;
    displayCardsInRow(hand_to_display, hand_details);

    vector<pair<string, string>> test_cards_row1_details = {
        {"J", "Club"}, {"K", "Spade"}, {"2", "Heart"}, {"4", "Diamond"}, {"5", "Club"}
    };
    vector<vector<string>> test_cards_row1_display;
    for(const auto& detail : test_cards_row1_details) {
        test_cards_row1_display.push_back(buildCard(detail.first, detail.second));
    }
    cout << "--- Test Row 1 ---" << endl;
    displayCardsInRow(test_cards_row1_display, test_cards_row1_details);

    vector<pair<string, string>> test_cards_row2_details = {
        {"6", "Spade"}, {"8", "Heart"}, {"9", "Diamond"}, {"10", "Club"}, {"A", "Spade"}
    };
    vector<vector<string>> test_cards_row2_display;
    for(const auto& detail : test_cards_row2_details) {
        test_cards_row2_display.push_back(buildCard(detail.first, detail.second));
    }
    cout << "--- Test Row 2 ---" << endl;
    displayCardsInRow(test_cards_row2_display, test_cards_row2_details);

    return 0;
}
