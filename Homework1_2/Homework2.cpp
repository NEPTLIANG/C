//已知圆柱的半径为10，高为100，求该矩形的对角线长度
#include <stdio.h>
int main()
{
	double r = 10 , h = 100 , pi = 3.14159 , s = 2 * pi * r * r + 2 * pi * r * h ;
	printf ("该圆柱的表面积为%f\n" , s );
	return 0;
}
