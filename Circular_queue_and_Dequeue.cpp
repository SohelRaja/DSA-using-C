/*Insertion and Deletion using Circular Queue .*/
/*Circular Queue follows FIFO rule.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void inrear();
void delfront();
void display();
void infront();
void delrear();
int rear=-1,front=-1,value;
int cq[MAX];
int main()
{
	int ch;
	while(true)
	{
		printf("\nMENU:\n");
		printf("\nPress 1 for Insertion through REAR.(Circular Queue Insertion.)\n");
		printf("\nPress 2 for Deletion through REAR.(Dequeue Deletion.)\n");
		printf("\nPress 3 for Display.\n");
		printf("\nPress 4 for Deletion through FRONT.(Circular Queue Deletion.)\n");
		printf("\nPress 5 for Insertion through FRONT.(Dequeue Insertion.)\n");
		printf("\nPress 6 for EXIT.\n");
		printf("\nEnter your choice:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:inrear();
			break;
			case 4:delfront();
			break;
			case 3:display();
			break;
			case 5:infront();
			break;
			case 2:delrear();
			break;
			case 6:exit(1);
			default :system("cls");
			printf("\nInvalid Input.\n");	
		}
	}
	return 0;
}
void inrear(){
	system("cls");
	if(front==-0&&rear==MAX-1||front==rear+1)
	{
		printf("\nQueue is full.\n");
	}
	else
	{
		if(front==-1)
		{
			front=0;
			rear=0;
		}
		else if(rear==MAX-1)
		{
			rear=0;
		}
		else
		{
			rear++;
		}
		printf("\nInsert an element:\t");
		scanf("%d",&value);
		cq[rear]=value;
		printf("\nInsertion successful.\n");
	}
}
void delfront(){
	system("cls");
	if(front==-1)
	{
		printf("\nQueue is empty.\n");
	}
	else
	{
		value=cq[front];
		printf("\n%d successfully deleted.\n",value);
		if(rear==front)
		{
			rear=-1;
			front=-1;
		}
		else if(front==MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}
	}
}
void display(){
	system("cls");
	int i;
	if(rear==-1||front==-1)
	{
		printf("\nCreated by Sohel Raja Molla.\n");
		printf("\nQueue is empty.\n");
	}
	else
	{
		printf("Inserted elements are :\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",cq[i]);
		}
		printf("\n");
	}
}
void infront(){
	system("cls");
	if(front==0&&rear==MAX-1)
	{
		printf("\nQueue is full.\n");
	}
	else
	{
			front--;
			printf("\nInsert an element:\t");
			scanf("%d",&value);
			cq[front]=value;
			
			printf("\nInsertion successful.\n");	
	}
}
void delrear(){
	system("cls");
	if(rear==-1)
	{
		printf("\nQueue is empty.\n");
	}
	else
	{
		
		value=cq[rear];
		printf("\n%d successfully deleted.\n",value);
		rear--;
		if(rear==-1)
		{
			front=-1;
		}
		
	}
}
