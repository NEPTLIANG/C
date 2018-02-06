#include <stdio.h>
main()
{
	int a ;
	scanf ("%d" , &a ) ;
	if ( a%3==0 && a%5==0 )
	{
		printf ("can\n") ;
	}
	else
	{
		printf ("cannot\n") ;
	}
}