#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

const int WIDTH = 800, HEIGHT = 600;
const int TILE_SIZE = 32;
const int ROWS = 16, COLS = 16, MINES = 40;

int grid[ROWS][COLS]; // -1: mine, 0-8: number
bool revealed[ROWS][COLS];
bool flagged[ROWS][COLS];
bool gameOver = false;

void placeMines() {
    int placed = 0;
    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (grid[r][c] == -1) continue;
        grid[r][c] = -1;
        placed++;
    }
    // Calculate numbers
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == -1) continue;
            int count = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == -1)
                        count++;
                }
            }
            grid[r][c] = count;
        }
    }
}

void reveal(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || revealed[r][c] || flagged[r][c]) return;
    revealed[r][c] = true;
    if (grid[r][c] == 0) {
        for (int dr = -1; dr <= 1; dr++)
            for (int dc = -1; dc <= 1; dc++)
                if (dr != 0 || dc != 0) reveal(r + dr, c + dc);
    }
    if (grid[r][c] == -1) gameOver = true;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    placeMines();

    sf::RenderWindow window(sf::VideoMode(COLS * TILE_SIZE, ROWS * TILE_SIZE), "Minesweeper");
    sf::Font font;
    font.loadFromFile("arial.ttf");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!gameOver && event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x / TILE_SIZE;
                int y = event.mouseButton.y / TILE_SIZE;
                if (event.mouseButton.button == sf::Mouse::Left)
                    reveal(y, x);
                else if (event.mouseButton.button == sf::Mouse::Right)
                    flagged[y][x] = !flagged[y][x];
            }
        }

        window.clear(sf::Color::White);

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                sf::RectangleShape tile(sf::Vector2f(TILE_SIZE - 2, TILE_SIZE - 2));
                tile.setPosition(c * TILE_SIZE + 1, r * TILE_SIZE + 1);

                if (revealed[r][c]) {
                    tile.setFillColor(grid[r][c] == -1 ? sf::Color::Red : sf::Color(200, 200, 200));
                    window.draw(tile);

                    if (grid[r][c] >= 1 && grid[r][c] <= 8) {
                        sf::Text text;
                        text.setFont(font);
                        text.setString(std::to_string(grid[r][c]));
                        text.setCharacterSize(18);
                        text.setFillColor(sf::Color::Black);
                        text.setPosition(c * TILE_SIZE + 8, r * TILE_SIZE + 5);
                        window.draw(text);
                    }
                } else {
                    tile.setFillColor(sf::Color(100, 100, 100));
                    window.draw(tile);

                    if (flagged[r][c]) {
                        sf::Text text;
                        text.setFont(font);
                        text.setString("F");
                        text.setCharacterSize(18);
                        text.setFillColor(sf::Color::Yellow);
                        text.setPosition(c * TILE_SIZE + 8, r * TILE_SIZE + 5);
                        window.draw(text);
                    }
                }
            }
        }

        window.display();
    }

    return 0;
}
