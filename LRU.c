[10:45 am, 29/06/2022] harika😊: #include<stdio.h>
int counter[100],temp=0,fts=0;
int main()
{
int frames,ref[100],len,i,p,j,flag=0,q,rear=-1;
printf("enter number of frames\n");
scanf("%d",&frames);
printf("enter length of string\n");
scanf("%d",&len);
printf("enter reference string\n");
for(int i=0;i<len;i++)
{
scanf("%d",&ref[i]);
}
int mem[frames],counter[frames];
for(p=0;p<frames;p++)
    {
        mem[p]=-1;
        counter[p]=0;
    }
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
 counter[r]=temp+1;
            temp=counter[r];
            printf("counter:%d\n",counter[r]);
            for(k=0;k<frames;k++)
            {
                printf("%d \t",mem[k]);
            }
            printf("\n");
        }
    } //part1 completed
    for(int i=q;i<len;i++)
    {
    printf("reference is:%d\n",ref[i]);
    printf("temp:%d\n",temp);
    int flag=0;
    for( j=0;j<frames;j++)
        {
            if(mem[j] == ref[i])
            {
                flag=1;
                for(int k=0;k<frames;k++)
                {
                    printf("%d\t",mem[k]);
                }
                printf("\n");
                printf("j:%d\n",j);
                counter[j]=++temp;
                printf("counter:%d",counter[j]);
                printf("\n");
                break;
            }
        }
        if(flag==0)
        {
        fts++;
        int min=0;
        for(int k=0;k<frames;k++)
        {
        if(counter[k]<counter[min])
        {
        min=k;
}
}
printf("min is:%d\n",min);
mem[min]=ref[i];
counter[min]=++temp;
//counter[min]=counter[min]+1;
q++;
printf("counter:%d \n",counter[min]);
for(int k=0;k<frames;k++)
            {
                printf("%d\t",mem[k]);
            }
            printf("\n");
}
}
printf("page fault:%d\n",fts);
}
