// You are tasked with implementing an AVL tree, a self-balancing binary search tree. The tree supports two types of operations: insert x and subtree x.

// For the insert x operation, you need to insert the element x into the AVL tree. After the insertion, you should print two space-separated integers representing the total number of left rotations (L) and right rotations (R) performed during the insertion process, respectively.
// The subtree x operation requires you to print the sum of all elements in the subtree rooted at node x, including the value of x itself if x exists otherwise print 'NA'.
// Constraints:

// The number of queries, denoted by Q, will be between 1
//  and 10^5
// , inclusive. (1 ≤ 𝑄 ≤ 10^5)
// Each query will be either of the two types: insert x or subtree x.
// For the insert x operation, the value of x will be an integer between −10^9
//  and 10^9
// , inclusive. (−10^9 ≤ 𝑥 ≤ 10^9)
// All input and output values will fit in a 64
// -bit signed integer.
// Input
// The first line of the input contains an integer 𝑄
// , representing the number of queries.

// The next 𝑄
//  lines contain the queries. Each query is in one of the following formats:

// insert x: representing the insertion of the element x into the AVL tree.
// subtree x: representing the query to print the sum of the subtree rooted at node x.
// It is guaranteed that the input format will follow the constraints mentioned earlier.
// Output
// print the answer of each query in above mentioned format.


// input
// 9
// insert 1
// subtree 1
// insert 5
// subtree 1
// insert 3
// subtree 1
// subtree 3
// subtree 5
// subtree 10


// output
// 0 0
// 1
// 0 0
// 6
// 1 1
// 1
// 9
// 5
// NA





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) 
{
return a > b ? a : b;
}

struct node 
{
long long int data;
struct node* left;
struct node* right;
int height;
long long int sum;
};

int height(struct node* root) 
{
if (root == NULL)
return 0;
return root->height;
}


struct node* populate(long long int data) 
{
struct node* temp = (struct node*)malloc(sizeof(struct node));
temp->data = data;
temp->left = temp->right = NULL;
temp->height = 1;
temp->sum = data;
return temp;
}



void newheight(struct node* root) 
{
int leftHeight = height(root->left);
int rightHeight = height(root->right);
root->height = max(leftHeight, rightHeight) + 1;
}


long long int sumoftree(struct node* root) 
{
if (root == NULL)
return 0;
return root->sum;
}


void newsub(struct node* root) 
{
if (root == NULL)
return;
long long int leftSum = (root->left) ? sumoftree(root->left) : 0;
long long int rightSum = (root->right) ? sumoftree(root->right) : 0;
root->sum = root->data + leftSum + rightSum;
}



struct node* rotleft(struct node* root) 
{
struct node* newRoot = root->right;
struct node* leftSubtree = newRoot->left;
newRoot->left = root;
root->right = leftSubtree;
newheight(root);
newheight(newRoot);
newsub(root);
newsub(newRoot);
return newRoot;
}


struct node* rotright(struct node* root) 
{
struct node* newRoot = root->left;
struct node* rightSubtree = newRoot->right;
newRoot->right = root;
root->left = rightSubtree;
newheight(root);
newheight(newRoot);
newsub(root);
newsub(newRoot);
return newRoot;
}



int ifavl(struct node* root) 
{
if (root == NULL)
return 0;
return height(root->left) - height(root->right);
}



struct node* putvalues(struct node* root, long long int data, int* leftRots, int* rightRots) 
{
if (root == NULL)
return populate(data);

if (data < root->data) 
{
*leftRots = 0;
*rightRots = 0;
root->left = putvalues(root->left, data, leftRots, rightRots);
int BF = ifavl(root);

if (BF > 1) 
{

if (data < root->left->data) 
{

(*rightRots)++;
root = rotright(root);
}
else 
{

(*leftRots)++;
root->left = rotleft(root->left);
(*rightRots)++;
root = rotright(root);
}
}
} 
else if (data > root->data) 
{
*leftRots = 0;
*rightRots = 0;
root->right = putvalues(root->right, data, leftRots, rightRots);
int BF = ifavl(root);

if (BF < -1) 
{

if (data > root->right->data) 
{

(*leftRots)++;
root = rotleft(root);
} 
else 
{

(*rightRots)++;
root->right = rotright(root->right);
(*leftRots)++;
root = rotleft(root);
}
}
}

newheight(root);
newsub(root);

return root;
}

struct node* look(struct node* root, long long int data) {
if (root == NULL || root->data == data)
{
return root;
}
if (data < root->data){


return look(root->left, data);
}
else{


return look(root->right, data);
}
}

int main() {
int nn;
scanf("%d", &nn);
struct node* root = NULL;
int leftRots = 0;
int rightRots = 0;

for (int i = 0; i < nn; i++) 
{
char command[10];
long long int value;
scanf("%s %lld", command, &value);

if (strcmp(command, "insert") == 0) 
{
root = putvalues(root, value, &leftRots, &rightRots);

printf("%d %d\n", leftRots, rightRots);
} 
else if (strcmp(command, "subtree") == 0) 
{

struct node* tmp = look(root, value);




if (tmp != NULL){

printf("%lld\n", sumoftree(tmp));
}
else{


printf("NA\n");
}
}
}

return 0;
}