class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==0){
            return head;
        }
        ListNode *p,*q;
        p=head;
        q=p->next;
        while(q!=nullptr){
            
            if(p->val==q->val){
                p->next=q->next;
                q=q->next;
            }else if(p->val!=q->val){
                p=q;
                q=q->next;
            }
            
        }
        return head;
    }
};