class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==0){
            return head;
        }
        ListNode *p,*q;
        p=head->next;
        q=head;
        while(p){
            if(p->val==val){
                q->next=p->next;
                p=p->next;
            }
            else{
                q=p;
                p=p->next;
            }
        }
        if(head->val==val){
            head=head->next;
        }
        return head;
        
        
    }
};