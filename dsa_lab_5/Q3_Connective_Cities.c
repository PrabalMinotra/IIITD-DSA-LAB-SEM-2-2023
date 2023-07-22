// NOTE: You are allowed to use only stdlib.h and stdio.h . Your submission will not be graded if there is use of any other library.

// There are 𝑁
//  cities which are connected in the form an 𝐧-𝐚𝐫𝐲
//  tree. The city at the root of the tree is numbered as city 1. You will be given the list of cities which are interconnected to each other. Say 𝐬-𝐭
//  is the shortest path between city 𝑠
//  and city 𝑡
// . We define the connectivity of the city as the distance of the shortest path be 𝐷(𝑠−𝑡)=𝑑
// . You will be given 𝑇
//  test-cases where in each test-case contains 2 integers 𝑉
//  and 𝐷
// . You need to compute the number of cities having connectivity 𝐷
//  with the city 1 such that 𝑉
//  lies in the shortest path from that particular city to the city 1
// . Constraints:

// 1 ≤ 𝑇 ≤ 200000
// 2 ≤ 𝑁 ≤ 200000
// 2 ≤ 𝑉 ≤ 𝑁
// 0 ≤ 𝐷 ≤ (𝑁−1)

// Input
// The first line contains 2 spaced integers 𝑁
//  and 𝑇
//  denoting the number of cities and number of test-cases. Each of the following 𝑁−1
//  lines contains 2 spaced integers 𝑢
//  and 𝑣
//  denoting the connection between city 𝑢,𝑣
// . Each of the following 𝑇
//  lines contains 2 spaced integers 𝑉
//  and 𝐷
//  as defined in the problem statement.

// Output
// Print the number of cities having connectivity 𝐷
//  with the city 1 such that 𝑉
//  lies in the shortest path from that particular city to the city 1
// .


// input
// 7 3
// 5 1
// 7 1
// 6 1
// 3 1
// 4 5
// 2 5
// 6 6
// 7 1
// 2 3
// output
// 0
// 1
// 0