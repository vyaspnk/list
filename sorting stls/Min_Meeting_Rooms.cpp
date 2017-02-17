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
    inline bool operator()(const Interval &a, const Interval& b) {
        return a.start < b.start;
    }
};
void printVector(vector<Interval>& intervals) {
    for(auto mt: intervals) cout << "("<<mt.start<<","<<mt.end<<"), ";
    cout <<endl;
}
void printPriorityQ(std::priority_queue<int,vector<int>,greater<int>> & p){
    priority_queue<int,vector<int>,greater<int>>  myp(p);
    for(int i=0;i<p.size();i++){
        cout << myp.top() << " ";
        myp.pop();
    }
    cout << endl;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size()==0)
            return 0;
        std::sort(intervals.begin(),intervals.end(),less_than_start());
        std::priority_queue<int,vector<int>,greater<int>> mypq;
        mypq.push(intervals[0].end);
        for(vector<Interval>::iterator mt = intervals.begin()+1; mt!=intervals.end();mt++){
            if(mypq.top() <= mt->start){
                mypq.pop();
            }
            mypq.push(mt->end);
            }

        return (int)mypq.size();
    }
};

vector<Interval> intervals;
int main() {
    intervals.push_back(Interval(9,10));
    intervals.push_back(Interval(4,9));
    
    intervals.push_back(Interval(4,17));
    printVector(intervals);
    Solution s;
    cout << s.minMeetingRooms(intervals)<< endl;
    printVector(intervals);

    return 0;
}
