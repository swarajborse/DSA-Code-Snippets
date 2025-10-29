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
// Adding Edge
void addEdge(int u,int v,int directed) {
    adj[u][v]=1; // For Directed because it only follows 1 way connection
    if(!directed) adj[v][u]=1; // undirected
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
// Displaying Adjacency List
void displayList(int n){
    for(int i=0;i<n;i++){
        printf("%d: ",i);
        struct Node* temp = adjList[i];
        while(temp){
            printf("%d ",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
// BFS using adjacency Matrix
void BFS(int start){
    int visited[10] = {0};
    int queue[10], front = 0, rear = 0; // Queue stores the Node's index
    visited[start] = 1;
    queue[rear++] = start; 
    while(front < rear){
        int u = queue[front++];
        printf("%d ",u);
        for(int v=0; v<n;v++){
            if(adj[u][v] && !visited[v]){
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
    // TC: O(n^2) , SC: O(n)
   // Can be optimized with Adjacency List
}
// DFS using Adjacency Matrix
void DFS(int start){
    int visited[10] = {0};
    DFSHelper(start,visited);
    printf("\n");
}
void DFSHelper(int u,int visited[]){
    visited[u] = 1;
    printf("%d ",u);
    for(int v=0;v<n;v++){
        if(adj[u][v] && !visited[v]){
            DFSHelper(v,visited);
        }
    }
    // TC: O(n^2) , SC: O(n); 
   // Can be optimized with Adjacency List
}
// Detecting Cycle in Undirected Graph using DFS
int cycleUndirectedGraphHelperFunc(int u, int visited[], int parent){
    visited[u] = 1;
    for(int v=0;v<n;v++){
        id(adj[u][v]){
            if(!visited[v]){
                if(cycleUndirectedGraphHelperFunc(v,visited,u)) return 1;
            }else if(v!=parent) return 1;
        }
    }
    return 0;
}
int cycleUnidirected(){
    int visited[10] = {0};
    for(int i=0;i<n;i++){
        if(!visited[i] && cycleUndirectedGraphHelperFunc(i,visited,-1))
            return 1;
    }
    return 0;
}
// Detecting Cycle in Directed Graph --> Use Recursion Stack
int cycleDirectGraphHelperFunc(int u, int visited[], int recStack[]){
    visited[u] = 1;
    recStack[u] = 1;
    for(int v=0;v<n;v++){
        if(adj[u][v]){
            if(!visited[v] && cycleDirectGraphHelperFunc(v,visited,recStack))
                return 1;
            else if(recStack[v]) return 1;
        }
    }
    recStack[u] = 0;
    return 0;
}
int cycleDirected(){
    int visited[10] = {0}, recStack[10] = {0};
    for(int i=0;i<n;i++){
        if(!visited[i] && cycleDirectGraphHelperFunc(i,visited,recStack));
            return 1;
    }
    return 0;
}
int main(){
    printf("Author: Divyansh Garg , Starman248");
    return 0;
}
