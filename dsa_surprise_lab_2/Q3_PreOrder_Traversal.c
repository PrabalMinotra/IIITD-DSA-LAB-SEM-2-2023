// You are given 𝑁
//  distinct nodes, numbered from 1
//  to 𝑁
// . Your task is to build a Binary Search Tree (BST) using these nodes and then print the preorder traversal of the resulting tree.

// Note:

// The input nodes are distinct, i.e., no duplicate values will be present.
// You can assume that a valid BST can always be constructed from the given nodes.
// Input
// The input consists of two lines.

// The first line contains an integer 𝑁
//  (1 ≤ 𝑁 ≤ 10^5)
// : the number of nodes.

// The second line contains 𝑁
//  space-separated distinct integers (1 ≤ 𝚗𝚘𝚍𝚎𝚜[𝑖] ≤ 𝑁)
// : the values of the nodes.

// Output
// Print a single line containing the preorder traversal of the BST built from the given nodes.


// input
// 8
// 1 2 8 5 3 7 4 6

// output
// 1 2 8 5 3 4 7 6 


#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
struct Node* createNode(int data) {
    struct Node* newnew = (struct Node*)malloc(sizeof(struct Node));
    newnew->data = data;
    newnew->left = NULL;
    newnew->right = NULL;
    return newnew;
}
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
int main() {
    int n;
    scanf("%d", &n);
    int children[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &children[i]);
}
    struct Node* root = NULL;
    for (int i = 0; i < n; i++){
        root = insert(root, children[i]);
}
    preorder(root);
    printf("\n");

    return 0;
}