// The only difference between easy and hard versions is the constraint on matrix dimensions.

// It's April and Lawrence's birthday is just round the corner. Lawrence plans to throw a grandiose birthday party where he and his friends will vibe to classical pieces by Chopin, Mozart and Beethoven. Now, Lawrence will be hosting this party in the main hall of his house and wants your help to figure out the maximum number of friends he can invite. Lawrence wants all his friends to sit around one big rectangular table, therefore, he wants to know what is the largest rectangular table he can place such that maximum friends can sit around it.

// The hall is represented as a 2D matrix of size 𝑚
//  x 𝑛
//  and the entries of the matrix are either '.' or 'X' indicating the particular cell is available or preoccupied by some furniture, respectively. You have to find the largest possible rectangle consisting of only free cells such that maximum number of friends can be accommodated.

// Note: The number of friends that can sit around a table equals the perimeter of the table.

// Constraints

// 1≤𝑚,𝑛≤2500
// Input
// The first line of input consists of two integers 𝑚
//  and 𝑛
//  respectively. Subsequently, there are 𝑚
//  lines with 𝑛
//  entries in each line which are either '.' or 'X' representing Lawrence's main hall.

// Output
// Print the maximum number of friends Lawrence can invite (note that you have to subtract 1 from the final answer to exclude Lawrence)

// input
// 4 4
// X.XX
// X..X
// ..X.
// ..XX
// output
// 9



#include<stdio.h>
// void matrixPrinter(int array[], int size) {
//   for (int i = 0; i < size; ++i) {
// for (int i = 0; i < size; ++i){
//     printf("%d ", array[i][j]);
//}
//   }
//   printf("\n");
// }

int birthday(int a, int b, int matrix[][b]){
int h[b];
int l[b];
int r[b];
int invites = 0;
for (int i = 0; i < b; i++)
{
h[i] = 0;
l[i] = 0;
r[i] = b-1;
}
for (int i = 0; i < a; i++)
{
int left = 0, right = b-1;
{
for (int j = 0; j < b; j++)
{
if (matrix[i][j] == 0)
{
h[j]++;
if (left > l[j]) l[j] = left;
}
else
{
h[j] = 0;
l[j] = 0;
left = j + 1;
}
if (matrix[i][b-1-j] == 0)
{
if (right < r[b-1-j])
{
    r[b-1-j] = right;
}
}
else
{
r[b-1-j] = b-1;
right = b-j-2;
}
}
for (int j = 0; j < b; j++)
{
if (matrix[i][j] == 0)
{
int friends = (h[j]+(r[j]-l[j]+1))*2-1;
if (friends > invites) invites = friends;
}
}
}
}
return invites;
}

int main(){
int n, m;
scanf("%d %d",&n,&m);
int hall[n][m];
for (int i = 0; i < n; i++)
{
char frens[m+1];

scanf("%s",frens);

for (int j = 0; j < m; j++)
{
if(frens[j] == '.') {

hall[i][j] = 0;}

else{

hall[i][j] = 1;}
}

}

printf("%d\n",birthday(n, m, hall));
//matrixPrinter
return 0;
}