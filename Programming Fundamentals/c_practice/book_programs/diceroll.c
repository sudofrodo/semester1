
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 7
// function main begins program execution
int main( void )
{
size_t face; // random die value 1 - 6
unsigned int roll; // roll counter 1-6,000,000
unsigned int frequency[ SIZE ] = { 0 }; // clear counts
srand( time( NULL ) ); // seed random number generator
// roll die 6,000,000 times
for ( roll = 1; roll <= 6000000; ++roll ) {
face = 1 + rand() % 6;
++frequency[ face ]; // replaces entire switch of Fig. 5.8
} // end for
printf( "%s%17s\n", "Face", "Frequency" );
// output frequency elements 1-6 in tabular format
for ( face = 1; face < SIZE; ++face ) {
printf( "%4d%17d\n", face, frequency[ face ] );
} // end for
} // end main
