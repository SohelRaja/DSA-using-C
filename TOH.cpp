#include<stdio.h>
#include<conio.h>
void toh(int,char,char,char);
int moves(long int);
int main()
{
	int n;
	long int i;
	char con;
	do{

	printf("\nEnter no of discs:\t");
	scanf("%d",&n);
	if(n==0)
	{
		printf("\nINVALID INPUT!!!!!!!!!!\n");
	}
	else	
	{
	i=n;
	printf("\nNO.OF MOVES REQUIRES \32\32\32 %ld\n\n",moves(i)); //  (\32 represents : -> )
	i=moves(i);
	toh(n,'S','A','D');
	printf("Total moves= %ld",i);
	}
	printf("\nDo you want to continue?.\nPRESS \"Y\".\n");
	con=getche();
	printf("\n_____________________________________________\n");
}while(con=='y');

return 0;
}
void toh(int n,char sou,char aux,char des)
{
	if(n==1)
	{
		printf("MOVE FROM TOWER %c TO TOWER %c \32\32\32\32\32  %c \32 %c .\n",sou,des,sou,des);
			
	}
	else
	{
	    /*                                         
		Let There are 2 disks and three stands (Source,Auxalary,Destination) so, 
		first smaller once will go Source to Auxalary ,                (S -> A)
		then Bigger once will go Source to Destination,                (S -> D)
		then Finally smaller once will go to Auxalary to Destination.  (A -> D)
		*/
		toh(n-1,sou,des,aux);	
		toh(1,sou,aux,des);
		toh(n-1,aux,sou,des);
	}
}
int moves(long int n)
{
	long int pow=1,i;
	for(i=1;i<=n;i++)
	{
		pow=2*pow;
	}
	pow=pow-1;
	return pow;
}
