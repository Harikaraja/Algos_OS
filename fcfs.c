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
}p[50];
int main()
{
int n,i,j;
int wavg=0,tavg = 0;
int a[10];
printf("enter number of processes in ready queue \n");
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
}
    //printf ("\n");
for(i=0;i<n-1;i++)
{
for (j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
int temp;
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
for(i=0;i<n;i++)
{
   for (j=0;j<n;j++)
 {
      if(a[i]==p[j].arrival_time)
 {
   if(a[i]<fts)
{
  p[j].st_time=fts;
  p[j].ft_time=p[j].st_time+p[j].burst_time;
  fts=p[j].ft_time;
}
else
{
  p[j].st_time=p[j].arrival_time;
  p[j].ft_time=p[j].st_time+p[j].burst_time;
  fts=p[j].ft_time;
}
}
}
}
   for(i=0;i<n;i++)
{
   p[i].waiting_time=p[i].st_time - p[i].arrival_time;
   p[i].turn_time = p[i].waiting_time + p[i].burst_time;
}
   printf("process_name arrival_time   burst_time       start_time       finish_time       waiting_time      turnaround_time\n");
   for (i=0;i<n;i++)
   {
       printf("%s\t\t      %d\t\t   %d\t\t %d\t\t %d\t\t  %d\t\t  %d\n",p[i].name,p[i].arrival_time,p[i].burst_time,p[i].st_time,p[i].ft_time,p[i].waiting_time,p[i].turn_time);
   }
   for(i=0;i<n;i++)
{
    wavg = wavg+p[i].waiting_time;
    tavg = tavg + p[i].turn_time;
}
printf("Average waiting time is : %d \n",(wavg)/2);
printf("Average Turn around time is : %d \n",(tavg)/2);
}
