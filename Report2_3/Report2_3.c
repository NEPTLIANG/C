#include <stdio.h>
#include <math.h>
main()
{
	double x , y ;
	printf ("请输入x值：") ;
	scanf ("%lf" , &x ) ;
	if ( x<0 )
	{
		y = fabs(x) * tan(3.14159/6) ;
	}
	if ( 0<=x && x<=100 )
	{
		y = sqrt( pow(x,2) + pow(x,3) ) ;
	}
	if ( x>100 )
	{
		y = pow(x,2) * (x+6) + 7*x ;
	}
	printf ("对应的y值为：%lf\n" , y ) ;
}
