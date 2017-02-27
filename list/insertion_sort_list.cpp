#include <iostream>
#include "algorithm"
using namespace std;
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      	int val;
     	ListNode *next;
      	//ListNode(int x) : val(x), next(NULL) {}
 };
void swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}
class Solution {
public:
    ListNode * InsertNodeInList(ListNode *head, ListNode *end,ListNode *tmp) {
        auto *prev = nullptr;
        ListNode *curr = head;
        while(curr!=end){
            if(curr->val >= tmp->val){
                if(curr == head){
                    tmp->next = head;
                    head = tmp;
                } else {
                    prev->next = tmp;
                    tmp->next = curr;
                }
                return head;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = tmp;
        tmp->next = end;
        return head;
    }
    
    ListNode* InsertionSortList(ListNode* head) {
        if(!head || head->next == NULL)
            return head;
        if(head->val > head->next->val)
            swap(head->val,head->next->val);
        ListNode *sorted = head->next;
        while(sorted->next){
            ListNode *unsorted = sorted->next;
            sorted->next = unsorted->next;
            head = InsertNodeInList(head,sorted->next,unsorted);
			if(sorted->next == unsorted)
            	sorted = sorted->next;
        }
        return head;
    }
};
		
