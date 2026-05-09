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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        else if (!list2) return list1;

        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        
        ListNode* head = nullptr;
        if (list1->val < list2->val) {
            head = list1;
            cur1 = cur1->next;
        } else {
            head = list2;
            cur2 = cur2->next;
        }

        ListNode* cur = head;

        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }

        if (cur1) cur->next = cur1;
        else if (cur2) cur->next = cur2;
 
        return head;
    }
};
