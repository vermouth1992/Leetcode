/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (64.10%)
 * Total Accepted:    201K
 * Total Submissions: 320.3K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 * 
 * 
 */

#include "common.hpp"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int method = 2;
        if (method == 0) {
            // quick sort doesn't work for edge cases O(N^2)
            return quickSort(nums);
        } else if (method == 1) {
            return mergeSort(nums);
        } else {
            return heapSort(nums);
        }
    }

private:
    vector<int> quickSort(vector<int>& nums) {
        // find position for the pivot, then sort left and right
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSortHelper(vector<int> &nums, int left, int right) {
        if (left < right) {
            int pos = this->partition(nums, left, right);
            quickSortHelper(nums, left, pos - 1);
            quickSortHelper(nums, pos + 1, right);
        }
    }

    int partition(vector<int> &nums, int left, int right) {
        // move nums[right] to the correct position
        int pivot_pos = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < nums[right]) {
                if (i != pivot_pos) {
                    std::swap(nums[pivot_pos], nums[i]);
                }
                pivot_pos += 1;
            }
        }
        std::swap(nums[pivot_pos], nums[right]);
        return pivot_pos;
    }

    vector<int> mergeSort(vector<int> &nums) {
        return this->mergeSortHelper(nums, 0, nums.size());
    }

    vector<int> mergeSortHelper(vector<int> &nums, int left, int right) {
        if (right - left == 1) return std::vector<int> {nums[left]};
        if (right - left == 2) {
            if (nums[left] > nums[right - 1]) {
                return std::vector<int> {nums[right - 1], nums[left]};
            } else {
                return std::vector<int> {nums[left], nums[right - 1]};
            }
        }
        int mid = (left + right) / 2;
        // sort left portion [left, mid)
        auto left_result = mergeSortHelper(nums, left, mid);
        // sort right portion [mid, right)
        auto right_result = mergeSortHelper(nums, mid, right);
        // merge
        std::vector<int> result;
        int left_index = 0;
        int right_index = 0;
        while (left_index < left_result.size() && right_index < right_result.size()) {
            if (left_result.at(left_index) < right_result.at(right_index)) {
                result.push_back(left_result.at(left_index));
                left_index += 1;
            } else {
                result.push_back(right_result.at(right_index));
                right_index += 1;
            }
        }
        // push the reset
        for (int i = left_index; i < left_result.size(); i++) {
            result.push_back(left_result.at(i));
        }
        for (int i = right_index; i < right_result.size(); i++) {
            result.push_back(right_result.at(i));
        }
        return result;
    }

    vector<int> heapSort(vector<int> &nums) {
        // heapification of the num as max heap. remove the maximum one by one
        for (int root = get_parent(nums.size() - 1); root >= 0; root--) {
            heapify(nums, root, nums.size());
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            // swap the first and the i-th
            std::swap(nums[i], nums[0]);
            // perform pop down to rebuild the heap
            heapify(nums, 0, i);
        }
        return nums;
    }

    inline int get_left(int index) {
        return index * 2 + 1;
    }

    inline int get_right(int index) {
        return index * 2 + 2;
    }

    inline int get_parent(int index) {
        return (index - 1) / 2;
    }

    void heapify(vector<int> &nums, int root, int last_item) {
        // perform heapify from root to last_item
        int current_index = root;
        int i = last_item;
        while (true) {
            int left_child = get_left(current_index);
            int right_child = get_right(current_index);
            if (left_child >= i) break;
            if (right_child >= i) {
                // only compare with left
                if (nums[current_index] < nums[left_child]) {
                    std::swap(nums[current_index], nums[left_child]);
                }
                break;
            }
            // both valid
            if (nums[current_index] >= nums[left_child]) {
                if (nums[current_index] >= nums[right_child]) {
                    // parent is already the max
                    break;
                } else {
                    // go right path
                    std:: swap(nums[current_index], nums[right_child]);
                    current_index = right_child;
                }
            } else {
                if (nums[current_index] >= nums[right_child]) {
                    // sift left
                    std::swap(nums[current_index], nums[left_child]);
                    current_index = left_child;
                } else {
                    // parent is smaller than both left and right
                    if (nums[left_child] > nums[right_child]) {
                        // sift left
                        std::swap(nums[current_index], nums[left_child]);
                        current_index = left_child;
                    } else {
                        // sift right
                        std:: swap(nums[current_index], nums[right_child]);
                        current_index = right_child;
                    }
                }
            }
        }
    }
};
