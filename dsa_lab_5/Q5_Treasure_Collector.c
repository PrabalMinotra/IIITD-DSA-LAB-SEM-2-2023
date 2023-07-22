// You are given an 𝑛×𝑛
//  matrix, representing a game board. The matrix contains four types of entries:

// An empty cell denoted by '.', where players can move freely.
// A player's position denoted by 'p'. There are two players, player 1 and player 2, initially located at different positions.
// A treasure position denoted by 't'. The goal is to find this treasure.
// A wall denoted by '#', which is an obstacle that players cannot pass through.
// Both players can move in four directions: up, down, left, and right. Each movement to an adjacent cell (up, down, left, or right) takes exactly one unit of time. Players can move through empty cells but cannot move through walls.

// Your task is to calculate the minimum time required for both players to find the treasure, assuming they collaborate optimally.

// Input
// The first line of input consists of a single integer 𝑛
//  (1 ≤ 𝑛 ≤ 1000)
// , representing the size of the game board.

// Subsequently,There are 𝑛
//  lines which represent rows of matrix.

// The strings contain characters '.', 'p', 't', and '#', separated by spaces.

// Output
// print the minimum time required for both players to find the treasure. If the treasure is unreachable, return −1
// .


// input
// 4
// t . . t
// . . . #
// . . # .
// p p # .

// output
// 5

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1005
#define INF INT_MAX

char trash_map[MAX_SIZE][MAX_SIZE];
int t_to_t[MAX_SIZE][MAX_SIZE];
int p1_to_t[MAX_SIZE][MAX_SIZE];
int p2_to_t[MAX_SIZE][MAX_SIZE];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int min(int a, int b) {
return (a < b) ? a : b;
}

int max(int a, int b) {
return (a > b) ? a : b;
}

void bfs(int n, int sig, int xx, int yy) {
int queue[MAX_SIZE * MAX_SIZE][3];
int tail = 0;
int head = 0;

queue[tail][0] = xx;
queue[tail][1] = yy;
queue[tail][2] = 0;
tail++;

int (*dist)[MAX_SIZE];
if (sig == 0)
dist = p1_to_t;
else if (sig == 1)
dist = p2_to_t;
else if (sig == 2)
dist = t_to_t;

dist[xx][yy] = 0;

while (head != tail) {
int x = queue[head][0];
int y = queue[head][1];
int t = queue[head][2];
head++;

for (int j = 0; j < 4; j++) {
int nx = x + dx[j];
int ny = y + dy[j];
int nt = t + 1;

if (nx < 0 || nx >= n || ny < 0 || ny >= n)
continue;
if (trash_map[nx][ny] == '#')
continue;
if (dist[nx][ny] != INF)
continue;

dist[nx][ny] = nt;
queue[tail][0] = nx;
queue[tail][1] = ny;
queue[tail][2] = nt;
tail++;
}
}
}

int main() {
int n;
scanf("%d", &n);

int xp1 = 0, yp1 = 0;
int xp2 = 0, yp2 = 0;
int xt1 = 0, yt1 = 0;
int xt2 = 0, yt2 = 0;
int vis_person = 0;
int vis_treasue = 0;

for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
t_to_t[i][j] = INF;
p1_to_t[i][j] = INF;
p2_to_t[i][j] = INF;

if ((j != 0) && (j != n - 1))
scanf(" %c ", &trash_map[i][j]);
if (j == 0)
scanf("\n%c", &trash_map[i][j]);
if ((j == n - 1) && (i != n - 1))
scanf("%c\n", &trash_map[i][j]);
if ((i == n - 1) && (j == n - 1))
scanf("%c", &trash_map[i][j]);

if ((trash_map[i][j] == 'p') && (vis_person == 0)) {
xp1 = i;
yp1 = j;
vis_person = 1;
}
if ((trash_map[i][j] == 'p') && (vis_person == 1)) {
xp2 = i;
yp2 = j;
}
if ((trash_map[i][j] == 't') && (vis_treasue == 0)) {
xt1 = i;
yt1 = j;
vis_treasue = 1;
}
if ((trash_map[i][j] == 't') && (vis_treasue == 1)) {
xt2 = i;
yt2 = j;
}
}
}

bfs(n, 0, xp1, yp1);
bfs(n, 1, xp2, yp2);
bfs(n, 2, xt1, yt1);

int single_p = INF;
int both_p = INF;

if (t_to_t[xt2][yt2] != INF) {
if (p1_to_t[xt1][yt1] != INF) {
single_p = min(single_p, p1_to_t[xt1][yt1] + t_to_t[xt2][yt2]);
}
if (p1_to_t[xt2][yt2] != INF) {
single_p = min(single_p, p1_to_t[xt2][yt2] + t_to_t[xt2][yt2]);
}
if (p2_to_t[xt1][yt1] != INF) {
single_p = min(single_p, p2_to_t[xt1][yt1] + t_to_t[xt2][yt2]);
}
if (p2_to_t[xt2][yt2] != INF) {
single_p = min(single_p, p2_to_t[xt2][yt2] + t_to_t[xt2][yt2]);
}
}

if (((p1_to_t[xt1][yt1] != INF) && (p1_to_t[xt2][yt2] != INF)) ||
((p2_to_t[xt1][yt1] != INF) && (p2_to_t[xt2][yt2] != INF))) {
if ((p1_to_t[xt1][yt1] != INF) && (p2_to_t[xt2][yt2] != INF)) {
both_p = min(both_p, max(p2_to_t[xt2][yt2], p1_to_t[xt1][yt1]));
}
if ((p2_to_t[xt1][yt1] != INF) && (p1_to_t[xt2][yt2] != INF)) {
both_p = min(both_p, max(p2_to_t[xt1][yt1], p1_to_t[xt2][yt2]));
}
}

if (min(single_p, both_p) == INF)
printf("-1");
else
printf("%d", min(single_p, both_p));

return 0;
}
