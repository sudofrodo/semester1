#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;
int main() {
//cout << "hello!" << endl;
//int a = 10, b = 0;
//try {
//    if (b == 0)
//        throw "Division by zero error!";
//    cout << "Result " << a / b << endl;
//} catch (const char* msg) {
//cout << "Exception Caught: " << msg << endl;
//}
//int age;
//cout << "Enter your age : ";
//cin >> age;
//try {
//if (age < 18)
//    throw age;
//    cout << "You are eligible to vote!" << endl;
//} catch (int e) {
//cout << "Exception : Age " << e << " is not eligible to vote.";
//}
//try {
//throw 3.14;
//} catch (int e) {
//cout << "Caught int: " << e << endl;
//} catch(...) {
//cout << endl << "Caught an unknown exception!" << endl;
//}
vector<int>numbers = {1,2,3};
try {
cout << "Element at index 5: " << numbers.at(5) << endl;
} catch (const out_of_range& e) {
cout << "Built-in exception Caught: " << e.what() << endl;

}
return 0;
}
