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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)
            return NULL;
        vector<ListNode*> pointers(k);
        for (int i = 0; i < k; i++) {
            pointers[i] = lists[i];
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (true) {
            int minIndex = -1;
            for (int i = 0; i < k; i++) {
                if (pointers[i] == NULL)
                    continue;

                if (minIndex == -1 ||
                    pointers[i]->val < pointers[minIndex]->val) {
                    minIndex = i;
                }
            }
            if (minIndex == -1)
                break;
            tail->next = pointers[minIndex];
            tail = tail->next;
            pointers[minIndex] = pointers[minIndex]->next;
        }
        return dummy->next;
    }
};