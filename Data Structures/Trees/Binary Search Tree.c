#include <stdio.h>
#include <stdlib.h>
    int flag_prev = 0;


struct Binode
{
    int value;
    struct Binode * leftchild;
    struct Binode * Rightchild;
};

struct Binode * Root = NULL;
int flag = 0;
void insert()
{
    flag = 1;
    printf("\n////INSERTING////\n");
    struct Binode * temp = (struct Binode*)malloc(sizeof(struct Binode));
    int val;
    printf("Enter the value that you would like to insert\n");
    scanf("%d" , &val);
    temp->value = val;
    temp->leftchild = NULL;
    temp->Rightchild = NULL;
    
    struct Binode * current = Root;
    if(Root == NULL)
    {
        Root = temp;
    }
    else
    {
        struct Binode * current = Root;
        int a = 1;
        while(a==1)
        {
            if(temp->value <= current->value)
            {
                if(current->leftchild == NULL)
                {
                    current->leftchild = temp;
                    break;
                }
                else
                {
                    current = current->leftchild;
                }
            }
            else if(temp->value > current->value)
            {
                if(current->Rightchild == NULL)
                {
                    current->Rightchild = temp;
                    break;
                }
                else
                {
                    current = current->Rightchild;
                }
            }
        }
    }
}
void Inorder(struct Binode * Node)
{
    if(flag == 0)
    {
        printf("No elements inserted\n");
        main();
    }
    if(Node != NULL)
    {
        Inorder(Node->leftchild);
        printf("%d\n",Node->value);
        Inorder(Node->Rightchild);
    }
}
void preorder(struct Binode * Node)
{
     if(flag == 0)
    {
        printf("No elements inserted\n");
        main();
    }
    if(Node != NULL)
    {
        printf("%d\n" , Node->value);
        preorder(Node->leftchild);
        preorder(Node->Rightchild);
    }
}
void postorder(struct Binode * Node)
{
     if(flag == 0)
    {
        printf("No elements inserted\n");
        main();
    }
    if(Node != NULL)
    {
        postorder(Node->leftchild);
        postorder(Node->Rightchild);
        printf("%d\n" , Node->value);
    }
}

void search()
{
    if(flag == 0)
    {
        printf("Please insert elements first\n");
        main();
    }
    struct Binode * current = Root;
    int tosearch;
    int flag1 = 0;
    int count = 0;
    printf("Enter the number that you want to search\n");
    scanf("%d" , &tosearch);
    while(current!=NULL)
    {
        if(tosearch == current->value)
        {
            flag1 = 1;
            printf("Number found at count %d\n" , count);
            break;
        }
        else
        {
            if(tosearch<current->value)
            {
                current = current->leftchild;
                count = count+1;
            }
            else if(tosearch>current->value)
            {
                current = current->Rightchild;
                count = count +1 ;
            }
        }
    }
    if(flag1 == 0)
    {
        printf("Not found\n");
    }
}

rec_search(struct Binode * node, int key)
{
    if(node!=NULL)
    {
        if(key == node->value)
        {
            printf("Found\n");
        }
        if(key>node->value)
        {
            rec_search(node->Rightchild , key);
        }
        if(key<node->value)
        {
            rec_search(node->leftchild , key);
        }
    }
    else if(node == NULL)
    {
        printf("Not Found\n");
    }
}
struct Binode * rec_insert(struct Binode * root , struct Binode * temp)
{
    flag = 1;
    if(root == NULL)
    {
        return temp;
    }
    if(temp->value > root->value)
    {
        root->Rightchild= rec_insert(root->Rightchild , temp);
    }
    else if(temp->value < root->value)
    {
        root->leftchild = rec_insert(root->leftchild , temp);
    }
}


struct Binode* minValueNode(struct Binode* node)
{
    struct Binode* current = node;
 
    while (current->leftchild != NULL)
        current = current->leftchild;
 
    return current;
}
 
struct Binode* deleteNode(struct Binode* root, int key)
{
    if (root == NULL)
        {return root;}
 
    if (key < root->value)
       { root->leftchild = deleteNode(root->leftchild, key);}
 
    else if (key > root->value)
       { root->Rightchild = deleteNode(root->Rightchild, key);}
 
    else {
        // node with only one child or no child
        if (root->leftchild == NULL) {
            struct node* temp = root->Rightchild;
            free(root);
            return temp;
        }
        else if (root->Rightchild == NULL) {
            struct node* temp = root->leftchild;
            free(root);
            return temp;
        }
 
        struct Binode* temp = minValueNode(root->Rightchild);

        root->value = temp->value;
        root->Rightchild = deleteNode(root->Rightchild, temp->value);
    }
    return root;
}


int main()
{
    int choice;

    while(choice!=0)
    {
        printf("\nEnter \n1.To insert \n2.Inorder \n3.Preorder \n4.Postorder \n5.Search \n6.Rec_search \n7.Rec_insert \n8.Delete");
        printf("\n");
        scanf("%d" , &choice);
        if(choice == 1)
        {
            insert();
        }
        if(choice == 2)
        {
            Inorder(Root);
        }
        if(choice == 3)
        {
            preorder(Root);
        }
        if(choice == 4)
        {
            postorder(Root);
        }
        if(choice == 5)
        {
            search();
        }
        if (choice == 6)
        {
            int tosearch; 
            printf("Enter the number that you want to search\n");
            scanf("%d" , &tosearch);
            rec_search(Root , tosearch);
        }
        if(choice == 7)
        {
            struct Binode * temp = (struct Binode*)malloc(sizeof(struct Binode));
            int val;
            printf("Enter the value that you would like to insert\n");
            scanf("%d" , &val);
            temp->value = val;
            temp->leftchild = NULL;
            temp->Rightchild = NULL;
            Root = rec_insert(Root , temp);
        }
        if(choice == 8)
        {
            int todel;
        printf("Enter the number that you want to delete\n");
        scanf("%d" , &todel);
           
            deleteNode(Root , todel);
        }
    }
}