//
//  search_rotated_array.cpp
//  list
//
//  Created by Vijetha Malla on 2/14/17.
//  Copyright © 2017 vy. All rights reserved.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define CHECK(p,target) {\
	if(p == target) \
		return true;\
}
#define CHECK_NOT_ROTATED(b,e,t) ((b<=t && t<=e) || (b>=t && t>=e))
void printarray1(int arr[],int size){
    for(int i = 0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
}
bool binarysearch(vector<int>& nums, int target, int begin, int end) {
    return false;
}
bool search_in_rotated_array(vector<int> &nums,int target){
    if(nums.size() == 0)
        return false;
    else if(nums.size()==1){
        return (nums[0] == target)?true:false;
    }
    
    for(int b = 0, e = nums.size()-1,m = (e-b)/2;; m = b+(e-b)/2) {
        CHECK(nums[m],target);
        if(CHECK_NOT_ROTATED(nums[b],nums[e],target)) // not rotated;
            return binarysearch(nums,target,b,e);
        if(nums[b]>=target && target<= nums[e]){
            
        } else {
            
        }
    }
    
    
    return false;
}

int test_vector1[7][9] = {
    {0},
    {9,1,2,3,4,5,6,7,8},
    {3,4,5,6,7,8,9,1,2},
    {4,5,6,7,8,9,1,2,3},
    {8,9,1,2,3,4,5,6,7},
    {9,1,2,3,4,5,6,7,8},
    {6,7,8,9,1,2,3,4,5}
};
int target = 1;
int main(){
    
    for(int i = 0; i< 7;i++){
        vector<int> test(9);
        for(int j=0;j<9;j++){
            test.push_back(test_vector1[i][j]);
        }
        cout << (search_in_rotated_array(test,target)?"Preset":"Absent" )<< endl;
    }
    return 0;
}
