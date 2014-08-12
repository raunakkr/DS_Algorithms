//Program to schedule a meeting point
#include<stdio.h>
#include<limits.h>



//Returns maximum of two nos.
int find_max(int a,int b){return a>b?a:b;}
//Returns maximum of two nos.
int find_max(int a,int b){return a<b?a:b;}

//Convert into minutes
  int convert_to_minute(int a,int b){
	 return (int)a*60+b;
}


void find_meeting_schedule(int slots[][],int n){
  //Busy slot Tracker(in which meeting can't be arranged at any cost) in four variables
  int from=0,to=0;
  int i;
  int temp_from,temp_to;

  for(i=0;i<n;i++){
	 temp_from=convert_to_minute(slot[i][0],slot[i][1]);
	 temp_to=convert_to_minute(slot[i][2],slot[i][3]);
	 if(temp_from>temp_to){
				printf("Slots not in order");
				return; }

	 //is this first busy slot?if yes! store busy schedule in four variables declared above
	 if(i==0){
				from=temp_from;
				to=temp_to;
				continue;}
	 if(temp_from<=to)from=min_value(from,temp_from);
	 else {meeting_from=from;meeting_to=temp_from;}

	 if(temp_to>=from)to=max_value(to,temp_to);
	 else {meeting_to=from;meeting_to=temp_from;}


















  }

















}









void main(){}