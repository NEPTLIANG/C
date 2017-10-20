//已知华氏转摄氏温度的公式为：C=5/9(F-32)，编程序求当F=35时C的值
#include <stdio.h>
int main()
{
	double f = 35 , c = 5.0 / 9 * ( f - 32 ) ;
	//易错：千万别忘了要得到浮点值须用5.0/9而非5/9
	printf("C的值为%f\n" , c );
	return 0;
}
