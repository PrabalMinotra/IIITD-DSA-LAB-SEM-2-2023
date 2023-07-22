// Rohu and Ishu, long-time friends from the vibrant city of Zythera, want to play Hide and Seek. Zythera is made up of N houses, including the majestic King's Mansion with address 1. All houses are connected by roads, ensuring a unique path between any two houses.

// In this game, Ishu runs and hides in a particular house, let's call it X. Rohu, starting from his own house, let's call it Y, must try to find Ishu. If Rohu reaches house X, then he is certain to find Ishu. Rohu has two options during his search: he can either move towards the King's Mansion and stop when he reaches it, or he can choose any path away from the Mansion until he reaches the last house on that path.

// Now, imagine there are Q queries, and you must determine if it's possible for Rohu to find Ishu based on these queries. Each query can be of two types:

// towards X Y: Rohu moves towards the King's Mansion.
// away X Y: Rohu moves away from the King's Mansion.
// Your task is to evaluate each query and determine if Rohu will be able to find Ishu or not.
// Constraints:

// 1 ≤ 𝑁 ≤ 10^5
// 1 ≤ 𝐴,𝐵 ≤ 𝑁
// 1 ≤ 𝑄 ≤ 5×10^5
// 1 ≤ 𝑋,𝑌 ≤ 𝑁
// Input
// The first line of the input contains a single integer N, total number of houses in the city.

// Next N-1 lines contain two space separated integers A and B denoting a road between the houses at address A and B.

// Next line contains a single integer Q denoting the number of queries. Following Q lines contain three space separated integers representing each query as explained above.

// Output
// For each query, print a single line containing "YES" if Rohu can find Ishu or "NO" otherwise.


// input
// 9
// 1 2
// 1 3
// 2 6
// 2 7
// 6 9
// 7 8
// 3 4
// 3 5
// 5
// towards 2 8
// away 2 8
// away 6 5
// towards 6 5
// away 9 1


// output
// YES
// NO
// NO
// NO
// YES