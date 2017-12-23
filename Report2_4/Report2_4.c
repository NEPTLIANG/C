#include <stdio.h>
//实验2-题目4：编写程序，输入任意梯形的上底、下底和高，计算并打印该梯形的面积
main()
{
	double s , x , g , m ;
	printf ("请依次输入梯形的上底、下底和高并以空格间隔：") ;
	scanf ("%lf %lf %lf" , &s , &x , &g ) ;
	m = (s+x) * g / 2 ;
	printf ("该梯形的面积为%lf\n" , m );
} 
