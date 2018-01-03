#include <stdio.h>
main()
{
	int i , j , tmp , a[4] ;
	for ( i=0 ; i<4 ; i++ )
	{
		scanf ( "%d" , &a[i] ) ;
	}
	for ( i=0 ; i<4 ; i++ )
	{
		for ( j=i ; j<4 ; j++ )
		{
			if ( a[i]>a[j] )
			{
				tmp = a[i] ;
				a[i] = a[j] ;
				a[j] = tmp ;
			}
		}
	}
	for ( i=0 ; i<4 ; i++ )
	{
		printf ( "%d " , a[i] ) ;
	}
	printf ( "\n" ) ;
}
