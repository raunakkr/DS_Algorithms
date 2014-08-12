//simple structure example

#include<stdio.h>
void main()
{

 struct student{
	int age;
	int roll;

 };

 struct student st;
 printf("Enter age and roll no. of student");
scanf("%d%d",&st.age,&st.roll);
 printf("%d%d",st.age,st.roll);



}