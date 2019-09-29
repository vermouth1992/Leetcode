/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.58%)
 * Total Accepted:    413.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

#include <vector>
#include <algorithm>

using namespace std;

struct IntervalComparator {
    inline bool operator() (const vector<int>& interval1, const vector<int>& interval2)
    {
        return (interval1[0] < interval2[0]);
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.empty() || intervals.size() == 1) return intervals;

        vector<vector<int>> result;
        // 1. sort the interval based on the first element O(nlogn)
        std::sort(intervals.begin(), intervals.end(), IntervalComparator());
        // 2. merge from left to right in place. O(n)
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                if (intervals[i][1] > result.back()[1]) {
                    result.back()[1] = intervals[i][1];
                }
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
