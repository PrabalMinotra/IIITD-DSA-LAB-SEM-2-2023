// NOTE: the easy and the hard version of the problem vary on the basis of the constraints given. Use of any other libraries apart from "stdio.h" is not allowed. Otherwise, your submission will not be graded.

// Lawrence has bought 𝑁
//  cupcakes for Kone. But it turns out that Kone doesn't want to eat them. Kone will eat the cupcakes only if Lawrence solves the problem given by him. Kone arranges the cupcakes in a row and assigns a random value 𝐴𝑖
//  to the 𝑖𝑡ℎ
//  cupcake. The values assigned to the cupcakes will be given to you in the form of an array 𝐴
// . He asks Lawrence to arrange the cupcakes in the ascending order of their values. Now he gives him 𝑄
//  queries to answer. In each query Kone gives three integers 𝐿,𝑅,𝐾
//  where 𝐿,𝑅
//  are indices of the array. Lawrence needs to print the number of subarrays in the subarray 𝐴[𝐿..𝑅]
//  which have 𝐾
//  distinct elements.

// Constraints:

// 1≤𝐴𝑖≤100
// 1≤𝑁≤5∗104
// 1≤𝑄≤50
// 0≤𝐿≤𝑅≤𝑁−1
// 1≤𝐾≤𝑁
// Input
// The first line contains two spaced integers 𝑁
//  and 𝑄
// . The next line contains 𝑁
//  spaces integers 𝐴𝑖
//  denoting the values of the cupcakes. Each of the next 𝑄
//  lines contain 3 integers 𝐿,𝑅,𝐾
// .

// Output
// Print the number of subarrays in the subarray 𝐴[𝐿..𝑅]
//  which have 𝐾
//  distinct elements for every query in separate line.

// input
// 7 2
// 60 66 94 56 59 8 67
// 4 5 7
// 5 6 6
// output
// 0
// 0



#include<stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
    i++;
    swap(&array[i], &array[j]);
}
}
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
int main(){
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    for(int i = 0; i < q; i++){
        int l, r, k;
        scanf("%d", &l);
        scanf("%d", &r);
        scanf("%d", &k);


        int sub_arr[r-l+1];
        for(int j = 0; j < r-l+1; j++) sub_arr[j] = arr[j+l];
        int t = 0;
        int arr_no[r-l+1];
        for(int j = 0; j < r-l+1; j++) arr_no[j] = 0;
        arr_no[0] = 1;
        for(int j = 1; j < r-l+1; j++){
            if(sub_arr[j] != sub_arr[j-1]){
                t++;
                arr_no[t]++;
            }
            else{
                arr_no[t]++;
            }
        }
        if(k == 0){
            printf("%d\n",0);
            continue;
        }
        if (k == 1){
            int resulte=0;
            for(int b = 0; b < t+1; b++){
                resulte += (int)(arr_no[b]*(arr_no[b]+1))/2;
            }
            printf("%d\n",resulte);
            continue;
        }
        if(t+1 < k){
            printf("%d\n",0);
            continue;
        }
        int outpu = 0;
        for(int b = 0; b < t-k+2; b++){
            outpu += arr_no[b]*arr_no[b+k-1];
        }
        printf("%d\n",outpu);
    }
    return 0;
}