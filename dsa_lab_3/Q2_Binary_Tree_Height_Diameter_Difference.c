// You are given the level order traversal of a binary tree. The level order traversal of a binary tree is defined as the sequence of node values visited by level, from the root node at level 0, followed by the nodes at level 1, then level 2, and so on. Each level is visited from left to right. If a node has no child, it is represented by the integer -1 in the level order traversal sequence.

// Your task is to compute the absolute difference between the height and diameter of the binary tree represented by the given level order traversal.

// The height of a binary tree is defined as the length of the longest path from the root node to any leaf node in the tree.

// The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree.

// Input
// The input consists of two lines. The first line contains a single integer 𝑛
//  (1≤𝑛≤104)
// , the number of nodes in the binary tree.

// The second line contains 2𝑛+1
//  space-separated integers representing the level order traversal of the binary tree, where each integer represents the value of a node in the tree.

// The values of the nodes are unique and range from 1 to 𝑛
// . If a node has no child, it is represented by the integer -1.

// Output
// Output a single integer, the absolute difference between the height and diameter of the binary tree

// input
// 6
// 1 2 3 4 -1 5 -1 6 -1 -1 -1 -1 -1
// output
// 2

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

struct node {

int value;

struct node  * left ;

struct node * right;

};

int max(int a , int b)
{

return a>b ? a:b;

}







struct node * populate(int n)
{
struct node * root = NULL;

int a;

scanf("%d" , &a);

if( a == -1)

{
{

return root;

}
}

root = (struct node *)malloc(sizeof(struct node));

root->value   =a;

root->left = NULL;

root->right = NULL;


struct node * q[n];

int c = 0 , l=1;

q[c] = root;

int b;

for (int i = 0; i < n; i++)

{

struct node * treecurr = q[c];

c+=1;

scanf("%d %d" , &a , &b);

if(a!=-1){

struct node *  new1 = (struct node *)malloc(sizeof(struct node));

new1->value   =a;

new1->left = NULL;

new1->right = NULL;

treecurr->left = new1;

q[l] = new1;

l += 1;

}

if(b!=-1)
{

struct node *  new2 = (struct node *)malloc(sizeof(struct node));

new2->value   =b;

new2->left = NULL;

new2->right = NULL;

treecurr->right = new2;

q[l] =  new2;

l += 1;

}
}

return root;

}


int* gettdiameter(struct node * root)
{

if(root == NULL) 

{

int *a = (int *)malloc(sizeof(int) *2);

a[0]= 0 ;a[1] =0;

return a;

}

int *a = gettdiameter(root->left);

int *b= gettdiameter(root->right);

int inib = b[0];

if(a[0] > b[0]) inib = a[0];

inib = max(inib , 1 + a[1] + b[1]);

int *ans =  (int *)malloc(sizeof(int) *2);

ans[0] = inib;

ans[1] = max(a[1] , b[1]) +1;

return ans;

}


int height(struct node * root)

{

if(root == NULL)
{
return 0;
}

return max(height(root->left) , height(root->right)) + 1;

}

int main()
{

struct node * root;

int n;

scanf("%d" , &n);

root = populate(n);

int *final = gettdiameter(root);

printf("%d\n", abs(final[1] - final[0]));

return 0;
}