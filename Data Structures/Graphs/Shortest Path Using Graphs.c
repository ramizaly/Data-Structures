#include <stdio.h>
#define R 5
#define C 6
int arr[R][C];

int sr = 0;
int sc = 0; // 'S' symbol row and column values
// int rq[], cq[];     // Queues

int moves_count = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;

int reached_end = 0; // false

int visited[R][C];

dr[] = {-1, 1, 0, 0};
dc[] = {0, 0, 1, -1};

// -------------*Queue 1*---------------------------

#define MAX 50

int rq[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int isFull()
{
   if (itemCount == MAX)
      return 1;
   else
      return 0;
}
void enQueue1(int data)
{

   if (!isFull())
   {

      if (rear == MAX - 1)
      {
         rear = -1;
      }

      rq[++rear] = data;
      itemCount++;
   }
}
int deQueue1()
{
   int data = rq[front++];

   if (front == MAX)
   {
      front = 0;
   }

   itemCount--;
   return data;
}
int display1()
{
   for (int i = 0; i < MAX; i++)
   {
      printf("%d\t", rq[i]);
   }
}

// -----------------*Queue2*--------------------

// #define MAX 50

int cq[MAX];
int front2 = 0;
int rear2 = -1;
int itemCount2 = 0;

int isFull2()
{
   if (itemCount2 == MAX)
      return 1;
   else
      return 0;
}
void enQueue2(int data)
{

   if (!isFull2())
   {

      if (rear2 == MAX - 1)
      {
         rear2 = -1;
      }

      cq[++rear2] = data;
      itemCount2++;
   }
}
int deQueue2()
{
   int data = cq[front2++];

   if (front2 == MAX)
   {
      front2 = 0;
   }

   itemCount2--;
   return data;
}
int display2()
{
   for (int i = 0; i < MAX; i++)
   {
      printf("%d\t", cq[i]);
   }
}

// ------------------*Main Solution*----------------------

void explore_neighbours(int r, int c)
{
   for (int i = 0; i < 4; i++)
   {
      int rr = r + dr[i];
      int cc = c + dc[i];

      // Skipping bound locations
      if (rr < 0 || cc < 0)
      {
         continue;
      }
      if (rr >= R || cc >= C)
      {
         continue;
      }

      // Skipping bound locations
      if (visited[rr][cc] == 1)
      {
         continue;
      }
      if (arr[rr][cc] == 1)
      {
         continue;
      }

      enQueue1(rr);
      enQueue2(cc);
      visited[rr][cc] = 1;
      nodes_in_next_layer++;
   }
}

int solve(int arr[R][C])
{
   enQueue1(sr);
   enQueue2(sc);

   visited[sr][sc] = 1;

   while (sizeof(rq) > 0)
   {
      int r = deQueue1();
      int c = deQueue2();

      if (arr[r][c] == 6)
      {
         reached_end = 1;
         break;
      }
      explore_neighbours(r, c);

      nodes_left_in_layer--;
      if (nodes_left_in_layer == 0)
      {
         nodes_left_in_layer = nodes_in_next_layer;
         nodes_in_next_layer = 0;
         moves_count++;
      }
   }
   if (reached_end)
   {
      return moves_count;
   }
   return -1;
}

// ---------------------*Adjacency Matrix*---------------------------
// Initialize the matrix to zero
void init(int arr[R][C])
{
   int i, j;
   for (i = 0; i < R; i++)
      for (j = 0; j < C; j++)
         arr[i][j] = 0;
}

// Add edges
// void addEdge(int arr[][V], int i, int j)
// {
//     int weight;
//     // printf("Enter the weight\n");
//     // scanf("%d", &weight);
//     arr[i][j] = 9;
//     // arr[j][i] = weight;
// }

// Print the matrix
void printAdjMatrix(int arr[][C])
{
   int i, j;

   for (i = 0; i < R; i++)
   {
      printf("%d: ", i);
      for (j = 0; j < C; j++)
      {
         printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
}

// --------------------*Main*------------------------
int main()
{

   int adjMatrix[R][C];

   //  init(visited[R][C]);

   init(adjMatrix);
   adjMatrix[sr][sc] = 9;
   adjMatrix[0][5] = 1;
   adjMatrix[1][4] = 1;
   adjMatrix[3][4] = 1;
   adjMatrix[4][2] = 1;
   adjMatrix[1][2] = 6;
   adjMatrix[2][0] = 1;
   adjMatrix[3][3] = 1;
   printAdjMatrix(adjMatrix);

   printf("\n-------------------\n");

   //  printAdjMatrix(visited);

   int a = solve(adjMatrix);
   // printf("\n-------------------\n");
   printf("\n%d", a);
   printf("\n-------------------\n");
   printAdjMatrix(visited);
}