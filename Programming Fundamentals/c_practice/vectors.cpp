#include <iostream>
#include <vector>
using namespace std;
int main() {
vector<int> v1;
vector<int> v2(5);
vector<int> v3(5,10);
vector<int> v = {1,2,3};
v[2] = 100;
int x = v.at(2);
cout << x << endl;
for (int x : v)
    cout << x << "";
    cout << endl;
//v.clear();
for (int x : v)
    cout << x << "";
    cout << endl;
cout << v.empty() << endl;
v.resize(2);
for (int x : v)
    cout << x << "";
    cout << endl;
return 0;

}
