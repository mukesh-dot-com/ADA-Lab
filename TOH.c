#include <stdio.h>
#include <time.h>
#include <math.h>

void delay(){
    long i,j;
    for(i=0;i<1000;i++){
        for(j=0;j<100000;j++);
    }
}

void hanoi(int n, char a,char b,char c) {
    if(n==1){
        printf("move from %c to %c\n",a,c);
    }
    else {
        hanoi(n-1,a,c,b);
        printf("move from %c to %c\n",a,c);
        delay();
        hanoi(n-1,b,a,c);
    }
}
void main() {
    clock_t start,end;
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    moves = pow(2,n)-1;
    printf("Number of moves is %d\n",moves);
    start= clock();
    hanoi(n,'a','b','c');
    end=clock();
    printf("%lf seconds",(double)(end-start)/CLOCKS_PER_SEC);
}
