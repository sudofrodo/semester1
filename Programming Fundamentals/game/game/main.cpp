int main() {
const char *suit[SUITS] = {"Hearts" , "Diamonds" , "Clubs" , "Spades"};
const char *face[FACES] = { "Ace", "Deuce", "Three", "Four",
"Five", "Six", "Seven", "Eight",
"Nine", "Ten", "Jack", "Queen", "King" };

display_ascii_art_logo();
cout << endl;
display_intro_and_rules();
int player_score = 0 , computer_score = 0;
string pattern;
int deck[SUITS][FACES] = {0};
srand (time(NULL));
shuffle(deck);
computer_hand(deck, face, suit);
player_hand(deck, face , suit);
card_art();

cout << endl;

cout << "Cards Left : "<< total_cards<<  endl;
cout << "Computer's Point : " ;
computer_hand_evaluater(computer_cards,computer_score,deck);

display_hand_ascii_art(player_cards, "Player Cards");
cout << "What's your Pattern (e.g., 'royalflush', 'straightflush', 'fourofakind', 'fullhouse', 'flush', 'straight', threeofakind', 'twopair', 'onepair', 'highcard') : ";
cin >> pattern;
player_hand_evaluater(player_cards,player_score,deck,pattern);
clear_screen();
cout << endl;

}
cout << "Result : " << endl;
cout << "Your score : " << player_score << endl;
cout << "Computer score : " << computer_score << endl;
if (player_score > computer_score) {
    cout << "YOU WON!!!";
} else if (computer_score == player_score) {
     cout << "Its a Draw!";
} else {
    cout << "You lost!";
}
return 0;

}
