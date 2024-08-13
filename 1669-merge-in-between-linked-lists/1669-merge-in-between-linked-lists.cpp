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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode *curr=list1, *prev=nullptr,*lastItr=list2;
        int flag=0;
        while (lastItr->next!=nullptr)lastItr=lastItr->next;

        for (int i=0;i<a-1;i++){
            curr=curr->next;
        }
        // cout<<curr->val;
        ListNode *beforeA=curr;
        curr=list1;

        for (int i=0;i<b+1;i++){
            curr=curr->next;
        }
        beforeA->next=list2;
        lastItr->next=curr;
        cout<<curr->val;



        return list1;
    }
};