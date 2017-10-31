#include <stdio.h>
#include <math.h>
/*
ÌâÄ¿£ºÄ³º¯Êý¶¨ÒåÈçÏÂ£º

            |x |          x<0
      Y=   ln(x3)-xcos(300)-3x       0¡Üx¡Ü100
            8x2(5x+6)      x>100
±àÐ´³ÌÐò,ÊäÈëÈÎÒâxµÄÖµ£¬´òÓ¡ÏàÓ¦µÄyÖµ
*/
int main()
{
	double x , y ;
	printf ("请输入x的值：");
	scanf ("%lf" , &x );
	if ( x < 0 )
	{
		y = fabs(x) ;
		printf("%lf\n",y);
	}
	if ( x >= 0 && x <= 100 )
	{
		y = log ( pow(x,3) ) - x * cos(30*3.1415/180) - 3 * x ;
		printf("%lf\n",y);
	}
	if ( x > 100 )
	{
		y = 8 * pow(x,2) * (5*x+6);
		printf("%lf\n",y);
	}
	//printf ("相应的y值为%lf\n" , y );
	return 0;
}
