
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==0){
            return head;
        }
        vector<ListNode*> vect;
        ListNode *tail,*f;
        tail=head;
        while(tail!=nullptr){
            vect.push_back(tail);
            tail=tail->next;
        }
       
        head=vect[vect.size()-1];
        head->next=nullptr;
        tail=head;
        for(int i=vect.size()-2;i>=0;i--){
            f=vect[i];
            f->next=nullptr;
            tail->next=f;
            tail=f;
            
        }
        
        return head;
    }
};