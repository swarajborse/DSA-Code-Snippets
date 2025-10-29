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
struct Node{
  int key;
  struct Node* left;
  struct Node* right;
  int height;
};
int height(struct Node* n){
    if(n == NULL) return 0;
    return n->height;
}
int max(int a , int b){
    return (a>b)?a:b;
}
struct Node* newNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
struct Node* LL(struct Node* y){
    struct Node* x = y->left;
    struct Node* t2 = x->right;
    
    x->right = y;
    y->left = t2;
    
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
struct Node* RR(struct Node* x){
    struct Node* y = x->right;
    struct Node* t2 = y->left;
    
    y->left = x;
    x->right = t2;
    
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}
int balance(struct Node* n){
    if(n == NULL) return 0;
    return height(n->left) - height(n->right);
}
struct Node* insert(struct Node* node , int key){
    if(node == NULL) return newNode(key);
    if(key < node->key) node->left = insert(node->left,key);
    else if(key > node->key) node->right = insert(node->right,key);
    else return node;
    
    node->height = 1 + max(height(node->left),height(node->right));
    int balanceFac = balance(node);
    // ab check karte hai cases 
    // case : 1 -> LL
    if(balanceFac > 1 && key < node->left->key) 
        return LL(node);
    // case : 2 -> RR
    if(balanceFac < -1 && key > node->right->key)
        return RR(node);
    // case : 3 -> LR
    if(balanceFac > 1 && key > node->left->key){
        node->left = RR(node->left);
        return LL(node);
    }
    // case : 4 -> RL
    if(balanceFac < -1 && key < node->right->key){
        node->right = LL(node->right);
        return RR(node);
    }
    return node;
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf(" %d ",root->key);
        inorder(root->right);
    }
}
struct Node* minValNode(struct Node* node){
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}
struct Node* deleteNode(struct Node* root, int key){
    if(root == NULL) return root;
    if(key < root->key) root->left = deleteNode(root->left,key);
    else if(key > root->key) root->right = deleteNode(root->right,key);
    else{
        // reached the node to be deleted
        // case 1: no child or 1 child 
        if(root->left == NULL || root->right == NULL){
            struct Node* temp = root->left ? root->left: root->right;
            if(temp == NULL){ // No child
                temp = root;
                root = NULL;
            }else{ // 1 child
                *root = *temp;
            }
            free(temp);
        }else{
            // 2 children
            struct Node* temp = minValNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }
    if(root == NULL) return root;
    root->height = 1 + max(height(root->left),height(root->right));
    int balanceFac = balance(root);
    if(balanceFac > 1 && balance(root->left) >= 0) return LL(root);
    if(balanceFac < -1 && balance(root->right) <= 0) return RR(root);
    if(balanceFac > 1 && balance(root->left) < 0){
        root->left = RR(root->left);
        return LL(root);
    }
    if(balanceFac < -1 && balance(root->right) > 0){
        root->right = LL(root->left);
        return RR(root);
    }
    return root;
}
int main() {
  struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder before deletion: ");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 40);

    printf("Inorder after deleting 40: ");
    inorder(root);
    printf("\n");

    return 0;
}
