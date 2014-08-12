#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256

/* This function builds the TF table which represents Finite Automata for a
	given pattern  */
void computeTransFun(char *pat, int M, int TF[][NO_OF_CHARS])
{
	 int i, lps = 0, x;

	 // Fill entries in first row
	 for (x =0; x < NO_OF_CHARS; x++)
		 TF[0][x] = 0;
	 TF[0][pat[0]] = 1;

	 // Fill entries in other rows
	 for (i = 1; i<= M; i++)
	 {
		  // Copy values from row at index lps
		  for (x = 0; x < NO_OF_CHARS; x++)
				TF[i][x] = TF[lps][x];

		  // Update the entry corresponding to this character
		  TF[i][pat[i]] = i + 1;

		  // Update lps for next row to be filled
		  if (i < M)
			 lps = TF[lps][pat[i]];
	 }

	  for(i=0;i<=M;i++) {
		  for(x=0;x<5;x++)
			 printf("%d ",TF[i][x]);
			 printf("\n");
								 }

}

/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
	 int M = strlen(pat);
	 int i,j,N = strlen(txt);

	 int TF[6][256];

	 computeTransFun(pat, M, TF);

	 // process text over FA.
	 j=0;
	 for (i = 0; i < N; i++)
	 {
		 j = TF[j][txt[i]];
		 if (j == M)
		 {
			printf ("\n pattern found at index %d", i-M+1);
		 }
	 }
}

/* Driver program to test above function */
int main()
{
	 char *txt = "GEEKSFORGEEKS";
	 char *pat = "GEEKS";
	 search(pat, txt);
	 getchar();
	 return 0;
}
