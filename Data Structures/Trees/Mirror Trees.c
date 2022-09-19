#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};


struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int identicalTrees(struct node *a , struct node * b)
{
    if (a == NULL && b == NULL)
        return 1;

    

    if(a!=NULL && b!=NULL){
        return (
            a->data == b->data && identicalTrees(a->left, b->left) && identicalTrees(a->right, b->right));}


    return 0;
}
int areMirror(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a==NULL || b == NULL)
        return 0;

   
        return (
            a->data == b->data && areMirror(a->left, b->right) && areMirror(a->right, b->left));
    
}

int areEqual(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    

    if(a!=NULL && b!=NULL){
        return (
             areEqual(a->left, b->left) && areEqual(a->right, b->right));}


    return 0;
}

void makeMirror(struct node* a)
{
    if(a==NULL)
    {
        return;
    }
    else{
        struct node* temp;
        makeMirror(a->left);
        makeMirror(a->right);

        temp = a->left;
        a->left = a->right;
        a->right = temp;

    }
}


void inorder(struct node* node)
{
    if(node==NULL)
    {
        return;
    }

    inorder(node->left);
    printf("%c\n" , node->data);
    inorder(node->right);
}
int main()
{
    struct node *root1 = newNode('a');
    struct node *root2 = newNode('a');
    root1->left = newNode('b');
    root1->right = newNode('c');
    root1->left->left = newNode('d');
    root1->left->right = newNode('e');
    root1->right->left = newNode('f');
    root1->right->right = newNode('g');

    // root2->left = newNode(2);
    // root2->right = newNode(3);
    // root2->left->left = newNode(4);
    // root2->left->right = newNode(5);
    // root2->right->left = newNode(6);
    // root2->right->right = newNode(7);

    // if (areMirror(root1, root2))
    //     printf("Both tree are Mirrored.");
    // else
    //     printf("Trees are not Mirrored.");

    //  if (identicalTrees(root1, root2))
    //     printf("Both tree are identical");
    // else
    //     printf("Trees are not not identical.");

//  if (areEqual(root1, root2))
//         printf("Both tree are equal");
//     else
//         printf("Trees are not not equal.");

    inorder(root1);
    makeMirror(root1);
    printf("\n");
    inorder(root1);
    getchar();
    return 0;
}