#include <stdio.h>
#include <math.h>
//编写程序，任意输入5个数，将其最大值、最小值打印出来
int main()
{
	double a , b , c , d , e , max , min ;
	printf ("请输入5个数并以空格隔开：");
	scanf ("%lf %lf %lf %lf %lf" , &a , &b , &c , &d , &e );
	if ( a > b )
	{
		max = a ;
		min = b ;
	}
	else
	{
		max = b ;
		min = a ;
	}
	if ( max < b ) { max = b ; }
	if ( max < c ) { max = c ; }
	if ( max < d ) { max = d ; }
	if ( max < e ) { max = e ; }
	if ( min > b ) { min = b ; }
	if ( min > c ) { min = c ; }
	if ( min > d ) { min = d ; }
	if ( min > e ) { min = e ; }
	printf ("最大值为%lf\n" , max );
	printf ("最小值为%lf\n" , min );
	return 0;
}
