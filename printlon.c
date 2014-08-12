//Program to print longest substring without any repeating character
#include<stdio.h>
int visited[20];
  char str[]="geeksforgepks";
  int max_length=0;
void reset_visited(){

  int i=0;
  while(str[i]!='\0'){

	 visited[str[i]]=0;
	 i++;
  }

}


void print_longest_substring_unrepeated(){
		int i=0,local_max_length=0,last_index=0;
		 while(str[i]!='\0'){
		  if(!visited[str[i]]){
			 local_max_length++;
			if(max_length<local_max_length)
			 max_length=local_max_length;




			 last_index=i;
			 visited[str[i]]=1;


		  }
			else{

				//Reset visited array to zero
				reset_visited();
				//Reset local_max_length
				 local_max_length=1;
				 visited[str[i]]=1;
			}


			i++;


		 }









}





void main(){
print_longest_substring_unrepeated();

printf("Maximum non-repeating length is %d", max_length);

}