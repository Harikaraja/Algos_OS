#include<stdio.h>
int fts=0;
void equal(int n,int res,int par)
{
int tot_spa,size,i;
tot_spa=n-res;//space left in memeory
printf("Availble memory is:%d\n",tot_spa);
size=tot_spa/par;//size of each partiton
int p[par];
//printf("Enter size of each partition\n");
for(int i=0;i<par;i++)
{
p[i]=size;//each aprtiton size
}
float pro[par];//enter each processs size
for(int i=0;i<par;i++)
{
printf("Enter size of %d process\n",i+1);
scanf("%f",&pro[i]);//process size
}
float diff[par];
//calculating internal fragmentation
for(int i=0;i<par;i++)
{
if(pro[i]>p[i])
{
  printf(" process %d size is larger than partition size The process cant be fitted into partition\n",i+1);
}
else
{
  diff[i]=p[i]-pro[i];
  printf("Internal fragmentation is:%f\n",diff[i]);
}
}
}
void First_fit(int sto[20],int par,int name,int size[20],int pro[20])
{
int flag=0;
for(int i=0;i<par;i++)
{
//printf("hello1\n");
//printf("size:%d\t %d\n",size[i],pro[name]);
if((sto[i]==-1)&&(size[i]>=pro[name]))//size of partition greater than process size.
{
//printf("hello2\n");
sto[i]=name;
int frag = size[i]-pro[name];
printf("process inserted in partition %d\n",i+1);
printf("Internal fragmentation is : %d\n",frag);
fts=i;
flag=1;
return;
}
}
if(flag==0)
{
printf("process size is larger than partition size.so process %d cant be inserted\n",name);
return;
}
}
void Best_fit(int sto[20],int par,int name,int size[20],int pro[20])
{
int fra,min=9999,p,flag=0;
printf("\n");
for(int i=0;i<par;i++)
{
if((sto[i]==-1)&&(size[i]>=pro[name]))
{
flag=1;
    fra=size[i]-pro[name];
    if(min>fra)
    {
        min=fra;
p=i;

}
}
}
if(flag==1)
{
sto[p]=name;
printf("process inserted in partition %d\n",p+1);
printf("Internal fragmentation is : %d\n",fra);
fts=p;
}
else
{
printf("unable to place the process %d in memory\n",name);
}
}
void Worst_fit(int sto[20],int par,int name,int size[20],int pro[20])
{
int fra,min=-3,p,flag=0;
printf("\n");
for(int i=0;i<par;i++)
{
if((sto[i]==-1)&&(size[i]>=pro[name]))
{
flag=1;
    fra=size[i]-pro[name];
    if(min<fra)
    {
        min=fra;
p=i;
}
}
}
if(flag==1)
{
sto[p]=name;
printf("process inserted in partition %d\n",p+1);
printf("Internal fragmentation is : %d\n",fra);
fts=p;
}
else
{
printf("unable to place the process %d in memory\n",name);
}
}
void Next_fit(int sto[20],int par,int name,int size[20],int pro[20])
{
int rear=fts;
printf("rear is:%d\n",rear);
int tr=fts;
int frag,flag=0,pos,flag1=0;
if(fts==0)
{
rear=-1;
printf("rear inner is:%d\n",rear);
int kk=(rear+1)%par;
rear++;
if(sto[kk]==-1&&size[kk]>=pro[name])
{
frag=size[kk]-pro[name];
flag=1;
flag1=1;
pos=kk;
}
}
 if(flag1==0)
 {
while((rear+1)%par!=fts)
{
int kk=(rear+1)%par;
printf("kk:%d\n",kk);
   rear++;
   printf("size:%d\t%d\n",size[kk],pro[name]);
if(sto[kk]==-1&&size[kk]>=pro[name])
{
frag=size[kk]-pro[name];
flag=1;
pos=kk;
break;
}
}
}
if(flag==1||flag1==1)
{
sto[pos]=name;
   printf("process inserted in partition %d\n",pos+1);
   printf("Internal fragmentation is : %d\n",frag);
   fts=pos;
}
else
{
printf("unable to place the process %d in memory\n",name);
}
}
void unequal(int n,int res,int par)
{
int tot_spa,i,choices;
tot_spa=n-res;//space left in memeory or space available
int sizes=tot_spa;
printf("Available memory space is:%d\n",tot_spa);
int size[20];//entering size of each partition
for(int i=0;i<par;i++)
{
printf("enter the size of  partiton %d\n",i+1);
if(sizes>0)
{
scanf("%d",&size[i]);//partitions sizes are stored here.
}
else
{
        printf("partiton size exceeded total size\n");
}
}

int nu;//enter each processs size
printf("enter number of processes\n");
scanf("%d",&nu);
int pro[nu];
for(int i=0;i<nu;i++)
{
  printf("Enter size of  process %d\n",i+1);
  scanf("%d",&pro[i]);//process sizes are stored here.
 // printf("process size is : %d\n",pro[i]);
}
int sto[par];
//initialising the storing array with -1
for(int i=0;i<par;i++)
{
sto[i]=-1;
}
printf("1.First fit  2.Best fit  3.Next fit  4.Worst fit\n");
scanf("%d",&choices);
for(i=0;i<nu;i++)
{
int name;
printf("Enter name of process u want  to insert into memory\n");
scanf("%d",&name);
//printf("Enter your choice\n");
   switch(choices)
   {
    case 1:printf("Inserting process through first fit\n");
      First_fit(sto,par,name,size,pro);
          break;
    case 2:printf("Inserting process through Best fit\n");
      Best_fit(sto,par,name,size,pro);
          break;
    case 3:printf("Inserting process through Next fit\n");
      Next_fit(sto,par,name,size,pro);
          break;
    case 4:printf("Inserting process through Worst fit\n");
      Worst_fit(sto,par,name,size,pro);
          break;
}

}
}
int main()
{
int choice,n,res,par;
printf("Enter the total memory size\n");
scanf("%d",&n);
printf("Enter resident monitor space\n");
scanf("%d",&res);
printf("Enter total number of partitions\n");
scanf("%d",&par);//number of partitions
printf("enter your choice: 1.Fixed partition with equal size  2.Fixed partition with unequal size \n");
printf("enter option 1 or 2\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("executing fixed partition with equal size\n");
      equal(n,res,par);
      break;
case 2:printf("executing fixed partition with unequal size\n");
      unequal(n,res,par);
 break;
}
}
