#include <stdio.h>
main()
{
	int a[10] , i ;
	printf ("请输入10个整数并以空格间隔：");  //别忘了分号
	for ( i=0 ; i<10 ; i++ )  //别忘了for中用分号
	{	
		scanf ("%d" , &a[i] );
		printf ("%d " , a[i] );
	}
}