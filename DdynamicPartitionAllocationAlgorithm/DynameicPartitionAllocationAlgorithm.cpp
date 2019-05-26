#include <stdio.h>
#include <string>
#define MEMSIZE 32;  //�ڴ��С����λ��MByte
#define SIZE 1 ;  //�����и��ʣ�������С

typedef struct FreePartitionChainNode  //���з������ڵ�
{
	fNodep	forward	;  //ǰ��ָ��
	fNodep	next	;  //����ָ��
	bool	status	;  //״̬λ
	int		size	;  //������С
	int		start	;  //������ʼλ�ã������ַ��
	int		end		;  //��������λ��
} fNode , *fNodep ;

int main()
{
	//����������ʼ��ͷ���
	fNodep head=(fNodep)malloc(sizeof(fNode)) , p ;
	head->forward = null ;
	head->next = (fNodep)malloc(sizeof(fNode)) ;  //������ʼ�ռ�ڵ�
	head->status = 1 ;
	head->size = 0 ;
	//��ʼ����ʼ�ռ�ڵ�
	p = head->next ;
	p->forward = head ;
	p->next = null ;
	p->status = 0 ;
	p->size = MEMSIZE ;
	p->start = 0 ;
	p->end = MEMSIZE ;
	memoAlloc() ;
	return 0 ;
}

int memoAlloc(string name, int size)  //�����ڴ�
{
	fNodep p=head ;
	while ( p->next )  //��������
	{
		if ( (p->size-size)>SIZE )  //���ಿ���㹻��
		{
			//�޸�p�ڵ��С��״̬������ָ�롢����λ��
			p->size = size ;
			p->status = 1 ;
			p->next = (fNodep)malloc(sizeof(fNode)) ;  //�����½ڵ���Ϊʣ��ռ�
			p->end = p->start + p->size ;
			p = p->next ;
