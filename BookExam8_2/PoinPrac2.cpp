#include <stdio.h>
//课本例8.2：输入a和b两个整数，按先大后小的顺序输出a和b
main()
{
	int a , b , *c , *d , *min ;
	c = &a ;
	d = &b ;
	printf ("请输入两个整数并以空格间隔：") ;
	scanf ("%d %d" , c , d );
	
	if ( *c < *d )
	{
		min = c ;
		c = d ;
		d = min ;
	}

	printf ("这两个整数按先大后小的顺序排列为%d,%d\n" , *c , *d );
}
