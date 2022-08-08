#include<stdio.h>
int q=0,fts=0;
int main()
{
        int frames,len,ref[100],p,i;
        printf("enter number of frames in main memory\n");
        scanf("%d",&frames);
        printf("enter length of reference string\n");
        scanf("%d",&len);
        printf("enter reference string\n");
        for( i=0;i<len;i++)
        {
                scanf("%d",&ref[i]);
        }
        int mem[frames];
        for(p=0;p<frames;p++)
        {
                mem[p]=-1;
        }
        int rear=-1,j,flag=0;
        for(i=0;i<frames;i++)
        {

                for( j=0;j<frames;j++)
                {
                        if(mem[j] == ref[q])
                        {
                                flag=1;
                            for(int k=0;k<frames;k++)
                            {
                              printf("%d\t",mem[k]);
                            }
                                printf("\n");
                                break;
                        }
                }
                int k=0;
                if(flag==0)
                {
                        fts++;
                        int r=(rear+1)%frames;
                        rear++;
                        mem[r]=ref[q++];
 for(k=0;k<frames;k++)
                          {
                             printf("%d \t",mem[k]);
                          }
                        printf("\n");
                }
        } //part1 completed
        printf("fts:%d\n",fts);
        int rear1=-1;
        for(i=q;i<len;i++)
        {
                int flag=0,pp=0,id[100];
                printf("reference is :%d \t,i is:%d\n",ref[i],i);
                for(int t=0;t<frames;t++)
                {
                    if(mem[t]==ref[i])
                    {
                        flag=1;
                        for(int rq=0;rq<frames;rq++)
                        {
                          printf("%d\t",mem[rq]);
                        }
                        break;
                    }
                }
                printf("flag is:%d\n",flag);
                int flag1[100];
                for(int ii=0;ii<frames;ii++)
                {
                  flag1[ii]=0;
                }
                if(flag==0)
                {
                    for(int m=0;m<frames;m++)
                    {
                        for(int l=i;l<len;l++)
                        {
                            if(mem[m]==ref[l])
                            {
                                id[pp++]=l;
                                //count++;
                                flag1[m]=1;
                                break;//store in arra
 }
                        }
                    }
                    int mini,flag2=0,tr;
                  for(int ip=0;ip<frames;ip++)
                  {
                    if(flag1[ip]==0)
                    {
                       mini=ip;//frame number is  storing
                       tr=ip;
                       flag2=1;
                        break;
                    }
                 }
               if(flag2==0)
               {
                    //fts++;
                    //printf("fts:%d\n",fts);
                    int max=0,lq;
                    for(lq=0;lq<pp;lq++)
                    {
                       if(id[lq]>id[max])
                      {
                         max=lq;
                      }
                    }
                    printf("max in range:%d",max);
                    printf("size of array is:%d\n",pp);
                    printf("identity array is:\n");
                    for(int it=0;it<pp;it++)
                    {
                       printf("%d  ",id[it]);
                    }
                    printf("\n");
                   tr=max;
                }
                    fts++;
                    printf("fts:%d\n",fts);
                    printf("max value is:%d\n",tr);
                    mem[tr]=ref[i];
                    for(p=0;p<frames;p++)
                    {
                        printf("%d\t",mem[p]);
}
                    printf("\n");
                }
        }
        printf("page faults:%d\n",fts);
}
