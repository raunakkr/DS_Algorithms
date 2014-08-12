# include<stdio.h>
# define MAX_SIZE 100
  int n=2;

 
void _printParenthesis(int pos,int open, int close)
{
  static char a[MAX_SIZE];

  if(close == n)
  {
	 printf("%s \n", a);
	 return;
  }
  else
  {
	 if(open > close) {
		  a[pos] = '}';
		  _printParenthesis(pos+1,open, close+1);
	 }
	 if(open < n) {
		 a[pos] = '{';
		 _printParenthesis(pos+1,open+1, close);
	 }
  }
}

/* driver program to test above functions */
int main()
{

  _printParenthesis(0,0,0);
  return 0;
}
