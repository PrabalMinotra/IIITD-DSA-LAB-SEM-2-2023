// NOTE - you need to implement a heap from scratch. Also note that you are not allowed to use libraries other than stdlib.h and stdio.h your submission will not be graded if implementation of heap is not found.

// Sandheap is a farmer who owns a herd of 𝑁
//  goats. He goes everyday to a nearby rental farm to feed hay and grass to the goats. Since every farm has different capacity to accommodate a number of goats, therefore let's say the farm they go to has a capacity to accommodate 𝐾
//  goats at a time. Each goat takes some specific time to eat, say 𝑖𝑡ℎ
//  goat takes 𝑇𝑖
//  time. Once a goat is done eating, immediately it moves out and another goat comes in. So let's say that the total time taken till the last goat has eaten is 𝑇
// . The farmer has to feed the goats in at most 𝑇𝑢
//  time since the farm is booked on a rental basis. Therefore he must go to a farm with enough size to accommodate the goats so that he gets done well within time. Your task is to determine the infimum value of 𝐾
//  so that he can rent a farm with the optimal constraints.

// Constraints:

// 1 ≤ 𝑁 ≤ 10^4
// 1 ≤ 𝑇𝑈 ≤ 10^6
// 1 ≤ 𝑇𝑖 ≤ 10^5
// Input
// The first line contains 2 spaced integers 𝑁
//  and 𝑇𝑢
// . Following 𝑁
//  lines contains 𝑁
//  integers denoting 𝑇𝑖
//  i.e. the time taken by each goat to eat the hay and grass.

// Output
// Print the infimum value of 𝐾
//  such that all goats are fed in ≤𝑇𝑢
//  time.


// input
// 5 8
// 4
// 7
// 8
// 6
// 4

// output
// 4