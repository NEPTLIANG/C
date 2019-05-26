#include <stdio.h>
#include <string>
//#include <string.h>
//#include <stdbool.h>
#define MEMSIZE 32 ;  //内存大小，单位：MByte
#define SIZE 1 ;  //不再切割的剩余分区大小
//宏定义布尔类型（C89没有定义布尔类型）
//typedef int bool ;
#define bool int
#define true 1 ;
#define false 0 ;

typedef struct FreePartitionChainNode  //空闲分区链节点
{
	struct FreePartitionChainNode	*forward	;  //前向指针
	struct FreePartitionChainNode 	*next	;  //后向指针
	bool	status	;  //状态位
	int		size	;  //分区大小
	int		start	;  //分区开始位置（虚拟地址）
	int		end		;  //分区结束位置
} fNode , *fNodep ;

int main()
{
    //int memoAlloc(string name , int size) ;
	//创建链表并初始化头结点
	fNodep head=(fNodep)malloc(sizeof(fNode)) , p ;
	head->forward = NULL ;
	head->next = (fNodep)malloc(sizeof(fNode)) ;  //创建初始空间节点
	head->status = 1 ;
	head->size = 0 ;
	//初始化初始空间节点
	p = head->next ;
	p->forward = head ;
	p->next = NULL ;
	p->status = 0 ;
	p->size = MEMSIZE ;
	p->start = 0 ;
	p->end = MEMSIZE ;
	memoAlloc() ;
	return 0 ;
}

int memoAlloc(string name , int size)  //分配内存
{
	fNodep p=head ;
	while ( p->next )  //遍历链表
	{
		if ( (p->size-size)>SIZE )  //多余部分足够大
		{
			//修改p节点大小、状态、后向指针、结束位置
			p->size = size ;
			p->status = 1 ;
			p->next = (fNodep)malloc(sizeof(fNode)) ;  //创建新节点作为剩余空间
			p->end = p->start + p->size ;
			p = p->next ;
