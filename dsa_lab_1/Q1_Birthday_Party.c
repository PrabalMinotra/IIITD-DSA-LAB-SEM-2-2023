// NOTE: Please note that to solve the problem you would need to implement mergesort algorithm from scratch. Otherwise, your submission will not be graded. Use of any other libraries apart from "stdio.h" is not allowed. Otherwise, your submission will not be graded.

// Ishu has plenty of deadlines to complete by the end of the day. But, she also needs to dress up for a friend's birthday party, because of which she can't focus on deadlines. Luckily, she got a close "friend" Rohu who would happily help her. So, Rohu decides to take on the deadlines, and for this, he comes up with the idea of arranging the deadlines first based on preference (easiness in Rohu's words).

// However, it is not as simple as it appears as Rohu is quite lazy and would want to make this arrangement using the minimum number of swaps. Help Rohu arrange the deadlines as this might be the only chance he would have of impressing Ishu.

// Formally, given 𝑁
//  distinct integers 𝑑1,𝑑2,...𝑑𝑖,...𝑑𝑁
// . You must report the minimum number of swaps required to order 𝐷1,𝐷2,...𝐷𝑖,...𝐷𝑁
// , where 𝐷1<𝐷2<...<𝐷𝑁
// .

// Input
// The first line contains a single integer 𝑛
//  (1≤𝑛≤105
// ) — the number of elements in the array.

// The second line contains 𝑛
//  distinct integers 𝑑1,𝑑2,…,𝑑𝑛
//  (1≤𝑎𝑖≤106
// ).

// Output
// Print minimum numbers of swaps.

// example input
// 4
// 1 2 4 3
// example output
// 1

#include <stdio.h> 

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;


    if (array[mid] == x)
      return mid;


    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int merge(int unso[], int l, int m, int r) 
{ 
    int i;
    int j;
    int k; 

    int nn1 = m-l+1; 
    int nn2 = r-m; 
    int left[nn1];
    int right[nn2];

    for (i = 0; i < nn1; i++){
        left[i] = unso[l + i];
        }

for (j = 0; j < nn2; j++){
    right[j] = unso[m + 1 + j];
    } 

    i = 0;
    j = 0;  
    k = l; 

    while (i < nn1 && j < nn2){ 

        if (left[i] <= right[j]){ 

        unso[k] = left[i]; 
        i++;
        }else{

        unso[k] = right[j]; 
        j++; 

        } 
        k++; 
} 

    while (i < nn1) { 
        unso[k] = left[i]; 
        i++; 
        k++; 

} 
    while (j < nn2){ 
        unso[k] = right[j]; 
        j++; 
        k++; 

} 
    int *ptr=i+j;


} 
int mergeSort(int arr[],int l, int r)
{
    if (l < r)  
    { 

        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r ); 


    } 
}
void arrayprinter(int A[], int leng) 
{
    int i; 
    for (i = 0; i < leng; i++) printf("%d ", A[i]); 
}

int main() 
{

    int n;
    scanf("%d",&n);
    int a[n];
        int i;
        for (i = 0; i < n; i++) {

            scanf("%d", &a[i]);
        }
    int youu[n];
    int j; 
    for (j = 0; j < n; j++){
        youu[j]=a[j];
    }
    mergeSort(a,0,n-1);

    // arrayprinter(youu,n);
    // printf("\n");
    // arrayprinter(a,n);
    // printf("\n");


    int inec[n];
    for(int y=0;y<n;y++){
        int df=youu[y];
        int sd=binarySearch(a,df,0,n-1);
        inec[y]=sd;

    }





    int cycles = 0;




    int visited[n];
    for(int i = 0; i < n; ++i)
        visited[i] = 0;

    for(int i = 0; i < n; ++i){

        if(visited[i]) continue;
        visited[i] = 1;
        int k = inec[i];
        cycles++;
        while(k != i){
            visited[k] = 1;
            k = inec[k];
        }
    }
    int d=n-cycles;
    printf("%d",d);


    return 0;
}