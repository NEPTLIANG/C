#include <stdio.h>
#include <string.h>
//结构体练习：学籍管理

struct student
//定义结构体student
{
	char name[10] ;
	char num[10] ;
	char sex[2] ;
	char addr[100] ;
	int age ;
	float chengji ;
};  //注意这里有分号

main()
{
	int i , a ;
	char searnum[10] ;
	struct student student[3] ;
	printf ("请输入三个学生的姓名及学号并以空格间隔：") ;
	for ( i=0 ; i<3 ; i++ )  //别忘了for里用的是分号
	{
		
		scanf ("%s" , student[i].name ) ;
		scanf ("%s" , student[i].num ) ;
	}
	printf ("请输入要查找的学生学号：") ; //别忘了分号
	scanf ("%s" , searnum ) ;
	for ( i=0 ; i<3 ; i++ )
	{
		a = strcmp(searnum,student[i].num) ;  //注意字符串对比不能直接用双等号，而应用strcmp函数
		if ( a == 0 )
		{
			printf ("你所查找的%s号学生的姓名为“%s”。\n" , student[i].num , student[i].name ) ;
		}
	}
}
