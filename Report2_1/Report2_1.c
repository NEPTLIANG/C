#include <stdio.h>
#include <math.h>
//实验2-题目1：编写程序，输入任意三角形的3个边长，然后判断其是否能构成三角形，如果能则计算其面积，否则打印出错信息
main()
{
	double a , b , c , s , y ;
	printf ("请输入三角形三边长并以空格间隔：") ;
	scanf ("%lf %lf %lf" , &a , &b , &c );
	if ( a+b>c && a+c>b && b+c>a )
	{
		s = (a+b+c) / 2 ;
		y = sqrt ( s * (s-a) * (s-b) * (s-c) ) ;
		printf ("该三角形面积为%lf\n" , y );
	}
	else
	{
		printf ("Error!\n");
	}
}
