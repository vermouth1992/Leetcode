/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.73%)
 * Total Accepted:    642.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            std::map<int, int> left;
            std::vector<bool> used(nums.size(), false);
            int sum = -nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (left.find(nums[j]) != left.end()) {
                    // find the left over
                    int index = left[nums[j]];
                    if (!used.at(index)) {
                        vector<int> temp {nums[i], nums[index], nums[j]};
                        result.push_back(temp);
                        used.at(index) = true;
                    }
                } else {
                    left[sum - nums[j]] = j;
                }
            }
        }
        return result;
    }
};
