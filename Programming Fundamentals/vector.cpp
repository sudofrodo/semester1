#include <iostream>
#include<vector>
using namespace std;
int main() {
    vector <int> vec(5);
cout<<vec.size()<<endl;
    for(int i=0 ;i<vec.size();i++)
       cin>>vec[i];
    vec.insert(vec.begin()+2,25);
     vec.insert(vec.end(),25);
     vec.push_back(3);
     //vec.pop_back();
    for(int i :vec)
       cout<<i<<endl;
       cout<<vec.size()<<endl;
       cout<<vec.empty()<<endl;
       vec.clear();
       cout<<vec.empty()<<endl;
       vec.resize(10);
       cout<<vec.size()<<endl;

    return 0;
}
