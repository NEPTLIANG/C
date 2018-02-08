#include <stdio.h>
#include <windows.h>
//本程序用于练习咏春防守，随机生成散手
main()
{
	int i;
	srand((unsigned)(time(NULL)));
	for (;;)
	{
		i = rand()%6+0;
		if (i == 0) { printf("内摊\n"); }
		if (i == 1) { printf("外摊\n"); }
		if (i == 2) { printf("内拦\n"); }
		if (i == 3) { printf("外拦\n"); }
		if (i == 4) { printf("撑掌\n"); }
		if (i == 5) { printf("耕手\n"); }
		Sleep(1000);
	}
}