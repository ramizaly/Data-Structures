// Adjacency Matrix representation in C

#include <stdio.h>
#define V 5
#define INT_MAX 999


// Initialize the matrix to zero
void init(int arr[V][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}


int minDistance(int dist[] , int sptset[])
{
  int min = INT_MAX;
  int minIndex;
  for (int i = 0; i < V; i++)
  {
     if(sptset[i] == 0 && dist[i] <= min)
     {
       min = dist[i] ;
       minIndex = i;
     }
  }
  return minIndex;
}

void printSolution(int dist[])
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void Dijsaktra(int graph[V][V] , int src )
{
    int dis[V]; //Will hold the shortest distances from source to all the vertices
    int sptset[V]; //1 if vertex  if shortest distance from source to i is finalized

    for (int i = 0; i < V ; i++)
    {

       dis[i] = INT_MAX;
       sptset[i] = 0;
    }

    dis[src]= 0;

    for (int count = 0; count < V-1 ; count++)
    {

      int u = minDistance(dis , sptset);

      sptset[u] = 1;

      for (int j = 0; j < V; j++)
      {


        
        if(sptset[j] == 0 && graph[u][j] != INT_MAX && dis[u] != INT_MAX && dis[u] + graph[u][j] < dis[j])
        {

          dis[j] = dis[u] + graph[u][j];
        }
      }
      
    }
    
    printSolution(dis);
    
}


void prims(int graph[V][V] , int src)
{
  int no_of_edges;
  int selected[V];

  memset(selected , 0 , sizeof(selected));
  no_of_edges = 0;
  selected[src] = 1;

  int x;
  int y;

  while(no_of_edges < V-1)
  {
    int min = INT_MAX;
    x=0;
    y=0;

    for (int i = 0; i < V; i++)
    {
      if(selected[i] == 1)
      {
        for (int j = 0; j < V; j++)
        {
          if(selected[j] != 1 && graph[i][j] != 0)
          if(min>graph[i][j])
          {
            min = graph[i][j];
            x = i;
            y = j;
          }
        }
        
      }
    }
    printf("%d - %d : %d\n", x, y, graph[x][y]);
    selected[y] = 1;
    no_of_edges++;
    
  }

}

// Add edges
void addEdge(int arr[][V], int i, int j) {
  int weight;
  printf("Enter the weight\n");
  scanf("%d" , &weight);
  arr[i][j] = weight;
  arr[j][i] = weight;
}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    printf("%d: ", i);
    for (j = 0; j < V; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }


}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
int choice=-1;
while(choice!=0)
{
    printf("The vertices are 0,1,2,3,4\n");
    printf("Select\n1.To add Edge \n2.Print \n3.Shortest Path \n4.Min spanning tree\n" );
    scanf("%d" , &choice);
    if(choice == 1)
    {
        int vertex1;
        int vertex2;
        printf("Enter the first vertex\n");
        scanf("%d" , &vertex1);
        printf("Enter the second vertex\n");
        scanf("%d" , &vertex2);
        addEdge(adjMatrix , vertex1 , vertex2);
    }
    if(choice == 2)
    {
        printAdjMatrix(adjMatrix);
    }

    if(choice == 3)
    {
      int src;
      printf("Enter the source\n");
      scanf("%d" , &src);
      Dijsaktra(adjMatrix , src);

    }
    if(choice == 4)
    {
       int src;
      printf("Enter the source\n");
      scanf("%d" , &src);
      prims(adjMatrix , src);
    }
}

}
