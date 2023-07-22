// Rohu is a student who needs to complete a total of n courses in order to graduate. Each course is identified by a unique integer from 1
//  to 𝑛
// . However, some courses have prerequisites, which must be completed before taking the course. Rohu wants to know whether it is possible for him to complete all the courses and graduate.

// You are given the total number of courses 𝑛
//  and a list of prerequisites. Each prerequisite is represented by a pair of integers (𝑎,𝑏)
// , indicating that course a must be completed before taking course b. Your task is to determine whether Rohu can complete all the courses, considering the given prerequisites.

// Constraints

// 1≤𝑛≤105
// 1≤𝑚≤2∗105
// 1≤𝑎,𝑏≤𝑛
// Input
// The first line contains two integers n and m separated by a space, representing the total number of courses and the number of prerequisites, respectively.
// The following m lines each contain two integers a and b separated by a space, denoting a prerequisite relationship that course a must be completed before taking course b.
// Output
// output a single line containing "Yes" if it is possible for Rohu to complete all the courses, or "No" otherwise.


// input
// 5 4
// 1 2
// 2 3
// 3 4
// 4 5

// output
// Yes

#include <stdio.h>
#include <stdlib.h>
#define MAXC 100005
#define MAXP 200005
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
int dfs(int v, int color[], Node* adj[]) {
color[v] = 1;
Node* temp = adj[v];
while (temp != NULL) {
int neighbor = temp->vertex;
if (color[neighbor] == 0) {
if (!dfs(neighbor, color, adj))
    return 0;
} else if (color[neighbor] == 1) {
return 0;
}
temp = temp->next;
}
color[v] = 2;
return 1;
}
int canCompleteCourses(int n, int m, int requs[][2]) {
Node* adj[MAXC];
int color[MAXC] = {0};
for (int i = 1; i <= n; i++)
adj[i] = NULL;
for (int i = 0; i < m; i++) {
int a = requs[i][0];
int b = requs[i][1];
addEdge(adj, a, b);
}
for (int i = 1; i <= n; i++) {
if (color[i] == 0) {
if (!dfs(i, color, adj))
    return 0;
}
}
return 1;
}
int main() {
int n, m;
scanf("%d %d", &n, &m);
int requis[MAXP][2];
for (int i = 0; i < m; i++) {
scanf("%d %d", &requis[i][0], &requis[i][1]);
}
if (canCompleteCourses(n, m, requis)) {
printf("Yes\n");
} else {
printf("No\n");
}
return 0;
}
