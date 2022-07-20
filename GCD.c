#include <stdio.h>
#include <time.h>

void delay();
int gcd(int x,int y);

void main()
{
    int a,b,c;
    clock_t start,end;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    start= clock();
    delay();
    c=gcd(a,b);
    end= clock();
    printf("The gcd of two numbers is %d\n",c);
    printf("The time taken is %lf seconds",((double)(end-start)/CLOCKS_PER_SEC));
}
void delay(){
    long i;
    for(i=0;i<10000000;i++);
}
int gcd(int x,int y){
    int z;
    if(y==0)
        return x;
    z=x%y;
    x=y;
    y=z;
    delay();
    return gcd(x,y);
}
