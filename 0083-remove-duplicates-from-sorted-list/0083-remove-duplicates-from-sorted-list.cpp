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
        if(!head||!head->next){
            return head;
        }
        ListNode* front=head;
        ListNode* nextone=head->next;
        while(nextone){
            if(front->val==nextone->val){
             front->next=nextone->next;
             ListNode* temp=nextone;
             nextone=nextone->next;
             delete temp;
            }
            else{
                front=front->next;
                nextone=nextone->next;
            }
        }
    return head;}
};