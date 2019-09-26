/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (37.15%)
 * Total Accepted:    207.5K
 * Total Submissions: 555.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *sentinal = new ListNode(-1);
        ListNode *current = sentinal;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1 == NULL) current->next = l2;
        else current->next = l1;
        current = sentinal->next;
        delete sentinal;
        return current;
    }

    ListNode* findMiddleNodeAndSplit(ListNode* head) {
        // Guarantee that at least two elements in head.
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        ListNode *beforeSlow = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                beforeSlow = slow;
                slow = slow->next;
            }
        }
        beforeSlow->next = NULL;
        return slow;
    }


public:
    // merge sort
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *middle = findMiddleNodeAndSplit(head);
        ListNode *first = sortList(head);
        ListNode *second = sortList(middle);
        return mergeTwoLists(first, second);
    }
};
