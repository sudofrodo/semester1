#include <iostream>
using namespace std;
/* number union definition */
union number {
   int x;
   double y;
}; /* end union number */

int main()
{
   union number value; /* define union variable */

   value.x = 100; /* put an integer into the union */
   cout<<"Put a value in the integer member"
       <<"and print both members."<<endl
       <<"int:   "<< value.x<<endl
       <<"double:"<< value.y<<endl;

   value.y = 100.0; /* put a double into the same union */
   cout<<"Put a value in the double member"
       <<"and print both members."<<endl
       <<"int:   "<< value.x<<endl
       <<"double:"<< value.y<<endl;

   return 0; /* indicates successful termination */

} /* end main */

