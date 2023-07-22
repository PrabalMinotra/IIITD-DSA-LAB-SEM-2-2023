// You are given an array of positive integers of size n, and an integer x. Your task is to find the minimum number of elements required to achieve a sum of at least x from the array. If it is not possible to make the target sum then print -1.

// Input
// The first line of input contains two integers 𝑛
//  and 𝑥
//  (1 ≤ 𝑛 ≤ 10^5 , 1 ≤ 𝑥 ≤ 10^18)
//  — the size of the array and the target sum, respectively.

// The second line of input contains 𝑛
//  space-separated positive integers 𝑎1,𝑎2,...,𝑎𝑛
//  (1 ≤ 𝑎𝑖 ≤ 10^9)
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
#include <stdlib.h>

void arrp(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
//qsort to compare a pair of elements har baar to get mini

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int summers(int arr[], int n, int target) {
    qsort(arr, n, sizeof(int), comp);

    int count = 0, sum = 0;
    for (int i = n-1; i >= 0; i--) {
        sum += arr[i];
        count++;
        if (sum >= target) {
            return count;
        }
    }

    return -1;
}

int main() {
    int n, target;
    scanf("%d %d", &n,&target);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minCount = summers(arr, n, target);

    if (minCount == -1) {
        printf("%d",-1);
    } else {
        printf("%d\n", minCount);
    }

    return 0;
}
