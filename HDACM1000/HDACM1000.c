#include <stdio.h>
int main()
{
    int i , j , k , l , maxLeng ;
    char a[20] , b[20] , c[30] ;
    for ( i=0 ; i<20 ; i++ )
    {
        scanf("%c" , &a[i]) ;
        if ( a[i]==' ' ) { break ; }
        //printf("%d",i);
    }
    //printf("a OK");
    for ( j=0 ; j<20 ; j++ )
    {
        scanf("%c" , &b[j]) ;
        if ( b[j]==10 ) { break ; }
        //printf("%d",j);
    }
    /*
    if ( i>j )
    {
        maxLeng = i ;
        //for ( int tmp=20-i ; tmp<20-j ; tmp++ ) { b[tmp] = 0 ; }
    }
    else
    {
        maxLeng = j ;
        //for ( int tmp=20-j ; tmp<20-i ; tmp++ ) { a[tmp] = 0 ; }
    }
    */
    //printf("b OK");
    //for(int x=20-maxLeng;x<20;x++){printf("%c",b[x]);}
    //printf("\n%d  %d\n  %d \n",i,j,maxLeng);
    c[30-1] = 0 ;
    for ( k=1 ; k<=i&&k<=j ; k++ )
    {
        if ( a[i-k]+b[j-k]-'0'> '9')
        {
            c[30-k] += a[i-k] + b[j-k] - ('9'+1) ;
            c[30-k-1] = 1 ;
        }
        else
        {
            c[30-k] += a[i-k] + b[j-k] - '0' ;
            c[30-k-1] = 0 ;
        }
        if ( c[30-k] > '9' )
        {
            c[30-k] -= 10 ;
            c[30-k-1] +=1 ;
        }
    }
    c[30-k] += '0' ;
    for ( ; k<=i||k<=j ; k++ )
    {
        if ( i>j )
        {
            c[30-k] += a[i-k] - '0' ;
            c[30-k-1] = '0' ;
        }
        else
        {
            c[30-k] += b[j-k] - '0' ;
            c[30-k-1] = '0' ;
        }
        if ( c[30-k] > '9' )
        {
            c[30-k] -= 10 ;
            c[30-k-1] +=1 ;
        }
    }
    if ( c[30-k] == '1' )
    {
        k = k+1 ;
    }
    //printf("%d",k);
    for ( l=30-k+1 ; l<30 ; l++ )
    {
        printf("%c" , c[l]) ;
    }
}
