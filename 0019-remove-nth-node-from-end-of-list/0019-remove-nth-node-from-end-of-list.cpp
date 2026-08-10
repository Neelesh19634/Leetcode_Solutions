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
        ListNode* prev = NULL;
        ListNode* temp = head;

        while (temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp2 = reversing(head);
        ListNode* temp = temp2;
        ListNode* prev = NULL;
        int count = 0;
        while (temp != NULL) {
            if (count == n - 1) {

                if (prev == NULL) {
                    temp2 = temp->next;
                } else {
                    prev->next = temp->next;
                }
                break;
            }

            prev = temp;
            temp = temp->next;
            count++;
        }

        ListNode* newhead = reversing(temp2);

        return newhead;
    }
};