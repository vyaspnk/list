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
#include <set>
using namespace std;
struct less_than_start {
    inline bool operator()(const Interval &a, const Interval& b){
        return a.start < b.start;
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)
            return true;
        std::sort(intervals.begin(),intervals.end(),less_than_start());
        for(auto mt = intervals.begin(); (mt+1)!=intervals.end();mt++){
            if(mt->end > (mt+1)->start)
                return false;
        }
        return true;
    }
};
int main() {
    vector<Interval> intervals(3);

    intervals.push_back(Interval(15,20));
    intervals.push_back(Interval(25,30));

    intervals.push_back(Interval(10,16));
    Solution s;
    cout << (s.canAttendMeetings(intervals)?"Yes":"No") << endl;
    return 0;
}
