#include <stdio.h>
//ACM题目1446：输入一个年份，判断是否是闰年
main()
{
	int year , leap ;
	printf ("请输入年份:") ;
	scanf ("%d" , &year ) ;
	if ( year % 4 == 0 )
	{
		if ( year % 100 == 0 )
		{
			if ( year % 400 == 0 )
			{
				leap = 1 ;
			}
			else
			{
				leap = 0 ;
			}
		}
		else
		{
			leap = 1 ;
		}
	}
	else
	{
		leap = 0 ;
	}
	if ( leap == 1 )
	{
		printf ("leap year") ;
	}
	else
	{
		printf ("not leap year") ;
	}
}
