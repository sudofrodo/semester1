#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <map>
#include <sstream>
#include <utility> // For std::pair

using namespace std;
// --- Game Constants and Global State ---
#define SUITS 4
#define FACES 13
#define CARDS 52

// Your original global variables for game logic
int start_card = 11;
int end_card = 0;
int total_cards = 42;

vector<vector<int>> computer_cards;
vector<vector<int>> player_cards;
int wDeck[SUITS][FACES] = {{0}}; // Initialize to zero
const char *wSuit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *wFace[FACES] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
int player_score = 0; // Using your original variable names
int computer_score = 0;

// --- SFML and UI Global Variables ---
sf::Font gameFont;
map<pair<int, int>, sf::Texture> cardTextures;
sf::Texture cardBackTexture;

// Game state management for the UI
enum GameState
{
    PLAYING,
    EVALUATING,
    GAME_OVER
};
GameState currentGameState = PLAYING;

// UI messages
std::string playerMessage = "";
std::string computerMessage = "";
std::string statusMessage = "Choose a pattern for your hand.";

// Timer for the evaluation phase display
sf::Clock evaluationClock;
const sf::Time evaluationDisplayTime = sf::seconds(4.0f);

void shuffle(int wDeck[][FACES]);
void cards_adder(std::vector<std::vector<int>> &current_hand, int wDeck[][FACES], int start, int end);
void discarder(std::vector<std::vector<int>> &current_hand, std::string check_pattern);
int high_card_check(const std::vector<std::vector<int>> &current_hand);
int one_pair_check(const std::vector<std::vector<int>> &current_hand);
int two_pair_check(const std::vector<std::vector<int>> &current_hand);
int three_face_check(const std::vector<std::vector<int>> &current_hand);
int straight_check(const std::vector<std::vector<int>> &current_hand);
int flush_check(const std::vector<std::vector<int>> &current_hand);
int housefull_check(const std::vector<std::vector<int>> &current_hand);
int four_face_check(const std::vector<std::vector<int>> &current_hand);
int straight_flush_check(const std::vector<std::vector<int>> &current_hand);
int royal_flush(const std::vector<std::vector<int>> &current_hand);
void computer_hand_evaluater(std::vector<std::vector<int>> &current_hand, int &score, int wDeck[][FACES]);
void player_hand_evaluater(std::vector<std::vector<int>> &current_hand, int &score, int wDeck[][FACES], std::string pattern);

// --- Button Structure for SFML ---
struct Button
{
    sf::RectangleShape shape;
    sf::Text text;
    std::string patternName;

    Button(float x, float y, float width, float height, const std::string &name, const std::string &displayTxt, const sf::Font &font)
    {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color(0, 76, 153));
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(2);

        text.setFont(font);
        text.setString(displayTxt);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::White);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(x + width / 2.0f, y + height / 2.0f);

        patternName = name;
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(const sf::Vector2i &mousePos) const
    {
        return shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
};

std::vector<Button> patternButtons;

// --- SFML Helper Functions ---

std::string getCardFilename(int suit, int face)
{
    std::string suitStr = wSuit[suit];
    std::string faceStr = wFace[face];
    std::transform(suitStr.begin(), suitStr.end(), suitStr.begin(), ::tolower);
    std::transform(faceStr.begin(), faceStr.end(), faceStr.begin(), ::tolower);
    return "cards/" + faceStr + "_of_" + suitStr + ".png";
}

bool loadResources()
{
    if (!gameFont.loadFromFile("font/Arial.ttf"))
    {
        std::cerr << "Error: Could not load font/Arial.ttf" << std::endl;
        return false;
    }

    if (!cardBackTexture.loadFromFile("cards/card_back.png"))
    {
        std::cerr << "Error: Could not load cards/card_back.png" << std::endl;
        return false;
    }

    for (int s = 0; s < SUITS; ++s)
    {
        for (int f = 0; f < FACES; ++f)
        {
            sf::Texture tex;
            std::string filename = getCardFilename(s, f);
            if (!tex.loadFromFile(filename))
            {
                std::cerr << "Error: Could not load " << filename << std::endl;
            }
            cardTextures[{s, f}] = tex;
        }
    }
    return true;
}

