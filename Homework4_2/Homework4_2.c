#include <stdio.h>
#include <math.h>
main()
//作业4-题目2：编写给定三角形任意三边长能计算并返回任意三角形的面积的函数。函数的原型为：float ss1(float a,float b,float c),然后编写主程序从键盘输入任意三角形三边长再调用该函数，在主程序中输出面积
{
	float a , b , c , s , y , ss1(float a,float b,float c) ;
	printf ("请输入三角形三边长并以空格间隔：") ;
	scanf ("%f %f %f" , &a , &b , &c ) ;
	y = ss1(a,b,c) ;  //别忘了调用函数时参数列表里不要写参数类型
	printf ("该三角形面积为%f" , y );
}

float ss1(float a,float b,float c)
{
	float s , y ;
	s = (a+b+c) / 2 ;
	y = sqrt( s * (s-a) * (s-b) * (s-c) ) ;
	return y ;
}
