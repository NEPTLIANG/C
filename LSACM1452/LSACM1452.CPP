#include <stdio.h>
#include <string.h>
main()
{
	int i ;
	char a[5] ;
	gets(a) ;
	printf ( "%d\n" , strlen(a) ) ;
	for ( i=0 ; i<5 ; i++ )
	{
		printf ( "%c " , a[i] ) ;
	}
	printf ( "\n" ) ;
	for ( i=4 ; i>=0 ; i-- )
	{
		printf ( "%c " , a[i] ) ;
	}
	printf ( "\n" ) ;
}