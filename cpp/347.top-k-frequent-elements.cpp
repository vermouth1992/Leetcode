/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (56.51%)
 * Total Accepted:    249.6K
 * Total Submissions: 439.9K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */

#include "common.hpp"

class Solution {
private:
    struct pair_greater {
        bool operator()(const std::pair<int, size_t>& pair1, const std::pair<int, size_t>& pair2) {
            return pair1.second > pair2.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a hash map from n -> frequent O(n)
        std::unordered_map<int, size_t> numToFreq;
        for (auto num : nums) {
            if (numToFreq.find(num) == numToFreq.end()) {
                numToFreq[num] = 0;
            }
            numToFreq[num] += 1;
        }
        // push <n, freq> pair to the priority queue
        std::priority_queue<std::pair<int, size_t>, vector<std::pair<int, size_t>>, pair_greater> minPQ;

        size_t PQSize = 0;
        for (auto it = numToFreq.begin(); it != numToFreq.end(); ++it) {
            if (PQSize < k) {
                minPQ.push(std::make_pair(it->first, it->second));
                PQSize += 1;
            } else {
                minPQ.push(std::make_pair(it->first, it->second));
                minPQ.pop();
            }
        }
        vector<int> result;
        while (!minPQ.empty())
        {
            result.push_back(minPQ.top().first);
            minPQ.pop();
        }
        return result;
    }
};
