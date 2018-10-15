#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void push();
void pop();
void display();
int top=-1,array[MAX],value;
int main()
{
	int ch;
	printf("\nPush-Pop operation using Stack.\n");
	do
	{
		printf("\nMENU :\n");
		printf("Press 1 for Insertion(push).\n");
		printf("Press 2 for Deletion(pop).\n");
		printf("Press 3 for Display.\n");
		printf("Press 4 for Exit.\n");
		printf("Enter your choise:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :push();
					break;
			case 2 :pop();
					break;
			case 3 :display();
					break;
			case 4 :exit(1);
			default :printf("\nEnter correct option.\n");						
		}
	}while(true);
	return 0;
}
void push(){
	if(top==MAX-1)
	{
		printf("\nStack is full\n");
	}
	else
	{
		top=top+1;
		printf("\nInsert Element:\t");
		scanf("%d",&value);
		array[top]=value;
	}
}
void pop(){
	if(top==-1)
	{
	printf("\nStack is empty\n");
	}
	else
	{
		value=array[top];
		printf("\n%d was deleted.\n",value);
		top--;
	}
}
void display(){
	int i;
	if(top==-1)
	printf("\nStack is empty.\n");
	else{
	printf("\nThe elements are :\n");
	for(i=0;i<=top;i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
	}
}
