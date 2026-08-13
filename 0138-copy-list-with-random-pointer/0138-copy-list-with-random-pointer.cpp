/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node* temp=head;
        //copy 
        while(temp!=NULL){
            Node* newnode=new Node(temp->val);
            Node* next=temp->next;

            newnode->next=next;
            temp->next=newnode;

            temp=next;
        }


        temp=head;
        //rendom
        while(temp!=NULL){
            
            if(temp->random){
                temp->next->random=temp->random->next;
            }else{
                temp->next->random=NULL;
            }

            temp=temp->next->next;
        }

        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;

        //seperate copy
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;

            
            temp=temp->next;
        }

        return dummy->next;
    }
};