void createButtons()
{
    float startX = 50.f;
    float startY = 620.f;
    float btnWidth = 140.f;
    float btnHeight = 40.f;
    float xGap = 10.f;
    float yGap = 10.f;
    int itemsPerRow = 5;

    std::vector<std::pair<std::string, std::string>> patterns =
        {
            {"highcard", "High Card"}, {"onepair", "One Pair"}, {"twopair", "Two Pair"}, {"threeofakind", "3 of a Kind"}, {"straight", "Straight"}, {"flush", "Flush"}, {"fullhouse", "Full House"}, {"fourofakind", "4 of a Kind"}, {"straightflush", "Straight Flush"}, {"royalflush", "Royal Flush"}};

    for (size_t i = 0; i < patterns.size(); ++i)
    {
        float x = startX + (i % itemsPerRow) * (btnWidth + xGap);
        float y = startY + (i / itemsPerRow) * (btnHeight + yGap);
        patternButtons.emplace_back(x, y, btnWidth, btnHeight, patterns[i].first, patterns[i].second, gameFont);
    }
}

void drawHand(sf::RenderWindow &window, const vector<vector<int>> &hand, float yPos, bool hidden)
{
    float startX = (window.getSize().x - (5 * 90.f - 10.f)) / 2.f;
    float cardSpacing = 90.f;

    for (size_t i = 0; i < hand.size(); ++i)
    {
        sf::Sprite cardSprite;
        if (hidden)
        {
            cardSprite.setTexture(cardBackTexture);
        }
        else
        {
            auto it = cardTextures.find({hand[i][0], hand[i][1]});
            if (it != cardTextures.end())
            {
                cardSprite.setTexture(it->second);
            }
            else
            {
                cardSprite.setTexture(cardBackTexture);
            }
        }

        sf::Vector2u texSize = cardSprite.getTexture()->getSize();
        if (texSize.x > 0 && texSize.y > 0)
        {
            cardSprite.setScale(80.f / texSize.x, 120.f / texSize.y);
        }

        cardSprite.setPosition(startX + i * cardSpacing, yPos);
        window.draw(cardSprite);
    }
}

void drawText(sf::RenderWindow &window, const string &str, sf::Vector2f pos, int size, sf::Color color = sf::Color::White)
{
    sf::Text text(str, gameFont, size);
    text.setPosition(pos);
    text.setFillColor(color);
    window.draw(text);
}

// NEW FUNCTION: Draws text centered horizontally on the screen at a given Y position.
void drawCenteredText(sf::RenderWindow &window, const string &str, float yPos, int size, sf::Color color = sf::Color::White)
{
    sf::Text text(str, gameFont, size);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(window.getSize().x / 2.0f, yPos);
    text.setFillColor(color);
    window.draw(text);
}

