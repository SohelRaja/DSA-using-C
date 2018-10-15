#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *previous;
	struct node *next;
};
typedef struct node nd;
nd *start=NULL;
int total;
char op;
void option();
void creat(nd *);
void display(nd *);
void insert_beg(nd *);
void insert_end(nd *);
void insert_before(nd *);
void insert_after(nd *);
void delete_beg(nd *);
void delete_end(nd *);
void delete_node(nd *);
void delete_after(nd *);
void delete_list(nd *);
int main()
{
	option();
	return 0;	
}
void option ()
{
	int option;
	printf("\n**********MENU***********\n");
	printf("\n 1:  Creat Link List as well as Node.");
	printf("\n 2:  Display List.");
	printf("\n 3:  Add a node at the beginning.");
	printf("\n 4:  Add a node at the end.");
	printf("\n 5:  Add a node before a given node.");
	printf("\n 6:  Add a node after a given node.");
	printf("\n 7:  Delete a node from beginning.");
	printf("\n 8:  Delete a node from end.");
	printf("\n 9:  Delete a Specified given node.");
	printf("\n 10: Delete entire list.");
	printf("\n 11: EXIT.");
	printf("\n\nEnter your option:\t");
	scanf("%d",&option);
	switch(option)
	{
		case 1: creat(start);
		break;
		case 2: display(start);
		break;
		case 3: insert_beg(start);
		break;
		case 4: insert_end(start);
		break;
		case 5: insert_before(start);
		break;
		case 6: insert_after(start);
		break;
		case 7: delete_beg(start);
		break;
		case 8: delete_end(start);
		break;
		case 9: delete_node(start);
		break;
		case 10: delete_list(start);
		break;
		case 11: exit(0);
		break;
		default: printf("\n****Invalid Choice****\n");
	}
}
void creat(nd *ptr)
{
	total=0;
	ptr=(nd *)malloc(sizeof(nd));
	printf("\nEnter a value: ");
	scanf("%d",&ptr->data);
	start=ptr;
	total++;
	printf("\nLink List Is Created.");
	ptr->previous=NULL;
	do
	{
		printf("\nDo you wants to create another node.\nThen press \'y\'.");
		op=getche();
		if(op=='y')
		{
			ptr->next=(nd *)malloc(sizeof(nd));
			ptr->next->previous=ptr;
			ptr=ptr->next;
			printf("\nEnter a value: ");
			scanf("%d",&ptr->data);
			printf("\nNode is created.");
			total++;
		}
	}while(op=='y');
	ptr->next=NULL;
	printf("\nTotal Number of nodes = %d\n\n",total);
	option();
}
void display(nd *ptr)
{
	if(start==NULL)
	{
		printf("\nLink is not created till now.\nPlease Creat a link list first.\n\n");
	}
	else
	{
	start=ptr;
	printf("\nLink List\'s elements are below,\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	}
	option();	
}
void insert_beg(nd *ptr)
{
	if(start==NULL)
	{
		creat(start);
	}
	else
	{
		ptr->previous=(nd *)malloc(sizeof(nd));
		ptr->previous->next=ptr;
		ptr->previous->previous=NULL;
		printf("\nEnter a value: ");
		scanf("%d",&ptr->previous->data);
		printf("\nTotal Number of nodes = %d\n\n",++total);
		start=ptr->previous;
	}
	option();
}
void insert_end(nd *ptr)
{
	if(start==NULL)
	creat(start);
	else
	{
		while(ptr->next!=NULL)
		ptr=ptr->next;
		ptr->next=(nd *)malloc(sizeof(nd));
		ptr->next->previous=ptr;
		ptr->next->next=NULL;
		printf("\nEnter a value: ");
		scanf("%d",&ptr->next->data);
		printf("\nTotal Number of nodes = %d\n\n",++total);
	}
	option();
}
void insert_before(nd *ptr)
{
	if(start==NULL)
	creat(start);
	else
	{
		nd *p1;
		int n;
		printf("\nTotal Number of nodes = %d\n\n",total);
		printf("\nEnter a node number for creating a node BEFORE A NODE: ");
		scanf("%d",&n);
		if(n==1)
		insert_beg(start);
		else if(n==total+1 || n<=0)
		{
			printf("\n****INVALID INPUT***");
			option();
		}
		else
		{
		for(int i=1;i<n;i++)
		ptr=ptr->next;
		p1=(nd *)malloc(sizeof(nd));
		p1->previous=ptr->previous;
		p1->next=ptr;
		ptr->previous->next=p1;
		ptr->previous=p1;
		printf("\nEnter a value: ");
		scanf("%d",&p1->data);
		printf("\nTotal Number of nodes = %d\n\n",++total);
		}
	}
	option();
}
void insert_after(nd *ptr)
{
	if(start==NULL)
	creat(start);
	else
	{
		nd *p1;
		int n;
		printf("\nTotal Number of nodes = %d\n\n",total);
		printf("\nEnter a node number for creating a node BEFORE A NODE: ");
		scanf("%d",&n);
		if(n==total)
		insert_end(start);
		else if(n<=0)
		{
			printf("\n****INVALID INPUT***");
			option();
		}
		else
		{
		for(int i=1;i<=n;i++)
		ptr=ptr->next;
		p1=(nd *)malloc(sizeof(nd));
		p1->previous=ptr->previous;
		p1->next=ptr;
		ptr->previous->next=p1;
		ptr->previous=p1;
		printf("\nEnter a value: ");
		scanf("%d",&p1->data);
		printf("\nTotal Number of nodes = %d\n\n",++total);
		}
	}
	option();
}
void delete_beg(nd *ptr)
{
	if(start==NULL)
	printf("\nThere is no node.\n");
	else
	{
		start=ptr->next;
		printf("\n%d node deleted.\n",ptr->data);
		free(ptr);
		printf("\nTotal Number of nodes = %d\n\n",--total);
	}
	option();
}
void delete_end(nd *ptr)
{
	if(start==NULL)
	printf("\nThere is no node.\n");
	else if(total==1)
	delete_beg(start);
	else
	{
		for(int i=0;ptr->next!=NULL;i++)
		{
			ptr=ptr->next;
		}
		ptr->previous->next=NULL;
		printf("\n%d node deleted.\n",ptr->data);
		free(ptr);
		printf("\nTotal Number of nodes = %d\n\n",--total);
	}
	option();
}
void delete_node(nd *ptr)
{
	int n;
	printf("\nTotal number of nodes = %d\n\n",total);
	printf("\nEnter a node number: ");
	scanf("%d",&n);
	if(start==NULL)
	printf("\nThere is no node.\n");
	else if(total==1)
	delete_beg(start);
	else if(n==total)
	delete_end(start);
	else if(n>total)
	printf("\nINVALID INPUT\n");
	else
	{
		for(int i=1;i<n;i++)
		{
			ptr=ptr->next;	
		}
		ptr->next->previous=ptr->previous;
		ptr->previous->next=ptr->next;
		printf("\n%d node deleted.\n",ptr->data);
		free(ptr);
		printf("\nTotal Number of nodes = %d\n\n",--total);
	}
	option();
}
void delete_list(nd *ptr)
{
	int i;
	if(start==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		printf("\n****DELETION OF ENTIRE LIST****");
		printf("\nTotal %d number of Node will be deleted.",total);
		for(i=1;i<=total;i++)
		{
			ptr=start;
			start=start->next;
			free(ptr);
		}
	}
	option();
}
