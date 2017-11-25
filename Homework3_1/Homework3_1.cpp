#include <stdio.h>
#include <math.h>
//编写程序，输入任意10个数，分别输出负数、0、正数的个数
int main()
{
	int i ; //注意数组下标要定义为整刑
	double f=0 , l=0 , z=0 , a[10] ;  //注意定义数组要定义为a[10]而非a[i]
	printf("请输入10个数并以空格间隔：");
	for ( i=0 ; i<10 ; i++ )  //注意for里用的是分号
	{
		scanf ("%lf" , &a[i] );

		if ( a[i] < 0 ) { f++ ; }
		if ( a[i] == 0 ) { l++ ; }  //注意判断要用两个等于号
		if ( a[i] > 0 ) { z++ ; }
		
	}
	printf ("负数个数为%lf，0个数为%lf，正数个数为%lf\n" , f , l , z );
	return 0;
}
