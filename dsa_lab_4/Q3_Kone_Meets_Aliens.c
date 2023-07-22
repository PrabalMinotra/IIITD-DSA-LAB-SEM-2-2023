// Kone recently joined forces with Melon Tusk and went to the first ever mission on Mars, and much to his delight he made friends with aliens over there. Now Kone has to rank all these aliens based on their hostility and humour. Kone collects this data for 𝑛
//  aliens and sends it over to Earth for his friend Lawrence to analyze. To be specific, Kone sends 𝑞
//  queries to Lawrence, where each query contains a single integer 𝑞𝑖
//  and he's supposed to report the 𝑞𝑖𝑡ℎ
//  alien in the increasing order of the sum of hostility + humour values. Help Lawrence and Kone with this task and play a role in strengthening Earth-Mars ties.

// Update: the sum to be considered corresponds to all possible combinations of hostility and humour.

// Input
// the first line contains two space separated integers - the number of aliens 𝑛
//  and the number of queries 𝑞
//  (1≤𝑛≤20000
//  and 1≤𝑞≤500
// )
// the second line contains 𝑛
//  elements representing the hostility value of each alien (1≤𝑎𝑖≤1018
// )
// the third line contains 𝑛
//  elements representing the humour value of each alien (1≤𝑏𝑖≤1018
// )
// then 𝑞
//  lines follow where each line contains a single integer 𝑞𝑖
//  (1≤𝑞𝑖≤20000
// )
// Output
// For each query, report the 𝑞𝑖𝑡ℎ
//  value of hostility + humour sum in increasing order


// input
// 3 2
// 1 2 3
// 6 7 8
// 3
// 4

// output
// 8
// 9