#include<stdio.h>
#include<stdlib.h>
int count=1,a[100];
struct file
{
	int name;
	int s;
	int numblocks;
	int link[100];
}f[200];
int create(int n)
{
	int num,count1=0;
	printf("enter file name u want to create\n");
	scanf("%d",&f[count].name);
	//printf("enter the start block\n");
	//scanf("%d",&f[count].s);
	printf("enter number of blocks prescent in file\n");
	scanf("%d",&f[count].numblocks);
	num=f[count].numblocks;
	//printf("num:%d\n",num);
	int flag=0,reel=0;
	//a[f[count].s]=f[count].name;
	//f[count].link[count1++]=f[count].s;
	for(int ii=0;ii<n&&reel<num;ii++)
	{
		flag=0;
		int p = rand()%n;
		if(a[p]==-1)
		{
			reel++;
			flag=1;
			a[p]=f[count].name;
			f[count].link[count1++]=p;
		}
	}
	printf("\n");
	count++;
	printf("disc is:\n");
		for(int ik=0;ik<n;ik++)
		{
			printf("%d ",a[ik]);
		}
		printf("\n");
}
int del(int n)
{
	int namer,c,flag=0;
	printf("enter the file u want to delete\n");
	scanf("%d",&namer);
	for(int j=1;j<=count;j++)
	{
		if(f[j].name==namer)
		{
			c=j;
			flag=1;
		}
	}
	int num=f[c].numblocks;
	//printf("num:%d\n",num);
	if(flag==0)
	{
		printf("file does not exist\n");
	}
	for(int i=0;i<num;i++)
	{
		printf("hello\n");
	    a[f[c].link[i]]=-1;	
	}
	f[c].name=-1;
	printf("\n");
	printf("disc is:\n");
		for(int ik=0;ik<n;ik++)
		{
			printf("%d ",a[ik]);
		}
		printf("\n");
}
int traverse()
{
	printf("File_name\t length of blocks\t blocks allocated\n");
	for(int i=1;i<count;i++)
	{
		if(f[i].name != -1)
		{
		    printf("%d\t ",f[i].name);
		    printf("%d\t ",f[i].numblocks);
		    for(int j=0;j<f[i].numblocks;j++)
		   {
			  printf("%d ",f[i].link[j]);
		   }
		   printf("\n");	
		}
	}
}
int main()
{
	int n,size,t=0,tab,choice,num;
	printf("enter total number of blocks\n");
	scanf("%d",&n);
	printf("enter block size\n");
	scanf("%d",&size);
	for(int i=0;i<n;i++)
	{
		a[i]=-1;
	}
	printf("\n");
	do
	{
	   printf("enter your choice\n");
	   printf("1.create  2.del  3.traverse\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
	     case 1 : printf("file is being created\n");
		          create(n);
		          printf("file created successfully\n");
				  break;
		 case 2 : printf ("file is being deleted\n");
		          del(n);
		          printf("file deleted successfully\n");
				  break;
		 case 3 : printf("file is being traversed\n");
		          traverse();
				  break;	
	   }
	   printf("do u want to continue press 1 if u wish to continue\n");
	   scanf("%d",&t);	
	}while(t==1);
}
