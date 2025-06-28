#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // For std::sort, std::remove_if, std::min
#include <sstream>   // For stringstream (input parsing)
#include <time.h>    // For srand, time
#include <cstdlib>   // For system() to clear screen
#include <limits>    // For numeric_limits (clearing input buffer)
#include <iomanip>   // For std::left, std::setw

using namespace std;

#define SUITS 4
#define FACES 13 // Ace (0) to King (12)
#define CARDS 52
const int POKER_HAND_SIZE = 5; // Standard poker hand size

// --- Global Game State ---
int current_start_card = 1; // Global for dealing next cards from the deck
int total_cards_in_deck = 52; // Total cards remaining in the main deck

vector<vector<int>> player_cards;
vector<vector<int>> computer_cards;
vector<vector<int>> to_add_cards; // Temporary storage for new cards drawn

// For pattern evaluation functions
vector<int> three_of_a_kind_ranks; // Stores rank for three of a kind
vector<int> five_faces_ranks;       // Stores faces for royal flush check (was `five_faces`)

// Deck state: using a 2D array to represent cards in the shuffled deck
int current_deck[SUITS][FACES] = {0}; // 0 = unused, >0 = order in shuffled deck

// Map suit names to symbols for ASCII art display
map<string, string> suitSymbols = {
    {"Hearts", "♥"},
    {"Diamonds", "♦"},
    {"Clubs", "♣"},
    {"Spades", "♠"}
};

// Map face index (0-12) to string rank for ASCII art display
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
        default: return "?"; // Should not happen with valid indices
    }
}

// Map suit index (0-3) to string name for ASCII art display
string getSuitString(int suit_idx) {
    switch (suit_idx) {
        case 0: return "Hearts";
        case 1: return "Diamonds";
        case 2: return "Clubs";
        case 3: return "Spades";
        default: return "Unknown"; // Should not happen with valid indices
    }
}

// Map face index to full rank name for summary text
map<int, string> fullRankNames = {
    {0, "Ace"}, {1, "Two"}, {2, "Three"}, {3, "Four"},
    {4, "Five"}, {5, "Six"}, {6, "Seven"}, {7, "Eight"},
    {8, "Nine"}, {9, "Ten"}, {10, "Jack"}, {11, "Queen"},
    {12, "King"}
};

// --- Screen Clearing Function ---
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
std::vector<std::string> buildCard(const std::string& rank_str, const std::string& suitName) {
    std::string suitSymbol = suitSymbols[suitName];
    std::vector<std::string> card(8); // Cards are 8 lines tall

    // Define the fixed-width borders and internal spaces
    const std::string TOP_BOTTOM_BORDER = "+-------------+"; // 15 chars wide
    const std::string EMPTY_LINE_INNER = "|             |"; // 13 spaces inside
    const std::string SPACE_11 = "           "; // 11 spaces
    const std::string SPACE_10 = "          "; // 10 spaces

    card[0] = TOP_BOTTOM_BORDER;
    card[1] = "| " + rank_str + (rank_str.length() == 1 ? SPACE_11 : SPACE_10) + "|";
    card[7] = TOP_BOTTOM_BORDER;
    card[6] = "| " + (rank_str.length() == 1 ? SPACE_11 : SPACE_10) + rank_str + " |";

    if (rank_str == "J" || rank_str == "Q" || rank_str == "K" || rank_str == "A") {
        card[2] = EMPTY_LINE_INNER;
        card[3] = "|      " + suitSymbol + "      |";
        card[4] = EMPTY_LINE_INNER;
        card[5] = EMPTY_LINE_INNER;
    } else {
        int count = std::stoi(rank_str);
        switch (count) {
            case 2:
                card[2] = "| " + suitSymbol + "           |"; card[3] = EMPTY_LINE_INNER; card[4] = EMPTY_LINE_INNER; card[5] = "|           " + suitSymbol + " |"; break;
            case 3:
                card[2] = "| " + suitSymbol + "           |"; card[3] = "|      " + suitSymbol + "      |"; card[4] = EMPTY_LINE_INNER; card[5] = "|           " + suitSymbol + " |"; break;
            case 4:
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[3] = EMPTY_LINE_INNER; card[4] = EMPTY_LINE_INNER; card[5] = "| " + suitSymbol + "         " + suitSymbol + " |"; break;
            case 5:
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[3] = EMPTY_LINE_INNER; card[4] = "|      " + suitSymbol + "      |"; card[5] = "| " + suitSymbol + "         " + suitSymbol + " |"; break;
            case 6:
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[3] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[4] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[5] = EMPTY_LINE_INNER; break;
            case 7:
                card[2] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[3] = "| " + suitSymbol + "   " + suitSymbol + "   " + suitSymbol + " |"; card[4] = "| " + suitSymbol + "         " + suitSymbol + " |"; card[5] = EMPTY_LINE_INNER; break;
            case 8:
                card[2] = "| " + suitSymbol + " " + suitSymbol + "       " + suitSymbol + " " + suitSymbol + " |"; card[3] = EMPTY_LINE_INNER; card[4] = "| " + suitSymbol + " " + suitSymbol + "       " + suitSymbol + " " + suitSymbol + " |"; card[5] = EMPTY_LINE_INNER; break;
            case 9:
                card[2] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |"; card[3] = "|      " + suitSymbol + "      |"; card[4] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |"; card[5] = EMPTY_LINE_INNER; break;
            case 10:
                card[2] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |"; card[3] = EMPTY_LINE_INNER; card[4] = EMPTY_LINE_INNER; card[5] = "| " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " " + suitSymbol + " |"; break;
            default:
                card[2] = EMPTY_LINE_INNER; card[3] = "|      ?      |"; card[4] = EMPTY_LINE_INNER; card[5] = EMPTY_LINE_INNER; break;
        }
    }
    return card;
}

