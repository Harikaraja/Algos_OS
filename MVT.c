#include<stdio.h>
int allocated[100][2],freem[100][2];
void	print(int i,int available){

			    	printf("\n Not possible to allocate memory \nTime quantum ended:\n\n");
			    	printf("        start\t endlocation\n");
			    	for(int k=1;k<i;k++)
			    	{
			    		
			    		printf("process  %d :  %d     %d\n",k,allocated[k][0],allocated[k][1]);
					}
                                 for(int k=0;k<i;k++)
			    	{
			    		if(freem[k][1]-freem[k][0]!=0)
			    		printf("freelocation  %d : %d \t %d\n",k,freem[k][0],freem[k][1]);
					}
					printf("\nExternal fragmentation:%d",available);
                                }
				
int main()
{
	int i=1,m,os,available,tq,p,psize[100],pbt[100],fts=0,flag,y=0;
	for(int i=0;i<100;i++)
	{
		freem[i][0]=0;
		freem[i][1]=0;
	}
	printf("Enter memory size:");
	scanf("%d",&m);
	printf("Enter os size:");
	scanf("%d",&os);
	available=m-os;
	fts=400;
	
	printf("\n Available memory:%d\n",available);
	printf("Enter time quantum:");
	scanf("%d",&tq);
	printf("Enter no of processes:");
	scanf("%d",&p);
	int sum=0;
	int avail=m;
	while(i<=p)
	{
		flag=0;
		printf("Enter process %d size:",i);
		scanf("%d",&psize[i]);
		printf("Enter process %d burst time:",i);
		scanf("%d",&pbt[i]);
		if(psize[i]<=available)
		{
			
			if(fts+psize[i]<=avail){

			allocated[i][0]=fts;
						
			allocated[i][1]=fts+psize[i];
			fts+=psize[i];
			available-=psize[i];
			printf("\nprocess %d is allocated from %d-%d:\n",i,allocated[i][0],
		      allocated[i][1]);
	    	printf("\nAvailable:%d\n",available);
			flag=1;}
			
			else
			{
				
				for(int j=0;j<i;j++)
				{
				    
					if(psize[i]<=freem[j][1]-freem[j][0])
					{
						flag=1;
						allocated[i][0]=freem[j][0];
						allocated[i][1]=freem[j][0]+psize[i];
						freem[i][0]=allocated[i][1];
						freem[i][1]=freem[j][1];
						freem[j][0]=0;
						freem[j][1]=0;
						
						printf("\nprocess %d is allocated from %d-%d:\n",i,allocated[i][0],
		                  allocated[i][1]);
	                	printf("\nAvailable:%d\n",available);
		 			}
				}
		   }                               
			
		}
		
		 if( flag==0)
		{
			
			if(fts<avail && psize[i]>available)
			{
				freem[0][0]=fts;
				freem[0][1]=avail;
				printf("\nExternal fragmentation:%d",avail-fts);
			}
			else{
			}
			int min=1;
     	   	for(int j=1;j<i;j++)
     	   	{
     	   		if(pbt[min]>pbt[j])
     	   		  min=j;
			}
		   	if(psize[i]<=psize[min])
            {
            	if(pbt[min]<=tq)
            	{
            		tq-=pbt[min];
				   
            	printf("\nprocess %d is taken out\n",min);
            	pbt[min]=100000;
            	freem[min][0]=0;
            	freem[min][1]=0;
            	
            	printf("\nExternal fragmentation:%d\n",psize[min]-psize[i]);
            	
            	
            	allocated[i][0]=allocated[min][0];
            
            	allocated[i][1]=allocated[i][0]+psize[i];
            	available+=psize[min]-psize[i];
            	
            	freem[i][0]=allocated[i][1];
            	freem[i][1]=allocated[min][1];
            	allocated[min][0]=0;
            	allocated[min][1]=0;
            	printf("\nprocess %d is allocated from %d - %d\n",i,allocated[i][0],
				       allocated[i][1]);
				printf("\nAvailable:%d\n",available);
			    } 
			    else
			    {
			    	print(i,available);
			    	y=1;
			        break;
				
				}
			}	
		    else
			{
				printf("\n process %d cant be fit into memory\n",i);
			
			}
			
		}
	    for(int p=0;p<=i;p++)
	    {
	      for(int r=0;r<=i;r++)
		  {
		  	
		  	if(freem[p][1]==freem[r][0])
		  	{
		  		freem[p][1]=freem[r][1];
		  		freem[r][0]=0;
		  		freem[r][1]=0;
			}
		  }	
		}
		i++;
	}
	   if(y!=1)
		print(p,available);
}
