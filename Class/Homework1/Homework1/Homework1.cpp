//已知矩形的边长分别为100/200，求该矩形的对角线长度
#include <stdio.h>
#include <math.h>
int main()
{
	double l = 100 , w = 200 , x ;
	x = sqrt ( l * l + w * w ) ;
	printf ( "该矩形的对角线长度为%f\n" , x ) ;
	return 0 ;
}
