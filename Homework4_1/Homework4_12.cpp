#include <stdio.h>
#include <math.h>
main()
{
	float a , b , y , ss(float a,float b,float *y) ;
	scanf ("%f %f" , &a , &b );
	ss(a,b,&y) ;  //要直接把变量y的地址传递给子函数
	printf ("%f" , y );
}

float ss(float a,float b,float *y)  //定义子函数时参数列表要包含指针变量
{
	*y = sqrt ( pow(a,2) + pow(b,2) ) ;
}
