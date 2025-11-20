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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Create reversed copy
        ListNode* rev = NULL;
        for (ListNode* curr = head; curr; curr = curr->next) {
            ListNode* node = new ListNode(curr->val);
            node->next = rev;
            rev = node;
        }

        // Step 2: Compare both lists
        ListNode* a = head;
        ListNode* b = rev;
        while (a && b) {
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};
        
