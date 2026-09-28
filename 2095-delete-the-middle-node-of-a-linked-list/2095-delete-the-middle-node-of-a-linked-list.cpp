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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL)
        return NULL;
        ListNode *temp = head;
        int count = 0 ;
        while(temp){
            count++;
            temp = temp->next;
        }
        int n = count/2;
    
        ListNode *current = head;
        ListNode *pre = NULL;

        while(n){
            pre = current;
            current = current->next;
            n--;
        }
        pre->next = current->next;
        delete current;
        return head;

    }
};