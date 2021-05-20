class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *p;
        int n=0;
        while(p){
            n=n+1;
            p=p->next;
        }
        int sum=0;
        p=head;
        for(int i=n-1;i>=0;i--){
            sum=sum+pow(2,i)*(p->val);
            p=p->next;
        }
        return sum;
        
        
    }
};