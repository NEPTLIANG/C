#include <stdio.h>
#include <windows.h>
//������������ϰӽ�����أ��������ɢ��
main()
{
	int i;
	srand((unsigned)(time(NULL)));
	for (;;)
	{
		i = rand()%6+0;
		if (i == 0) { printf("��̯\n"); }
		if (i == 1) { printf("��̯\n"); }
		if (i == 2) { printf("����\n"); }
		if (i == 3) { printf("����\n"); }
		if (i == 4) { printf("����\n"); }
		if (i == 5) { printf("����\n"); }
		Sleep(1000);
	}
}