#include <stdio.h>
#include <time.h>

void delay() {
    int t,i;
    for(i =0;i<100000000;i++) {
    t = 210/3;
    }
}

int lsearch(int ch[],int key,int index,int i) {
    int arrpos=0;
    if(index>=i)
        return 0;
    if(key==ch[index]){
        arrpos = index + 1;
        return arrpos;
    }
    else
        return lsearch(ch,key,index+1,i);

    return arrpos;
}


void main() {
    clock_t start,end;
    int ch[100000];
    int i,key,index=0,result;
    for(i = 0;i<100000;i++) {
        ch[i] = i;
    }
    printf("Enter the key\n");
    scanf("%d",&key);
    start = clock();
    delay();
    result = lsearch(ch,key,index,i);
    end = clock();
    if(result==0)
        printf("Element not found\n");
    else
        printf("Element found\n");
    printf("%f",(float)(end-start)/CLOCKS_PER_SEC);
}
