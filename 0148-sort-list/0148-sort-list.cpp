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

    ListNode* mergeSorted(ListNode *l1,ListNode *l2){
        if(!l1 && !l2)return nullptr;
        else if(!l1)return l2;
        else if(!l2)return l1;
        ListNode *node=new ListNode(0);
        ListNode *temp=node;

        while (l1 && l2){
            if(l1->val < l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1)temp->next=l1;
        if(l2) temp->next=l2;

        return node->next;

    }


    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;


        ListNode *slow,*fast,*prev;
           slow=fast=head;
        //findthe mid
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;


        ListNode * L1=sortList(head);
        ListNode * L2=sortList(slow);

        return mergeSorted(L1,L2);

    }

};