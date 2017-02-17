/**
 Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct less_than_start {
    inline bool operator()(const pair<int,int> &a, const pair<int,int>& b) {
        return a.first < b.first;
    }
};
void printVector(vector<pair<int, int>>& points) {
    for(auto mt: points) cout << "("<<mt.first<<","<<mt.second<<"), ";
    cout <<endl;
}
void printPriorityQ(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> & p){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  myp(p);
    for(int i=0;i<p.size();i++){
        cout << "("<<myp.top().first<<","<<myp.top().second << "), ";
        myp.pop();
    }
    cout << endl;
}

class Solution {
public:
    int add(vector<pair<int, int>>& bigballoons, int prev_index,const pair<int, int>& newballoon) {
        for(vector<pair<int, int>>::iterator i=bigballoons.begin()+prev_index;i!=bigballoons.end();i++){
            if(newballoon.first > i->second )
                continue;
            if(newballoon.second < i->first) {//insert at i
                bigballoons.insert(i, newballoon);
                return (int)(i - bigballoons.begin());
            }
        	//overlap case. replace i with bigger balloon
            i->first = std::max(newballoon.first, i->first);
            i->second = std::min(newballoon.second, i->second);
            return (int)(i - bigballoons.begin());
        }
        return (int)(bigballoons.insert(bigballoons.end(),newballoon) - bigballoons.begin());
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() <=1)
            return (int)points.size();
        std::sort(points.begin(), points.end(), less_than_start());
        vector<pair<int,int>> bigballoons;
        //vector<pair<int,int>>::iterator it = bigballoons.begin();
        int prev_index=0;
        vector<pair<int, int>>::iterator pt = points.begin();
        bigballoons.insert(bigballoons.begin(), *pt);
        pt++;
        do{
            //cout <<  "# " << pt->first << "," << pt->second << endl;
            prev_index = add(bigballoons,prev_index,*pt);
            pt++;
            printVector(bigballoons);

        }while(pt!=points.end());
        return (int)bigballoons.size();
    }
};

vector<pair<int, int>> balloons;
int main() {
    balloons.push_back(std::make_pair(1,2));
    balloons.push_back(std::make_pair(3,4));
    balloons.push_back(std::make_pair(5,6));
    balloons.push_back(std::make_pair(7,8));
    printVector(balloons);
    Solution s;
    cout << s.findMinArrowShots(balloons)<< endl;
    
    return 0;
}
