#include <stdio.h>
#include <math.h>
main()
{
	int n , a , i ;
	scanf ("%d" , &n ) ;
	if ( n>=3 && n<10000 )
	{
		a = sqrt(n) ;
		for ( i=a ; i<n ; i++ )
		{
			if ( n%i==0 )
			{
				break ;
			}
		}
		if ( i<n )
		{
			printf ("not prime\n") ;
		}
		else
		{
			printf ("prime\n") ;
		}
	}
}
