#include <stdio.h>
main()
{
	int score ;
	char y ;
	scanf ( "%d" , &score ) ;
	if ( score>=0 && score<=100 )
	{
		if ( score>=90 ) { y = 'A' ; }
		if ( score>=80 && score<=89 ) { y = 'B' ; }
		if ( score>=70 && score<=79 ) { y = 'C' ; }
		if ( score>=60 && score<=69 ) { y = 'D' ; }
		if ( score<=60 ) { y = 'E' ; }
		printf ( "%c\n" , y ) ;
	}
}