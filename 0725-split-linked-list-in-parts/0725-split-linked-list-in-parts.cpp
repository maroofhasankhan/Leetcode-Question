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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode* curr = head;
        int n = 0;

        while (curr) {
            n++;
            curr = curr->next;
        }

        int partSize = n / k;
        int remainder = n % k;
        curr = head;

        for (int i = 0; i < k; i++) {
            if (curr) {
                ans[i] = curr;
                int currentPartSize = partSize + (remainder > 0 ? 1 : 0);
                remainder--;

                for (int j = 1; j < currentPartSize; j++) {
                    curr = curr->next;
                }

                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }

        return ans;
    }
};
