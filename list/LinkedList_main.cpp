//
//  LinkedList_main.cpp
//  list
//
//  Created by Vyas on 2/19/17.
//  Copyright © 2017 vy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "linkedlist.h"
using namespace std;

Solution::Solution(vector<int> &V){
    if(V.size()==0)
        return;
    Node *head = new Node(V[0]);
    this->head = head;
    for(int i=1;i<V.size();i++) {
        head->next = new Node(V[i]);
        head = head->next; //TODO check for failure cases;
    }
}
Solution::Solution(vector<int> &V, bool loop=false) {
    if(V.size()==0)
        return;
    Node *head = new Node(V[0]);
    this->head = head;
    for(int i=1;i<V.size();i++) {
        head->next = new Node(V[i]);
        head = head->next; //TODO check for failure cases;
    }
    if(loop)
        head->next = this->head->next;
}
Node *
Solution::getHead(){
    return head;
}
void
Solution::printList() {
    Node *head = this->head;
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
vector<int>
Solution::getListValues(){
    vector<int> V;
    Node *head = this->head;
    while(head) {
        V.push_back(head->val);
        head = head->next;
    }
    return V;
}
vector<Node *>
Solution::getList() {
    vector<Node *> V;
    Node *head = this->head;
    while(head) {
        V.push_back(head);
        head = head->next;
    }
    return V;
}
Node *
Solution::addNode(Node *head, int val) {
    if(head == NULL) {
        head = new Node(val);
    	return head;
	}
    auto *curr = head;
    while(curr->next) curr = curr->next;
    curr->next = new Node(val);
    return head;
}
Node *
Solution::deleteNode(Node *head, int val) {
    if(!head)
        return head;
    if(head->val == val) {
        auto t = head->next;
        free(head);
        return t;
    }
    auto curr = head;
    while(curr->next) {
        if(curr->next->val == val) {
            auto tmp = curr->next;
            curr->next = tmp->next;
            free(tmp);
            break;
        }
        curr = curr->next;
    }
    return head;
}
