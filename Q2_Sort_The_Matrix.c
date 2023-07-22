// NOTE: Please note that to solve the problem you would need to implement quicksort algorithm from scratch. Otherwise, your submission will not be graded. Use of any other libraries apart from "stdio.h" is not allowed. Otherwise, your submission will not be graded.

// Given an 𝑚
//  x 𝑛
//  2D matrix 𝐴
//  consisting of only 0𝑠
//  and 1𝑠
// , sort the columns of 𝐴
//  such that the sums of columns are in non-decreasing order. In case two columns have equal sums, prioritise the column with a lower index in the original input. Print the final binary matrix after sorting.

// Constraints

// 1≤𝑚,𝑛≤104
// 1≤𝑚∗𝑛≤106
// Input
// The first line of input consists of two integers 𝑚
//  and 𝑛
//  respectively. Subsequently, there are 𝑚
//  lines with 𝑛
//  entries in each line representing the binary 2D matrix.

// Output
// Print the final binary matrix after sorting according to the criteria specified.
// input

// 4 5
// 0 0 1 1 0
// 1 1 1 0 1
// 0 1 1 1 0
// 1 0 1 1 0

// output

// 0 0 0 1 1 
// 1 1 1 0 1 
// 0 0 1 1 1 
// 0 1 0 1 1 

#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows,&cols);

    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int column_sum[cols];
    for (int j = 0; j < cols; j++) {
        column_sum[j] = 0;
        for (int i = 0; i < rows; i++) {
            column_sum[j] += matrix[i][j];
        }
    }

    for (int j = 1; j < cols; j++) {
        int key = column_sum[j];
        int i = j - 1;
        while (i >= 0 && column_sum[i] > key) {
            column_sum[i + 1] = column_sum[i];
            for (int k = 0; k < rows; k++) {
                int temp = matrix[k][i + 1];
                matrix[k][i + 1] = matrix[k][i];
                matrix[k][i] = temp;
            }
            i--;
        }
        column_sum[i + 1] = key;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