// displayCardsInRow function:
void displayCardsInRow(const std::vector<std::vector<std::string>>& cards_art, const std::vector<std::vector<int>>& cards_data) {
    if (cards_art.empty()) return;

    size_t linesCount = cards_art[0].size();
    const int CARD_WIDTH = 15;
    const int SPACING_BETWEEN_CARDS = 3;

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

// Wrapper to display a hand using ASCII art
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


// --- Game Functions ---

void shuffle(int wDeck[][FACES]) {
    for (int i = 0; i < SUITS; ++i) {
        for (int j = 0; j < FACES; ++j) {
            wDeck[i][j] = 0;
        }
    }

    int row, column, card;
    for (card = 1; card <= CARDS; ++card) {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
    current_start_card = 1; // Reset card counter for dealing
    total_cards_in_deck = CARDS; // Reset total cards
}

// Deals a hand from the deck
// Returns true if deal was successful, false if not enough cards.
bool deal_hand(int wDeck[][FACES], vector<vector<int>>& hand_to_deal, int num_cards_to_deal) {
    if (total_cards_in_deck < num_cards_to_deal) {
        return false; // Not enough cards to deal
    }

    hand_to_deal.clear(); // Clear existing cards in hand

    for (int card_count = 0; card_count < num_cards_to_deal; ++card_count) {
        bool found = false;
        for (int r = 0; r < SUITS && !found; ++r) {
            for (int c = 0; c < FACES && !found; ++c) {
                if (wDeck[r][c] == current_start_card) {
                    hand_to_deal.push_back({r, c});
                    found = true;
                }
            }
        }
        current_start_card++; // Move to the next card in the shuffled deck
        total_cards_in_deck--;
    }
    return true;
}


void computer_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {
    // No display for computer's hand here
    deal_hand(wDeck, computer_cards, POKER_HAND_SIZE);
}

void player_hand(int wDeck[][FACES] , const char *wFace[] , const char *wSuit[]) {
    deal_hand(wDeck, player_cards, POKER_HAND_SIZE);
    display_hand_ascii_art(player_cards, "Your Hand:");
}


void discard_cards(vector<vector<int>>& current_hand, const vector<vector<int>>& cards_to_discard) {
    for (const auto& d_card : cards_to_discard) {
        current_hand.erase(std::remove_if(current_hand.begin(), current_hand.end(),
            [&](const vector<int>& c_card) {
                return c_card[0] == d_card[0] && c_card[1] == d_card[1];
            }),
            current_hand.end());
    }
}

void add_card(vector<vector<int>>& current_hand,vector<vector<int>>& add_vector ) {
    for (size_t card = 0 ; card < add_vector.size() ; card++) {
        current_hand.push_back(add_vector[card]);
    }
    add_vector.clear();
}

// --- Poker Hand Evaluation Functions ---

map<int, int> get_face_frequencies(const vector<vector<int>>& hand) {
    map<int, int> freq;
    for (const auto& card : hand) {
        freq[card[1]]++;
    }
    return freq;
}

vector<int> get_sorted_faces(const vector<vector<int>>& hand) {
    vector<int> faces;
    for (const auto& card : hand) {
        faces.push_back(card[1]);
    }
    sort(faces.begin(), faces.end());
    return faces;
}

int high_card_check(const vector<vector<int>>& current_hand) {
    return 1;
}

int one_pair_check(const vector<vector<int>>& current_hand, vector<int>& pair_ranks_out) {
    pair_ranks_out.clear();
    map<int, int> freq = get_face_frequencies(current_hand);
    for (const auto& entry : freq) {
        if (entry.second == 2) {
            pair_ranks_out.push_back(entry.first);
        }
    }
    return pair_ranks_out.size() == 1 ? 1 : 0;
}

int two_pair_check(const vector<vector<int>>& current_hand, vector<int>& pair_ranks_out) {
    pair_ranks_out.clear();
    map<int, int> freq = get_face_frequencies(current_hand);
    for (const auto& entry : freq) {
        if (entry.second == 2) {
            pair_ranks_out.push_back(entry.first);
        }
    }
    return pair_ranks_out.size() == 2 ? 1 : 0;
}

int three_face_check(const vector<vector<int>>& current_hand, int& three_of_a_kind_rank_out) {
    map<int, int> freq = get_face_frequencies(current_hand);
    for (const auto& entry : freq) {
        if (entry.second == 3) {
            three_of_a_kind_rank_out = entry.first;
            return 1;
        }
    }
    return 0;
}

int four_face_check(const vector<vector<int>>& current_hand, int& four_of_a_kind_rank_out) {
    map<int, int> freq = get_face_frequencies(current_hand);
    for (const auto& entry : freq) {
        if (entry.second == 4) {
            four_of_a_kind_rank_out = entry.first;
            return 1;
        }
    }
    return 0;
}

int flush_check(const vector<vector<int>>& current_hand) {
    if (current_hand.empty()) return 0;
    int first_suit = current_hand[0][0];
    for (size_t i = 1; i < current_hand.size(); ++i) {
        if (current_hand[i][0] != first_suit) {
            return 0;
        }
    }
    return 1;
}

bool are_faces_consecutive(const vector<int>& sorted_faces) {
    if (sorted_faces.size() != POKER_HAND_SIZE) return false;

    // Check for A-2-3-4-5 straight (Ace as 0, then 1,2,3,4)
    if (sorted_faces[0] == 0 && sorted_faces[1] == 1 && sorted_faces[2] == 2 && sorted_faces[3] == 3 && sorted_faces[4] == 4) {
        return true;
    }
    // Check for standard consecutive
    for (size_t i = 0; i < sorted_faces.size() - 1; ++i) {
        if (sorted_faces[i+1] - sorted_faces[i] != 1) {
            return false;
        }
    }
    return true;
}

int straight_check(const vector<vector<int>>& current_hand) {
    vector<int> faces = get_sorted_faces(current_hand);
    return are_faces_consecutive(faces);
}

int housefull_check(const vector<vector<int>>& current_hand) {
    map<int, int> freq = get_face_frequencies(current_hand);
    bool has_three = false;
    bool has_pair = false;

    for (const auto& entry : freq) {
        if (entry.second == 3) {
            has_three = true;
        } else if (entry.second == 2) {
            has_pair = true;
        }
    }
    return (has_three && has_pair) ? 1 : 0;
}

int straight_flush_check(const vector<vector<int>>& current_hand) {
    return (straight_check(current_hand) && flush_check(current_hand));
}

int royal_flush(const vector<vector<int>>& current_hand) {
    if (!flush_check(current_hand)) return 0;

    vector<int> faces = get_sorted_faces(current_hand);
    // Royal Flush: 10, J, Q, K, A of same suit (faces 9, 10, 11, 12, 0)
    if (faces.size() == 5 && faces[0] == 0 && faces[1] == 9 && faces[2] == 10 && faces[3] == 11 && faces[4] == 12) {
        return 1;
    }
    return 0;
}

// Helper to handle drawing new cards after discards
bool redraw_cards(vector<vector<int>>& current_hand, int wDeck[][FACES], int num_to_draw) {
    if (total_cards_in_deck < num_to_draw) {
        return false; // Not enough cards left in deck
    }
    return deal_hand(wDeck, to_add_cards, num_to_draw); // Deal into temp vector
}


void computer_hand_evaluater(vector<vector<int>>& current_hand, int& computer_score, int wDeck[][FACES], const char* wFace[], const char* wSuit[]) {
    // NO display of computer's hand in this function
    cout << "Computer is evaluating hand..." << endl;

    int four_kind_rank = -1;
    int three_kind_rank = -1;
    vector<int> pair_ranks;
    int num_to_draw = 0; // Number of cards computer will discard and redraw

    // Determine hand and set num_to_draw
    if (royal_flush(current_hand)) {
        cout << "Computer has a ROYAL FLUSH!" << endl;
        computer_score += 10;
        num_to_draw = 0; // Don't discard/draw
    } else if (straight_flush_check(current_hand)) {
        cout << "Computer has a STRAIGHT FLUSH!" << endl;
        computer_score += 9;
        num_to_draw = 0; // Don't discard/draw
    } else if (four_face_check(current_hand, four_kind_rank)) {
        cout << "Computer has FOUR OF A KIND!" << endl;
        computer_score += 8;
        num_to_draw = 1; // Discard 1 odd card
        vector<vector<int>> cards_to_discard;
        for (const auto& card : current_hand) {
            if (card[1] != four_kind_rank) {
                cards_to_discard.push_back(card);
            }
        }
        discard_cards(current_hand, cards_to_discard);
    } else if (housefull_check(current_hand)) {
        cout << "Computer has a FULL HOUSE!" << endl;
        computer_score += 7;
        num_to_draw = 0; // Don't discard/draw
    } else if (flush_check(current_hand)) {
        cout << "Computer has a FLUSH!" << endl;
        computer_score += 6;
        num_to_draw = 0; // Don't discard/draw
    } else if (straight_check(current_hand)) {
        cout << "Computer has a STRAIGHT!" << endl;
        computer_score += 5;
        num_to_draw = 0; // Don't discard/draw
    } else if (three_face_check(current_hand, three_kind_rank)) {
        cout << "Computer has THREE OF A KIND!" << endl;
        computer_score += 4;
        num_to_draw = 2; // Discard 2 odd cards
        vector<vector<int>> cards_to_discard;
        for (const auto& card : current_hand) {
            if (card[1] != three_kind_rank) {
                cards_to_discard.push_back(card);
            }
        }
        discard_cards(current_hand, cards_to_discard);
    } else if (two_pair_check(current_hand, pair_ranks)) {
        cout << "Computer has TWO PAIR!" << endl;
        computer_score += 3;
        num_to_draw = 1; // Discard 1 odd card
        vector<vector<int>> cards_to_discard;
        for (const auto& card : current_hand) {
            bool is_in_pair = false;
            for (int rank : pair_ranks) {
                if (card[1] == rank) {
                    is_in_pair = true;
                    break;
                }
            }
            if (!is_in_pair) {
                cards_to_discard.push_back(card);
            }
        }
        discard_cards(current_hand, cards_to_discard);
    } else if (one_pair_check(current_hand, pair_ranks)) {
        cout << "Computer has ONE PAIR!" << endl;
        computer_score += 2;
        num_to_draw = 3; // Discard 3 non-pair cards
        vector<vector<int>> cards_to_discard;
        for (const auto& card : current_hand) {
            if (card[1] != pair_ranks[0]) {
                cards_to_discard.push_back(card);
            }
        }
        discard_cards(current_hand, cards_to_discard);
    } else { // High Card
        cout << "Computer has HIGH CARD." << endl;
        computer_score += 1;
        num_to_draw = 2; // Discard 2 lowest cards (simple AI)
        vector<int> sorted_faces_in_hand = get_sorted_faces(current_hand);
        vector<vector<int>> cards_to_discard;
        // Keep 3 highest cards, discard 2 lowest
        for(size_t i = 0; i < current_hand.size(); ++i) {
            bool is_kept = false;
            for(size_t j = current_hand.size() - 3; j < current_hand.size(); ++j) { // Keep top 3 by rank
                if (current_hand[i][1] == sorted_faces_in_hand[j]) {
                    is_kept = true;
                    break;
                }
            }
            if (!is_kept) {
                cards_to_discard.push_back(current_hand[i]);
                if (cards_to_discard.size() == num_to_draw) break; // Discard exact number
            }
        }
        // If still didn't get 2, just remove the lowest unique ones
        while(cards_to_discard.size() < num_to_draw) {
             int lowest_face = -1;
             vector<int> current_hand_faces = get_sorted_faces(current_hand);
             if(!current_hand_faces.empty()) lowest_face = current_hand_faces[0];

             bool found_lowest = false;
             for(const auto& card : current_hand) {
                 if(card[1] == lowest_face) {
                    // Check if already in cards_to_discard to avoid duplicates
                    bool already_marked = false;
                    for(const auto& discarded : cards_to_discard) {
                        if (discarded[0] == card[0] && discarded[1] == card[1]) {
                            already_marked = true;
                            break;
                        }
                    }
                    if(!already_marked) {
                        cards_to_discard.push_back(card);
                        found_lowest = true;
                        break;
                    }
                 }
             }
             if (!found_lowest) break; // Should not happen if hand has cards
        }
        discard_cards(current_hand, cards_to_discard);
    }

    if (num_to_draw > 0) {
        if (!redraw_cards(current_hand, wDeck, num_to_draw)) {
            cout << "WARNING: Computer could not draw " << num_to_draw << " cards. Not enough cards left in deck!" << endl;
            // The game should end here, or handle this state.
            // For now, it will simply continue with fewer cards if needed.
        }
        add_card(current_hand, to_add_cards);
    }

    // No display of computer's hand after redraw.
    cout << "Computer Score: " << computer_score << endl;
}

void player_hand_evaluater(vector<vector<int>>& current_hand, int& player_score, int wDeck[][FACES], const char* wFace[], const char* wSuit[]) {
    // Player's turn to input discard strategy and pattern
    display_hand_ascii_art(current_hand, "Your Hand:");
    cout << "Enter cards to discard (e.g., 'Ace of Hearts', 'Two of Clubs'). Type 'done' when finished." << endl;
    cout << "If you want to keep all cards, just type 'done'." << endl;

    string input_line;
    vector<vector<int>> cards_to_discard_player;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer before getline
    while (true) {
        cout << "Discard card (or 'done'): ";
        getline(cin, input_line);
        if (input_line == "done") {
            break;
        }

        // Parse card input (e.g., "Ace of Hearts")
        stringstream ss(input_line);
        string rank_name_str, of_str, suit_name_str;
        ss >> rank_name_str; // Read rank name (e.g., "Ace", "Two", "Ten")

        // Handle multi-word ranks like "Ten" and then "of"
        if (rank_name_str == "Two" || rank_name_str == "Three" || rank_name_str == "Four" ||
            rank_name_str == "Five" || rank_name_str == "Six" || rank_name_str == "Seven" ||
            rank_name_str == "Eight" || rank_name_str == "Nine" || rank_name_str == "Ten") {
            // It's a number-word rank, 'of' comes next
            ss >> of_str >> suit_name_str;
        } else if (rank_name_str == "Ace" || rank_name_str == "Jack" ||
                   rank_name_str == "Queen" || rank_name_str == "King") {
            // It's a face card, 'of' comes next
            ss >> of_str >> suit_name_str;
        } else {
            cout << "Invalid card format. Please use 'Rank of Suit' (e.g., 'Ace of Hearts')." << endl;
            continue; // Go to next loop iteration
        }


        int discard_face_idx = -1;
        int discard_suit_idx = -1;

        // Convert string rank name to face_idx
        for (int i = 0; i < FACES; ++i) {
            if (fullRankNames[i] == rank_name_str) {
                discard_face_idx = i;
                break;
            }
        }
        // Convert string suit name to suit_idx
        for (int i = 0; i < SUITS; ++i) {
            if (getSuitString(i) == suit_name_str) {
                discard_suit_idx = i;
                break;
            }
        }

        if (discard_face_idx != -1 && discard_suit_idx != -1) {
            bool found_in_hand = false;
            // Check if card exists in player's hand and isn't already marked for discard
            for (const auto& card : current_hand) {
                if (card[0] == discard_suit_idx && card[1] == discard_face_idx) {
                    bool already_in_discard_list = false;
                    for (const auto& d_card : cards_to_discard_player) {
                        if (d_card[0] == card[0] && d_card[1] == card[1]) {
                            already_in_discard_list = true;
                            break;
                        }
                    }
                    if (!already_in_discard_list) {
                        cards_to_discard_player.push_back(card);
                        found_in_hand = true;
                        cout << "Marked for discarding: " << fullRankNames[discard_face_idx] << " of " << getSuitString(discard_suit_idx) << endl;
                        break;
                    }
                }
            }
            if (!found_in_hand) {
                cout << "Card not found in your hand or already marked. Please enter a valid card you possess." << endl;
            }
        } else {
            cout << "Could not parse card. Please use 'Rank of Suit' (e.g., 'Ace of Hearts')." << endl;
        }
    }

    if (!cards_to_discard_player.empty()) {
        int num_to_draw = cards_to_discard_player.size();
        if (total_cards_in_deck < num_to_draw) {
            cout << "WARNING: Not enough cards left in deck to draw " << num_to_draw << " cards! Game might end prematurely." << endl;
            cout << "Only " << total_cards_in_deck << " cards available." << endl;
            num_to_draw = total_cards_in_deck; // Draw all remaining if not enough
            if (num_to_draw == 0) { // If literally no cards left to draw
                 cout << "No cards available to draw. Your hand will remain as is after discards." << endl;
            }
        }

        discard_cards(current_hand, cards_to_discard_player);

        if (num_to_draw > 0) {
            cout << "Drawing " << num_to_draw << " new cards..." << endl;
            deal_hand(wDeck, to_add_cards, num_to_draw);
            add_card(current_hand, to_add_cards);
        }
        cout << "Your Hand after discards and draws:" << endl;
        display_hand_ascii_art(current_hand, "Your Hand (New):");
    } else {
        cout << "You chose to keep all cards." << endl;
    }

    cout << "Now, declare your pattern (e.g., 'royalflush', 'straightflush', 'fourofakind', 'fullhouse', 'flush', 'straight', 'threeofakind', 'twopair', 'onepair', 'highcard'): ";
    string pattern;
    cin >> pattern;

    int four_kind_rank = -1;
    int three_kind_rank = -1;
    vector<int> pair_ranks;

    // Evaluate declared pattern
    if (pattern == "royalflush" && royal_flush(current_hand)) {
        cout << "Correct! ROYAL FLUSH!" << endl; player_score += 10;
    } else if (pattern == "straightflush" && straight_flush_check(current_hand)) {
        cout << "Correct! STRAIGHT FLUSH!" << endl; player_score += 9;
    } else if (pattern == "fourofakind" && four_face_check(current_hand, four_kind_rank)) {
        cout << "Correct! FOUR OF A KIND!" << endl; player_score += 8;
    } else if (pattern == "fullhouse" && housefull_check(current_hand)) {
        cout << "Correct! FULL HOUSE!" << endl; player_score += 7;
    } else if (pattern == "flush" && flush_check(current_hand)) {
        cout << "Correct! FLUSH!" << endl; player_score += 6;
    } else if (pattern == "straight" && straight_check(current_hand)) {
        cout << "Correct! STRAIGHT!" << endl; player_score += 5;
    } else if (pattern == "threeofakind" && three_face_check(current_hand, three_kind_rank)) {
        cout << "Correct! THREE OF A KIND!" << endl; player_score += 4;
    } else if (pattern == "twopair" && two_pair_check(current_hand, pair_ranks)) {
        cout << "Correct! TWO PAIR!" << endl; player_score += 3;
    } else if (pattern == "onepair" && one_pair_check(current_hand, pair_ranks)) {
        cout << "Correct! ONE PAIR!" << endl; player_score += 2;
    } else if (pattern == "highcard" && high_card_check(current_hand)) {
        cout << "Correct! HIGH CARD!" << endl; player_score += 1;
    } else {
        cout << "Wrong pattern declared! 2 points deducted." << endl;
        player_score -= 2;
    }

    cout << "Cards Left in Deck: " << total_cards_in_deck << endl;
    cout << "Your Score: " << player_score << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer for next turn
    cout << "\nPress Enter to continue to next turn...";
    cin.get(); // Wait for user to press enter
}


const int majestic_flush[5] = {0,9,10,11,12}; // Ace (0), Ten (9), Jack (10), Queen (11), King (12) for Royal Flush check


int main() {
    const char *suit[SUITS] = {"Hearts" , "Diamonds" , "Clubs" , "Spades"};
    const char *face[FACES] = { "Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King" };

    int player_score = 0 , computer_score = 0;

    srand (time(NULL));

    // Game Loop
    // The game continues as long as there are enough cards to deal initial hands (5 for player, 5 for computer)
    // plus at least one card for potential draws (even if a player discards 0, they still need to be able to draw).
    while (total_cards_in_deck >= POKER_HAND_SIZE * 2) { // Minimum cards for 2 hands (5 each)
        clear_screen();
        cout << "--- NEW ROUND ---" << endl;
        shuffle(current_deck); // Shuffle for each round

        cout << "Dealing hands..." << endl;
        // Check if there are enough cards for initial deal
        if (!deal_hand(current_deck, computer_cards, POKER_HAND_SIZE) ||
            !deal_hand(current_deck, player_cards, POKER_HAND_SIZE))
        {
            cout << "Not enough cards left in deck for initial deal. Game Over." << endl;
            break; // Exit game loop
        }

        // Player's Turn
        cout << "\n--- Your Turn ---" << endl;
        // player_hand_evaluater now internally handles displaying player hand and drawing logic
        player_hand_evaluater(player_cards, player_score, current_deck, face, suit);
        // After player's turn, check if enough cards for computer's potential redraw
        if (total_cards_in_deck < 0) { // This check should happen *before* computer's turn to prevent negative draws
            cout << "Not enough cards for computer's turn. Game Over." << endl;
            break;
        }

        clear_screen(); // Clear screen before showing computer's turn/outcome
        // Computer's Turn
        cout << "--- Computer's Turn ---" << endl;
        // computer_hand_evaluater no longer displays computer's hand ASCII art
        computer_hand_evaluater(computer_cards, computer_score, current_deck, face, suit);

        cout << "\n--- Round End ---" << endl;
        cout << "Current Scores: Player: " << player_score << " | Computer: " << computer_score << endl;
        cout << "Cards Left in Deck: " << total_cards_in_deck << endl;
        cout << "Press Enter to start next round or 'q' to quit...";
        string response;
        getline(cin, response);
        if (response == "q" || response == "Q") {
            break;
        }
    }

    clear_screen();
    cout << "--- GAME OVER ---" << endl;
    cout << "Final Scores:" << endl;
    cout << "Player: " << player_score << endl;
    cout << "Computer: " << computer_score << endl;

    if (player_score > computer_score) {
        cout << "You Win!" << endl;
    } else if (computer_score > player_score) {
        cout << "Computer Wins!" << endl;
    } else {
        cout << "It's a Tie!" << endl;
    }

    return 0;
}
