# 21. Merge Two Sorted Lists
## 题目
You are given the heads of two sorted linked lists list1 and list2.  
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.  
Return the head of the merged linked list.  
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

Example 1:  
Input: list1 = [1,2,4], list2 = [1,3,4]  
Output: [1,1,2,3,4,4]

Example 2:  
Input: list1 = [], list2 = []  
Output: []  

Example 3:  
Input: list1 = [], list2 = [0]  
Output: [0]  
 

Constraints:
- The number of nodes in both lists is in the range [0, 50].
- -100 <= Node.val <= 100
- Both list1 and list2 are sorted in non-decreasing order.  

提示：  
- 两个链表的节点数目范围是 [0, 50]
- -100 <= Node.val <= 100
- l1 和 l2 均按 非递减顺序 排列

## 题解
### First version 
#### 误区：
```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    if(list1 == NULL) return list2;
    else if (list2 == NULL) return list1;
        else{
            struct ListNode* p = NULL;
            struct ListNode* pp1 = NULL;
            if(p1->val > p2->val){
                list1 = p2;
                p = p2->next;
                p2->next = p1;
                pp1 = p2;
                p2 = p;
            }
            else{
                p = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                pp1 = p2;
                p2 = p;
                p1 = pp1->next;
            }
            while(p1 != NULL && p2 != NULL){
                if(p1->val > p2->val){
                    pp1->next = p2;
                    p = p2->next;
                    p2->next = p1;
                    pp1 = p2;
                    p2 = p;
                }
                else{
                    p = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    pp1 = p2;
                    p1 = pp1->next;
                    p2 = p;
                }
            }
            if(p2 != NULL){
                pp1->next = p2;
            }
        }
    return list1;
}
```
一开始的思维误区是比较两个结点数值大小，如果p1大于p2就放前面否则放后面。这种解法是错误的，因为如果p2比p1当前结点小，他是可能继续比p1下一个结点小的，所以在这种情况下我们暂时还不能确定他应该被放在哪里。
所以正确接发应该是一直向后判断知道p2的结点值比p1前结点一个小，比后一个结点大时，插入进两节点之间。

### Second version  
```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    if(list1 == NULL) return list2;
    else if (list2 == NULL) return list1;
        else{
            struct ListNode* p = NULL;
            struct ListNode* pp1 = NULL;
            if(p1->val > p2->val){
                list1 = p2;
                pp1 = p2;
                p2 = p2->next;
                pp1->next = p1;
            }
            else{
                pp1 = p1;
                p1 = p1->next;
            }
            while(p1 != NULL && p2 != NULL){
                if(p1->val > p2->val){
                    pp1->next = p2;
                    pp1 = p2;
                    p2 = p2->next;
                    pp1->next = p1;
                }
                else{
                    pp1 = p1;
                    p1 = p1->next;
                }
            }
            if(p2 != NULL){
                pp1->next = p2;
            }
        }
    return list1;
}
```
最后发现处理头结点和其他结点是重复代码较多，故又润色了现有版本


