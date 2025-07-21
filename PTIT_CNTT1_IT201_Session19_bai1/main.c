#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *create_node(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf(" chua cap phat");
        return NULL;
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int main(void)
{

    return 0;
}