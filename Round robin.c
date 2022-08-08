#include<stdio.h>
struct process
{
 int ft,at,bt,pr,wt,tat;
}p[100],q[100],temp,rq[100];

int main()
{ int n,c=0,i,l=0,r,j,position,front=1,top=0,tq;
int tbt=0,pr,count=0,endtime,swap=0;
int avgwt=0,avgtat=0;
    printf("enter the no of processes");
    scanf("%d",&n);
    printf("enter the time quantum");
    scanf("%d",&tq);
    for(i=0;i<n;i++)
    {  p[i].pr=i+1;
    printf("enter the arrival time of %d",i+1);
    scanf("%d",&p[i].at);
    printf("enter the burst time of %d",i+1);
    scanf("%d",&p[i].bt);
    }
    for(i=0;i<n;i++)
    q[i]=p[i];
   for(i = 0; i < n - 1; i++)
{
position=i;
for(j = i + 1; j < n; j++)
{
if(p[position].at > p[j].at)
position=j;
if(p[position].at == p[j].at)
{
        if(p[position].pr > p[j].pr)
        {position=j;
        }
}
}
if(position != i)
{
temp=p[i];
p[i]=p[position];
p[position]=temp;
}
}
 printf("process\tarrival\tburst\tfinal\twait\ttat\n");
 rq[top]=p[0];
 r=p[0].bt;
if(p[0].bt>tq)
{p[0].bt-=tq;
rq[top].bt-=tq;
 count=p[0].at+tq;
}
else
{ count=p[0].bt+p[0].at;
p[0].bt=0;
rq[0].bt=0;
p[0].ft=count;
pr=p[0].pr-1;
q[pr].ft=count;

c=1;}
top++;
for(i=1;i<n;i++)
        {
                if(p[i].at<=count)
                { l++;
                     swap=1;
                        rq[top++]=p[i];
                 }
         }
if(swap==0)
rq[top++]=p[++l];
if(p[0].bt>0)
{
  rq[top++]=p[0];
}
p[0].bt=r;
 while(c<n)
 {      swap=0;
         if(rq[front].bt>tq)
         {  if(rq[front].at<=count)
                count+=tq;
else
 count=rq[front].at+tq;
                rq[front].bt-=tq;
for(i=l+1;i<n;i++)
  {
     if(p[i].at<=count)
                { l++;
                 swap=1;
                        rq[top]=p[i];
                        top++;
                 }
  }

                rq[top++]=rq[front];
                front++;

         }
else  if(rq[front].bt<tq)
         {
c++;
 if(rq[front].at<=count)
                count+=rq[front].bt;
else
 count=rq[front].at+rq[front].bt;
pr=rq[front].pr-1;
q[pr].ft=count;
                        rq[front].bt=0;
                front++;
         }
        else
  {c++;
 if(rq[front].at<=count)
                count+=tq;
else
 count=rq[front].at+tq;

        pr=rq[front].pr-1;
q[pr].ft=count;
                        rq[front].bt=0;
                front++;

         }
 if(l+1<n)
{
  if(swap==0)
{
rq[top++]=p[l+1];
l++;
}
}

 }

for(i=0;i<n;i++)
{
 q[i].tat=q[i].ft-q[i].at;
avgwt+=q[0].tat;
q[i].wt=q[i].tat-q[i].bt;
avgtat+=q[0].wt;
}


     for(i=0;i<n;i++)
  {
printf("%d\t%d\t%d\t%d\t%d\t%d",q[i].pr,q[i].at,q[i].bt,q[i].ft,q[i].wt, q[i].tat);
printf("\n");
}
printf("Average waiting time=%d\n",avgwt/n);
printf("Average Turnaround time=%d",avgtat/n);
    return 0;
}
