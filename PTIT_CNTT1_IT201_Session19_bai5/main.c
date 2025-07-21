#include <stdio.h>
#include <stdlib.h>
typedef  struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL) return NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int dfs_search(node *root, int key)
{
    if(root == NULL) return 0;
    if(root->data == key)
    {
        return 1;

    }
    return dfs_search(root->left, key)|| dfs_search(root->right, key);
}

int main(void)
{
    node *root= createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int value;
    printf(" nhap gia tri can tim");
    scanf("%d",&value);
    if(dfs_search(root, value))
    {
        printf(" %d co ton tai",value);

    } else
    {
        printf(" %d khong co trong cay",value);

    }


    return 0;
}