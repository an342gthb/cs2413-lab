// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next2 = NULL;

    while(current!=NULL){
        next2=current->next;
        current->next = prev;
        prev = current;
        current = next2;
    }

    return prev;
    // TODO: implement
    // Hints (optional):
    // - Keep track of previous and current pointers.
    // - Iterate until current becomes NULL.

}