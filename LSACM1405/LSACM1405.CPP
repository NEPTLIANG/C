#include<stdio.h>
main()
{
	int a , b , c , max ;
	scanf("%d,%d,%d" , &a , &b , &c ) ;
	if ( a>b )
	{
		max = a ;
	}
	else  //注意还要有个else，否则b>a时会出错
	{
		max = b ;
	}
	if ( c>max )
	{
		max = c ;
	}
	printf("max=%d\n" , max ) ;
}