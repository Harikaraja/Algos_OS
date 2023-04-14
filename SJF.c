#include<stdio.h>
int fts =0;
struct process
{
char name[20];
int arrival_time;
int burst_time;
int st_time;
int ft_time;
int waiting_time;
int turn_time;
}p[100];
int main()
{
int n,i,j,min=0,mini=0,k,kk=0,t,it,tear=0,len=0,ti=0,ik=0,minu;
float wavg=0,tavg = 0;
int a[100],b[100],c[100],d[100];
printf("enter number of processes in ready quque \n");
scanf ("%d",&n);
for (i=0;i<n;i++)
{
printf("enter process name \n");
scanf ("%s",p[i].name);
printf("enter arrival time \n");
scanf ("%d",&p[i].arrival_time);
printf ("enter burst time \n");
scanf ("%d",&p[i].burst_time);
}
for (i=0;i<n;i++)
{
  a[i]=p[i].arrival_time;
  b[i]=p[i].burst_time;

}
for(i=0;i<n;i++)
{
  if(a[i]<=a[min])
  {
    minu=i;
    //min=i;
    if(b[minu]<b[min])
    {
    min=minu;
 }
  }
}
p[min].st_time=p[min].arrival_time;
p[min].ft_time=p[min].st_time+p[min].burst_time;
fts=p[min].ft_time;
a[min]=9999;
printf("\n");
for(i=0;i<n;i++)
{
 for(t=0;t<n;t++)
 {
  c[t]=-1;
  d[t]=-1;
 }
  ti=0;
 for(j=0;j<n;j++)
 {
  if(a[j]<=fts)
  {
   c[ti]=j;
   ti++;
  }
 }
 printf("\n");
 for(k=0;k<ti;k++)
 {
  d[k]=b[c[k]];
  kk++;
 }
 printf("\n");
 mini=0;
 int glo=0;
 for(it=0;it<ti;it++)
 {
     if(d[it]<d[mini])
  {
      mini=it;
      glo=it;
  }
 }
 int minute=0,h[100],kite=0;
 for(i=0;i<kk;i++)
 {
   if(d[mini]==d[i])
   {
     h[kite]=i;
     kite++;
   }
 }
 int micro=0,color=0;;
 for(i=0;i<kite;i++)
 {
    if(a[h[minute]]<a[h[i]])
    {
     color=1;
      micro=h[i];
    }
 }
if(color==1)
{
        mini=micro;
}
else
{
        mini=glo;
}

 /*
 for(i=0;i<ti;i++)
 {
         if(b[c[i]]==b[c[mini]])
         {
                 if(a[c[i]]<a[c[mini]])
                 {
                         mini=i;
                 }
         }
         else
         {
                 mini=mini;
         }
 }*/
 tear=c[mini];
 if(p[tear].arrival_time<fts)
 {
 p[tear].st_time=fts;
 p[tear].ft_time=p[tear].st_time+p[tear].burst_time;
 fts=p[tear].ft_time;
 a[tear]=9999;
 }
 else
 {
 p[tear].st_time=p[tear].arrival_time;
 p[tear].ft_time=p[tear].st_time+p[tear].burst_time;
 fts=p[tear].ft_time;
 a[tear]=9999;
 }
}

 for(i=0;i<n;i++)
{
        p[i].waiting_time=p[i].st_time - p[i].arrival_time;
        p[i].turn_time = p[i].waiting_time+p[i].burst_time;
}
for(i=0;i<n;i++)
{
        wavg=wavg+p[i].waiting_time;
        tavg=tavg+p[i].turn_time;
}
printf("process_name  arrival_time    burst_time       start_time       finish_time       waiting_time      turnaround_time\n");
   for (i=0;i<n;i++)
   {
       printf("%s\t\t      %d\t\t   %d\t\t %d\t\t %d\t\t  %d\t\t  %d\n",p[i].name,p[i].arrival_time,p[i].burst_time,p[i].st_time,p[i].ft_time,p[i].waiting_time,p[i].turn_time);
   }
   //finding average waiting time and average turn around time
printf("The average waiting time is : %f \n",(wavg)/n);
printf("The average turn around time is : %f \n",(tavg)/n);
}
