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
4
liang 16
luo 2
ming 8
nb 4*/

typedef struct FreePartitionChainNode  //空闲分区链节点
{
	struct FreePartitionChainNode   *forward	            ;  //前向指针;c语言结构体递归定义要写struct，而且是要写结构体名而不是后面typedef出来的那个
	struct FreePartitionChainNode   *next	                ;  //后向指针
	bool	                        status                  ;  //状态位，已分配为1，反之为0
    char                            statusDescript[100]     ;  //所属进程
	int		                        size	                ;  //分区大小
	int		                        start	                ;  //分区开始位置（虚拟地址）
	int		                        end		                ;  //分区结束位置
} fNode , *fNodep ;

int main()
{
    int boot() ;
    boot() ;  //开始开机
}

int boot()  //开机
{
    int memAlloc(char name[100] , int size , fNodep head) ;
    int memRele(char name[100] , fNodep head) ;
	//创建链表并初始化头结点
	fNodep head=(fNodep)malloc(sizeof(fNode)) , p ;
	head->forward = NULL ;
	head->next = (fNodep)malloc(sizeof(fNode)) ;  //创建初始空间节点
	head->status = 1 ;
    strcpy(head->statusDescript , "Head") ;
	head->size = 0 ;
    head->start = 0 ;
    head->end = 0 ;
	//初始化初始空间节点
	p = head->next ;
	p->forward = head ;
	p->next = NULL ;
	p->status = 0 ;
    strcpy(p->statusDescript , "Unallocated") ;
	p->size = MEMSIZE ;
	p->start = 0 ;
	p->end = MEMSIZE ;
    int progressCount ;
    scanf("%d" , &progressCount) ;
    char name[100] ; int size ;  //进程名、请求空间大小
    for ( int i=0 ; i<progressCount ; i++ )  //输入进程信息并分配空间
    {
        scanf("%s %d" , &name , &size) ;
	    memAlloc(name , size , head) ;  //开始分配
    }
    //输出分配结果
    p = head->next ;  //注意p是赋为head还是head->next
    while ( p )  //注意是while(p)还是while(p->next)
    {
        printf("所属进程：%11s，分区状态：%d，分区大小：%8dMB \n开始地址：%11d，结束地址：%8d\n\n" , p->statusDescript , p->status , p->size , p->start , p->end) ;
        p = p->next ;
    }
    for ( int i=0 ; i<progressCount ; i++ )  //输入进程名回收对应空间
    {
        scanf("%s" , &name) ;
	    memRele(name , head) ;  //开始回收
        //输出回收结果
        p = head->next ;
        while ( p )
        {
            printf("所属进程：%11s，分区状态：%d，分区大小：%8dMB \n开始地址：%11d，结束地址：%8d\n\n" , p->statusDescript , p->status , p->size , p->start , p->end) ;
            p = p->next ;
        }
    }
	return 0 ;
}

int memAlloc(char name[100] , int size , fNodep head)  //分配内存
{
	fNodep p=head->next ;
	while ( p )  //遍历链表寻找可用分区
	{
        //int residue=(p->size)-size ;  //剩余空间
		if ( (p->size-size)>SIZE && !p->status )  //若多余部分足够大则划分一块空间分配
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
            strcpy(newNode->statusDescript , "Unallocated") ;
            newNode->size = p->size-size ;
            newNode->start = p->start+size ;
            newNode->end = p->end ;
			//修改原节点的信息，分配出去
			p->status = 1 ;
            strcpy(p->statusDescript , name) ;  //C语言字符串数组不可以直接赋值，应该用strcpy函数
			p->size = size ;
			p->end = p->start + p->size ;
            return 0 ;
        }
        if ( p->size-size>=0 && !p->status )  //若多余部分不够大则整块空间分配
        {
            p->status = 1 ;
            strcpy(p->statusDescript , name) ;
            return 0 ;
        }
        p = p->next ;  //若空闲分区不够大则检查下一个分区
    }
    printf("剩余空间不足，进程%s分配失败\n" , name) ;  //若找不到足够大的分区，输出错误信息
    return 0 ;
}

int memRele(char name[100] , fNodep head)  //分配内存
{
	fNodep p=head->next ;
	while ( p )  //遍历链表寻找对应进程
	{
        if ( !strcmp(p->statusDescript , name) )  //判断字符串是否相等要用strcmp而不能直接用双等号
        {
            if ( p->forward && p->next && !p->forward->status && !p->next->status )  //前后都邻接空闲分区
            {
                p->forward->size += (p->size+p->next->size) ;
                p->forward->end = p->next->end ;
                p->forward->next = p->next->next ;
                if ( p->next->next ) { p->next->next->forward = p->forward ; }
                return 0 ;
            }
            if ( p->forward && !p->forward->status )  //仅前接空闲分区
            {
                p->forward->size += p->size ;
                p->forward->end = p->end ;
                p->forward->next = p->next ;
                p->next->forward = p->forward ;
                return 0 ;
            }
            if ( p->next && !p->next->status )  //仅后接空闲分区
            {
                p->status = 0 ;
                strcpy(p->statusDescript , "Unallocated") ;
                p->size += p->next->size ;
                p->end = p->next->end ;
                p->next = p->next->next ;
                if ( p->next ) { p->next->next->forward = p ; }
                return 0 ;
            }
            //前后都不邻接空闲分区
            p->status = 0 ;
            strcpy(p->statusDescript , "Unallocated") ;
            return 0 ;
        }
        p = p->next ;
    }
    return 0 ;
}
