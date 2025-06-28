#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;
int main() {
//int seed;
//cout << "Input seed   ";
//cin >> seed;
//srand(seed);
srand(time(NULL));
int j;
for (j = 1 ; j <= 20 ; ++j) {

    cout << "     " << 1 + (rand() % 6) << "   ";
    if (j % 5 == 0) {
        puts("");
    }
}

return 0;
}
