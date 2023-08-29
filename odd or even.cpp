#include<stdio.h>
int main()
{
	int num[10],i;
	printf("enter the numbers:");
	for(i=0;i<10;i++)
	
		scanf("%d",&num[i]);
		
		printf("\n even numbers: \n");	
	
	for(i=0;i<10;i++)
	{
	if(num[i]%2==0)
	printf("%d\n",num[i]);
	}
	printf("\n odd number: \n");
	for(i=0;i<10;i++)
	{
	
	if(num[i]%2==1)
printf("%d\n",num[i]);
}
return 0;	
}
