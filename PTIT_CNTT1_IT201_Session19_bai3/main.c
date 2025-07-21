#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf(" chua cap phat");
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void Postorder(node *root)
{
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);


}


int main(void)
{
    node *root=create_node(2);
    root->left = create_node(3);
    root->right = create_node(4);
    root->left->left = create_node(5);
    printf(" duyet theo LRN");
    Postorder(root);
    printf("\n");
    return 0;
}