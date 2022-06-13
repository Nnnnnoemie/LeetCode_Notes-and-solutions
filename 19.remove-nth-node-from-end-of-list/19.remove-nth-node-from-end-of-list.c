/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
};

int removeNode(struct ListNode* p1, struct ListNode* p2, int n){
    if(p2->next == NULL){
        if(n == 1){
            p1->next = NULL;
            free(p2);
            return 0；
        }
        return 1;
    }
    else{
        int i = removeNode(p2, p2->next,n);
        if(i==0) return 0;
        if ((i+1) == n){
            if(p1 == NULL){
                return -1;
            }
            else{
                p1->next = p2->next;
                free(p2);
                return 0;
            }
        }
        return i+1;
    }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head->next == NULL){
        if(n == 1){
            free(head);
            return NULL;
        }
        else{
            printf("Error !");
            return 0;
        }
    }
    else{
        int i = removeNode(NULL, head, n);
        if(i == -1){
            return head->next;
            free(head);
        }
        else{
           return head; 
        }
    }
}

int main(){
    struct ListNode* p1;
    struct ListNode* p2;
    p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1->val = 9;
    p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1->next->val = 9;
    p1->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1->next->next->val = 1;
    p1->next->next->next = NULL;
    struct ListNode* p;
    p=removeNthFromEnd(p1, 2);
    do{
        printf("%d", p->val);
        p=p->next;
    }while (p != NULL);
    return 0;
}
// @lc code=end

