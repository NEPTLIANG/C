#include <stdio.h>
main()
{
	int i , x[50] , c[50] ;
	for ( i=0 ; i<50 ; i++ )
	{
		scanf ("%d %d" , &x[i] , &c[i] ) ;
	}
	for ( i=0 ; i<50 ; i++ )
	{
		if ( c[i]>=0 && c[i]<=100 )
		{
			if ( c[i] >= 80 )
			{
				printf ("%d %d\n" , x[i] , c[i] ) ;
			}
		}
	}
}