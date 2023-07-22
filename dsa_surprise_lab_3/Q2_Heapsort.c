// You are given an array arr
//  of size 𝑛
// . Your task is to sort the array in ascending order using only the heap data structure.

// Note: your submission will not be graded if implementation of heap is not found.

// Constraints:

// 1 ≤ 𝑛 ≤ 10^5
// −10^9 ≤ 𝑎𝑖 ≤ 10^9
//  , 𝑎𝑖:
//  element of the array
// Input
// The first line of input contains an integer n, representing the size of the array. The second line of input contains n space-separated integers, representing the elements of the array.

// Output
// Output a single line containing 𝑛
//  space-separated integers representing the array sorted in ascending order.


// input
// 10
// 16 19 2 10 15 7 3 8 8 19

// output
// 2 3 7 8 8 10 15 16 19 19 

#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int size, int rootIndex) {
    int largest = rootIndex;   
    int left = 2 * rootIndex + 1;     
    int right = 2 * rootIndex + 2;   


    if (left < size && arr[left] > arr[largest])
        largest = left;


    if (right < size && arr[right] > arr[largest])
        largest = right;


    if (largest != rootIndex) {
        swap(&arr[rootIndex], &arr[largest]);


        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size) {

    for (int i=size/2-1;i>=0;i--)
        heapify(arr, size, i);


    for (int i=size-1;i>0;i--) {

        swap(&arr[0], &arr[i]);


        heapify(arr, i, 0);
    }
}


void printArray(int arr[], int size) {
    for (int i=0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main() {
    int n;

    scanf("%d",&n);
    int array[n];

    for(int i=0; i<n; i++){
    
    scanf("%d", &array[i]);
    }


    heapSort(array, n);

    printArray(array, n);

    return 0;
}
