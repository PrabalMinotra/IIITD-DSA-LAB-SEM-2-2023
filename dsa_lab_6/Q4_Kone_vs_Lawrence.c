// They may have graduated, but Kone and Lawrence remain kids at heart. They decide to square off in a game of paintball and need to build a team. They have a group consisting 𝑛
//  children and they want to form their own teams out of them. However, these children have 𝑚
//  friendships among them and to increase competitiveness, Lawrence and Kone decide to divide the children such that no team has children who are friends. Help them in this task.

// Input
// first line consists of two integers 1≤𝑛≤105𝑎𝑛𝑑1≤𝑚≤2∗105
//  the number of children and friendships respectively
// the next 𝑚
//  lines consist of two integers 1≤𝑥,𝑦≤𝑛
//  indicating that children 𝑥𝑎𝑛𝑑𝑦
//  are friends
// Output
// Print "YES" if such an arrangement is possible, else "NO"


// input
// 5 3
// 1 2
// 1 3
// 4 5

// output
// YES

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100005
#define MAX_EDGES 200005

typedef struct Node {
int vertex;
struct Node* next;
} Node;

Node* createNode(int v) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->vertex = v;
newNode->next = NULL;
return newNode;
}

void addEdge(Node* adj[], int src, int dest) {
Node* newNode = createNode(dest);
newNode->next = adj[src];
adj[src] = newNode;
}

int bfs(int start, int color[], Node* adj[]) {
int queue[MAX_NODES];
int front = -1;
int rear = -1;

queue[++rear] = start;
color[start] = 1;

while (front != rear) {
int current = queue[++front];
Node* temp = adj[current];

while (temp != NULL) {
int neighbor = temp->vertex;

if (color[neighbor] == color[current])
return 0;

if (color[neighbor] == 0) {
color[neighbor] = (color[current] == 1) ? 2 : 1;
queue[++rear] = neighbor;
}

temp = temp->next;
}
}

return 1;
}

int checkBipartite(int n, int m, int adjacency_list[][2]) {
Node* adj[n + 1];
int color[n + 1];

for (int i = 0; i <= n; i++) {
adj[i] = NULL;
color[i] = 0;
}

for (int i = 0; i < m; i++) {
int x = adjacency_list[i][0];
int y = adjacency_list[i][1];
addEdge(adj, x, y);
addEdge(adj, y, x);
}

for (int i = 1; i <= n; i++) {
if (color[i] == 0) {
if (!bfs(i, color, adj))
return 0;
}
}

return 1;
}

int main() {
int n, m;
scanf("%d %d", &n, &m);

int adjacency_list[MAX_EDGES][2];
for (int i = 0; i < m; i++) {
scanf("%d %d", &adjacency_list[i][0], &adjacency_list[i][1]);
}

if (checkBipartite(n, m, adjacency_list)) {
printf("YES\n");
}
else {
printf("NO\n");
}

return 0;
}
