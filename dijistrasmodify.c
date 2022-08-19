#include <stdio.h>
void dijkstras();
// int parent[10];
// int count;
int c[10][10], n, src;
void main()
{
  int i, j;
  printf("\nenter the no of vertices: ");
  scanf("%d", &n);
  // parent[n];
  printf("\nenter the cost matrix:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &c[i][j]);
    }
  }
  printf("\nenter the source node: ");
  scanf("%d", &src);
  dijkstras();
}
// int printPath(int parent[], int j, int c)
// {
//   // Base Case : If j is source
//   if (parent[j] == -1)
//     return 0;
//   printPath(parent, parent[j], c);
//   c++;
//   return c;
// }
void dijkstras()
{
  int vis[10], dist[10], u, j, min;
  int parent[n];
  int count = 0;
  for (j = 1; j <= n; j++)
  {
    dist[j] = c[src][j];
    parent[j] = src;
    vis[j] = 0;
  }
  // for (j = 1; j <= n; j++)
  // {
  //   vis[j] = 0;
  // }
  dist[src] = 0;
  vis[src] = 1;
  count = 1;
  while (count != n)
  {
    min = 9999;
    for (j = 1; j <= n; j++)
    {
      if (dist[j] < min && vis[j] != 1)
      {
        min = dist[j];
        u = j;
      }
    }
    vis[u] = 1;
    count++;
    for (j = 1; j <= n; j++)
    {
      if (min + c[u][j] < dist[j] && vis[j] != 1)
      {
        dist[j] = min + c[u][j];
        parent[j] = u;
      }
    }
  }
  printf("\nthe shortest distance is:\n");
  for (j = 1; j <= n; j++)
  {
    count = 0;
    if (j != src)
    {
      /* code */
      printf("\n%d----->%d=%d", src, j, dist[j]);
      printf("\nPath = %d ", j);
      int i = j;
      do
      {
        count++;
        i = parent[i];
        printf("<-%d", i);
      } while (i != src);
      printf("\n number of nodes along the path %d to %d = %d",src,j,count+1);
    }
  }
}
