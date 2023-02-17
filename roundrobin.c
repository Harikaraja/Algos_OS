#include<stdio.h>
#include<stdlib.h>

struct process
{
        char pname[10];
        int arrivaltime;
        int bursttime;
        int starttime;
        int endtime;
        int tattime;
        int waittime;


}p[10];

int main()
{
        int n,tq,sum=0,fts=0,rear=-1,front=0;
        printf("enter no of processes:");
        scanf("%d",&n);
        int a[n],b[n],rq[100];
        for(int i=0;i<100;i++)
        {
                rq[i]=-1;
                }
        printf("enter time quantum:");
        scanf("%d",&tq);

        for(int i=0;i<n;i++)
        {
                printf("enter process %d name:",i+1);
                scanf("%s",p[i].pname);
                printf("enter arrival time of process %d:",i+1);
                scanf("%d",&p[i].arrivaltime );
                a[i]=p[i].arrivaltime;

                printf("enter burst time of process %d:",i+1);
                scanf("%d",&p[i].bursttime );
                b[i]=p[i].bursttime;
                sum+=b[i];

       }

       printf("\nprocessname \t AT \t BT \t ST \t ET \t WT \t TAT \n");
       int  m=0;
       for(int j=0;j<n;j++)
       {
                 if(a[m]>a[j] )
                  m=j;
       }
       p[m].starttime=p[m].arrivaltime;

       if(b[m]<=tq)
       {

               p[m].endtime=b[m]+p[m].starttime;
               fts=b[m]+a[m];
               sum-=b[m];
               b[m]=0;
               p[m].waittime=p[m].starttime-a[m];


        }
       else
       {
               fts=a[m]+tq;
               p[m].endtime=tq+p[m].starttime;
               sum-=tq;
               b[m]-=tq;
               p[m].waittime=p[m].starttime-a[m];

       }

       for(int i=0;i<n;i++)
       {

               if(a[i]<=fts && i!=m && b[i]!=0)
               {
                    rq[++rear]=i;
               }
       }

       if(b[m]!=0){
               rq[++rear]=m;
               a[m]=fts;
       }



       while(sum>0)
       {
               m=rq[front];


               if(m!=-1){

               p[m].starttime=fts;


             if(b[m]<=tq)
             {


               fts+=b[m];
               p[m].endtime=fts;
               sum-=b[m];
               b[m]=0;
               p[m].waittime+=p[m].starttime-a[m];

             }
             else
             {
                       fts+=tq;
                       p[m].endtime=fts;
                       sum-=tq;
                       b[m]-=tq;
                       p[m].waittime+=p[m].starttime-a[m];

             }
             front=front+1;
               }
            for(int i=0;i<n;i++)
            {
               if(a[i]<=fts && i!=m && b[i]!=0)
               {
                       int k=0;
                       for(int j=front;j<=rear;j++)
                       {
                               if(i==rq[j])
                                  k=1;
                       }
                       if(k==0)
                               rq[++rear]=i;
              }

           }
            if(m!=-1)
            {
           if(b[m]!=0){
                 rq[++rear]=m;
                 a[m]=fts;}
            }
           if(rq[front]==-1 )
           {
               for(int i=0;i<n;i++)
               {
                   if(a[i]>fts && i!=m  && b[i]!=0)
                   {
                       rq[++rear]=i;

                   }
               }

               int min=rq[front];
               for(int i=front;i<=rear;i++)
               {
                   if(a[min]>a[rq[i]])
                   {
                       min=rq[i];
                   }
                }
                int p=rear;
                for(int i=front;i<=p;i++)
                {
                    if(rq[i]!=min)
                    {
                        rq[i]=-1;
                        --rear;
                    }
                }
                rq[front]=min;
                fts=a[min];
           }



           }

       for(int i=0;i<n;i++)
       {
               p[i].tattime=p[i].waittime+p[i].bursttime;
               printf("%s            %d \t  %d \t %d \t  %d \t %d \t %d \n",p[i].pname,p[i].arrivaltime,p[i].bursttime,p[i].starttime,p[i].endtime,p[i].waittime,p[i].tattime);
             }
}
