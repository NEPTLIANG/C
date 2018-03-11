#include <stdio.h>
#include <string.h>
//字符串处理练习

calc()
//统计句子里的单词数
{
	int y=0 , i , x=0 ;  //别忘了初始化该初始化的值
	char a[10000] ;
	puts("请输入一句话：") ;
	gets(a) ;
	for ( i=0 ; a[i]!='\0' ; i++ )  //可通过判断是否到达空字符(\0)来判断是否判断完，要加单引号
	{
		if ( x==0 && ( ( a[i]>='0' && a[i]<='9' ) || ( a[i]>='A' && a[i]<='Z' ) || ( a[i]>='a' && a[i]<='z' ) ) )  //"\0"是空字符而非空格；"0"是空值(null)的ASCII码值而非空格的；空格是ASCII码值为32而非0，判断可用“' '”表示空格；别忘了判断是否相等用的是两个等号
		{
			y++ ;
			x = 1 ;
		}
		if ( ( a[i]<'0' ) || ( a[i]>'9' && a[i]<'A' ) || ( a[i]>'Z' && a[i]<'a' ) || ( a[i]>'z') )
		{
			x = 0 ;
		}
	}
	printf ( "单词数为%d\n" , y ) ;
}

int sear()
//查找字符串
{
	int i , j , k=-1 , stat=0 ;
	char sest[10000] ;
	gets(sest) ;
	for ( i=0 ; a[i]!='\0' ; i++ )
	{
		if ( strcmp(a[i],sest[0]) == 1 )  //别忘了字符串对照要用?函数而非两个等号
		{
			for ( j=0 ; sest[j]!='\0' ; j++ )
			{
				if ( strcmp(a[i+j],sest[j]) == 1 )
				{
					stat = 1 ;
				}
				else
				{
					//stat = 0 ;
					break ;  //注意区分break（打破）和brake（刹车）
				}
			}
			/*
			if ( stat==0 )
			{
				puts("没有找到该字符串") ;
			}
			*/
			if ( stat==1 )
			{
				k=i ;
				printf ( "%d" , k ) ;
			}
		}
	}
	if ( k==-1 )
	{
		puts("没有找到该字符串") ;
	}
	return 0 ;
}

main()
{
	char choo(100) ;
	scanf ( "%c" , choo ) ;
	if ( strcmp(choo,calc) ==1 )
	{
		calc() ;
	}
	if ( strcmp(choo,sear) == 1 )
	{
		choo() ;
	}

}
