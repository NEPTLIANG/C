#include <iostream>
#include <string>
#include <algorithm>
using namespace std ;

struct Prog
{
	string name ;
	double waitingTime ;
} prog[10000] ;

bool cmp(Prog a , Prog b)
{
	return a.waitingTime<b.waitingTime ;
}

int quantity ;

int create()
{
	for ( int i=0 ; i<quantity ; i++ )
	{
		cin >> prog[i].name >> prog[i].waitingTime ;
	}
	return 0 ;
}

int dispatch()
{
	for ( int i=quantity-1 ; i>=0 ; i-- )
	{
		sort(prog , prog+quantity , cmp) ;
		cout << prog[i].name << " " << prog[i].waitingTime << endl ;
		quantity-- ;
	}
	return 0 ;
}

int main()
{
	cin >> quantity ;
	create() ;
	dispatch() ;
	return 0 ;
}