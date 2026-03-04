// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      struct ListNode original;
      original.next=head;
      struct ListNode* prev = &original;
      struct ListNode* current = head;
      //struct ListNode* next2 = current->next;

      while(current!=NULL && current->next!=NULL){
            struct ListNode* first = current;
            struct ListNode* second = current->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
            current = first->next;
      }

      return original.next;

}