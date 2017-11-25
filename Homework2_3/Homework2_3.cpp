#include <stdio.h>
#include <math.h>
/*
某函数定义如下：
           |x|                       x<0
      Y=   ln(x3)-xcos(300)-3x       0<=x<=100
           8x2(5x+6)                 x>100
编写程序，输入任意x的值，打印相应的y值
*/
int main()
{
	double x , y ;
	printf ("请输入x的值：");
	scanf ("%lf" , &x );
	if ( x < 0 )
	{
		y = fabs(x) ;
	}
	if ( x >= 0 && x <= 100 )
	{
		y = log ( pow(x,3) ) - x * cos(30*3.1415/180) - 3 * x ;
	}
	if ( x > 100 )
	{
		y = 8 * pow(x,2) * (5*x+6);
	}
	printf ("相应的y值为%lf\n" , y );
	return 0;
}
