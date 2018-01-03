#include <stdio.h>
//输入一个小于五位的数，然后把各位数字倒序输出
main()
{
	int x , g , s , b , q , w , tmp ;
	scanf ( "%d" , &x ) ;
	if ( x<100000 )
	{
		w = x/10000 ;
		tmp = x%10000 ;
		q = tmp/1000 ;
		tmp = tmp%1000 ;
		b = tmp/100 ;
		tmp = tmp%100 ;
		s = tmp/10 ;
		tmp = tmp%10 ;
		g = tmp/1 ;
		printf ( "%d %d %d %d %d\n" , g , s , b , q , w ) ;
	}
}
