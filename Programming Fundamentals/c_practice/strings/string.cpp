#include <iostream>
#include <string>
using namespace std;
int main() {
string x("hello");
string y = "world! ";
string z;

char t[] = {'m','i','l','\0'};
char *p = " is here.";
z = x + " " + y + t + p;
cout << z;
cout << endl << z.length() << endl << "size " << x.size();
bool l = z.empty();
cout << l;
string sub = x.substr(0,4);
cout << endl <<sub;
string addstr = " athar here.";
x.insert(5, addstr);
cout << endl<<x;
x.replace(6,5,"arifa");
cout << endl << x;
string rase = "pallard";
rase.erase(0,3);
cout << rase;
rase.clear();
cout << rase;
int index = x.find("o");
cout << endl << index;
int rindex = x.rfind("o");
cout << endl << rindex;
return 0;
}
