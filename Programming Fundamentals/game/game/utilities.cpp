void shuffle(int wDeck[][FACES]) {

    int row , column , card;
    for (card = 1; card <= CARDS ; ++card) {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(wDeck[row][column] != 0);
    wDeck[row][column] = card;
    }

}
