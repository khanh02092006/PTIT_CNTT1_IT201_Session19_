#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


typedef struct queue_node {
    node* tree_node;
    struct queue_node* next;
} queue_node;


typedef struct queue {
    queue_node* front;
    queue_node* rear;
} queue;

queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int is_empty(queue* q) {
    return q->front == NULL;
}

void enqueue(queue* q, node* n) {
    queue_node* temp = (queue_node*)malloc(sizeof(queue_node));
    temp->tree_node = n;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

node* dequeue(queue* q) {
    if (is_empty(q)) return NULL;

    queue_node* temp = q->front;
    node* result = temp->tree_node;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return result;
}


void level_order(node* root) {
    if (root == NULL) return;

    queue* q = create_queue();
    enqueue(q, root);

    while (!is_empty(q)) {
        node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    printf("\n");
}


int bfs_search(node* root, int target) {
    if (root == NULL) return 0;

    queue* q = create_queue();
    enqueue(q, root);

    while (!is_empty(q)) {
        node* current = dequeue(q);
        if (current->data == target) return 1;

        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    return 0;
}


int main() {
    node* root = create_node(2);
    root->left = create_node(3);
    root->right = create_node(4);
    root->left->left = create_node(5);

    printf("Cây duyệt theo BFS: ");
    level_order(root);

    int x;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);

    if (bfs_search(root, x))
        printf("Tìm thấy %d trong cây.\n", x);
    else
        printf(" kh thấy %d trong cây.\n", x);

    return 0;
}
