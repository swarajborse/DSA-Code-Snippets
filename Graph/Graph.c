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
int adj[10][10]; // assuming max 10 nodes.
int n;
// Initializing the Adjacency Matrix
void intiGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = 0;
        }
    }
}
// Displaying the Adjaceny Matrix
void displayGraph(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}
// Directed = 1 ( for Directed Graph) and viceversa 
struct Node{
    int vertex; // means the position number
    struct Node* next;
}
struct Node* adjlist[10]; // Adjancency List
// Adding Edges in the List
void addEdgeList(int u,int v,int directed){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode; // because we always insert at the head
    // For Undirected Graph -> 2 way connection important here
    if(!directed){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adjlist[v];
        adjList[v] = newNode;
    }
}

int main(){
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
