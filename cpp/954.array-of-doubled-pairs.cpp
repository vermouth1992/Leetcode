/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 *
 * https://leetcode.com/problems/array-of-doubled-pairs/description/
 *
 * algorithms
 * Medium (34.93%)
 * Total Accepted:    50.8K
 * Total Submissions: 139.7K
 * Testcase Example:  '[3,1,3,6]'
 *
 * Given an integer array of even length arr, return true if it is possible to
 * reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i <
 * len(arr) / 2, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,1,3,6]
 * Output: false
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,1,2,6]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [4,-2,2,-4]
 * Output: true
 * Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4]
 * or [2,4,-2,-4].
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: arr = [1,2,4,16,8,4]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 3 * 10^4
 * arr.length is even.
 * -10^5 <= arr[i] <= 10^5
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        // sort the arr based on its absolute value
        std::sort(arr.begin(), arr.end(), [](const auto&lhs, const auto &rhs){
            return abs(lhs) < abs(rhs);
        });
        // a hashtable that map from number of a set of indexes
        std::unordered_map<int, std::queue<int>> num_to_idx;
        for (int i = 0; i < arr.size(); i++) {
            if (num_to_idx.find(arr.at(i)) == num_to_idx.end()) {
                num_to_idx[arr.at(i)] = std::queue<int>();
            }
            num_to_idx.at(arr.at(i)).push(i);
        }
        // traverse the array from left to right 
        std::vector<bool> selected(arr.size(), false);
        for (int i = 0; i < arr.size(); i++) {
            if (!selected.at(i)) {
                int two_x = 2 * arr.at(i);
                if (num_to_idx.find(two_x) == num_to_idx.end()) {
                    // can't find 2x
                    return false;
                } else {
                    int two_x_idx = num_to_idx.at(two_x).front();
                    num_to_idx.at(two_x).pop();
                    // mark it as selected
                    selected[i] = true;
                    selected[two_x_idx] = true;
                    if (num_to_idx.at(two_x).empty()) {
                        // remove the number
                        num_to_idx.erase(two_x);
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> arr {2, 1, 2, 1, 1, 1, 2, 2};
    std::cout << Solution().canReorderDoubled(arr) << std::endl;
}