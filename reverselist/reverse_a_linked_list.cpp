/**
 * Definition for singly-linked list.*/
#include <iostream>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
  		if(!head || !head->next) return head;  		
  		ListNode* prev = NULL, *next = head->next;
  		while(head){
  			head->next = prev;
  			prev = head;
  			head = next;
  			if(next)
  				next = next->next;
  		}
  		return prev;
    }
};

void  printList(ListNode *head) {
    while(head){
        cout << head->val <<  " ";
        head = head->next;
    }
        cout << endl;
}
        
int main()
{
  ListNode one(1),two(2),three(3);  
  one.next = &two;
  two.next = &three;
  Solution s;
    ListNode *head = &one;
    printList(head);
  head = s.reverseList(&one);
    printList(head);

}
