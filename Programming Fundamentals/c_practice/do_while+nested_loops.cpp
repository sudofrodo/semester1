#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main() {
//do while loop
/* we design the loop in such a way that the condition on which the input will be invalid ,
we write its inverse in the condition. e.g to make sure that user must input positive number , we will write condition
to check if number is negative , in this case condition will be true and loop will re-execute  */
//int num;
//do {
//    cout << "Enter a number" << endl;
//    cin >> num;
//}   while (num < 0);
//int num2;
//do {
//    cout << "Enter an even number" << endl;
//    cin >> num2;
//} while (num2 % 2 != 0);
//char c;
//do {
//    cout << "Input a character (A - E)" << endl;
//    cin >> c;
//} while (c > 'E' || c < 'A');
//int num3;
//do {
//    cin.clear();
//    cin.ignore();
//    cout << "Enter a value: ";
//    cin >> num3;
//}   while (!cin || num3 < 0);
//SENTINEL CONTROLLED LOOP
//int sum = 0;
//int num4;
//int counter = -1;
//cout << "Enter amounts (-1 to exit)" << endl;
//do {
//    counter++;
//    cin >> num4;
//    if (num4 > 0) {
//    sum += num4;
//    }
//
//} while ( num4 != -1);
/* since loop will be exited when condition is false hence we write num != -1 ,
which means when number is not -1 , condition will be true loop will re-execute,
when number is -1 ,condition is false loop is exited */
//cout << "Sum = " << sum << endl;
//cout << "Average = " << sum / counter << endl;
//char ch;
//do {
//    cout << "Do you want to save the document (press esc to exit)" << endl;
//    cin >> ch;
//    if (ch == 'y') {
//        cout << "Document saved." << endl;
//
//    }
//} while (ch != 27);
//ofstream thefile("score.txt");
//thefile << "23\n23\n33\n24";
//thefile.close();
//int score , sum = 0;
//cin >> score;
//do ( !cin.eof()) {
//ifstream thefile;
//sum += score;
//cin >> score;
//}
//cout << "Sum of the square is" << endl;
//NESTED LOOPS
for (int i=1; i<=5; i++){
    for (int j=1;j<=5;j++){
        cout << '*';
    }
    cout << endl;

}
cout << endl;
for(int x=0; x<3; x++) {
	    for(int y=0; y<3; y++) {
		cout << "* ";
	    }
	    cout << endl;
	}
cout << endl;
//uni
for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
		if( i==0 || j==0 || i==4 || j==4 )
                	    cout << "*";
            	else
                	    cout << " ";
           }
           cout << endl;
	}

for(int x=1; x<5; x++) {
	    for(int y=1; y<=x; y++) {
		cout << "*";
	    }
	    cout << endl;
	}
for(int x=1; x<5; x++) {
	    for(int y=x; y<5; y++) {
		cout <<  "*" ;
	    }
	    cout << endl;
	}
	int x = 0;
	while(x<5) {
 	     int y = 0;
	     while(y<5) {
		cout << "*";
		y++;
	     }
	cout << endl;
	x++;
	}

// to print even number till 10;
int x3 = 0;
bool flag = false;
while (flag == false)
{
    x3 += 2;
    if ( x3 > 10)
        flag = true;
    else
        cout << x3 << endl;

}
int i, num, product = 1;
	for(i=1; i<=5; i++)
	{
	     cout << "Enter a number: ";
	     cin >> num;
	     if (num==0)
		continue;
	     product = product*num;
	}
	cout << "Product " << product;










return 0;
}

