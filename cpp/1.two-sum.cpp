/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.52%)
 * Total Accepted:    2.1M
 * Total Submissions: 4.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

#include<vector>
#include<map>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map from conterpart to index
        std::map<int, int> conterpart;
        for (int i = 0; i < nums.size(); ++i) {
            if (conterpart.find(nums[i]) != conterpart.end()) {
                return vector<int>({conterpart[nums[i]], i});
            } else {
                conterpart[target - nums[i]] = i;
            }
        }
        return vector<int>();
    }
};

int main() {
    vector<int> a = {3, 2, 4};
    auto result = Solution().twoSum(a, 6);
    std::cout << result[0] << " " << result[1] << std::endl;
}
