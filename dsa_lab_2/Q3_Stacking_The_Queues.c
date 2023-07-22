// Kirdah is preparing for EDOBE's interview. He has asked Lawrence to take his mock interview. Lawrence was exploring some DSA problems which he could ask in the interview. He has surprisingly come up with a new problem of his own. The problem is as follows -

// Let 𝐒
//  be a stack. Each element in the stack 𝐒
//  is going to be a queue. You can perform the following operations:

// 𝐏𝐮𝐬𝐡
//  𝐊
//  :=
//  meaning that you have to push a queue containing a single element with value 𝐊
//  at its front.
// 𝐄𝐧𝐪𝐮𝐞𝐮𝐞
//  𝐊
//  :=
//  meaning that you have to enqueue value 𝐊
//  in the queue at the stack's top. If a stack is empty then perform 𝐏𝐮𝐬𝐡
//  𝐊
//  operation.
// 𝐏𝐨𝐩
//  :=
//  meaning that you have to pop a stack element.
// 𝐃𝐞𝐪𝐮𝐞𝐮𝐞
//  :=
//  meaning that you have to dequeue element from the queue at the stack's top and print that element. Note that if the queue becomes empty, then you must perform the 𝐏𝐨𝐩
//  operation. If the stack is empty then print -1
// .
// 𝐌𝐚𝐱𝐒𝐮𝐦𝐏𝐚𝐢𝐫𝐬
//  𝐊
//  :=
//  meaning that in the queue present at the stack's top, print the maximum number of consecutive pairs with sum atleast 𝐊
// . After printing, perform the 𝐏𝐨𝐩
//  operation.
// He is given to perform 𝐐
//  of the above operations mentioned above. Kirdah was unable to solve the problem in the interview. Can you help him solve the problem?

// Constraints:

// 1 ≤ 𝑄 ≤ 10^6
// 1 ≤ size of stack S, queues ≤ 10^6
// −10^9 ≤ 𝐾 ≤ 10^9
// Input
// The first line contains an integer 𝐐
// , denoting the number of operations to be perfomed. Each of the following 𝐐
//  lines contains any one of the operations given.

// Output
// Print the outputs corresponding to the operation if any.


// input
// 10
// Push 2
// Enqueue 1
// Enqueue 1
// MaxSumPairs 3
// Dequeue
// Dequeue
// Dequeue
// Push 1
// Pop
// Dequeue

// output
// 1
// -1
// -1
// -1
// -1