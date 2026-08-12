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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newnode=head->next;
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr && curr->next){
            ListNode* newpair=curr->next->next;
            ListNode* second=curr->next;

            second->next=curr;
            curr->next=newpair;

            if(prev){
                prev->next=second;
            }

            prev=curr;
            curr=newpair;
        }
        return newnode;
    }
};