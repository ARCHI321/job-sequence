#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,**a,*job,i,j,min = 0,temp;
	scanf("%d",&n);
	a = (int**)malloc(n*sizeof(int*));
	job = (int*)malloc(n*sizeof(int));
	for(j=0;j<n;j++)
	{ 
	  a[j] = (int*)malloc(3*sizeof(int));
    }   
    
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j][2]>a[min][2])
			min = j;
		}
		
		temp = a[min][2];
		a[min][2] = a[i][2];
		a[i][2] = temp;
		
		temp = a[min][1];
		a[min][1] = a[i][1];
		a[i][1] = temp;
		
		temp = a[min][0];
		a[min][0] = a[i][0];
		a[i][0] = temp;
	}
	

	
	
	for(j=1;j<=n;j++)
	{ 
	 job[j] = 0;
    }
	
	
	j=0;
	int count = 0,max,dead,sum = 0;
	while(j< n)
	{
	max = a[j][2];
	dead = a[j][1];
	if(job[dead] == 0)
	{
		job[dead] = a[j][0];
		count++;
		sum = sum + max;
	}
	else
    {

    	for(i=dead-1;i>=1;i++)
	    {
		  if(job[i] == 0)
		  {
		  	count++;
		  	sum = sum + max;
		  	job[i] = a[j][0];
		  	break;
		  }

	    }
	}
	j++;
	}

    printf("\n%d %d",count,sum);
}
