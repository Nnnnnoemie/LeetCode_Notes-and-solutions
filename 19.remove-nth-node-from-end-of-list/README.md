# 19.Remove Nth Node From End of List
## 题目
Given the head of a linked list, remove the nth node from the end of the list and return its head.  
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

Example 1:
Input: head = [1,2,3,4,5], n = 2  
Output: [1,2,3,5] 

Example 2:  
Input: head = [1], n = 1  
Output: []  

Example 3:  
Input: head = [1,2], n = 1  
Output: [1]  
 
Constraints:
- The number of nodes in the list is sz.  
- 1 <= sz <= 30  
- 0 <= Node.val <= 100  
- 1 <= n <= sz  
提示：
- 链表中结点的数目为 sz  
- 1 <= sz <= 30  
- 0 <= Node.val <= 100  
- 1 <= n <= sz  
 
Follow up: Could you do this in one pass?  
进阶：你能尝试使用一趟扫描实现吗？

## 题解
我直接写了一次遍历输出结果的版本。  
### 1. 思路：
因为是倒数第n个结点，所以我考虑了用递归方法将倒数和删去结点一起完成，实现了一次遍历。

### 2. 遇到的问题 : 
* 如何跳出递归？  
使用return只能结束当前一次循环返回上一级函数，而无法直接跳出循环。使用exit()是退出整个程序（包括主函数）。在这种情况下我们可以**通过设置一个flag或者通过函数的返回值来告诉函数可以直接返回上一级而不做任何事了**。  
因为我的函数本身就在返回int（倒数顺序）没到达倒数第n项时，返回值一定是正数，所以我选择在找到对应项时直接返回0.而函数也会在判断返回值为0时 直接继续向上返回0而不进行其他操作。

* 释放空间！  
因为本题涉及删除链表结点，所以**在删除结点之前要先释放指针所指向的内存空间**。

* 编译报错：Line 20: Char 22: runtime error: member access within null pointer of type 'struct ListNode' [solution.c]  
出现该报错是因为我们在删除结点的时候会直接使用以下代码
```C
p1->next = p2->next;
```
但忘记考虑了一种情况就是sz == n的情况！！！
**当sz == n时，p1 == NULL**，所以如果我们尝试执行上述代码时其实是在执行
```c
NULL->next = p2->next
```
故会出现报错

### 3.总结
* 使用递归的好处：除了可以**同时赋值不需要考虑顺序**以外 还可以**反向起点操作**，在单向链表中十分重要。例如这道题：用普通循环实现是从链表头结点开始，使用递归是从中止条件逆回，也就是从尾结点开始，如此便可直接倒数结点数了。

## 运行结果
![alt result](./../result_screenshoot/19.remove-nth-node-from-end-of-list.png)
