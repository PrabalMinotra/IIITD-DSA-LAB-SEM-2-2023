// NOTE: You are allowed to use only stdlib.h and stdio.h . Your submission will not be graded if there is use of any other library.

// King John has decided to acquire the nearby kingdoms. He has gotten along with his troops to accomplish this mission. There are total of 𝑁
//  cities. The path to each kingdom goes from city 1. The kingdoms are in the last city of each path from city 1. Along each path there are some cities where soldiers have been deployed to protect the kingdoms. So if 𝑖𝑡ℎ
//  city has soldiers deployed, then it'll be denoted by 𝑆𝑖=1
// , otherwise 𝑆𝑖=0
// . Note that there can be soldiers deployed in the cities containing kingdoms. Unfortunately the King's troops have power to defend soldiers in at most 𝐾
//  consecutive cities along the path. Your task is to tell the number of kingdoms that the King can conquer.

// Constraints:

// 2 ≤ 𝑁 ≤ 100000
// 1 ≤ 𝐾 ≤ 𝑁
// Input
// The first line contains two spaced integers 𝑁
//  and 𝐾
//  where 𝑁
//  is the number of cities. The second line contains 𝑁
//  spaced integers where 𝑆𝑖=1
//  or 𝑆𝑖=0
// , denoting whether soldiers are deployed in the 𝑖𝑡ℎ
//  city or not. Each of the following 𝑁−1
//  lines contains 2 spaced integers 𝑢
//  and 𝑣 (𝑢≠𝑣). denoting that city 𝑢 and 𝑣
//  are connected to each other.

// NOTE: it is guaranteed that there is no cyclic paths.

// Output
// Print the number of kingdoms that the King can conquer.


// input
// 5 2
// 1 1 0 1 1
// 1 2
// 2 3
// 3 4
// 4 5
// output
// 1