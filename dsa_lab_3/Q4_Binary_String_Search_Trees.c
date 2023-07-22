// NOTE - you need to implement a BST from scratch. Also note that you are not allowed to use libraries other than stdlib.h and stdio.h your submission will not be graded if implementation of BST is not found.

// Binary Search Trees are binary trees following a special property where in the key of each internal node being greater than all the keys in the respective node's left subtree and less than the ones in its right subtree.

// Following the same definition we have a come up with a new BST called Binary String Search Trees. It's a BST where in each key would be string. The keys would be kept in the left/right subtrees by checking whether they are smaller/greater than the key of the parent node.

// A string a is smaller than string b if the first non similar character in both strings are lexicographically smaller/greater than each other.

// NOTE: for example if strings are "aabb" and "aa", then "aabb" would be greater than "aa". But if strings are "aabb" and "ab", then "ab" would be greater than "aabb".

// You will be given 𝑁
//  unique strings at first. You will be required to create a BST by comparing the strings while inserting them. The strings will be inserted into the BST one by one starting in the same order as given in input.

// You can perform 2 operations on the BST constructed.

// Delete pref : Print -1 if no node with the prefix "pref" is deleted from the BST. Otherwise delete nodes with the prefix "pref" and don't print anything.
// Find pref : Print -1 if no node with the prefix "pref" exists in the BST. Otherwise print the strings with prefix "pref" in lexicographically sorted order.
// You will be given 𝑄
//  of the above mentioned operations to be performed on the BST.

// Constraints:

// 1≤𝑁∗𝑄≤106
// 1≤
//  length of string, pref ≤20
// Note that the strings would contain lowercase letters from 𝑎−𝑧
// .
// Input
// The first line contains 2 integers 𝑁
//  and 𝑄
//  denoting the number of the elements in the BST and number of queries. The next 𝑁
//  lines contains 𝑁
//  unique strings. Each of the following 𝑄
//  lines contain one of the operations to be performed on the BST as mentioned.

// Output
// Print output corresponding to the operation mentioned above.


// input
// 3 1
// aba
// abc
// abd
// Find ab

// output
// aba
// abc
// abd