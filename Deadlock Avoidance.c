#include<stdio.h>
int count=0;
int safety_algo(int res,int n,int ava[],int need[][20],int all[][20])
{
int cal=0,finish[10],work[10],result[n],i,tt=0,color=0;
for(int i=0;i<res;i++)
  {
     work[i]=ava[i];
  }
 for(int i=0;i<n;i++)
 {
  finish[i]=0;
 }
 for(int k=0;k<n;k++)
 {
  for(int t=0;t<n;t++)
  {
  cal=0;
    if(finish[t]==0)
{
for(int i=0;i<res;i++)
{
if(need[t][i]>work[i])
{

cal=1;
break;
}
}
if(cal==0)
{
   for(int z=0;z<res;z++)
               {
                  work[z]=work[z]+all[t][z];
               }
     result[tt]=t;
                  tt++;
                  finish[t]=1;
}
}
}
 }
 int host=0;
 for(int i=0;i<n;i++)
 {
  if(finish[i]==0)
  {
    host=1;
  printf("The following sequence is not safe\n");
  break;
}
 }
  if(host==0)
  {
  printf("The safe sequence is:\n");
  for(int i=0;i<n;i++)
  {
  printf("%d\t",result[i]);
  color=1;
}
  }
  return color;
 }
 void res_request(int item,int res,int n,int req[],int need[][20],int ava[],int all[][20])
 {
     int flag=0,common=0,tat=0;
     for(int t=0;t<res;t++)
{
if(req[t]>need[item][t])
{
printf("process %d has exceeded its maximum claim.",item);
flag=1;
return;
}
}
if(flag==0)
{
for(int i=0;i<res;i++)
{
  if(req[i]>ava[i])
{
common=1;
printf("wait for resources \n");
}
}
if(common==0)
{
for(int p=0;p<res;p++)
{
ava[p]=ava[p]-req[p];
all[item][p]=all[item][p]+req[p];
need[item][p]=need[item][p]-req[p];
}
  tat= safety_algo(res,n,ava,need,all);
  if(tat==1)
 {
printf("resources are allocated to process %d",item);
 }
 else
{
printf("process aborted \n");
for(int p=0;p<res;p++)
{
ava[p]=ava[p]+req[p];
all[item][p]=all[item][p]-req[p];
need[item][p]=need[item][p]+req[p];
}
printf("changes retransformed successfully\n");
}
}
}
 }
int main()
{
 int n,i,j,res,y;
 printf("enter number of processes\n");
 scanf("%d",&n);
 printf("enter total number of resource types\n");
 scanf("%d",&res);
 int all[20][20],max[20][20],ava[20],need[20][20],a[20];
 printf("enter number of instances of each resource\n");
 for(i=0;i<res;i++)
 {
  printf("enter number of instances of resource %d: \n",i+1);
  scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
  printf("enter resource allocation for process %d: \n",i+1);
 for(j=0;j<res;j++)
  {
   printf("enter number of instances of resource %d for process %d\n",j+1,i+1);
   scanf("%d",&all[i][j]);
  }
 }
 for(i=0;i<n;i++)
 {
  printf("enter maximum resource allocation for process %d:\n",i+1);
  for(j=0;j<res;j++)
  {
   printf("enter maximum number of instances of type %d for process %d\n",j+1,i+1);
   scanf("%d",&max[i][j]);
  }
 }
 //printf("calculating total available resources\n");
 for(j=0;j<res;j++)
 {
  int sum=0;
  for(i=0;i<n;i++)
  {
      sum=sum+all[i][j];
  }
  //printf("%d\t",sum);
  //printf("%d\t",a[j]);
  ava[j]=a[j]-sum;
 }
 printf("\n");
   /* for(i=0;i<res;i++)
 {
     printf("total available resources of instance %d are: \n",i+1);
  printf("%d\n",ava[i]);
 }*/
 //printf("calculating need of resources \n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<res;j++)
  {
   need[i][j]=max[i][j]-all[i][j];
  }
 }
 /*for(i=0;i<n;i++)
 {
  //printf("total resources required for process %d are:",i+1);
  for(j=0;j<res;j++)
  {
   //printf("total rsources required for instance %d by process %d ",j+1,i+1);
   printf("%d",need[i][j]);
  }
  printf("\n");
 }*/
 //implementing safety algorithm.
  int var=0;
  var=safety_algo(res,n,ava,need,all);
  //implementing request algorithm
  if(var==1)
  {
  do
  {
    int item,req[res];
  printf("printf enter which process wants the request for additional sources : \n");
  scanf("%d",&item);
  for(i=0;i<res;i++)
  {
    printf("enter how many resources have been claimed for instance %d by process %d:c\n",i+1,item);
  scanf("%d",&req[i]);
}
res_request(item,res,n,req,need,ava,all);
printf("Do u want to continue?? press 1 if you wish to continue\n");
scanf("%d",&y);
  }while(y==1);
 }
 else
 {
  printf("since safe sequence is not printed requests for additional resources cant be processed\n");
 }
}
