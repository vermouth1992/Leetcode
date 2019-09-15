/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 *
 * https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
 *
 * algorithms
 * Medium (35.54%)
 * Total Accepted:    16.3K
 * Total Submissions: 45.8K
 * Testcase Example:  '[1,3,5,4]\n[1,2,3,7]'
 *
 * We have two integer sequences A and B of the same non-zero length.
 * 
 * We are allowed to swap elements A[i] and B[i].  Note that both elements are
 * in the same index position in their respective sequences.
 * 
 * At the end of some number of swaps, A and B are both strictly increasing.
 * (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... <
 * A[A.length - 1].)
 * 
 * Given A and B, return the minimum number of swaps to make both sequences
 * strictly increasing.  It is guaranteed that the given input always makes it
 * possible.
 * 
 * 
 * Example:
 * Input: A = [1,3,5,4], B = [1,2,3,7]
 * Output: 1
 * Explanation: 
 * Swap A[3] and B[3].  Then the sequences are:
 * A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
 * which are both strictly increasing.
 * 
 * 
 * Note:
 * 
 * 
 * A, B are arrays with the same length, and that length will be in the range
 * [1, 1000].
 * A[i], B[i] are integer values in the range [0, 2000].
 * 
 * 
 */

#include<vector>
#include<iostream>
#include<climits>

using namespace std;

class Solution {

public:
    int minSwap(vector<int>& A, vector<int>& B) {
        if (A.size() <= 1) return 0;

        int minSwapCurrentIndexDoNotSwap = 0;
        int minSwapCurrentIndexSwap = 1;   // assume index at 0 already swaped

        for (int i = 1; i < A.size(); ++i) {
            // must be swaped
            int swapSwap = INT_MAX;
            int swapNotSwap = INT_MAX;
            int notSwapSwap = INT_MAX;
            int notSwapNotSwap = INT_MAX;

            // must swap
            if (A[i] <= A[i - 1] || B[i] <= B[i - 1]) {
                swapNotSwap = minSwapCurrentIndexSwap;
                notSwapSwap = minSwapCurrentIndexDoNotSwap + 1;
            } else {
                // can't swap
                if (A[i] <= B[i - 1] || B[i] <= A[i - 1]) {
                    swapSwap = minSwapCurrentIndexSwap + 1;
                    notSwapNotSwap = minSwapCurrentIndexDoNotSwap;
                } else {
                    // can swap
                    swapSwap = minSwapCurrentIndexSwap + 1;
                    swapNotSwap = minSwapCurrentIndexSwap;
                    notSwapNotSwap = minSwapCurrentIndexDoNotSwap;
                    notSwapSwap = minSwapCurrentIndexDoNotSwap + 1;
                }
            }
            minSwapCurrentIndexDoNotSwap = std::min(swapNotSwap, notSwapNotSwap);
            minSwapCurrentIndexSwap = std::min(swapSwap, notSwapSwap);
        }
        return std::min(minSwapCurrentIndexDoNotSwap, minSwapCurrentIndexSwap);
    }
};


int main() {
    std::vector<int> a = {1, 3, 5, 4};
    std::vector<int> b = {1, 2, 3, 7};
    std::cout << Solution().minSwap(a, b) << std::endl;
}