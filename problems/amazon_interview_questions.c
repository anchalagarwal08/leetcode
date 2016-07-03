#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

/*Dijkstra's shortest path. Its the path between 2 vertices rather than a MST which connects all the vertices*/
#define V 9

int min(int dist[], bool sptSet[])
{
  // Initialize min value
  int min = INT_MAX, min_index;     
  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}
void printSolution(int dist[], int n)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < V; i++){
    printf("%d \t\t %d\n", i, dist[i]);
  }
}
void dijkstra(int graph[][V], int src)
{
  bool spth[V];/*if vertices is included in shortest path or not from a given src*/
  int dis[V]; /*shortest distance from source to vertice*/
  int i=0,v=0;
  for(i=0;i<V;i++)
  {
    spth[i]=false;
    dis[i]=INT_MAX;
  }
  dis[src]=0;
  for(i=0;i<V-1;i++)/*V-1 vertices excluding src*/
  {
    int u = min(dis,spth);
    spth[u]=true;
    for(v=0;v<V;v++)
    {
      if(!spth[v] && graph[u][v] && dis[u]!=INT_MAX && dis[u]+graph[u][v]<dis[v])
      {
        printf("v=%d dis=%d\n", v, dis[v]);
        dis[v]=graph[u][v]+dis[u];
      }
    }
}
 printSolution(dis, V);
}

int main()
{
  /* Let us create the example graph discussed above */
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 0, 10, 0, 2, 0, 0},
    {0, 0, 0, 14, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
  };

  dijkstra(graph, 0);

  return 0;
}
