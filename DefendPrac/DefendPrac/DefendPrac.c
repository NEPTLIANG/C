#include <stdio.h>
#include <unistd.h>  //Linux下sleep函数的头文件为unistd.h(CSDN博客@qq_31828515)
//#include <windows.h>  Windows OS下Sleep函数的头文件为Windows.h(CSDN博客@qq_31828515)
//本程序用于通过随机生成动作来练习咏春防守
main()
{
	int i;
	srand((unsigned)(time(NULL)));  //用系统当前时间设置rand()随机序列种子,保证每次运行随机序列不一样(CSDN博客@u010141928)
	for (;;)
	{
		i = rand()%6+0;  //C语言中用rand()函数产生从0开始6个数内的随机整数(CSDN博客@u010141928)
		if (i == 0) { printf("内摊\n"); }
		if (i == 1) { printf("外摊\n"); }
		if (i == 2) { printf("内拦\n"); }
		if (i == 3) { printf("外拦\n"); }
		if (i == 4) { printf("撑掌\n"); }
		if (i == 5) { printf("耕手\n"); }
		sleep(1);  //sleep函数的函数名区分大小写,有的编译器是大写(如VS2017的编译器),有的编译器是小写(如GCC);Sleep函数的时间在Windows OS下以毫秒为单位,Linux下以秒为单位(CSDN博客@qq_31828515)
	}
}
