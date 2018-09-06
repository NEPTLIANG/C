#include <stdio.h>
int main()
{
    int i , j , k , l ;
    char a[20] , b[20] , c[30] ;
    for ( i=0 ; i<20&&a[i]!=' ' ; i++ )
    {
        scanf("%c" , &a[i]) ;
        if ( a[i]==' ' ) { break ; }
        //printf("%d",i);
    }
    //printf("a OK");
    for ( j=0 ; j<20&&b[j]!=10 ; j++ )
    {
        scanf("%c" , &b[j]) ;
        if ( b[j]==10 ) { break ; }
        //printf("%d",j);
    }
    //printf("b OK");
    //for(int x=0;x<j;x++){printf("%c",b[x]);}
    for ( k=1 ; k<=i&&k<=j ; k++ )
    {
        if ( a[i-k]+b[j-k]-'0'> '9')
        {
            c[30-k] = a[i-k] + b[j-k] - ('9'+1) ;
            c[30-k-1] ++ ;
        }
        else
        {
            c[30-k] = a[i-k] + b[j-k] - '0' ;
        }
    }
    for ( l=29-k ; l>29-i||l>29-j ; l-- )
    {
        printf("%c" , c[l]) ;
    }
}
