// You are given a rectangular land of dimension 𝑚∗𝑛
//  represented by a binary matrix, where 0
//  represents normal plants and 1
//  represents supernatural plants. A fire has started spreading from the boundaries of the land where normal plants are present. The fire cannot spread through supernatural plants, but it can spread horizontally and vertically to neighboring normal plants in one unit of time.

// You are given a series of queries, each consisting of two numbers 𝑥
//  and 𝑦
// . For each query, you need to determine the maximum time to pluck the fruits from the plant located at position (𝑥,𝑦)
//  before the fire reaches it. If the plant does not catch fire, print "infinity".

// Constraints

// 1 ≤ 𝑚,𝑛 ≤ 1000
// 0 ≤ 𝑥 < 𝑚
// 0 ≤ 𝑦 < 𝑛
// 0 ≤ 𝑞 < 2∗105

// Input
// The first line of input consists of two integers 𝑚
//  and 𝑛
// , separated by a space, representing the dimensions of the land (number of rows and columns).

// Subsequently, there are 𝑚
//  lines with 𝑛
//  entries in each line, representing the binary 2
// D matrix.

// The next line contains a single integer 𝑞
// , representing the number of queries.

// The following 𝑞
//  lines contain two space-separated integers 𝑥
//  and 𝑦
// , representing the position of a plant for each query.

// Output
// For each query, print the maximum time in next line to pluck the fruits from the plant before the fire reaches it. If the plant does not catch fire, print "infinity".


// input
// 6 5
// 0 0 0 0 0
// 0 0 1 0 0
// 0 1 0 1 0
// 1 0 0 1 0
// 0 1 1 0 0
// 0 0 0 0 0
// 6
// 0 0
// 1 1
// 2 2
// 3 3
// 4 4
// 5 0

// output
// 1
// 2
// infinity
// infinity
// 1
// 1

#include <stdio.h>
#include <stdlib.h>

typedef struct {
int x;
int y;
int t;
} Node;

typedef struct {
int rows;
int cols;
int** field;
} Graph;

void enqueue(Node* queue, int* end, int xx, int yy, int tt) {
queue[*end].x = xx;
queue[*end].y = yy;
queue[*end].t = tt;
(*end)++;
}

void adjacency(Graph* graph, Node* queue, int* end, int* start) {
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
for (int j = 0; j < 4; j++) {
int xx = queue[*start].x + dx[j];
int yy = queue[*start].y + dy[j];
int tt = queue[*start].t + 1;
if (xx < 0 || xx >= graph->rows || yy < 0 || yy >= graph->cols)
continue;
if (graph->field[xx][yy] != 0)
continue;
if (xx == 0 || xx == graph->rows - 1)
continue;
else if (yy == 0 || yy == graph->cols - 1)
continue;
graph->field[xx][yy] = tt;
enqueue(queue, end, xx, yy, tt);
}
(*start)++;
}

Graph createGraph(int m, int n) {
Graph graph;
graph.rows = m;
graph.cols = n;
graph.field = malloc(m * sizeof(int*));
for (int i = 0; i < m; i++) {
graph.field[i] = malloc(n * sizeof(int));
}
return graph;
}

void destroyGraph(Graph* graph) {
for (int i = 0; i < graph->rows; i++) {
free(graph->field[i]);
}
free(graph->field);
}

int main() {
int m = 0;
int n = 0;

scanf("%d %d", &m, &n);

Graph graph = createGraph(m, n);

Node* queue = malloc(m * n * sizeof(Node));
int start = 0;
int end = 0;

for (int j = 0; j < n * m; j++) {
queue[j].x = 0;
queue[j].y = 0;
queue[j].t = 0;
}
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
graph.field[i][j] = 0;
int scam = 0;
scanf("%d", &scam);
if (scam == 1)
graph.field[i][j] = -1;
else {
if (i == 0 || i == m - 1) {
enqueue(queue, &end, i, j, 1);
graph.field[i][j] = 1;
} else if (j == 0 || j == n - 1) {
enqueue(queue, &end, i, j, 1);
graph.field[i][j] = 1;
}
}
}
}

while (start != end) {
adjacency(&graph, queue, &end, &start);
}

int q = 0;
scanf("%d", &q);
for (int i = 0; i < q; i++) {
int xx = 0;
int yy = 0;

scanf("%d %d", &xx, &yy);

int time = graph.field[xx][yy];

if (time == 0 || time == -1)
printf("infinity\n");
else
printf("%d\n", time);
}

destroyGraph(&graph);
free(queue);

return 0;
}
