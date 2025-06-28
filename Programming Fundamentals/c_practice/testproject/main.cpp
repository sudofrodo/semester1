#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;
// Define a card structure
struct Card {
    std::string rank;
    std::string suit;
};

const std::string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const std::string symbols[] = {"\u2665", "\u2666", "\u2663", "\u2660"}; // Unicode for ♥ = heart, etc.
const std::string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

// Function to create a full deck of cards
std::vector<Card> createDeck() {
    std::vector<Card> deck;
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back({rank, suit});
        }
    }
    return deck;
}

// Function to shuffle the deck
void shuffleDeck(std::vector<Card>& deck) {
    std::srand(unsigned(std::time(nullptr)));
    std::random_shuffle(deck.begin(), deck.end());
}

// Function to draw a basic card as a rectangle with text
sf::RectangleShape drawCard(const Card& card, const sf::Font& font, float x, float y) {
    sf::RectangleShape shape(sf::Vector2f(100, 150));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2);

    int suitIndex = std::distance(suits, std::find(suits, suits+4, card.suit));
    std::string symbol = symbols[suitIndex];

    sf::Text text;
    text.setFont(font);
    text.setString(card.rank + "\n" + card.suit);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 10, y + 10);

    return shape;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Card Game");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1; // Ensure you have arial.ttf in your working directory
    }

    std::vector<Card> deck = createDeck();
    shuffleDeck(deck);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0, 128, 0)); // Green felt background

        // Draw 5 cards from the shuffled deck
        for (int i = 0; i < 5; ++i) {
            sf::RectangleShape cardShape(sf::Vector2f(100, 150));
            cardShape.setPosition(50 + i * 120, 200);
            cardShape.setFillColor(sf::Color::White);
            cardShape.setOutlineColor(sf::Color::Black);
            cardShape.setOutlineThickness(2);
            window.draw(cardShape);

            sf::Text text;
            text.setFont(font);
            text.setString(deck[i].rank + "\n" + deck[i].suit);
            text.setCharacterSize(16);
            text.setFillColor(sf::Color::Black);
            text.setPosition(50 + i * 120 + 10, 210);
            window.draw(text);
        }

        window.display();
    }
    return 0;
}

