/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (45.94%)
 * Total Accepted:    383.2K
 * Total Submissions: 813.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 * 
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1], k = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
 * 
 * 
 * 
 * Follow-up: Can you solve the problem in O(1) extra memory space?
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        if (k == 1) return head;
        // create a dummy head
        ListNode *pivot = new ListNode(0, head);
        ListNode *currentHead = pivot;
        ListNode *currentTail = pivot->next;

        while (true) {
            for (int i = 0; i < k; i++) {
                if (currentTail != nullptr) {
                    currentTail = currentTail->next;
                } else {
                    // not enough elements, finishes
                    head = pivot->next;
                    delete pivot;
                    return head;
                }
            }
            // reverse the nodes from pivot to currentTail
            currentHead = this->reverse(currentHead, currentTail);
        }
        // unachieveable code
        delete pivot;
        return pivot;
    }

private:
    ListNode* reverse(ListNode* pivot, ListNode *tail) {
        ListNode *temp1 = pivot->next;
        ListNode *temp2 = temp1->next;
        ListNode *temp3 = temp2->next;
        while (true) {
            temp2->next = temp1;
            if (temp3 == tail) {
                break;
            } else {
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3->next;
            }
        }
        temp1 = pivot->next;
        temp1->next = tail;
        pivot->next = temp2;
        return temp1;
    }
};
