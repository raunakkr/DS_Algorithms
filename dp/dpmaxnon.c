//Length of longest non-repeated substring
#include<stdio.h>
#include<string.h>

char str[]="abdefgabef";

 int visited[20];



  //Returns maximum of two nos.
  int max(int a,int b){

	 return a>b?a:b;

  }



int length_longest_non_repeated_substring(){

	  int i,cur_len=0,max_len=0,prev_index=0;

		for(i=0;i<strlen(str);i++)
		{
			if(visited[str[i]]==-1)
			{   //Update last index
					  visited[str[i]]=i;
					  cur_len++;
					  max_len=max(cur_len,max_len);
                  printf("Till %d-currnet length %d--Max length %d\n",i,cur_len,max_len);
				}
					  //Take care of conditions
			 else if(visited[str[i]]!=-1 && visited[str[i]]>=prev_index)
			 {
				 //If we are here it means we have found the duplicate character
				cur_len=i-visited[str[i]];
				//Update prev_index
				prev_index=visited[str[i]]+1;
				 max_len=max(cur_len,max_len);
				  visited[str[i]]=i;
					printf("Till %d-currnet length %d--Max length %d\n",i,cur_len,max_len);
			 }

			else {

				 cur_len++;
				 max_len=max(cur_len,max_len);
				  visited[str[i]]=i;
				  printf("Till %d-currnet length %d--Max length %d\n",i,cur_len,max_len); }

		}


		 return max_len;
}




void main(){
	  int i;
//Mark visited array as '-1' for all elements initially
	 for( i=0;i<strlen(str);i++)
		  visited[str[i]]=-1;

	 printf("Length of longest non-repeated substring  %d",length_longest_non_repeated_substring());

}