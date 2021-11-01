/*
 * @lc app=leetcode id=1654 lang=cpp
 *
 * [1654] Minimum Jumps to Reach Home
 *
 * https://leetcode.com/problems/minimum-jumps-to-reach-home/description/
 *
 * algorithms
 * Medium (24.58%)
 * Total Accepted:    14.4K
 * Total Submissions: 56.5K
 * Testcase Example:  '[14,4,18,1,15]\n3\n15\n9'
 *
 * A certain bug's home is on the x-axis at position x. Help them get there
 * from position 0.
 * 
 * The bug jumps according to the following rules:
 * 
 * 
 * It can jump exactly a positions forward (to the right).
 * It can jump exactly b positions backward (to the left).
 * It cannot jump backward twice in a row.
 * It cannot jump to any forbidden positions.
 * 
 * 
 * The bug may jump forward beyond its home, but it cannot jump to positions
 * numbered with negative integers.
 * 
 * Given an array of integers forbidden, where forbidden[i] means that the bug
 * cannot jump to the position forbidden[i], and integers a, b, and x, return
 * the minimum number of jumps needed for the bug to reach its home. If there
 * is no possible sequence of jumps that lands the bug on position x, return
 * -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
 * Output: 3
 * Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
 * Output: 2
 * Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7)
 * will get the bug home.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= forbidden.length <= 1000
 * 1 <= a, b, forbidden[i] <= 2000
 * 0 <= x <= 2000
 * All the elements in forbidden are distinct.
 * Position x is not forbidden.
 * 
 * 
 */

#include "common.hpp"

class Solution {
    typedef std::pair<int, bool> State;
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // bfs
        int steps = 0;
        std::queue<State> frontier;
        std::queue<State> frontier2;

        std::queue<State> *current_frontier = &frontier;
        std::queue<State> *next_frontier = &frontier2;

        std::set<State> explored;

        for (auto &pos : forbidden) {
            explored.insert(std::make_pair(pos, true));
            explored.insert(std::make_pair(pos, false));
        }


        frontier.push(std::make_pair(0, false));

        int max_forbidden = *std::max_element(forbidden.begin(), forbidden.end());
        max_forbidden = std::max(max_forbidden, x);

        while (true) {
            while (!current_frontier->empty()) {
                auto top = current_frontier->front();
                current_frontier->pop();

                if (explored.find(top) != explored.end()) continue;

                explored.insert(top);
                auto pos = get_pos(top);

                std::cout << pos << std::endl;

                if (pos == x) return steps;
                // otherwise push the next possible positions
                // move forward
                auto forward_state = std::make_pair(pos + a, false);
                // we can't always move forward. It must be smaller than max(forbidden) + b
                if (pos + a <= max_forbidden + b + a) {
                    next_frontier->push(forward_state);
                }
                
                
                // move backward
                if (backward_available(top) && pos - b >= 0) {
                    auto backward_state = std::make_pair(pos - b, true);
                    next_frontier->push(backward_state);
                }
            }
            steps += 1;
            if (next_frontier->empty()) return -1; // end of path
            // swap frontier pointer
            auto temp = current_frontier;
            current_frontier = next_frontier;
            next_frontier = temp;
        }
        // not reachable
        return -1;
    }

private:
    int get_pos(const State &s) {
        return s.first;
    }

    bool backward_available(const State &s) {
        return !s.second;
    }
};


int main(int argc, char const *argv[]) {
    std::vector<int> a {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    std::cout << Solution().minimumJumps(a, 29, 98, 80);
    return 0;
}