// --- Main Game Function ---
int main()
{
    sf::RenderWindow window(sf::VideoMode(850, 750), "SFML Card Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    if (!loadResources())
        return -1;
    createButtons();

    srand(time(NULL));
    shuffle(wDeck);
    cards_adder(player_cards, wDeck, 1, 5);
    cards_adder(computer_cards, wDeck, 6, 10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (currentGameState == PLAYING && event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    for (const auto &button : patternButtons)
                    {
                        if (button.isClicked(mousePos))
                        {
                            int scoreBefore = player_score;
                            // This now calls YOUR original function
                            player_hand_evaluater(player_cards, player_score, wDeck, button.patternName);

                            // Set UI message based on if score changed
                            if (player_score > scoreBefore)
                            {
                                playerMessage = "Correct! You declared " + button.patternName;
                            }
                            else
                            {
                                playerMessage = "Incorrect pattern declared.";
                            }

                            // This now calls YOUR original function
                            computer_hand_evaluater(computer_cards, computer_score, wDeck);

                            if (total_cards <= 1)
                            {
                                currentGameState = GAME_OVER;
                                statusMessage = "Game Over!";
                            }
                            else
                            {
                                currentGameState = EVALUATING;
                                statusMessage = "Evaluating hands... New round shortly.";
                                evaluationClock.restart();
                            }
                            break;
                        }
                    }
                }
            }
        }

        if (currentGameState == EVALUATING)
        {
            if (evaluationClock.getElapsedTime() > evaluationDisplayTime)
            {
                currentGameState = PLAYING;
                playerMessage = "";
                computerMessage = "";
                statusMessage = "Choose a pattern for your hand.";
            }
        }

        window.clear(sf::Color(11, 79, 39));

        // Use the new centered drawing function for titles
        drawCenteredText(window, "Computer's Hand", 35, 24);
        drawHand(window, computer_cards, 60, currentGameState != GAME_OVER && currentGameState != EVALUATING);

        drawCenteredText(window, "Player's Hand", 425, 24);
        drawHand(window, player_cards, 450, false);

        // Keep scores and deck info left-aligned
        drawText(window, "Player Score: " + std::to_string(player_score), {50, 250}, 22);
        drawText(window, "Computer Score: " + std::to_string(computer_score), {50, 280}, 22);
        drawText(window, "Cards Left in Deck: " + std::to_string(total_cards), {50, 310}, 22, sf::Color::Yellow);

        if (currentGameState == PLAYING)
        {
            for (auto &button : patternButtons)
            {
                button.draw(window);
            }
        }

        drawText(window, playerMessage, {50, 550}, 20, sf::Color(173, 216, 230));
        drawText(window, computerMessage, {50, 580}, 20, sf::Color(255, 182, 193));

        // Use the new centered drawing function for status messages
        sf::Color statusColor = (currentGameState == GAME_OVER) ? sf::Color::Red : sf::Color::White;
        drawCenteredText(window, statusMessage, 385, 24, statusColor);

        if (currentGameState == GAME_OVER)
        {
            std::string finalMessage;
            if (player_score > computer_score)
                finalMessage = "You Win!";
            else if (computer_score > player_score)
                finalMessage = "Computer Wins!";
            else
                finalMessage = "It's a Tie!";
            drawCenteredText(window, finalMessage, 345, 40, sf::Color::Yellow);
        }

        window.display();
    }

    return 0;
}

void shuffle(int wDeck[][FACES])
{
    int row, column, card;
    for (card = 1; card <= CARDS; card++)
    {
        do
        {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
}

void cards_adder(vector<vector<int>> &current_hand, int wDeck[][FACES], int start, int end)
{
    for (int card = start; card <= end; card++)
    {
        for (int row = 0; row < SUITS; row++)
        {
            for (int column = 0; column < FACES; column++)
            {
                if (wDeck[row][column] == card)
                {
                    current_hand.push_back({row, column});
                }
            }
        }
    }
}

void discarder(vector<vector<int>> &current_hand, string check_pattern)
{
    vector<vector<int>> discard_vector;
    if (check_pattern == "highcard")
    {
        discard_vector.push_back(current_hand[0]);
    }
    if (check_pattern == "onepair")
    {
        for (int card = 0; card < 4; ++card)
        {
            for (int c_card = card + 1; c_card < 5; ++c_card)
            {
                if (current_hand[card][1] == current_hand[c_card][1])
                {
                    discard_vector.push_back(current_hand[card]);
                    discard_vector.push_back(current_hand[c_card]);
                }
            }
        }
    }
    if (check_pattern == "twopair")
    {
        int freq[13] = {0};
        for (int i = 0; i < 5; i++)
        {
            freq[current_hand[i][1]]++;
        }

        int pairs = 0;
        vector<int> pair_ranks;
        for (int i = 0; i < 13; i++)
        {
            if (freq[i] == 2)
            {
                pairs++;
                pair_ranks.push_back(i); // stores rank only if it appears two times.
            }
        }
        if (pairs == 2)
        {
            for (int i = 0; i < 5; i++)
            {
                int rank = current_hand[i][1];
                if (rank == pair_ranks[0] || rank == pair_ranks[1])
                {
                    discard_vector.push_back(current_hand[i]);
                }
            }
        }
    }
    if (check_pattern == "fourofakind")
    {
        int freq[13] = {0};
        for (int i = 0; i < 5; i++)
        {
            freq[current_hand[i][1]]++;
        }
        for (int i = 0; i < 13; i++)
        {
            if (freq[i] == 4)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (current_hand[j][1] == i)
                    {
                        discard_vector.push_back(current_hand[j]);
                    }
                }
            }
        }
    }
    if (check_pattern == "threeofakind")
    {
        int freq[13] = {0};
        for (int i = 0; i < 5; i++)
        {
            freq[current_hand[i][1]]++;
        }
        for (int i = 0; i < 13; i++)
        {
            if (freq[i] == 3)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (current_hand[j][1] == i)
                    {
                        discard_vector.push_back(current_hand[j]);
                    }
                }
            }
        }
    }
    vector<vector<int>> to_remove;
    for (const auto &dcard : discard_vector)
    {
        for (const auto &ccard : current_hand)
        {
            if (ccard[1] == dcard[1])
            {
                to_remove.push_back(ccard);
            }
        }
    }
    for (const auto &card : to_remove)
    {
        current_hand.erase(remove(current_hand.begin(), current_hand.end(), card), current_hand.end());
    }
}
int high_card_check(const vector<vector<int>> &current_hand)
{
    if (one_pair_check(current_hand))
    {
        return 0;
    };
    return 1;
}
int one_pair_check(const vector<vector<int>> &current_hand)
{
    for (int card = 0; card < 4; ++card)
    {
        for (int c_card = card + 1; c_card < 5; ++c_card)
        {
            if (current_hand[card][1] == current_hand[c_card][1])
            {
                return 1;
            }
        }
    }
    return 0;
}
int two_pair_check(const vector<vector<int>> &current_hand)
{
    int freq[13] = {0};
    for (int i = 0; i < 5; i++)
    {
        freq[current_hand[i][1]]++;
    }

    int pairs = 0;
    for (int i = 0; i < 13; i++)
    {
        if (freq[i] == 2)
        {
            pairs++;
        }
    }
    if (pairs == 2)
    {
        return 1;
    }

    return 0;
}

