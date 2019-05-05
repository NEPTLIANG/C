#include <stdio.h>
#include <string>

typedef struct PCB
{
	string name ;  //进程名称
	int arriveTime ;  //到达时间
	int runningTime ;  //运行时长
	int starttime ;  //开始时间
	int endtime ;  //结束时间
	bool status=false ;  //是否运行完成
	PCB *next ;
} proc , *p ;

int time ;  //系统时间
int procQuantity ;  //就绪进程数量
p head = new proc ;  //就绪进程队列
head->next = NULL ;
p = head ;

int createProc()
{
	p->next = new proc ;
	p = p->next ;
	p->next = NULL ;
	scanf("%s %d %d" , &p->name , &p->arriveTime , &p->runningTime ) ;
	return 0 ;
}

p findNextProc()
{
	p = head ;
	int earliestArriTime=0 ;
	p nextProc=head ;
	for ( int i=0 ; i<procQuantity ; i++ )
	{
		if ( p->arriveTime<earliestArriTime )
		{
			nextProc = p ;
		}
		p = p->next ;
	}
	return nextProc ;
}

int dispatch(p nextProc)
{
	nextProc->starttime = time ;
	nextProc->endtime = time+nextProc->runningTime ;
	nextProc->status = true;
	return 0 ;
}

int main()
{
	cin >> quantity ;
	create() ;
	dispatch() ;
	return 0 ;
}