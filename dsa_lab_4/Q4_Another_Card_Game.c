// Ishu and Rohu are back with their exciting card game using a deck of 𝑁
//  cards. Each card has a non-negative value assigned to it.

// The game is played as follows: Ishu and Rohu take turns drawing cards from the deck. In each turn, Rohu draws the card with the smallest value, while Ishu draws the card with the largest value. After each draw, a new card is placed in the deck with a value equal to the absolute difference between the cards drawn by Ishu and Rohu. This process continues until there are fewer than 2 cards left in the deck.

// After each turn, Ishu and Rohu want to know the score, which is the sum of all the card values obtained up to that point.

// You need to write a program to help Ishu and Rohu determine the score after each turn.

// Input
// The first line of input contains a single integer, 𝑁
//  (1 ≤ 𝑁 ≤ 10^5)
//  denoting the number of cards.

// The second line of input contains 𝑁
//  space-separated non-negative integers, representing the initial values assigned to the 𝑁
//  cards. The values ranges from 1 to 109
// .

// Output
// Print 𝑛−1
//  lines, each containing a single integer. The 𝑖
// -th line represents the score after the 𝑖
// -th turn.


// input
// 6
// 8 9 2 10 5 4

// output
// 34
// 26
// 16
// 10
// 0





#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//START TREE
typedef struct Node
{
struct Node* left;
struct Node* right;
long long data;
long long height;
}Node;

//POPULATE 
Node* createNode(long long data)
{
Node* newNode=(Node*)malloc(sizeof(Node));

newNode->left=NULL;
newNode->right=NULL;
newNode->height=1;
newNode->data=data;
return newNode;
}
//GREATER FUNCTION
long long MAX(long long a, long long b)
{  
return (a > b)? a : b;
}
//height
long long height(Node* root)
{
if (root == NULL) return 0;

return root->height;

}


//right rotation to balance tree
Node* RR(Node* root)
{
Node* x=root->left;
Node* y=x->right;

x->right=root;
root->left=y;

root->height=MAX(height(root->left),height(root->right)) + 1;

x->height=MAX(height(x->left),height(x->right)) + 1;

return x;
}
//left rotation to balance tree
Node* LR(Node* root)
{
Node* x=root->right;
Node* y=x->left;
x->left=root;
root->right=y;

root->height=MAX(height(root->left),height(root->right)) + 1;
x->height=MAX(height(x->left),height(x->right)) + 1;
return x;
}
//balance factor
long long findBalance(Node* root){
if(root==NULL)
return 0;
return height(root->right)-height(root->left);
}

//rohu score
Node* rohuu(Node* root){
Node* ptr=root;
while(ptr->left!=NULL){
ptr=ptr->left;
}
return ptr;
}
//ishu score
Node* ishuu(Node* root){
Node* ptr=root;
while(ptr->right!=NULL){
ptr=ptr->right;
}
return ptr;
}
//deletion
Node* delete(Node* root, long long key){
if (root == NULL) {
return NULL;
}
if (root->data == key) {
if (root->left == NULL) {
Node *ret = root->right;
free(root);
return ret;
}
else if (root->right == NULL) {
Node *ret = root->left;
free(root);
return ret;
}
else if (root->right != NULL && root->left != NULL) {
Node *min_node = rohuu(root->right);
root->data = min_node->data;
root->right = delete(root->right, min_node->data);
}
}
else if(key < root->data) {
root->left = delete(root->left, key);
}
else{
root->right = delete(root->right, key);
}

if(root==NULL){
return root;
}

root->height=1+MAX(height(root->right),height(root->left));

long long balance=findBalance(root);

if(balance>1){
if (findBalance(root->right) >= 0) return LR(root);
else {root->right = RR(root->right); return LR(root);}
}

if(balance<-1){
if (findBalance(root->left)<= 0) return RR(root);
else{root->left = LR(root->left); return RR(root);}
}

return root;
}


//insertion populate
Node* insert(Node* root, long long x){

if(root==NULL){
return createNode(x);
}
if(x<(root->data)){
root->left=insert(root->left,x);
}
else{
root->right=insert(root->right,x);
}
root->height=1+MAX(height(root->right),height(root->left));

long long balance=findBalance(root);

if(balance>1){
if (findBalance(root->right) >= 0) return LR(root);
else {root->right = RR(root->right); return LR(root);}
}
if(balance<-1){
if (findBalance(root->left)<= 0) return RR(root);
else{root->left = LR(root->left); return RR(root);}
}

return root;
}




//real deal


int main(){
int n;
scanf("%d",&n);

long long treesum = 0;

long long num = 0;

Node* root = NULL;

for(int i = 0; i < n; i++)
{
scanf("%lld",&num);
root = insert(root,num);
treesum += num;
}

for(int i = 0; i < n-1; i++)
{
Node* rohuscore = rohuu(root);
long long rohu = rohuscore->data;
root=delete(root,rohu);


Node* ishuscore = ishuu(root);
long long ishu = ishuscore->data;
root=delete(root,ishu);



long long newNum=ishu-rohu;

treesum=(treesum-(ishu+rohu))+newNum;

root=insert(root,newNum);

printf("%lld\n",treesum);
}

return 0;
}