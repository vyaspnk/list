//
//  linkedlist.h
//  list
//
//  Created by Vijetha Malla on 2/19/17.
//  Copyright © 2017 vy. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h
#include <vector>
using namespace std;
struct Node {
    int val;
    Node * next;
    Node(int x): val(x), next(NULL) {}
};

class Solution {
private:
    Node * head;
public:
    Solution() { head = nullptr; }
    Solution(vector<int>&);
    Solution(vector<int>&,bool loop);
    Node *getHead();
    void printList();
    vector<int> getListValues();
    vector<Node *> getList();
    Node * addNode(Node *head, int val);
    Node * deleteNode(Node *head, int val);
};
#endif /* linkedlist_h */
