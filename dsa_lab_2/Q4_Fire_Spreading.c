// Dee and Anny are working on a case where a building, consisting of m*n houses, caught fire in an accident. They have already determined which houses the fire started to spread from. As forensic investigators, they want to determine how long it took for the entire building to burn down, given that the fire can spread from one house to every house touching that house.

// Constraints

// 1≤𝑚,𝑛≤104
// 1≤𝑚∗𝑛≤105
// Input
// The first line of input consists of two integers 𝑚
//  and 𝑛
//  respectively. Subsequently, there are 𝑚
//  lines with 𝑛
//  entries in each line representing the binary 2D matrix. Where 1
//  represent the starting point of the fire spread and 0
//  represent the unburned houses.

// Output
// To determine the time it took for all the houses to burn down.

// input
// 3 3
// 0 0 0
// 0 1 0
// 0 0 0
// output
// 1





#include <stdio.h>
#include <stdlib.h>

void setframe(int* a, int* b, int* c, int* tail, int bb, int aa, int cc){
    a[*tail]=aa;
    c[*tail]=cc;
    b[*tail]=bb;

    *tail=*tail+1;    
}

void game(int n, int m, int** matrix, int* a, int* b, int* c, int* tail, int* head){
    int dx[]={1,0,-1,0,1,-1,1,-1};
    int dy[]={0,1,0,-1,1,1,-1,-1};

    for (int j=0;j<8;j++){
        int cc=c[*head]+1;
        int aa=a[*head]+dx[j];
        int bb=b[*head]+dy[j];


        if(aa<0 || aa>=m || bb<0 || bb>=n){
            continue;
        }else if(aa>=m){
            continue;
        }else if(bb<0){
            continue;
        }else if(bb>=n){
            continue;
        }
        if(matrix[bb][aa]==1){
            continue;
        }
        matrix[bb][aa]=1;
        setframe(a,b,c,tail,bb,aa,cc);
    }
    *head = *head + 1;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    int **matrix;
    matrix = malloc(a * sizeof *matrix);
    for(int i=0;i<a;i++){
        matrix[i]=malloc(b * sizeof *matrix[i]);
    }
    int x[a*b];
    int y[a*b];
    int t[a*b];
    int tail=0;
    int head=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&matrix[i][j]);
            if (matrix[i][j]==1){
        setframe(x,y,t,&tail,i,j,0);
    }
    }
    }
    while(tail!=a*b){

        game(a,b,matrix,x,y,t,&tail,&head);
    }
    printf("%d\n",t[tail-1]);
    return 0;
}