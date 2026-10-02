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
    ListNode* removeElements(ListNode* head, int val) {

        if(head == NULL){
            return head;
        }

        // Remove matching nodes from beginning
        while(head != NULL && head->val == val){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        ListNode *temp = head;
        ListNode *pre = NULL;

        while(temp){

            if(temp->val == val){

                pre->next = temp->next;

                ListNode *nextNode = temp->next;  // save next
                delete temp;
                temp = nextNode;                  // move forward
            }
            else{
                pre = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};