#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
struct menuItemType {
string menuItem;
double menuPrice;
};
void getdata(menuItemType arr_item[]);
void showMenu(menuItemType arr_item[]);
double price_checker(string item);
void printCheck(vector <string> items);
int main() {
menuItemType menuList[8];
getdata(menuList);
showMenu(menuList);
}
void getdata(menuItemType arr_item[]) {
string items[8] = {"Plain Egg", "Bacon and Egg", "Muffin", "French Toast", "Fruit Basket", "Cereal", "Coffee", "Tea"};
double prices[8] = {1.45, 2.45, 0.99, 1.99, 2.49, 0.69, 0.50, 0.75};
for (int i = 0 ; i < 8 ; i++) {
    arr_item[i].menuItem = items[i];
    arr_item[i].menuPrice = prices[i];
}
}
void showMenu(menuItemType arr_item[]) {
    string food;
    vector <string> items_list;
    cout << "Welcome to Johnny's Restaurant\n";
    for(int i = 0 ; i < 8 ; i++) {
        cout << setw(20) << left << setfill(' ') << arr_item[i].menuItem << "$" << arr_item[i].menuPrice << endl;
    }
    cout << "What would you want to have(e to exit) ?\n";
    int i = 1;
    do {
        cout << "Item " << i << ": ";
        getline(cin, food);
        if (food != "e") {
        items_list.push_back(food);
        }
        i++;
    } while (food != "e");
    printCheck(items_list);

}
double price_checker(string item) {
    double price = 0;
     if (item == "Plain Egg") {
        price = 1.45;
    } else if (item == "Bacon and Egg") {
        price = 2.45;
    } else if (item == "Muffin") {
        price = 0.99;
    } else if (item == "French Toast") {
        price = 1.99;
    } else if (item == "Fruit Basket") {
        price = 2.49;
    } else if (item == "Cereal") {
        price = 0.69;
    } else if (item == "Coffee") {
        price = 0.50;
    } else if (item == "Tea") {
        price = 0.75;
    }
    return price;
}
void printCheck(vector <string> items) {
cout << "Your bill\n";
double total = 0;
for (int i = 0 ; i < items.size(); i++) {
    double price = price_checker(items[i]);
    cout << setw(20) << left << setfill(' ') << items[i] << "$" <<setprecision(3)<< price << endl;
    total += price;
}
    double tax = 5 * total / 100;
    total += tax;
    cout << setprecision(3) << setw(20) << left << setfill(' ') <<"Tax"<<"$"<<tax << endl;
    cout << setw(20) << left << setfill(' ') <<"Amount Due"<<"$"<<total;

}
