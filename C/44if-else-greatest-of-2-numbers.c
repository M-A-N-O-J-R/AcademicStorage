#include <stdio.h>

int main()
{
	int x,y;

	printf("Enter two integers: ");
	scanf("%d",&x);
	scanf("%d",&y);
	if( x < y )
    {
        printf("%d is greater than %d\n",y,x);
    }
	else
    {
        printf("%d is greater than %d\n",x,y);
    }
	return(0);
}
