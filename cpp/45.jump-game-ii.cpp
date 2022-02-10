/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (32.77%)
 * Total Accepted:    537.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * You can assume that you can always reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int current_location = 0;
        int current_first_location = 1;
        int steps = 0;
        while (current_location < nums.size()) {
            steps += 1;
            int next_max_location = nums[current_location] + current_location;
            if (next_max_location >= nums.size() - 1) break;
            // find the maximum one from current_location + 1 to next_max_location
            int current_max_location = current_location;
            int current_max_reachable_location = next_max_location;
            for (int j = current_first_location; j <= next_max_location; j++) {
                if (nums[j] + j > current_max_reachable_location) {
                    current_location = j;
                    current_max_reachable_location = nums[j] + j;
                }
            }
            current_first_location = next_max_location + 1;
        }
        return steps;
    }
};


int main() {
    std::vector<int> a {2, 3, 1, 1, 4};
    std::cout << Solution().jump(a);
    return 0;
}
