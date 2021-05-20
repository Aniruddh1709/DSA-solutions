class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode *p;
        p=head;
        int n=0;
        while(p){
            n=n+1;
            p=p->next;
        }
        p=head;
        int num=n/2;
        for(int i=0;i<num;i++){
            p=p->next;
        }
        return p;
    }
};