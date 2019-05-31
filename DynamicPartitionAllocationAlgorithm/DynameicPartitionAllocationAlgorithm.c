#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //C语言用的是stdlib.h而不是cstdlib
//#include <cstdlib>
//#include <string>
//#include <stdbool.h>  //引入真布尔类型
#define MEMSIZE 32  //内存大小，单位MByte；注意define行末无分号
#define SIZE 1  //不再切割的剩余分区大小
//宏定义布尔类型（C89没有定义布尔类型）
//typedef int bool ;
#define bool int
#define true 1
#define false 0
//2019.5.31.Fri 操作系统实验3：内存分配（动态分区分配算法）
//诸神庇佑，BUG退散
/*Test case:
3
liang 16
luo 4
ming 8*/

typedef struct FreePartitionChainNode  //空闲分区链节点
{
	struct FreePartitionChainNode	*forward	;  //前向指针
	struct FreePartitionChainNode 	*next	;  //后向指针
	bool	status  ;  //状态位，已分配为1，反之为0
    char statusDescript[100] ;  //所属进程
	int		size	;  //分区大小
	int		start	;  //分区开始位置（虚拟地址）
	int		end		;  //分区结束位置
} fNode , *fNodep ;

int main()
{
    int boot() ;
    boot() ;  //开始开机
}

int boot()  //开机
{
    int memoAlloc(char name[100] , int size , fNodep head) ;
	//创建链表并初始化头结点
	fNodep head=(fNodep)malloc(sizeof(fNode)) , p ;
	head->forward = NULL ;
	head->next = (fNodep)malloc(sizeof(fNode)) ;  //创建初始空间节点
	head->status = 1 ;
    strcpy(head->statusDescript , "头结点") ;
	head->size = 0 ;
    head->start = 0 ;
    head->end = 0 ;
	//初始化初始空间节点
	p = head->next ;
	p->forward = head ;
	p->next = NULL ;
	p->status = 0 ;
    strcpy(p->statusDescript , "  未分配") ;
	p->size = MEMSIZE ;
	p->start = 0 ;
	p->end = MEMSIZE ;
    int progressCount ;
    scanf("%d" , &progressCount) ;
    while ( progressCount-- )  //输入进程信息并分配空间
    {
        char name[100] ; int size ;
        scanf("%s %d" , &name , &size) ;
	    memoAlloc(name , size , head) ;  //开始分配
    }
    //输出分配结果
    p = head->next ;
    while ( p )
    {
        printf("所属进程：%8s，分区状态：%d，分区大小：%8dMB \n开始地址：%8d，结束地址：%8d\n\n" , p->statusDescript , p->status , p->size , p->start , p->end) ;
        p = p->next ;
    }
	return 0 ;
}

int memoAlloc(char name[100] , int size , fNodep head)  //分配内存
{
	fNodep p=head->next ;
	while ( p )  //遍历链表
	{
        //int residue=(p->size)-size ;  //剩余空间
		if ( (p->size-size)>=SIZE && !p->status )  //若多余部分足够大则划分一块空间分配
		{
			fNodep newNode = (fNodep)malloc(sizeof(fNode)) ;  //给剩余空间创建新节点作为新空闲分区
            //修改指针，将新节点插入链表
            newNode->forward = p ;
            newNode->next = p->next ;
            p->next = newNode ;
            if ( newNode->next )
            {
                newNode->next->forward = newNode ;
            }
            //修改新节点的信息，作为新空闲分区
            newNode->status = 0 ;
            strcpy(newNode->statusDescript , "  未分配") ;
            newNode->size = p->size-size ;
            newNode->start = p->start+size ;
            newNode->end = p->end ;
			//修改原节点的信息，分配出去
			p->status = 1 ;
            strcpy(p->statusDescript , name) ;  //C语言字符串数组不可以直接赋值，应该用strcpy函数
			p->size = size ;
			p->end = p->start + p->size ;
            return 0 ;  //分配结束
        }
        if ( p->size-size>=0 && !p->status )  //若多余部分不够大则整块空间分配
        {
            p->status = 1 ;
            return 0 ;  //分配结束
        }
        p = p->next ;  //若空闲分区不够大则检查下一个分区
    }
    printf("剩余空间不足，进程%s分配失败\n" , name) ;  //若找不到足够大的分区，输出错误信息并结束分配
    return 0 ;
}
