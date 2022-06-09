/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}; 

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p3->next = NULL;
    struct ListNode* p = p3;
    int flag=0;
    int result;
    result=p1->val+p2->val;
    if(result>9){
        flag = 1;
        p->val=result%10;
    }
    else{
        p->val = result;
    }
    while(p1->next != NULL){
        p1=p1->next;
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->next = NULL;
        if(p2->next != NULL){
            p2=p2->next;
            if(flag){
                result = p1->val+p2->val+1;
                flag=0;
                }
            else{
                result = p1->val+p2->val;
            }
            if(result>9){
                flag = 1;
                p->val = result%10;
            }
            else{
                p->val = result;
            }
        }
        else{
            if(flag){
                result = p1->val+1;
                flag = 0;
            }
            else{
                result = p1->val;
            }
            if(result>9){
                flag=1;
                p->val = result%10;
            }
            else{
                p->val=result;
            }
        }
    }
    while(p2->next != NULL){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p=p->next;
        p->next = NULL;
        p2=p2->next;
        if(flag){
            result = p2->val+1;
            flag = 0;
        }
        else{
            result = p2->val;
        }
        if(result>9){
            flag=1;
            p->val = result%10;
        }
        else{
            p->val=result;
        }
    }
    if(flag){
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = 1;
        p->next = NULL;
    }
    return p3;
}

int main(){
    struct ListNode* p1;
    struct ListNode* p2;
    p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1->val = 9;
    p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    p1->next->val = 9;
    p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p2->val = 1;
    struct ListNode* p3;
    p3 = addTwoNumbers(p1, p2);
    struct ListNode* p;
    p=p3;
    do{
        printf("%d", p->val);
        p=p->next;
    }while (p != NULL);
    return 0;
}