// Rohu and Ishu are playing a card game. They have a deck of n cards, each with some value. In each round of the game, they perform the following steps:

// They draw K cards from the top of the deck.
// They note the highest value among the drawn cards.
// They remove the first card from the drawn set.
// Steps 1-3 are repeated until there are fewer than K cards left in the deck.
// Once the game has ended, the winner is determined as follows-

// The total score for the Player is calculated as the sum of the highest values noted by him during the game.

// The player with the highest total score is declared the winner. If both players have the same total score, the game is declared a draw.

// Note: The game Always starts with Ishu

// Input
// The first line of input consists of two integers 𝑛
//  and 𝑘
//  where 𝑛
//  is The number of cards in the deck (1≤𝑛≤105)
//  and K is The number of cards drawn in each round (1≤𝐾≤𝑛)
//  and the second line contains n space-separated numbers 𝑎1
// , 𝑎2
// , ..., 𝑎𝑛
// , where 𝑎𝑖
//  is the value of the i-th card in the deck (1≤𝑎𝑖≤109)
// Output
// Print "Rohu" if Rohu wins, "Ishu" if Ishu wins, or "draw" if the scores are equal.


// input
// 6 3
// 4 6 2 8 1 7
// output
// rohu

// input
// 10 2
// 3 7 1 9 4 8 2 6 5 10
// output
// ishu



#include<stdio.h>

int main(){
int n, k;
scanf ("%d %d", &n, &k);
int ishu = 0;
int rohu = 0;
int arr[n];
for (int i = 0; i < n; i++)
{
scanf ("%d", &arr[i]);
}
int flag = 0;
int max = 0;
for (int i = 0; i <= n-k;i++){
if(i>0){
if(max != arr[i-1]){
    if(max<arr[i+k-1]){
    max=arr[i+k-1];
}
}else{
    max=0;
    for(int j=i;j<i+k;j++){
        if(arr[j]>max){
            max=arr[j];
            }
    }
}
}else{
    for(int j=i;j<i+k;j++){
        if(arr[j]>max){
            max=arr[j];
            }
    }
}
if(flag==0)
{
    ishu+=max;
    flag=1;
}
else
{
    rohu+=max;
    flag=0;
}
}
if(rohu>ishu)
{
    printf("rohu\n");
    }
else if(rohu==ishu)
{
    printf("draw\n");
    }
else {
    printf("ishu\n");
    }
}