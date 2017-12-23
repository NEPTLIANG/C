#include <stdio.h>
//用输入的密码给文本加密

void jiami(double passwd[],double word[],double *keyy)  //注意在函数之间传递字符串时要用字符数组名+[]而非字符数组名+[i]作参数
//加密函数
{
	int i ;
	double key ;
	for ( i=0 ; i<10 ; i++ )  //别忘了for里用分号
	{
		*keyy = *keyy + passwd[i] ;
		//计算：秘钥=密码（字符数组）各字符ASCII码值之和
	}
	//printf ("%f\n" , key );  //改了变量类型别忘了改printf和scanf里的
	//printf ("%s\n" , word ) ;
	for ( i=0 ; i<20 ; i++ )
	{
		word[i] = word[i] + key ;
		//加密：原文（字符数组）各字符的ASCII码值加上秘钥值得到密文（字符数组）
	}
	printf ("%s\n" , word ) ;
	printf ("finished\n") ;
}

void jiemi(double passwd[],double word[],double *keyy)
//解密函数
{
	int i ;
	double key ;
	printf ("%s\n" , word ) ;
	//printf ("%f\n" , key );
	for ( i=0 ; i<20 ; i++ )
	{
		word[i] = word[i] - key ;
		//解密：密文（字符数组）各字符的ASCII值减去秘钥值得到原文（字符数组）
	}
	printf ("%s\n" , word ) ;
	printf ("finished\n") ;
}

main()
{
	int  i , j ;  //别忘了定义数组下标
	double key = 0 ;
	double *keyy ;
	keyy = &key ;  //别忘了分号
	double passwd[10] , word[20] ;  //别忘了定义数组时定义为a[10]而非a[i]
	scanf ("%s" , passwd );  //输入字符串时不用for循环，直接sacnf+%s+字符数组名而非+字符数组名+[i]
	scanf ("%s" , word ) ;
	//printf ("%s %s\n" , passwd , word );  //printf中也是%s+字符数组名而非字符数组名+[i]
	jiami(passwd,word,&key) ;
	//调用加密函数
	jiemi(passwd,word,&key) ;
	//调用解密函数
}
