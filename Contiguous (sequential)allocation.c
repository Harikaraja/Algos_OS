#include<stdio.h>
int a[200],count=1,trace=0;
struct file
{
	int n;
	int s;
	int num;
}f[200];
int create(int n)
{
	int name,start,numer,flag=1,counter=0;
	printf("enter file name\n");
	scanf("%d",&name);
	f[count].n = name;
	printf("enter start location of file\n");
	scanf("%d",&start);
	f[count].s = start;
	printf("enter number of blocks\n");
	scanf("%d",&numer);
	f[count].num = numer;
	count++;
	int s=start;
	trace = trace+numer;
	for(int i=0;i<numer;i++)
	{
		if(a[s++]==-1)
		{
			counter++;
		}
		else
		{
			printf("file cant be inserted as memory locations are not contiguous\n");
			flag=0;
			return flag;
		}
	}
	if(counter==numer)
	{
	   for(int i=0;i<numer;i++)
	   {
	      a[start++]=name;	
	   }	
	}
	printf("memory representation is:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return flag;
}
int del(int n)
{
	int name;
	printf("enter the file you want to delete\n");
	scanf("%d",&name);
	int numer=f[name].s;
	int finish=f[name].num;
	trace = trace-finish;
	int ju = numer;
	for(int j=0;j<finish;j++)
	{
		a[ju++]=-1;
	}
	printf("memory representation is:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	f[name].n = -1;
	f[name].s = -1;
	f[name].num = -1;
	printf("\n");
}
void traverse()
{
	printf("memory layout is:\n");
	printf("File\t start_location\t blocks_allocated \n");
	for(int i=1;i<count;i++)
	{
		if(f[i].n != -1)
		{
			printf("%d\t %d\t\t    %d \n",f[i].n,f[i].s,f[i].num);
		}
	}
}
int main()
{
	int n,size,choice,t=1;
	printf("enter total number of blocks available in memory\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		a[i]=-1;
	}
	printf("enter each block size\n");
	scanf("%d",&size);
	do
	{
		int flag,rel=1;
	    printf("enter your choice\n");
	    printf("1.creation  2.deletion  3.traversing\n");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	    	case 1:if(trace==n)
	               {
	               	 printf("memory is full.delete some files\n");
	               	 rel=0;
				   }
				   if(rel!=0)
				   {
				   	printf("file is being created\n");
	    	        flag=create(n);
	    	        if(flag!=0)
	    	        {
	    	       	  printf("file created successfully\n");
				    }
				    else
				    {
				   	  printf("file is not created successfully\n");
				    }
				  }
	    	       break;
	    	case 2:if(trace==0)
	               {
	               	 printf("deletion operation cant be performed as memory is empty\n");
	               	 rel=0;
				   }
				   if(rel !=0)
				   {
				   	 printf("file is being deleted\n");
			         del(n);
			         printf("file deleted successfully\n");
				   }			       
				   break;
		    case 3:printf("file is being traversed\n");
			       traverse(); 
				   break;     
		}
		printf("do you want to continue.press 1 if u wish to continue\n");
		scanf("%d",&t);	
	}while(t==1);
}
