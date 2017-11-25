#include <stdio.h>
#include <math.h>
//分数按A(90-100),B(80-89),C(70-79),D(60-69),R(不及格)五级计分，编写程序，输入任意的分数，打印相应的等级，如果输入的分数大于100或者小于0，则打印出错
int main()
{
	double i ;
	printf ("请输入分数：");
	scanf ( "%lf" , &i );
	if ( i >= 90 && i <= 100 )
	{
		printf ("您的等级为A\n");
	}
	if ( i >= 80 && i <= 89 )
	{
		printf ("您的等级为B\n");
	}
	if ( i >= 70 && i <= 79 )
	{
		printf ("您的等级为C\n");
	}
	if ( i >= 60 && i <=69 )
	{
		printf ("您的等级为D\n");
	}
	if ( i >= 0 && i <= 59 )
	{
		printf ("您的等级为E\n");
	}
	if ( i > 100 || i < 0 )
	{
		printf ("Error!\n");
	}
	return 0;
}
