/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (50.28%)
 * Total Accepted:    480.1K
 * Total Submissions: 943.7K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        this->helper(result, curr, nums, visited);
        return result;
    }

private:
    void helper(vector<vector<int>> &result, vector<int> &curr, vector<int>& nums, vector<bool> &visited) {
        if (curr.size() == nums.size()) {
            result.push_back(vector(curr));
            return;
        }
        size_t i = 0;
        
        while (i < nums.size())
        {
            if (visited[i]) {
                i += 1;
                continue;
            }
            curr.push_back(nums[i]);
            visited[i] = true;
            this->helper(result, curr, nums, visited);
            curr.pop_back();
            visited[i] = false;
            // can't choose the same number in the same location
            size_t j = i + 1;
            while (j < nums.size())
            {
                if (nums[j] != nums[i]) break;
                else j += 1;
            }
            i = j;
        }
    }
};
