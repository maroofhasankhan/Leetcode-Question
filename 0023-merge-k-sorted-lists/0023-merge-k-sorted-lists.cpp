
class Solution {
public:

    ListNode* mergeTwoSorted(ListNode* l1,ListNode* l2 ){
        if(!l1)return l2;
        if(!l2)return l1;
        if(l1->val <=l2->val){
            l1->next=mergeTwoSorted(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoSorted(l1,l2->next);
            return l2;
        }
        return NULL;
    }


    ListNode* divideAndMerge(int start , int end, vector<ListNode*>& lists){
        if(start>end)return nullptr;
        if(start == end) return lists[start];

        int mid= start+(end-start)/2;

        ListNode * L1=divideAndMerge(start,mid, lists);
        ListNode * L2=divideAndMerge(mid+1,end,lists);
        return mergeTwoSorted(L1,L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        
        return divideAndMerge(0,lists.size()-1,lists);
    }
};