// You are given an array of positive integers of size n, and an integer x. Your task is to find the minimum number of elements required to achieve a sum of at least x from the array. If it is not possible to make the target sum then print -1.

// Input
// The first line of input contains two integers 𝑛
//  and 𝑥
//  (1≤𝑛≤105,1≤𝑥≤1018)
//  — the size of the array and the target sum, respectively.

// The second line of input contains 𝑛
//  space-separated positive integers 𝑎1,𝑎2,...,𝑎𝑛
//  (1≤𝑎𝑖≤109)
//  — the elements of the array.

// Output
// Output a single integer — the minimum number of elements required to achieve a sum of at least 𝑥
//  if possible otherwise -1.


// input
// 6 18
// 10 21 22 13 19 18

// output
// 1

#include <stdio.h>

void arrp(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int Indicerr(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int mid = 0;
    int index = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == x) {
            index = mid;
            high = mid - 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (index != -1)
        return index;
    else
        return low;
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[a];
    int q[b];



    for(int i=0; i<a;i++){
        scanf("%d",&arr[i]);
}
    //arrp(arr,a);
    for(int i=0; i<b;i++){
        scanf("%d",&q[i]);
}
    //arrp(q,b);






    //int arr[] = {1,2,2,3,4,5};
    //for (int i=0; i<a;)
    int n = sizeof(arr)/sizeof(arr[0]);
    //int q[] = {1,2,4,5,10,0};
    int num_queries = sizeof(q)/sizeof(q[0]);
    for (int i = 0; i < num_queries; i++) {
        int x = q[i];
        int index = Indicerr(arr, n, x);
        printf("%d\n", index);
    }
    return 0;
}