#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int y;
    double x;
    cout << "Input number ";
    cin >> x;
    y = floor( x * 100 + .5 ) / 100;
    cout << "rounded " << y << endl;


    return 0;
}
