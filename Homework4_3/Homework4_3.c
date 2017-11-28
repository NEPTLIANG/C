#include <stdio.h>
#include <math.h>
//作业4-题目3：编写能计算并返回任意圆柱体积的函数。函数的原型为：float ss2(float r,float h),其中r,h分别为圆柱的半径和高，然后编写主程序从键盘输入任意圆柱的半径和高，再调用该函数，在主程序中输出圆柱体积
main()
{
	float r , h , v , ss2(float r,float h) ;
	printf ("请依次输入圆柱的底面半径和高并以空格间隔：") ;
	scanf ("%f %f" , &r , &h ) ;
	v = ss2(r,h) ;
	printf ("该圆柱的体积为%f\n" , v ) ;
}

float ss2(float r,float h)
{
	float v ;
	v = 3.14159 * pow(r,2) * h ;
	return v ;
}
