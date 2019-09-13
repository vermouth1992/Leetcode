// Example:
// Input: A = [1,3,5,4], B = [1,2,3,7]
// Output: 1
// Explanation: 
// Swap A[3] and B[3].  Then the sequences are:
// A = [1, 3, 5, 7] and B = [1, 2, 3, 4]
// which are both strictly increasing.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        if (A.size() <= 1) return 0;
        // initialize table
        vector<int> optimal(A.size());
        optimal[0] = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                optimal[i] = optimal[i - 1];
            } else {
                
            }
        }
    }
};

int main() {
    // [0,1,4,6,8]
    // [1,2,2,7,10]
    vector<int> a = {0, 1, 4, 6, 8};
    vector<int> b = {1, 2, 2, 7, 10};
    cout << Solution().minSwap(a, b) << endl;
    return 0;
}