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
    ListNode* reversing(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

private:
    ListNode* findnode(ListNode* head, int k) {
        k -= 1;
        ListNode* temp = head;
        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* kth = findnode(temp, k);

            if(kth==NULL){
                if(prev){
                    prev->next=temp;
                }
                break;
            }

             ListNode* newnode=kth->next;
             kth->next=NULL;

             reversing(temp);

             if(temp==head) head=kth;
             else prev->next=kth;

             prev=temp;
             temp=newnode;
        }

        return head;
    }
};