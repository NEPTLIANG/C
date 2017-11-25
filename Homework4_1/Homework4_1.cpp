#include <stdio.h>
#include <math.h>  //包含了math.h头文件时，gcc编译记得加-lm参数
#include <string.h>
//作业4-题目1：编写能计算并返回任意矩形对角线长度的函数。函数的原型为：float ss(float a,float b),然后编写主程序从键盘输入任意矩形的两边长a,b,再调用该函数，在主程序中输出对角线长度
main()
{
	//float ss(float a,float b,float *y);
	float a , b , y , ss(float a,float b);
	//int *y
	//float *z ;
	puts ("请输入矩形的边长并以空格间隔：") ;  //puts内也要加双引号；puts输出完字符串后会换行
	scanf ("%f %f" , &a , &b );
	//*y = &y ;
	//z = &y ;
	y = ss(a,b) ;
	//ss(a,b) ;
	printf("该矩形对角线长度为%f\n" , y );
}

//float ss(float a,float b,float *z)
float ss(float a,float b)
{
	float y ;
	y = sqrt ( pow(a,2) + pow(b,2) ) ;
	//*y = sqrt ( pow(a,2) + pow(b,2) ) ;
	return y;
}
