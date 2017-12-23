#include <stdio.h>
#include <math.h>
//实验2-题目2：编写程序，输入任意圆柱的半径和高，计算并打印该圆柱的总面积和体积
main()
{
	double r , h , s , v , pi=3.14159 ;
	printf ("请输入圆柱的底面半径和高并以空格间隔：") ;
	scanf ("%lf %lf" , &r , &h );
	s = 2 * pi * pow(r,2) + 2 * pi * r * h ;
	v = pi * pow(r,2) * h ;
	printf ("该圆柱的总面积为%lf,体积为%lf\n" , s , v );
}
