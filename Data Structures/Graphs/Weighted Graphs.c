#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int data;
    struct vertex * next;
    struct edge * edgelist;
    int visited;
};

struct edge
{
    struct edge * next;
    struct vertex * v;
    int weight;
};

struct vertex * queue [100];
int front = 0;
int rear = 0;

struct vertex * Graph = NULL;

void enqueue(struct vertex * vertex)
{
    queue[rear++] = vertex;
}

struct vertex* dequeu()
{
    return(queue[front++]);
}

void addVertex()
{
    printf("\n//// Adding a vertex ////\n");
    struct vertex * temp = (struct vertex*)malloc(sizeof(struct vertex));
    int data;
    printf("Enter the data that you want your vertex to hold\n");
    scanf("%d" , &data);
    temp->data = data;
    temp->edgelist = NULL;
    temp->next = NULL;
    temp->visited = 0;
    if(Graph == NULL)
    {
        Graph = temp;
    }
    else
    {
        struct vertex * current = Graph;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void displayVertex()
{
    struct vertex * current = Graph;
    while(current!=NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
}

void addEdge()
{
    int vertex1;
    int vertex2;
    printf("Adjecnt From?:\t");
    scanf("%d" , &vertex1);
    printf("Adjecnt to?:\t");
    scanf("%d" , &vertex2);
    struct vertex * current = Graph;
    while(current != NULL)
    {
        if(current->data == vertex1)
        {
            struct vertex * current2 = Graph;
            struct vertex * Avertex2;
            while(current2 != NULL)
            {
                if(current2 ->data == vertex2)
                {
                    Avertex2 = current2;
                    struct edge * temp = (struct edge*)malloc(sizeof(struct edge));
                    struct edge * temp2 = (struct edge*)malloc(sizeof(struct edge));
                    int weight;
                    printf("What would be the weight of this edge\n");
                    scanf("%d" , &weight);
                    temp->v = Avertex2;
                    temp->weight = weight;
                    temp->next = NULL;
                    temp2->v = current;
                    temp2->next = NULL;
                    temp2->weight = weight;
                    struct edge * current3;
                    if(current->edgelist == NULL)
                    {
                        current->edgelist = temp;
                    }
                    else
                    {
                        current3 = current->edgelist;
                        while(current3->next != NULL)
                        {
                            current3 = current3->next;
                        }
                        current3->next = temp;
                    }
                    if(current2->edgelist == NULL)
                    {
                        current2->edgelist = temp2;
                    }
                    else
                    {
                        current3 = current2->edgelist;
                        while(current3->next != NULL)
                        {
                            current3 = current3->next;
                        }
                        current3->next = temp2;
                    }
                    break;
                }
                current2 = current2->next;
            }
            break;
        }
        current = current->next;
    }
}

void findOutDegree()
{
    int data;
    int count = 0;
    printf("Enter the data you want to find the Outdegree of\n");
    scanf("%d" , &data);
    struct vertex * current = Graph;
    while(current!=NULL)
    {
        if(current->data == data)
        {
            struct edge * current2 = current->edgelist;
            while(current2!=NULL)
            {
                count = count+1;
                current2 = current2->next;
            }
            break;
        }
        current = current->next;
    }
    printf("The out degree of %d is %d" , data , count);
}

void findInDegree()
{
    int data;
    int count = 0;
    printf("Enter the data you want to find the Indegree of\n");
    scanf("%d" , &data);
    struct vertex* current = Graph;
    while(current!= NULL)
    {
        struct  edge* current2 = current->edgelist;
        while(current2 != NULL)
        {
            if(current2->v->data == data)
            {
                count = count +1;
                break;
            }
            current2 = current2->next;
        }
        current = current->next;
    }
    printf("The indegree of %d is %d" , data , count);

}

void displayEdges()
{
    struct vertex * current = Graph;
    while(current!=NULL)
    {
        printf("\n%d\n" , current->data);
        if(current->edgelist!=NULL)
        {
            struct edge * current2 = current->edgelist;
            printf("The neighbours are");
            while(current2!=NULL)
            {
                printf("\t%d , W:" , current2->v->data);
                printf("%d\t->" , current2->weight);
                current2 = current2->next;
            }
        }
        current = current->next;
    }
}

void PathBFS(struct vertex* source)
{
    struct vertex* currentt = Graph;
    while(currentt!=NULL)
    {
        currentt->visited = 0;
        currentt = currentt->next;
    }
    struct edge* current;
    int flag = 0;
    enqueue(source);
    source->visited = 1;
    // printf("%d\n" , source->data);
    while(front != rear)
    {
        current = dequeu()->edgelist;
        while(current!=NULL)
        {
            if(current->v->visited == 0)
            {
                current->v->visited = 1;
                enqueue(current->v);
                printf("%d\n" , current->v->data);
            }
            current = current->next;
        }
        
    }

}

void DFS(struct vertex* source , int vertexx2)
{
  
    struct edge* current = NULL;
    source->visited = 1;
    printf("%d\n" , source->data);
    if(source->edgelist != NULL)
    {
        current = source->edgelist;
    }
    while(current != NULL)
    {
        struct vertex* connected = current->v;
        if(connected->visited == 0)
        {
            if(connected->data == vertexx2)
            {
                printf("%d\n" , connected->data);
                printf("This was the path\n");
                break;
            }
            else{

            DFS(connected , vertexx2);
            }
        }
        current = current->next;
    }
    // main();
}


int main()
{
    int choice = 10;
    while(choice!= 0)
    {
        printf("\nEnter \n1.To add \n2.To Display \n3.Add Edge \n4.Display Edges \n5.OutDegree \n6.Indegree \n7.BFS \n8.Find Path DFS \n0.Exit\n");
        scanf("%d" , &choice);
        if(choice == 1)
        {
            addVertex();
        }
        if(choice == 2)
        {
            displayVertex();
        }
        if(choice == 3)
        {
            addEdge();
        }
        if(choice == 4)
        {
            displayEdges();
        }
        if(choice == 5)
        {
            findOutDegree();
        }
        if(choice == 6)
        {
            findInDegree();
        }
        if(choice == 7)
        {
            int source;
            int flag = 0;
            printf("Enter your source\n");
            scanf("%d" , &source);
            struct vertex* current = Graph;
            while(current!=NULL)
            {
                if(current->data == source)
                {
                    flag = 1;
                    PathBFS(current);
                    break;

                }
               
                current = current->next;
            }
             if(flag == 0)
                {
                    printf("Source not present\n");
                }
        }
        if(choice == 8)
        {
            struct vertex* currentt = Graph;
            while(currentt!=NULL)
            {
                currentt->visited = 0;
                currentt = currentt->next;
            }
                int source;
            int vertex2;
            int flag = 0;
            printf("Enter your source\n");
            scanf("%d" , &source);
            printf("Enter the second vertex\n");
            scanf("%d" , &vertex2);
            struct vertex* current = Graph;
            while(current!=NULL)
            {
                if(current->data == source)
                {
                    flag = 1;
                    DFS(current , vertex2);
                    break;

                }
               
                current = current->next;
            }
             if(flag == 0)
                {
                    printf("Source not present\n");
                }
        }
    }
    return 0;
}
