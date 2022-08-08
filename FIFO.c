#include<stdio.h>
int fts=0;
int main()
{
        int frames,len,ref[100];
        printf("enter number of frames in main memory\n");
        scanf("%d",&frames);
        printf("enter length of reference string\n");
        scanf("%d",&len);
        printf("enter reference string\n");
        for(int i=0;i<len;i++)
        {
                scanf("%d",&ref[i]);
        }
        int mem[frames],count=0,rear=-1; //circular queue
        for(int p=0;p<frames;p++)
        {
                mem[p]=-1;
        }
        printf("Memory arrangement is: \n");
        for(int i=0;i<len;i++)
        {
                int flag=0;
                
                if(rear!=frames-1)
                {

                        for(int j=0;j<frames;j++)
                        {
                                if(mem[j]== ref[i])
                                {
                                        flag=1;
                                  /*for(int k=0;k<frames;k++)
                              {
                                printf(" \t");
                                  }
                                    printf("\n");*/
                                        break;
                                }
                        }
                        if(flag==0)
                        {
                                fts++;
                                int r=(rear+1)%frames;
                          
                            rear++;
                                mem[r] = ref[i];
                               
                            for(int k=0;k<frames;k++)
                            {
                                    if(mem[k]==-1)
                                {
                                        printf(" \t");
                                        }
                                else
                                {
                                        printf("%d \t",mem[k]);
                                        }
                                }
                                printf("\n");
                        }
                }
                else
                {
                        rear=-1;
                        i--;
                }

        }
        printf("page fault:%d\n",fts);
}
