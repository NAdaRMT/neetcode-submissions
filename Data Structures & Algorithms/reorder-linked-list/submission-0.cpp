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
    void reorderList(ListNode* head) {
        vector<ListNode*> arrayNode;

        ListNode* cur = head;
        while (cur) {
            arrayNode.push_back(cur);
            cur = cur->next;
        }

        int i = 0;
        int j = arrayNode.size() - 1;
        while (i < j) {
            arrayNode[i]->next = arrayNode[j];
            i++;    
            arrayNode[j]->next = arrayNode[i];
            j--;
        }
        arrayNode[i]->next = nullptr;
    }
};
