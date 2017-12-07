#include <stdio.h>
//课本例8.1：通过指针访问整型变量
main()
{
	int i ;
	char a , b ;
	char *c ;
	c = &a ;
	for(;;)
	{
	printf ("请输入字符:");
	scanf ("%c" , &b );
	*c = b ;
	printf ("该字符的ASCII码值为%d\n" , *c );
	}

	/*
	int a=1984 , *b ;
	b = &a ;
	printf ("%d\n" , *b ) ;
	*/

}
