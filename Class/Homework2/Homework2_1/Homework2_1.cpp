#include <stdio.h>
#include <math.h>
//ÌâÄ¿£º±àÐ´³ÌÐò,ÈÎÒâÊäÈë3¸ö×Ö·û£¬È»ºó°´ASCIIÂëÖµ´ÓÐ¡µ½´óµÄË³Ðò´òÓ¡Õâ3¸ö×Ö·û¡£
int main()
{
	char a , b , c , i ;
	printf ("请输入3个字符并以空格间隔：");
	scanf ("%c %c %c" , &a,&b,&c);
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
	printf("%c %c %c\n", a,b,c);
	return 0;
}
