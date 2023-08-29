#include <stdio.h>
#include<conio.h>
int factorial(int);
int main()
{
int n,fact;
printf("Enter a positive integer: ");
scanf("%d", &n);
fact= factorial(n);
printf("Factorial of %d = %d",n, fact) ;
return 0;
}
int factorial(int num)
{
int i=1,f=1;
while(i<=num)
{
f=f*i;//without recirsion function
i++;
}
return f;
}