int three_face_check(const vector<vector<int>> &current_hand)
{
    int freq[13] = {0};
    for (int i = 0; i < 5; i++)
    {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++)
    {
        if (freq[i] == 3)
        {
            return 1;
        }
    }

    return 0;
}
int four_face_check(const vector<vector<int>> &current_hand)
{
    int freq[13] = {0};
    for (int i = 0; i < 5; i++)
    {
        freq[current_hand[i][1]]++;
    }
    for (int i = 0; i < 13; i++)
    {
        if (freq[i] == 4)
        {
            return 1;
        }
    }
    return 0;
}

int flush_check(const vector<vector<int>> &current_hand)
{
    int card;
    int suit = current_hand[0][0];
    for (card = 0; card < 5; card++)
    {
        if (suit != current_hand[card][0])
        {
            return 0;
        }
    }
    return 1;
}
int straight_check(const vector<vector<int>> &current_hand)
{
    int face_arr[5] = {current_hand[0][1], current_hand[1][1], current_hand[2][1], current_hand[3][1], current_hand[4][1]};
    sort(face_arr, face_arr + 5);
    int i = 0, sum = 0;
    for (i = 0; i < 4; i++)
    {
        if ((face_arr[i + 1] - face_arr[i]) == 1)
        {
            sum++;
        }
    }
    if (sum == 4)
    {
        return 1;
    }
    return 0;
}
int straight_flush_check(const vector<vector<int>> &current_hand)
{

    if (straight_check(current_hand) && flush_check(current_hand))
    {
        return 1;
    }
    return 0;
}
int housefull_check(const vector<vector<int>> &current_hand)
{
    if (three_face_check(current_hand))
    {
        int key = 0;
        int freq[13] = {0};
        for (int i = 0; i < 5; i++)
        {
            freq[current_hand[i][1]]++;
        }
        for (int i = 0; i < 13; i++)
        {
            if (freq[i] == 3)
            {
                int key = freq[i];
            }
        }
        int pairs = 0;
        for (int i = 0; i < 13; i++)
        {
            if (freq[i] != key && freq[i] == 2)
                pairs++;
        }
        if (pairs == 1)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int royal_flush(const vector<vector<int>> &current_hand)
{
    vector<int> five_faces;
    const int majestic_flush[5] = {0, 10, 11, 12, 13};
    if (flush_check(current_hand))
    {
        int freq[13] = {0};
        int matches = 0;
        for (int i = 0; i < 5; i++)
        {
            freq[current_hand[i][1]]++;
            five_faces.push_back(current_hand[i][1]);
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (majestic_flush[i] == five_faces[j])
                {
                    matches++;
                }
            }
        }
        if (matches == 5)
        {
            five_faces.clear();
            return 1;
        }
    }
    five_faces.clear();
    return 0;
}

void computer_hand_evaluater(vector<vector<int>> &current_hand, int &score, int wDeck[][FACES])
{
    computerMessage = ""; // Clear previous message
    if (total_cards <= 0)
        return;

    if (royal_flush(current_hand))
    {
        computerMessage = "Computer had: Royal Flush";
        score += 10;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (straight_flush_check(current_hand))
    {
        computerMessage = "Computer had: Straight Flush";
        score += 9;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (four_face_check(current_hand))
    {
        computerMessage = "Computer had: Four of a Kind";
        score += 8;
        discarder(current_hand, "fourofakind");
        total_cards -= 4;
        cards_adder(current_hand, wDeck, start_card, start_card + 3);
        start_card += 4;
    }
    else if (housefull_check(current_hand))
    {
        computerMessage = "Computer had: Full House";
        score += 7;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (flush_check(current_hand))
    {
        computerMessage = "Computer had: Flush";
        score += 6;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (straight_check(current_hand))
    {
        computerMessage = "Computer had: Straight";
        score += 5;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (three_face_check(current_hand))
    {
        computerMessage = "Computer had: Three of a Kind";
        score += 4;
        discarder(current_hand, "threeofakind");
        total_cards -= 3;
        cards_adder(current_hand, wDeck, start_card, start_card + 2);
        start_card += 3;
    }
    else if (two_pair_check(current_hand))
    {
        computerMessage = "Computer had: Two Pair";
        score += 3;
        discarder(current_hand, "twopair");
        total_cards -= 4;
        cards_adder(current_hand, wDeck, start_card, start_card + 3);
        start_card += 4;
    }
    else if (one_pair_check(current_hand))
    {
        computerMessage = "Computer had: One Pair";
        score += 2;
        discarder(current_hand, "onepair");
        total_cards -= 2;
        cards_adder(current_hand, wDeck, start_card, start_card + 1);
        start_card += 2;
    }
    else
    {
        vector<int> five_faces = {current_hand[0][1], current_hand[1][1], current_hand[2][1], current_hand[3][1], current_hand[4][1]};
        int highest_card = *max_element(five_faces.begin(), five_faces.end());
        computerMessage = "Computer had: High Card";
        score += highest_card;
        discarder(current_hand, "highcard");
        total_cards -= 1;
        cards_adder(current_hand, wDeck, start_card, start_card);
        start_card += 1;
    }
}

void player_hand_evaluater(vector<vector<int>> &current_hand, int &score, int wDeck[][FACES], string pattern)
{
    if (total_cards <= 0)
        return;

    if (pattern == "royalflush" && royal_flush(current_hand))
    {
        score += 10;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (pattern == "straightflush" && straight_flush_check(current_hand))
    {
        score += 9;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (pattern == "fourofakind" && four_face_check(current_hand))
    {
        score += 8;
        discarder(current_hand, pattern);
        total_cards -= 4;
        cards_adder(current_hand, wDeck, start_card, start_card + 3);
        start_card += 4;
    }
    else if (pattern == "fullhouse" && housefull_check(current_hand))
    {
        score += 7;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (pattern == "flush" && flush_check(current_hand))
    {
        score += 6;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (pattern == "straight" && straight_check(current_hand))
    {
        score += 5;
        current_hand.clear();
        total_cards -= 5;
        cards_adder(current_hand, wDeck, start_card, start_card + 4);
        start_card += 5;
    }
    else if (pattern == "threeofakind" && three_face_check(current_hand))
    {
        score += 4;
        discarder(current_hand, pattern);
        total_cards -= 3;
        cards_adder(current_hand, wDeck, start_card, start_card + 2);
        start_card += 3;
    }
    else if (pattern == "twopair" && two_pair_check(current_hand))
    {
        score += 3;
        discarder(current_hand, pattern);
        total_cards -= 4;
        cards_adder(current_hand, wDeck, start_card, start_card + 3);
        start_card += 4;
    }
    else if (pattern == "onepair" && one_pair_check(current_hand))
    {
        score += 2;
        discarder(current_hand, pattern);
        total_cards -= 2;
        cards_adder(current_hand, wDeck, start_card, start_card + 1);
        start_card += 2;
    }
    else if (pattern == "highcard" && high_card_check(current_hand))
    {
        score += 1;
        discarder(current_hand, pattern);
        total_cards -= 1;
        cards_adder(current_hand, wDeck, start_card, start_card);
        start_card += 1;
    }
}
