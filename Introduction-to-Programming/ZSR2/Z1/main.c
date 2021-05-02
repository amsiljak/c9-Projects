#include <stdio.h>
#include <stdlib.h>


int main()
{
    int broj=-1234569;
    int x,max=0;
    do {
        x=abs(broj%10);
        if(x>max) max=x;
        broj/=10;
    }while(broj!=0);
    printf("max je %d",max);
    return 0;
}
