#include<stdio.h>
#include<stdlib.h>
int count=1,a[200];
struct file
{
	int name;
	int numblocks;
	int indblock[10];
	int indtab[20];
}f[100];
int create(int n,int tab)
{
	int t=0,ti=0,pt=0;
	printf("enter file name you want to create\n");
	scanf("%d",&f[count].name);
	printf("enter number of blocks in file\n");
	scanf("%d",&f[count].numblocks);
	int it=rand()%n;
	if(a[it]==-1)
	{
	   f[count].indblock[pt++]=it;
	   a[it]=f[count].name;	
	}
	for(int i=0;i<f[count].numblocks;i++)
	{
		int p=rand()%n;
		if(a[p]==-1 && t<=tab)
		{
			a[p]=f[count].name;
			f[count].indtab[ti++]=p;
			t++;
		}
		else
		{
			int pu=rand()%n;
			f[count].indblock[pt++]=pu;
			a[pu]=f[count].name;
			t=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int del(int n,int tab)
{
	int name;
	printf("enter the file you want to delete\n");
	scanf("%d",&name);
	f[name].name=-1;
	int o=f[name].numblocks/tab;
    for(int q=0;q<o;q++)
	{
	      a[f[name].indblock[q]]=-1;		  	
	}
	for(int ik=0;ik<f[name].numblocks;ik++)
	{
	   	a[f[name].indtab[ik]]=-1;	
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");	
}
int traverse(int n,int tab)
{
	printf("file name\t index blocks\t blocks in index block\n");
    for(int i=1;i<=count;i++)
	{
		//printf("i:%d\n",i);
		if(f[i].name!=-1)
		{
		     printf("%d\t ",f[i].name);
	     int o=f[i].numblocks/tab;
	   	for(int ip=0;ip<=o;ip++)
	   	{
	   		//printf("hello");
	   	       printf("%d ",f[i].indblock[ip]);	
		}
		printf("\t\t");
		for(int ik=0;ik<f[i].numblocks;ik++)
	   	{
	   		//printf("hii\n");
	   	       printf("%d ",f[i].indtab[ik]);	
		}
		printf("\n");	
		}
		
	}	
}
int main()
{
	int n,size,t=0,tab,choice;
	printf("enter total number of blocks\n");
	scanf("%d",&n);
	printf("enter block size\n");
	scanf("%d",&size);
	for(int i=0;i<n;i++)
	{
		a[i]=-1;
	}
	printf("enter the index table size\n  ");
	scanf("%d",&tab);
	int it[tab];
	do
	{
	   printf("enter your choice\n");
	   printf("1.create  2.del  3.traverse\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	     case 1 : printf("file is being created\n");
		          create(n,tab);
		          printf("file created sucessfully\n");
				  break;
		 case 2 : printf ("file is being deleted\n");
		          del(n,tab);
				  break;
		 case 3 : printf("file is being traversed\n");
		          traverse(n,tab);
				  break;	
	   }
	   printf("do u want to continue press 1 if u wish to continue\n");
	   scanf("%d",&t);	
	}while(t==1);
}
