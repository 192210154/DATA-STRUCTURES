#include<stdio.h>
int fibonacci(int num)
{
	if (num==0)
	{
		return 0;
	}
	else if(num==1)
	
	return 1;

	else
	{
		return fibonacci(num-1)+fibonacci(num-2);//recursio function
	}
}
int main()
{
	int num;
	printf("enter tye number of elements: ");
	scanf("%d",&num);
	int i;
	for(i=0;i<num;i++);
	{
		printf("%d, ",fibonacci(i));
	}
}

