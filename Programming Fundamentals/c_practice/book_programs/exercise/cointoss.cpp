#include <iostream>
#include <time.h>
using namespace std;

int main() {
srand(time(NULL));
int i = 0, heads_counter = 0 , tails_counter = 0;
for (i = 1 ; i <= 100 ; i++) {
int r = 1 + rand() % 2;
if (r == 1) {
    cout << "Heads" << endl;
    heads_counter++;
} else {
    cout << "Tails" << endl;
    tails_counter++;
}
}
cout << "Heads count " << heads_counter << endl;
cout << "Tails count " << tails_counter << endl;

return 0;
}
int flip(void) {

}
