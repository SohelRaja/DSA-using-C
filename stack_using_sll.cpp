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
nd *top=NULL;
nd *tag=NULL;
int total=0;
void insert_value();
void push(int);
void pop();
void display();
void option();
void list_delete();
int main()
{
	insert_value();
	return 0;
}
void insert_value()
{
	system("cls");
	int value,flag=true;
	char ch;
	printf("\n\n......STACK USING SINGLY LINK LIST......\n");
	while(flag==true)
	{
		printf("\nEnter a value : ");
		scanf("%d",&value);
		push(value);
		printf("\nDo you want to insert another node into the stack(y/n)?\n");
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
void option()
{
	int op;
	printf("\n\n......STACK USING SINGLY LINK LIST......\n");
	printf("\n\t\tMENU\n");
	printf("\nPress_1 :PUSH operation.");
	printf("\nPress_2 :DISPLAY.");
	printf("\nPress_3 :POP operation.");
	printf("\nPress_4 :DELETE ENTIRE STACK.");
	printf("\nPress_5 :EXIT.");
	printf("\n\nEnter your option : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			insert_value();
			break;
		case 2:
			display();
			break;
		case 3:
			pop();
			break;
		case 4:
			list_delete();
			break;
		case 5:
			system("cls");
			printf("\nMade by SRM10\n");
			exit(0);
		default:
			printf("\n*****Invalid input.*****\n");
			option();
	}
}
void push(int value)
{
	nd *ptr;
	total++;
	ptr=(nd *)malloc(sizeof(nd));
	ptr->next=NULL;
	ptr->data=value;
	if(total==1)
	top=tag=ptr;
	else
	{
		top->next=ptr;
		top=top->next;
	}
	printf("\nTotal number of nodes : %d\n",total);
}
void pop()
{
	if(top==tag)
	{
		free(top);
		top=tag=NULL;
	}
	else
	{
		nd *ptr=tag;
		while(ptr->next!=top)
		{
			ptr=ptr->next;
		}
		printf("%d is deleted.",top->data);
		free(top);
		top=ptr;
		ptr->next=NULL;
	}
	printf("\nTotal number of nodes : %d\n",--total);
	option();
}
void display()
{
	nd *ptr=tag;
	if(top==NULL)
	printf("There is no node.\n");
	else
	{	printf("\nTotal number of nodes : %d\n",total);
		printf("\nElements of the Stack :\n");
		while(ptr!=top->next)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
	option();
}
void list_delete()
{
	nd *ptr=tag;
	char ch;
	system("cls");
	if(top==NULL)
	printf("There is no node.\n");
	else
	{
		printf("\n***DELETE ENTIRE STACK***\n");
		printf("\nTotal number of nodes : %d\n",total);
		while(top!=NULL)
		{
			if(top==tag)
			{
				printf("\n%d is delete.",top->data);
				free(top);
				top=tag=NULL;
				total--;
			}
			else
			{
				
				ptr=tag;
				while(ptr->next!=top)
				{
					ptr=ptr->next;
				}
				printf("\n%d is delete.",top->data);
				free(top);
				top=ptr;
				ptr->next=NULL;
				total--;
			}
		}
	}
	printf("\nTotal number of node remaining in the STACK : %d",total);
	printf("\n\nDO YOU WANTS TO CREATE A NEW STACK(y/n)?\n");
	ch=getch();
	if(ch=='y' || ch=='Y')
	insert_value();
	else
	{
		system("cls");
		printf("\nMade by SRM10\n");
		exit(0);
	}
}
