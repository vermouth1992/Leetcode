/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (49.52%)
 * Total Accepted:    362.7K
 * Total Submissions: 725.1K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 * 
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 */


/* This is equivalent to permutation without duplicates with size 0, 1, 2, ... n
*/

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (size_t k = 0; k <= nums.size(); k++)
        {
            vector<int> curr;
            this->helper(result, curr, 0, k, nums);
        }
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, int startIndex, int leftNum, vector<int>& nums) {
        if (leftNum == 0) {
            result.push_back(vector(curr));
            return;
        }
        int i = startIndex;
        while (i < nums.size())
        {
            curr.push_back(nums[i]);
            this->helper(result, curr, i + 1, leftNum - 1, nums);
            curr.pop_back();

            int j = i + 1;
            while (j < nums.size())
            {
                if (nums[j] != nums[i]) break;
                else j += 1;
            }
            i = j;            
        }
        
    }
};
