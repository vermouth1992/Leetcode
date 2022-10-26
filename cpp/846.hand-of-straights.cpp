/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (55.66%)
 * Total Accepted:    104K
 * Total Submissions: 184.2K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has some number of cards and she wants to rearrange the cards into
 * groups so that each group is of size groupSize, and consists of groupSize
 * consecutive cards.
 * 
 * Given an integer array hand where hand[i] is the value written on the i^th
 * card and an integer groupSize, return true if she can rearrange the cards,
 * or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: hand = [1,2,3,4,5], groupSize = 4
 * Output: false
 * Explanation: Alice's hand can not be rearranged into groups of 4.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= hand.length <= 10^4
 * 0 <= hand[i] <= 10^9
 * 1 <= groupSize <= hand.length
 * 
 * 
 * 
 * Note: This question is the same as 1296:
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * 
 */

#include "common.hpp"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        std::map<int, int> hand_to_num; // map from value to the number of values
        for (auto &h : hand) {
            if (hand_to_num.find(h) == hand_to_num.end()) {
                hand_to_num[h] = 0;
            }
            hand_to_num[h] += 1;
        }
        for (int i = 0; i < hand.size() / groupSize; i++) {
            auto it = hand_to_num.begin();
            for (int j = 0; j < groupSize - 1; j++) {
                auto next = std::next(it);
                if (next == hand_to_num.end()) return false;

                if (next->first - it->first == 1) {
                    it->second -= 1;
                    if (it->second == 0) {
                        hand_to_num.erase(it);
                    }
                } else {
                    return false;
                }
                it = next;
                std::cout << it->first << " " << it->second << std::endl;
            }
            it->second -= 1;
            if (it->second == 0) {
                hand_to_num.erase(it);
            }
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
    std::vector<int> hand {0, 0};
    std::cout << Solution().isNStraightHand(hand, 2) << std::endl;
    return 0;
}

