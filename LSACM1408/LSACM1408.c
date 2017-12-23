#include <stdio.h>
main()
{
	int a ;
	scanf ("%d" , &a ) ;
	if ( a<2500 && a>2000 )
	{
		if ( ( a%4==0 && a%100!=0 ) || a%400==0 )
		{
			printf ("leap year\n") ;
		}
		else
		{
			printf ("not leap year\n") ;
		}
	}
}