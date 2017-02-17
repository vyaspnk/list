//
//  MergeSortList.cpp
//  list
//
//  Created by Vyas on 2/15/17.
//  Copyright © 2017 vy. All rights reserved.
//

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
int SizeofList(ListNode *head, ListNode *tail) {
    int cnt=0;
    while(head!=tail) { head = head->next; cnt++; }
    return cnt;
}
class Solution {
public:
    int SizeOfList(ListNode *head){
        int s=0;
        while(head) { s++; head = head->next; }
        return s;
    }
    ListNode *MergeSortList(ListNode *l1, ListNode *l2,int l2_size){ //l1 and l2 are sorted lists;
        ListNode *head = l1;
        while(l1 && l2 && l2_size) {
            if(l1->val > l2->val)
                swap(l1->val,l2->val);
            else {
                if(l1->next) {
                    l1 = l1->next;
                    continue;
                }
                else {
                    l1->next = l2;
                    break;
                }

        	}
            if(l2_size==1 && l1->next == l2)
                return head;
            ListNode *tmp = l2->next;
            l2->next = l1->next;
            l1->next = l2;
            l2 = tmp;
            l2_size--;
            if(l1->next)
            	l1 = l1->next;
            else {
                l1->next = l2;
                break;
            }
                
        }
        
        return head;
    }
    ListNode* SortList(ListNode *head){
        int listsize = SizeofList(head,NULL);
        int sortsize=1;
        while(sortsize<=listsize){
            ListNode *l1 = head;
            while(l1){
                ListNode *l2 = l1;
                int l2_size=0;
                int cnt = sortsize;
                while( cnt--) { if(!l2) break; l2 = l2->next; l2_size++; };
                if(l2) {
                	ListNode *tmp = l2->next;
                	MergeSortList(l1,l2,l2_size);
                    l1 = tmp;
                } else
                    break;
            }
            sortsize*=2;
            l1 = head;
        }
        
        return head;
    }
};
void printList(ListNode *head){
    while(head) { cout << head->val <<" "; head = head->next; }
    cout << endl;
}
int main(){
    ListNode test1[6] = {
        {1,&test1[1]},
        {4,&test1[2]},
        {5,&test1[3]},
        {7,&test1[4]},
        {8,&test1[5]},
        {9,NULL}
    };
    ListNode test2[6] = {
        {0,&test2[1]},
        {2,&test2[2]},
        {3,&test2[3]},
        {4,&test2[4]},
        {6,&test2[5]},
        {10,NULL}
    };
    ListNode test3[12] = {
        {1,&test3[1]},
        {8,&test3[2]},
        {3,&test3[3]},
        {7,&test3[4]},
        {8,&test3[5]},
        {9,&test3[6]},
        {0,&test2[7]},
        {2,&test3[8]},
        {3,&test3[9]},
        {4,&test3[10]},
        {6,&test3[11]},
        {10,NULL}
    };
    Solution S;
    ListNode *l1 = &test3[0];//, *l2 =&test2[0];
    printList(&test3[0]);
    //printList(l2);
    S.MergeSortList(&test3[0],&test3[2],2);//l1,l2,1);//SizeofList(l2, NULL));
    //S.SortList(l1);
    printList(&test3[0]);
}
