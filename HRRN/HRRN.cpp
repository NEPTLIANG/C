#include <stdio.h>
#include <cstdlib>
#define bool int
#define true 1
#define false 0
//#include <iostream>
//#include <string>
//using namespace std ;
//高响应比优先调度算法(Highest Response Ratio Next, HRRN)
/* Test case:
3
luo 6 12
liang 1 9
ming 8 5
*/

typedef struct PCB
{
    char	name[100]    ;	//进程名
    bool    status=false      ;
    int		arriveTime	;	//到达时间
    int		requireTime ;	//要求服务时间
    int		waitingTime	;	//等待时间
    double	priority	;	//当前优先级
    int		startTime	;	//开始时间
    int		endTime		;	//结束时间
    struct PCB	*next		;
} prog , *progp ;

int create(progp p , int quant)  //创建进程
{
    for ( int i=0 ; i<quant ; i++ )
    {
        p->next = (progp)malloc(sizeof(prog)) ;
        p = p->next ;
        scanf("%s %d %d" , &p->name , &p->arriveTime , &p->requireTime) ;  //输入新进程的进程名、到达时间、要求服务时间
        p->next = NULL ;
    }
    return 0 ;
}

progp searchByArriTime(progp head)
{
    progp p = head->next ;
    progp nextProg = p->next ;
    while ( p->next )
    {
        if ( p->arriveTime<nextProg->arriveTime && !p->status )
        {
            nextProg = p ;
        }
        p = p->next ;
    }
    return nextProg ;
}

int run(progp nextProg , int *timep)
{
    nextProg->status = true ;
    printf("进程名称    ：%8s\t到达时间：%8d\n"	, nextProg->name , nextProg->arriveTime) ;  //打印下一个被调度进程的进程名、到达时间
    printf("要求服务时间：%8d\t等待时间：%8d\n"	, nextProg->requireTime	, nextProg->waitingTime) ;  //打印下一个被调度进程的要求服务时间、等待时间
    printf("响应时间（等待时间+要求服务时间）：%8d\n优先级（响应时间/要求服务时间） ：%8lf\n" , (nextProg->waitingTime+nextProg->requireTime) , nextProg->priority)	;  //打印下一个被调度进程的响应时间、执行时的优先级
    printf("开始时间    ：%8d\t结束时间：%8d\n\n" , nextProg->startTime , nextProg->endTime) ;  //打印下一个被调度进程的开始时间、结束时间
    *timep += nextProg->requireTime ;
    return 0 ;
}

int dispatch(progp head , int *timep)  //调度
{
    progp p=head ;
    progp nextProg=head ;  //指向下一个被调度的进程
    while ( p->next )  //遍历各进程，寻找下一个被调度的进程
    {
        p = p->next ;
        if ( *timep>p->arriveTime && !p->status )
        {
            //*timep += p->requireTime ;
            p->waitingTime = *timep - p->arriveTime ;  //计算当前进程的等待时间
            p->priority = ((double)p->waitingTime+p->requireTime) / p->requireTime ;  //计算当前进程的当前优先级
            if ( p->priority > nextProg->priority ) { nextProg = p ; }  //如果当前进程优先级最高，以当前进程为下一个被调度的进程
        }
        p->startTime = *timep ;
        p->endTime = p->startTime + p->requireTime ;
    }
    if ( nextProg==head )
    {
        nextProg = searchByArriTime(head) ;
    }
    run(nextProg, timep) ;
    return 0 ;
}

int main()
{
    int time=0 , quantity ;  //系统时间，进程数
    scanf("%d" , &quantity) ;
    progp head = (progp)malloc(sizeof(prog)) ;  //创建进程列表
    head->next = NULL ;

    create(head , quantity) ;
    progp nextProg = searchByArriTime(head) ;
    time += nextProg->arriveTime ;
    dispatch(head , &time) ;
    //run(nextProg , &time) ;
    quantity-- ;
    while ( quantity-- )
    {
        dispatch(head , &time) ;
    }
    return 0 ;
}
