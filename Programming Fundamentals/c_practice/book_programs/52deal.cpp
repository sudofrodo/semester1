void deal(int wDeck[][FACES], const char *wFace[], const char *wSuit[]) {
int card, row , column;
for (card = 1 ; card <= CARDS; ++card) {
    for (row = 0; row < SUITS; ++row) {
        for (column = 0 ; column < FACES ; ++column) {
            if (wDeck[row][column] == card) {
           cout << wFace[column] << " of " << wSuit[ row ] << (card % 2 == 0 ? '\n' : '\t');
            }

        }
    }
}
}
