//
//  search_rotated_array.cpp
//  list
//
//  Created by Vijetha Malla on 2/14/17.
//  Copyright © 2017 vy. All rights reserved.
//


#include <iostream>
#include <algorithm>
using namespace std;

//int arr[] = 	{2,3,4,5,6,7,8,1};
int arr_rev[] = {2,3,4,5,6,7,8,9,1};
#define CHECK(p) {\
			if(arr[p] < arr[p-1]) \
			return arr[p];\
		}
void printarray(int arr[],int size){
    for(int i = 0;i<size;i++)
        cout << arr[i] << " ";
    cout << endl;
}
int min_in_rotated_array(int arr[8]){
    printarray(arr,8);
    int b = 0;
    int e = 7;//(sizeof(arr)/sizeof(int))-1;
    if(arr[b] < arr[e])
        return arr[b];
    
    int p = (e - b)/2;

    do {
        if( e-b<=1)
            return std::min(arr[e],arr[b]);
        p = b + (e - b)/2;
        CHECK(p);
        if(arr[p] < arr[b]) {//search in left half;
            e = p;
        } else { //search right half
            b = p;
        }
    }while(p>0);
    return arr[p];
}

int test_vector[7][8] = {
    {0},
    {1,2,3,4,5,7,8,9},
    {3,4,5,6,7,9,1,2},
    {4,5,6,7,9,1,2,3},
    {8,9,1,2,4,5,6,7},
    {9,1,2,3,5,6,7,8},
    {6,7,8,9,2,3,4,5}
};

int main1(){
    
    for(int i = 0; i< 7;i++)
    	cout << min_in_rotated_array(test_vector[i])<<endl;
    return 0;
}
