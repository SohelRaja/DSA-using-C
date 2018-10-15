/*Singly Link List's(using User Define Function) all operations are below. Date of creation of this programe is 9th september,2018.*/
/**************Made by Sohel Raja Molla.****************/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node nd;  //To Make Short Name of struct node that is nd.
nd *start=NULL; //Initially start pointer(struct pointer) is Null.
int total;  //To calculate Number of nodes.
char op;  //for repeating the function creat.
void option();  //switch case.
void creat(nd *); //For creating a new link list.
void display(nd *);  //for displaying the link list.
void insert_beg(nd *);  //to insert a node at the beginning.
void insert_end(nd *);  //to insert a node at the end position.
void insert_before(nd *);  //to insert a node before a node.
void insert_after(nd *);  //to insert a node after a node.
void delete_beg(nd *);  //to delete a node from beginning.
void delete_end(nd *);  //to delete a node from end.
void delete_node(nd *);  //to delete a specified node. 
void delete_after(nd *);  //to delete a node after a node.
void delete_list(nd *);  //to delete entire link list.
void sort(nd *);  //for sorting the link list.
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
	printf("\n 9:  Delete a given node.");
	printf("\n 10: Delete a node after a given node.");
	printf("\n 11: Delete entire list.");
	printf("\n 12: Sort the list.");
	printf("\n 13: EXIT.");
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
		case 10: delete_after(start);
		break;
		case 11: delete_list(start);
		break;
		case 12: sort(start);
		break;
		case 13: exit(0);
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
	printf("\nLink List Is Created.\n");
	do
	{
		printf("\nDo you want to insert another one (y/n)->: ");
		op=getche();
		if(op=='y')
		{
			ptr->next=(nd *)malloc(sizeof(nd));
			ptr=ptr->next;
			printf("\nEnter a value: ");
			scanf("%d",&ptr->data);
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
	total=0;
	ptr=(nd *)malloc(sizeof(nd));
	printf("\nEnter a value: ");
	scanf("%d",&ptr->data);
	start=ptr;
	ptr->next=NULL;
	printf("\nTotal number of node is %d\n\n",++total);
	option();
	}
	else
	{
	ptr=(nd *)malloc(sizeof(nd));
	printf("\nEnter a value: ");
	scanf("%d",&ptr->data);
	ptr->next=start;
	start=ptr;
	printf("\nTotal Number of nodes = %d\n\n",++total);
	option();
	}
}
void insert_end(nd *ptr)
{
	if(start==NULL)
	{
	total=0;
	ptr=(nd *)malloc(sizeof(nd));
	printf("\nEnter a value: ");
	scanf("%d",&ptr->data);
	start=ptr;
	ptr->next=NULL;
	printf("\nTotal number of node is %d\n\n",++total);
	option();
	}
	else
	{
		nd *new1;
		new1=(nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d",&new1->data);
		new1->next=NULL;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new1;
		new1->next=NULL;
		printf("\nTotal Number of nodes = %d\n\n",++total);
	}
	option();
}
void insert_before(nd *ptr)
{
	int loca,i;
	if(start==NULL)
	{
		printf("\nThere is no link list.\nYou should create a link list first.\n");
	}
	else
	{
		nd *new1;
		nd *pre;
		new1=(nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d",&new1->data);
		printf("\n****INSERT A NODE BEFORE A EXISTING NODE.****\nTotal Number of nodes = %d\nEnter a node number: ",total);
		scanf("%d",&loca);
		for(i=1;i<loca;i++)
		{
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=new1;
		new1->next=ptr;
		printf("\nTotal Number of nodes = %d\n\n",++total);
	}
	option();
}
void insert_after(nd *ptr)
{
	int loca,i;
	if(start==NULL)
	{
		printf("\nThere is no link list.\nYou should create a link list first.\n");
	}
	else
	{
		nd *new1,*pre;
		new1=(nd *)malloc(sizeof(nd));
		printf("\nEnter a value: ");
		scanf("%d",&new1->data);
		printf("\n****INSERT A NODE AFTER A EXISTING NODE.****\nTotal Number of nodes = %d\nEnter a node number: ",total);
		scanf("%d",&loca);
		if(loca==total)
		{
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new1;
			new1->next=NULL;
			printf("\nTotal Number of nodes = %d\n\n",++total);
		}
		else
		{
		for(i=1;i<=loca;i++)
		{
			pre=ptr;
			ptr=ptr->next;
		}
		new1->next=ptr;
		pre->next=new1;
		printf("\nTotal Number of nodes = %d\n\n",++total);
		}		
	}
	option();		
}
void delete_beg(nd *ptr)
{
	if(start==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		start=start->next;
		printf("\nNode is deleted from end.\nValue %d is Deleted.\n",ptr->data);
		free(ptr);
		printf("\nTotal Number of nodes remaining = %d\n\n",--total);
		option();
	}
}
void delete_end(nd *ptr)
{
	nd *pre;
	if(start==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		while(ptr->next!=NULL)
		{
			pre=ptr;
			ptr=ptr->next;
		}
		pre->next=NULL;
		printf("\nNode is deleted from end.\nValue %d is Deleted.\n",ptr->data);
		free(ptr);
		printf("\nTotal Number of nodes remaining = %d\n\n",--total);
		option();
	}
}
void delete_node(nd *ptr)
{
	nd *pre;
	int loca,i;
	if(start==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		printf("\n****DELETE A PERTICULAR NODE****\nThere is %d number of nodes present.\n",total);
		printf("\nEnter a Node Number: ");
		scanf("%d",&loca);
		if(loca==total)
		{
			for(i=1;i<loca;i++)
			{
				pre=ptr;
				ptr=ptr->next;
			}
			pre->next=NULL;
			printf("\nSpecifaied Node as well as Value %d is deleted.",ptr->data);
			free(ptr);
			printf("\nTotal Number of nodes remaining = %d\n\n",--total);
		}
		else
		{
			for(i=1;i<loca;i++)
			{
				pre=ptr;
				ptr=ptr->next;
			}
			pre->next=ptr->next;
			printf("\nSpecifaied Node as well as Value %d is deleted.",ptr->data);
			free(ptr);
			printf("\nTotal Number of nodes remaining = %d\n\n",--total);
		}
	}
	option();
}
void delete_after(nd *ptr)
{
	nd *pre;
	int loca,i;
	if(start==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else
	{
		printf("\n****DELETE A NODE AFTER A NODE****\nThere is %d number of nodes present.\n",total);
		printf("\nEnter a Node Number: ");
		scanf("%d",&loca);
		if(loca==total-1)
		{
			for(i=1;i<=loca;i++)
			{
				pre=ptr;
				ptr=ptr->next;
			}
			pre->next=NULL;
			printf("\nValue %d and mentioned node is deleted.",ptr->data);
			free(ptr);
			printf("\nTotal Number of nodes remaining = %d\n\n",--total);
		}
		else if(loca==total)
		{
			printf("\nThere is no node.\n");
		}
		else
		{
			for(i=1;i<=loca;i++)
			{
				pre=ptr;
				ptr=ptr->next;
			}
			pre->next=ptr->next;
			printf("\nValue %d and mentioned node is deleted.",ptr->data);
			free(ptr);
			printf("\nTotal Number of nodes remaining = %d\n\n",--total);
		}
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
void sort(nd *ptr)
{
	int i,temp;
	nd *ptr1;
	ptr=start;
	if(start==NULL)
	{
		printf("\nThere is no node.\n");
	}
	else if(total==1)
	{
		printf("\n***************After Sorting*****************\n");
		display(start);
	}
	else
	{
		printf("\nTotal number of Nodes are %d.",total);
		while(ptr->next!=NULL)
		{
			ptr1=ptr->next;
			while(ptr1!=NULL)
			{
				if(ptr->data>ptr1->data)//for ascending order sorting.
				{
					temp=ptr->data;
					ptr->data=ptr1->data;
					ptr1->data=temp;
				}
				ptr1=ptr1->next;
			}
			ptr=ptr->next;
		}
	}
	printf("\n***************After Sorting*****************\n");
	display(start);
	option();
}
