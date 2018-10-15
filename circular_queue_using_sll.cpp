#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node nd;
nd *rear=NULL;
nd *front=NULL;
int total=0;
void insert_value();
void node_create(nd *,int);
void option();
void display();
void node_delete();
void all_delete();
int main()
{
	front=rear;
	insert_value();
	return 0;	
}
void insert_value()
{
	system("cls");
	int value,flag=true;
	char ch;
	printf("\n\n...................CIRCULAR QUEUE USING LINK LIST..................\n");
	while(flag==true)
	{
		printf("\nEnter a value : ");
		scanf("%d",&value);
		node_create(rear,value);
		printf("\nDo you want to insert another node into the queue(y/n)?\n");
		ch=getch();
		if(ch=='Y' || ch=='y')
		{
			flag=true;
		}
		else
		{
			option();
		}
	}
}
void node_create(nd *insert,int value)
{
	insert=(nd *)malloc(sizeof(nd));
	total++;
	if(total==1)
	{
		rear=insert;
		front=rear;
	}
	rear->next=insert;
	insert->next=front;
	insert->data=value;
	rear=rear->next;
	printf("\nValue is inserted into the circular queue.\n");
	printf("\nTotal Number of Nodes = %d",total);
}
void option()
{
	int op;
	
	printf("\n\n..................CIRCULAR QUEUE USING LINK LIST..................\n");
	printf("\nPress_1 : Insertion.");
	printf("\nPress_2 : Display.");
	printf("\nPress_3 : Deletion.");
	printf("\nPress_4 : Delete Entire Link List.");
	printf("\nPress_5 : EXIT.");
	printf("\n\nEnter a option : ");
	scanf("%d",&op);
	printf("%c",7);
	switch(op)
	{
		case 1:
		insert_value();
		break;
		case 2:
		display();
		break;
		case 3:
		node_delete();
		break;
		case 4:
		all_delete();
		break;
		case 5:
		system("cls");
		system("color f5");
		printf("%c",7);
		printf("\n%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c\n",1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2);
		printf("%c**Made By Sohel Raja Molla.**%c\n",2,1);
		printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c ",1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2); 
		exit(0);
		default:
		printf("\n*****INVALID INPUT*****\n");
		option();
	}
}
void display()
{
	nd *ptr=front;
	if(front==NULL)
	printf("\nThere is no node.\nPlease Create First.\n");
	else
	{
		printf("\n\nDisplaying the value of created nodes: \n");
		do
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}while(ptr!=front);
	}
	option();
}
void node_delete()
{
	system("cls");
	nd *ptr;
	if(front==NULL)
	printf("\nThere is no node.\nPlease Create First.\n");
	else
	{
		ptr=front;
		front=front->next;
		if(front->next==front)
		{
			front=rear=NULL;
		}
		else
		rear->next=front;
		printf("\n%d is deleted.\n",ptr->data);
		free(ptr);
		printf("\nTotal Number of Nodes : %d",--total);
	}
	option();	
}
void all_delete()
{
	system("cls");
	int i;
	if(front==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		nd *ptr;
		printf("\n****DELETION OF ENTIRE LIST****");
		printf("\nTotal %d number of Node will be deleted.",total);
		for(i=1;i<=total;i++)
		{
			ptr=front;
			printf("\n%d is deleted.",ptr->data);
			front=front->next;
			free(ptr);
		}
		front=NULL;
	}
	option();
}
