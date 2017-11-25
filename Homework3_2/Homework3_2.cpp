#include <stdio.h>
//编写程序，输入任意10个数，输出最大数。最小数
main()
{
	int i ;
	double max , min , a[10] ;  //注意定义数组要定义为a[10]而非a[i]
	printf("请输入10个数并以空格间隔：");
	for ( i=0 ; i<10 ; i++ )  //注意for里用分号间隔
	{
		scanf ("%lf" , &a[i] );
	}

	min = a[0] ;
	max = a[0] ;
	for ( i=0 ; i<10 ; i++ )
	{
		if ( max < a[i] ) { max = a[i] ; }
		if ( min > a[i] ) { min = a[i] ; }
	}

	printf ("最大数为%lf，最小数为%lf\n" , max , min );
}
