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
private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* prevPrev = nullptr;
        while (cur) {
            prevPrev = prev;
            prev = cur;
            cur = cur->next;

            prev->next = prevPrev;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //after the loop slow is now mid
        // if only check for fast && fast->next
        // even nodes : 0 1 2 3_ 4 5 -> mid = 3 -> 0 _5 1 _4 2 _3
        // odd nodes : 0 1 2_ 3 4 -> mid = 2 -> 0 _4 1 _3 2

        //if check for fast->next->next too
        // even : 0 1 2_ 3 4 5
        // odd : 0 1 2_ 3 4
        // then mid->next is to be reversed
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        } 

        ListNode* cur1 = head;
        ListNode* cur2 = reverseList(slow->next);
        //debug : disconnect 2 list
        slow->next = nullptr;

        ListNode dum(0, nullptr); 
        ListNode* dummy = &dum;
        while (cur1 && cur2) {
            dummy->next = cur1;
            dummy = dummy->next;

            cur1 = cur1->next;

            dummy->next = cur2;
            dummy = dummy->next;

            cur2 = cur2->next;
        }
        if (cur1) dummy->next = cur1;
    }
};
