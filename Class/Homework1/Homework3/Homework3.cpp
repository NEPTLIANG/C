//已知某电路的电压、电阻分别为220、20，求该电路所消耗的功率
#include <stdio.h>
int main()
{
	double v = 220 , r = 10 , p ;
	p = v * v / r ;
	printf("该电路所消耗的功率为%f\n" , p);
	return 0;
}
