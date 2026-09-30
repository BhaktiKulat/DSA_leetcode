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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
    int count = 0 ;
    ListNode *temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }  
    count = count/2; 
    count--;            
    temp = head;
    while(count--){
        temp = temp->next;
    }
   ListNode *head2 = temp->next;
    temp->next = NULL;

     ListNode *current = head2;
    ListNode *pre = NULL;
    ListNode *future = NULL;
     while(current){
       future = current->next;
       current->next = pre;
       pre = current;
       current = future;

     }
     head2 = pre;

    ListNode *tempo = head;
    ListNode *tempo2 = head2;
    while(tempo){
        if(tempo->val!=tempo2->val){
           return false;
        }
        tempo =tempo->next;
        tempo2 =tempo2->next;
    }
    return true;    
    }
};