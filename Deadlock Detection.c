#include<stdio.h>
int detection(int all[][100],int req[][100],int work[50],int ava[50],int n,int res)
{
int finish[n];
int safe[n],tt=0;
for(int i=0;i<res;i++)
{
work[i]=ava[i];
}
for(int i=0;i<n;i++)
{
int count=0;
for(int j=0;j<res;j++)
{
if(all[i][j]==0)
{
count++;
}
}
if(count==res)
{
finish[i]=1;
}
else
{
finish[i]=0;
}
}
/*printf("finish\n");
for(int i=0;i<n;i++)
{
printf("%d",finish[i]);
}*/
printf("\n");
for(int j=0;j<n;j++)
{
for(int i=0;i<n;i++)
{
int common=0;
if(finish[i]==0)
{
for(int t=0;t<res;t++)
{
if(req[i][t]<=work[t])
{
common++;
}
}
if(common==res)
{
for(int t=0;t<res;t++)
{
work[t]=work[t]+all[i][t];
}
finish[j]=1;
safe[tt++]=i;
}
}
}
  }
    int flag=0;
for(int i=0;i<n;i++)
{
if(finish[i]==0)
{
printf(" process is deadlocked %d\n",i);
flag=1;
}
}
if(flag==0)
{
printf("no process is deadlocked.system is in safe state\n");
printf("safe sequence is: \n");
for(int i=0;i<n;i++)
{
printf("process:%d \t",safe[i]);
}
printf("\n");
}
return flag;
}
int main()
{
int n,res,show;
printf("enter number of processes\n");
scanf("%d",&n);
printf("enter number of resource types\n");
scanf("%d",&res);
int all[100][100],req[100][100],ava[50],work[50];
printf("enter total allocated resources\n");
for(int i=0;i<n;i++)
{
printf("allocated for process %d\n",i+1);
for(int j=0;j<res;j++)
{
scanf("%d",&all[i][j]);
}
}
printf("enter total requested resources\n");
for(int i=0;i<n;i++)
{
printf("requested for process %d\n",i+1);
for(int j=0;j<res;j++)
{
scanf("%d",&req[i][j]);
}
}
printf("enter total available resources\n");
for(int i=0;i<res;i++)
{
scanf("%d",&ava[i]);
work[i]=ava[i];
}
show=detection(all,req,work,ava,n,res);
}
