//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//Example 2:
//
//Input: [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considerred overlapping.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs) {
            return lhs.end < rhs.end;
        });
        vector<Interval> ans;
        int n = intervals.size();
        if (n == 0)
            return ans;
        n = n - 1;
        Interval last = intervals[n--];
        
        while(n >= 0) {
            Interval cur = intervals[n--];
            if (last.start > cur.end) {
                ans.push_back(last);
                last = cur;
            }
            else if (last.start <= cur.end && last.start >= cur.start) {
                last.start = cur.start;
            }
        }
        ans.push_back(last);
        reverse(ans.begin(), ans.end());
        return ans;
    }

};
