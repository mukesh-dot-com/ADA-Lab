#include <stdio.h>
#include <time.h>

void delay() {
    int t,i;
    for(i =0;i<100000000;i++) {
    t = 210/3;
    }
}

int binary(int ch[],int key,int fr,int la,int i) {
    int mid = (fr+la)/2;
        if(key==ch[mid])
            return 1;
        else if(key < ch[mid])
            return binary(ch,key,fr,mid-1,i);
        else
            return binary(ch,key,mid+1,la,i);
    }

void main() {
    clock_t start,end;
    int ch[100000];
    int i,key,index=0,result;
    int max = 100000,min=0;
    for(i = 0;i<100000;i++) {
        ch[i] = i;
    }
    printf("Enter the key\n");
    scanf("%d",&key);
    start = clock();
    delay();
    result = lsearch(ch,key,min,max,i);
    end = clock();
    if(result==0)
        printf("Element not found\n");
    else
        printf("Element found\n");
    printf("%f",(float)(end-start)/CLOCKS_PER_SEC);
}
