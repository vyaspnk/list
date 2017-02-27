//
//  main.cpp
//  list
//
//  Created by Vijetha Malla on 2/19/17.
//  Copyright © 2017 vy. All rights reserved.
//

#include "iostream"
#include "stdlib.h"
#include "algorithm"
#include "linkedlist.h"
#include <vector>
using namespace std;
int main() {
    vector<int> V = {1,3,5,7,8};
    cout << "List: ";
    Solution s(V);
    s.printList();
    cout << "Adding node 0";
    s.addNode(s.getHead(), 0);
    cout << endl;
    s.printList();
    s.deleteNode(s.getHead(), 3);
    s.printList();
    s.deleteNode(s.getHead(), 1);
    s.printList();
    s.deleteNode(s.getHead(), 0);
    s.printList();

    return 0;
}
    
