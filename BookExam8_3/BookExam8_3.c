#include <stdio.h>
//课本例8.3：题目要求同例8.2，即对输入的两个整数按先大后小顺序输出。现用函数处理，而且用指针类型的数据作函数参数
main()
{
	int a , b , *c , *d ;
	void MING(int *c,int *d) ;
	c = & a ;
	d = & b ;
	printf ("请输入两个整数：");
	scanf ("%d %d", c , d ) ;
	MING(c,d) ;
	printf ("这两个整数按先大后小顺序排列为%d,%d\n" , *c , * d) ;
}

void MING(int *c,int *d)  //子程序就算没有返回值也要定义返回值类型为void
{
	if ( *c < *d )
	{
		int *c , *d , *min ;
		min = c ;
		c = d ;
		d = min ;
	}
}
