/*
Author :

███████╗████████╗ █████╗ ██████╗  ███╗   ███╗ █████╗ ███╗   ██╗
██╔════╝╚══██╔══╝██╔══██╗██╔══██╗ ████╗ ████║██╔══██╗████╗  ██║
███████╗   ██║   ███████║██████╔╝ ██╔████╔██║███████║██╔██╗ ██║
╚════██║   ██║   ██╔══██║██║  ██║ ██║╚██╔╝██║██╔══██║██║╚██╗██║
███████║   ██║   ██║  ██║██║  ██║ ██║ ╚═╝ ██║██║  ██║██║ ╚████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝  STARMAN248
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Node {
    struct Node *left;
    int leftThread;
    char data;
    struct Node *right;
    int rightThread;
};

/* ---------- Create a new node ---------- */
struct Node* createNode(char data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->leftThread = TRUE;
    temp->rightThread = TRUE;
    return temp;
}

/* ---------- Find inorder successor ---------- */
struct Node* insucc(struct Node* node) {
    struct Node* temp = node->right;
    if (node->rightThread == FALSE)
        while (temp->leftThread == FALSE)
            temp = temp->left;
    return temp;
}

/* ---------- Inorder traversal ---------- */
void inorder(struct Node* head) {
    struct Node* temp = head;
    while (1) {
        temp = insucc(temp);
        if (temp == head)
            break;
        printf("%c ", temp->data);
    }
}

/* ---------- Insert Left ---------- */
struct Node* insertLeft(struct Node* s, struct Node* l) {
    l->left = s->left;
    l->leftThread = s->leftThread;
    l->right = s;
    l->rightThread = TRUE;

    s->left = l;
    s->leftThread = FALSE;

    if (l->leftThread == FALSE) {
        struct Node* temp = l->left;
        while (temp->rightThread == FALSE)
            temp = temp->right;
        temp->right = l;
    }

    return l;
}

/* ---------- Insert Right ---------- */
struct Node* insertRight(struct Node* s, struct Node* r) {
    r->right = s->right;
    r->rightThread = s->rightThread;
    r->left = s;
    r->leftThread = TRUE;

    s->right = r;
    s->rightThread = FALSE;

    if (r->rightThread == FALSE) {
        struct Node* temp = r->right;
        while (temp->leftThread == FALSE)
            temp = temp->left;
        temp->left = r;
    }

    return r;
}

/* ---------- Main ---------- */
int main() {
    // Create head node
    struct Node* head = createNode('H'); // head/sentinel
    head->leftThread = FALSE;
    head->rightThread = TRUE;
    head->right = head;

    // Root node
    struct Node* root = createNode('A');
    head->left = root;
    root->left = head;
    root->right = head;

    // Add some nodes
    struct Node* b = createNode('B');
    struct Node* c = createNode('C');
    struct Node* d = createNode('D');
    struct Node* e = createNode('E');
    struct Node* f = createNode('F');

    insertLeft(root, b);
    insertRight(root, c);
    insertLeft(b, d);
    insertRight(b, e);
    insertRight(c, f);

    printf("Inorder traversal using threads:\n");
    inorder(head);  // Output: D B E A C F
    printf("\n");

    return 0;
}
