# 2.Add Two Numbers | 两数相加
## 题目
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.  

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

Example 1:  
```
Input: l1 = [2,4,3], l2 = [5,6,4]  
Output: [7,0,8]  
Explanation: 342 + 465 = 807.  
```

Example 2:  
```
Input: l1 = [0], l2 = [0]  
Output: [0]  
```

Example 3:  
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]  
Output: [8,9,9,9,0,0,0,1]  
```
 
Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9  
It is guaranteed that the list represents a number that does not have leading zeros.  

提示：

- 每个链表中的节点数在范围 [1, 100] 内  
- 0 <= Node.val <= 9  
- 题目数据保证列表表示的数字不含前导零  

## I. First version
### 1. 编译报错
写完了第一版的代码可以在自己的电脑上编译运行，但在leetcode网站上有报错。

* 错误代码：runtime error: member access within misaligned address 0xbebebebebebebebe for type 'struct ListNode', which requires 8 byte alignment [ListNode.c]
0xbebebebebebebebe: note: pointer points here
\<memory cannot be printed>  

经过上网查询后发现是因为我们在访问的某个变量中有<font color="red"><u>**定义但未赋值的指针**</u></font>，也就是野指针(Wild Pointer)。野指针指向的位置是不可知的（随机的，不正确的，没有明确限制的），这种指针对程序有不可知的后果，如果被引用可能会出现严重的问题，所以应严格注意<font color="red"><u>**不应有野指针的存在**</u></font>。  

* 解决办法：
例如下面的代码用malloc申请了一块内存空间给p3，但没有对p3->next的指针赋初始值，就会导致在编译时出现上述报错
```C
struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
```
若给这段代码加上
```C
p3->next = NULL;
```
即可解决该问题。  

* 总结：
<font color="red"><u>**指针在要使用时再使用malloc申请空间，申请后要将其中含有的定义未赋值的指针赋值或设为NULL。**</u></font>

### 2. 进位问题
我定义了一个变量flag用来记录两数相加是否有进位。需要注意的是如果p1->next和p2->next都为NULL时，<font color="red"><u>**如果flag=1 仍然需要为p3再加一个节点**</u></font>，此时该节点的val一定等于1
