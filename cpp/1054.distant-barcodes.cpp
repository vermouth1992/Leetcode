/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 *
 * https://leetcode.com/problems/distant-barcodes/description/
 *
 * algorithms
 * Medium (44.48%)
 * Total Accepted:    33.6K
 * Total Submissions: 73.5K
 * Testcase Example:  '[1,1,1,2,2,2]'
 *
 * In a warehouse, there is a row of barcodes, where the i^th barcode is
 * barcodes[i].
 * 
 * Rearrange the barcodes so that no two adjacent barcodes are equal. You may
 * return any answer, and it is guaranteed an answer exists.
 * 
 * 
 * Example 1:
 * Input: barcodes = [1,1,1,2,2,2]
 * Output: [2,1,2,1,2,1]
 * Example 2:
 * Input: barcodes = [1,1,1,1,2,2,3,3]
 * Output: [1,3,1,3,1,2,1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= barcodes.length <= 10000
 * 1 <= barcodes[i] <= 10000
 * 
 * 
 */

#include "common.hpp"

class Solution {
    typedef pair<int, int> pd;
  
    // Structure of the condition
    // for sorting the pair by its
    // second elements
    struct myComp {
        constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
            const noexcept
        {
            if (a.second < b.second) return true;
            else if (a.second > b.second) return false;
            else return a.first < b.first;
        }
    };

public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        std::vector<int> output(barcodes.size());
        std::priority_queue<pd, vector<pd>, myComp> pq;
        
        // obtain count;
        std::map<int, int> count; // map from barcode to count
        for (auto &barcode : barcodes) {
            if (count.find(barcode) == count.end()) {
                count[barcode] = 0;
            }
            count[barcode] += 1;
        }
        // setup priority queue
        for (auto &it : count) {
            pq.push(it);
        }
        
        int index = 0;

        std::optional<pd> previous_top = std::nullopt;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            output[index] = top.first;
            top.second -= 1;

            index += 1;

            if (previous_top.has_value() && previous_top.value().second != 0) {
                pq.push(previous_top.value());
            }

            previous_top = top;
            
        }
        return output;
    }
};


int main() {
    std::vector<int> barcodes {1, 1, 1, 2, 2, 2};
    auto result = Solution().rearrangeBarcodes(barcodes);
    for (auto &a : result) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}