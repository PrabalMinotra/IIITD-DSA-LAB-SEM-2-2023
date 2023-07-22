// Kone has finally graduated and being passionate about art, wants to celebrate by visiting art galleries. Kone finds there are n art galleries in his area and wants to visit as many as he can within k days. Now, the 𝑖𝑡ℎ
//  art gallery has 𝑤𝑖
//  paintings and Kone wants to see the maximum number of paintings in each art gallery. Therefore, if Kone sees 𝑎𝑖
//  paintings at the 𝑖𝑡ℎ
//  art gallery, he wants 𝑤𝑖−𝑎𝑖
//  to be minimum for all art galleries.

// To come up with an efficient strategy, he seeks the wisdom of his pals Lawrence and TarS. The group can visit atmost 1 art gallery per day. They propose an algorithm - if the paintings left to be seen for a given art gallery are w, then Kone only sees 𝑐𝑒𝑖𝑙(𝑤2)
//  paintings and hope to revisit the art gallery later.

// Now, TarS knows that Lawrence dreads paintings and if the group sees 𝑎𝑖
//  paintings for the 𝑖𝑡ℎ
//  art gallery, Lawrence will be bored by 𝑏𝑖∗𝑎𝑖
//  units. But Kone would still prefer seeing maximum number of paintings, however, if there are multiple optimal ways to go about it, he would be considerate of Lawrence's feelings and take the approach which bores Lawrence the least.

// Now, it is up to you to help Kone, Lawrence and TarS. Formally, you have to maximise the total number of paintings they can see and if there are multiple answers, choose the one which minimises Lawrence's boredom.

// Input
// the first line contains the number of test cases (1≤𝑡≤5
// )
// the first line of each test case contains two integers n and k indicating the number of art galleries and days available (1≤𝑛,𝑘≤105
// )
// the second line of each test case contains n space separated integers indicating the number of paintings in each art gallery (1≤𝑤𝑖≤106
// )
// the third line of each test case contains n space separated integers indicating Lawrence's boredom for completing 1 painting in the 𝑖𝑡ℎ
//  art gallery (1≤𝑏𝑖≤106
// )
// Output
// For each test case, print two space separated integers - the total number of paintings left to be seen and the total boredom acquired by Lawrence.


// input
// 1
// 4 4
// 1 2 3 4
// 5 3 1 1

// output
// 4 6