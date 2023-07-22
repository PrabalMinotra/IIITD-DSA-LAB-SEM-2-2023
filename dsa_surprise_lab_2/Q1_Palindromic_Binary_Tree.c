// NOTE: you need to do implement a binary tree from scratch. Failing to do so will reward you no marks. Also you are only allowed to use stdlib.h and stdio.h only.

// You are given a binary tree of height 𝐻
// , where each node consists of a lower case character i.e. any one alphabet from 𝑎−𝑧
// . A path in the binary tree is a palindromic path if the values of the nodes arranged in any manner results in a palindrome. You will be given the level order traversal of the binary tree. A Null/No node will be depicted by character 𝑁
// . Your task is to print the number of such palindromic paths from root node to leaf node that exist in the binary tree.

// Constraints:

// 0 ≤ 𝐻 ≤ 16
// each node value is a lower case character i.e. any alphabet from 𝑎−𝑧
// .
// Assume that the height at which root node is present is 0.
// Input
// The First line contains an integer 𝐻
//  denoting the height of the binary tree. The following line contains level order traversal of the binary tree.

// Output
// Print the number of such palindromic paths that exist in the binary tree.


// input
// 1
// a b b

// output
// 0