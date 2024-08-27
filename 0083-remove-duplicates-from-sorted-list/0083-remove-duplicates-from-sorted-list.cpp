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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp=head,*prev=nullptr;
        while (temp!=nullptr){
            if(prev!=nullptr && prev->val==temp->val){
                ListNode *node=temp;
                prev->next=temp->next;
                temp=prev;
                delete node;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};