#include <stdio.h>
#include <math.h>
//编写程序，任意输入3个字符，然后按ASCII值从小到大的顺序打印这3个字符
int main()
{
	char a , b , c , i ;
	printf ("请输入3个字符并以空格间隔：");
	scanf ("%c %c %c" , &a , &b , &c );
	if ( a > b )
	{
		i = a ;
		a = b ;
		b = i ;
	}
	if ( a > c )
	{
		i = a ;
		a = c ;
		c = i ;
	}
	if ( b > c )
	{
		i = b ;
		b = c ;
		c = i ;
	}
	printf ("%c %c %c\n", a,b,c);
	return 0;
}
