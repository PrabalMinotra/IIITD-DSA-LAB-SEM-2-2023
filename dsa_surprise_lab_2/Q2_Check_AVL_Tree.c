// You are given a Binary Tree as input in level order traversal form. You have to check if the given binary tree is an AVL tree or not. If it is an AVL tree, print "YES", else print "NO".

// Note: there will be binary marking for this question - you will get marks only if ALL test cases pass.

// Input
// The first line consists of an integer 1≤𝑛≤1000
//  indicating total number of nodes in the binary tree
// The next lines contains binary tree nodes in level order traversal form. −1
//  indicates NULL node / NO node (see example). Each node's value ranges from 1≤𝑛𝑖≤106
// Output
// Print either "YES" or "NO" depending on whether given tree is AVL or not.


// input
// 6
// 50 20 80 15 -1 60 -1 -1 19 -1 -1 -1 -1

// output
// NO

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


int height(struct node* root) {

if (root == NULL){

return 0;
}
int leftHeight = height(root->left);

int rightHeight = height(root->right);

return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}


bool isBalanced(struct node* root) 
{
if (root == NULL){


return true;
}

int leftHeight = height(root->left);

int rightHeight = height(root->right);


if (abs(leftHeight - rightHeight) > 1){


return false;
}


return isBalanced(root->left) && isBalanced(root->right);
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








int main()
{
 
struct node * root;
 
int n;
 
scanf("%d" , &n);
 
root = populate(n);
isBalanced(root);

if (isBalanced(root)){
printf("YES\n");
}
else{
    
printf("NO\n");
}

return 0;
}