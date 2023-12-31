// The only difference between easy and hard versions is the constraint on matrix dimensions.

// It's April and Lawrence's birthday is just round the corner. Lawrence plans to throw a grandiose birthday party where he and his friends will vibe to classical pieces by Chopin, Mozart and Beethoven. Now, Lawrence will be hosting this party in the main hall of his house and wants your help to figure out the maximum number of friends he can invite. Lawrence wants all his friends to sit around one big rectangular table, therefore, he wants to know what is the largest rectangular table he can place such that maximum friends can sit around it.

// The hall is represented as a 2D matrix of size 𝑚
//  x 𝑛
//  and the entries of the matrix are either '.' or 'X' indicating the particular cell is available or preoccupied by some furniture, respectively. You have to find the largest possible rectangle consisting of only free cells such that maximum number of friends can be accommodated.

// Note: The number of friends that can sit around a table equals the perimeter of the table.

// Constraints

// 1≤𝑚,𝑛≤100
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







#include <stdio.h>
//slowly expanding the area of checking for dots and removing Xs
//couting sides and subtracting 1
//print guests
void arrayprinter(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    if (array[i] != 0){
    printf("%d ", array[i]);
  }
  }
  printf("\n");
}

int main(){
int a,b;
scanf("%d %d",&a,&b);
int hall[a][b];

for(int i=0;i<a;i++)
{
char chairs[b+1];
scanf("%s",chairs);
for(int j=0;j<b;j++)
{
if(chairs[j]=='.') hall[i][j]=0;
else hall[i][j]=1;
}
}
//arrayprinter(chairs,b+1);
int freess=0;
for(int i=0;i<a;i++)
{
for(int j=0;j<b;j++)
{
if(hall[i][j]==0)
{
int c=0;
int perime=b-j;
while(hall[i+c][j]==0 && i+c<a)
{
for(int d=0;d<=perime;d++)
{
if(hall[i+c][j+d]!=0)
{
perime=d;
break;
}
}
c++;
int friends=2*(c + perime)-1;
if(freess < friends){
freess=friends;
}

}

}

}
}
printf("%d\n",freess);
return 0;
}