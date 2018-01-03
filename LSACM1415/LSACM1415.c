#include <stdio.h>
#include <math.h>
main()
{
	int i , j ;
	for ( i=100 ; i<=200 ; i++ )
	{
		j = sqrt(i) ;
		for (   ; j<=i ; j++)
		{
			if ( i%j==0 ) { break ; }
		}
		if ( j>=i )
		{
			printf ( "%d\n" , i ) ;
		}
	}
}
