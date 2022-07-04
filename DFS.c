#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int adj[10][10],n,visited[10];
void dfs(int i){
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<n;j++){
        if(!visited[j] && adj[i][j]==1)
                dfs(j);
    }
}

void main(){
    clock_t start,end;
    int i,j;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    for(i=0;i<n;i++)
            visited[i]=0;
    start = clock();
    dfs(0);
    end = clock();
    printf("\n%lf",((double) (end - start)) / CLOCKS_PER_SEC);
}
