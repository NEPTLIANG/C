#include <stdio.h>
main()
{
	int m , n , x ;
	scanf ( "%d %d" , &m , &n ) ;
	if ( m>n ) { x=n ; }
	else { x=m ; }
	for (   ;   ; x-- )
	{
		if ( m%x==0 && n%x==0 )
		{
			printf ( "%d\n" , x ) ;
			break ;
		}
	}
}
