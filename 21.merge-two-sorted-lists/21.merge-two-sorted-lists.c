/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdlib.h>
#include<stdio.h>>

typedef struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    if(list1 == NULL) return list2;
    else if (list2 == NULL) return list1;
        else{
            struct ListNode* pp1 = NULL;
            while(p1 != NULL && p2 != NULL){
                if(p1->val > p2->val){
                    if(pp1 == NULL){
                       list1 = p2; 
                    }
                    else pp1->next = p2;
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
// @lc code=end

