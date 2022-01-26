#include<stdio.h>
#include<stdlib.h>
void main()
{
	int f,fs,p,i,page[20][2],add=5000,hash[20];
	printf("enter the no of frames:");
	scanf("%d",&f);
	printf("\nenter page/frame size:");
	scanf("%d",&fs);
	printf("\nenter the no. of pages:");
	scanf("%d",&p);

	for(i=0;i<p;i++)
	{
		page[i][0]=-1;
		page[i][1]=add;
		add=add+fs;
		hash[i]=0;
	}

	int lower=0,upper=15,num;
	num = (rand() % (upper - lower + 1)) + lower;
	i=0;
	while(i<p)
	{
		if(hash[num]!=1)
		{
			page[i][0]=num;
			hash[num]=1;
			i++;
		}
		num = (rand() % (upper - lower + 1)) + lower;
	}

	printf("page no. frame no. allocated address");
	for(i=0;i<p;i++)
	{
	    printf("\npage %d      %d       %d\n",i,page[i][0],page[i][1]);
	}


	int pg,o,flag=1;

	while(flag==1)
	{
		printf("\nenter the pg number:");
		scanf("%d",&pg);
		if(pg>=p)
		{
			printf("\ninvalid pg no");
			flag==1;
		}
		else
		{
			flag=0;
			break;
		}
	}


	flag=1;
	while(flag==1)
	{
		printf("\nenter the offset:");
		scanf("%d",&o);
		if(o>fs-1)
		{
			printf("\ninvalid offset");
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}


	for(i=0;i<p;i++)
	{
		if(i==pg)
		{
			int k=page[i][1]+o;
			printf("\nPhysical address:%d",k);
		}
	}



}
