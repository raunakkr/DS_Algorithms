// Dynamic Programming implementation of edit distance
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Change these strings to test the program
#define STRING_X "sa"
#define STRING_Y "s"

#define SENTINEL (-1)
#define EDIT_COST (1)


 int mint(int a,int b) {
	return a < b ? a : b;
}
// Returns Minimum among a, b, c
int Minimum(int a, int b, int c)
{
	 return mint(mint(a, b), c);
}



// Recursive implementation
int EditDistanceRecursion( char *X, char *Y, int m, int n )
{   int left,right,corner;
	 // Base cases
	 if( m == 0 && n == 0 )
		  return 0;

	 if( m == 0 )
		  return n;

	 if( n == 0 )
		  return m;

     // Recurse
	 left = EditDistanceRecursion(X, Y, m-1, n) + 1;
	 right = EditDistanceRecursion(X, Y, m, n-1) + 1;
	 corner = EditDistanceRecursion(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);

	 return Minimum(left, right, corner);
}

int main()
{
	 char X[] = STRING_X; // vertical
	 char Y[] = STRING_Y; // horizontal
	 printf("Minimum edits required to convert %s into %s is %d by recursion\n",
			  X, Y, EditDistanceRecursion(X, Y, strlen(X), strlen(Y)));

	 return 0;
}