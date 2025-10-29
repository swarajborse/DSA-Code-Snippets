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

struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* queue[100];
int front = 0, rear = 0;
void enqueue(struct Node* n){
    queue[rear++] = n;
}
struct Node* dequeue(){
    return queue[front++];
}
int isEmpty(){
    return front == rear;
}
struct Node* insertLevelOrder(struct Node* root, int val){
    struct Node* newNode = createNode(val);
    if(root == NULL) return newNode;
    front = rear = 0;
    enqueue(root);
    while(!isEmpty()){
        struct Node* temp = dequeue();
        if(temp->left == NULL){
            temp->left = newNode;
            return root;
        }else{
            enqueue(temp->left);
        }
        if(temp->right == NULL){
            temp->right = newNode;
            return root;
        }else{
            enqueue(root->right);
        }
    }
    return root;
}
int count = 0;
struct Node* insertAtSpecificPos(struct Node* root , int val, int level, int pos){
    if (!root) return NULL;
    if (level == 1) {
        count++;
        if (count == pos) {
            struct Node* newNode = createNode(val);
            if (!root->left) newNode->left = root;
            else newNode->right = root;
            return newNode;
        }
        return root;
    }
    root->left = insertAtPos(root->left, val, level - 1, pos);
    root->right = insertAtPos(root->right, val, level - 1, pos);
    return root;
}
void printLevel(Struct Node* root , int lvl){
    if(root == NULL) return;
    if(lvl == 1){
        printf("%d",root->data);
        return;
    }
    printLevel(root->left,lvl-1);
    printLevel(root->right,lvl-1);
}
// to print the nodes of the deepest lvl --> printLevel(root,height(root));
int height(Struct Node* root){
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l>r?l:r)+1;
}

// Traversals
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
// function to Mirror/Reverse the Tree
void mirror(struct Node* root){
    if(root == NULL) reutn;
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
// Finding Min/Max in a Tree
int findMin(struct Node* root){
    if(root == NULL) return INT_MAX;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    int min = root->data;
    if(leftMin < min) min = leftMin;
    if(rightMin < min) min = rightMin;
    return min;
}
int findMax(struct Node* root){
    if(root == NULL) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int Max = root->data;
    if(leftMax > Max) Max = leftMax;
    if(rightMax > Max) Max = rightMax;
    return Max;
}
// Level order Display
void levelOrderDisplay(struct Node* root){
    if(root == NULL) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(!isEmpty()){
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if(temp->left) queue[rear++] = temp->left;
        if(temp->right) queue[rear++] temp->right;
    }
}
// Copying tree into another
struct Node* copyTree(struct Node* root){
    
}
