//Program to keep duplicate character in a string d distance away in o(n)
#include<stdio.h>
#include<string.h>
 char str[]="geeksforgeeks";
 int n;
 int visited[20]={-1};
 int currentindex=0;
 int d=3;
 int count=0;
 void swap(int p,int q){char temp;if(q>n-1){ str[p]='\0';return;}printf("%d%d\n",p,q);temp=str[p];str[p]=str[q];str[q]=temp;}
void removeaway(char *a){
	if(!a){
	printf("Empty string");
	return;
	}

	while(*(a+d)!='\0')
	{
	 //This is visted first time

	 if(visited[*a]==-1){

		 visited[*a]=count;
		count++;

		a++;
		continue;
		}

		if(visited[*a]!=-1){
		if(str[count]==str[visited[*a]+d]){
		count++;
		a++;
		continue;}
		else if(count>visited[*a]+d){
		swap(count,visited[*a]+d);
		visited[*a]=visited[*a]+d;
		 a=&str[visited[*a]+d];
       count=visited[*a]+d;
		}
		else{swap(count,visited[*a]+d);
       // visited[*a]=visited[*a]+d;
		}
		}



	}

}


void main(){
  int i;
  n=strlen(str);

  for(i=0;i<n;i++)
	 visited[str[i]]=-1;
  //printf("%s",str);
 removeaway(str);
  printf("%s",str);




}