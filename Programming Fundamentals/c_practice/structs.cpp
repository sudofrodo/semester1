#include <iostream>
using namespace std;

struct bottle {
string shape;
string color;
int units;
float designs;
double price;

}bot2,bot3;
struct point3d {
double x, y, z;
};
point3d getPoints() {
point3d temp = {0.1 , 0.2 , 0.3};
return temp;
}
void doit(struct point3d *b) {
    b ->x=  1;
}
struct employee{
    int age;
    double wage;
};
struct company{
    employee CEO;
    int numberOfEmployees;
};
struct arr {
    int x;
};
void dothat(struct arr b[]){
        b[0].x = 42;
        b[1].x = 34;
}
int main() {
//company myCompany;
//cout << myCompany.CEO.wage << endl;
//point3d mypoints = getPoints();
//cout << mypoints.x << " " << mypoints.y << "  " << mypoints.z << endl;
//doit(&mypoints);
//cout << mypoints.x << " " << mypoints.y << "  " << mypoints.z << endl;
arr b[2];
b[0].x = 20;
b[1].x = 32;
dothat(b);
cout << b[0].x << "  " << b[1].x << endl;
return 0;

}
