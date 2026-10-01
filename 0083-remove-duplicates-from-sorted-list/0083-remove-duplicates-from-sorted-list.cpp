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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL){
            return head;
        }
        vector<int>ans;
    ans.push_back(head->val);
    ListNode *current = head->next;

    while(current){
        if(ans[ans.size()-1]!=current->val)
            ans.push_back(current->val);
            current = current->next;
        
    }
    current = head;
    int index  = 0 ;
    while(index<ans.size()){
        current->val = ans[index];
        index++;
        current = current->next;
    }
    int size = ans.size()-1;
    current = head;
    while(size--){
        current = current->next;
    }
    current->next = NULL;
    return head;
    }
};