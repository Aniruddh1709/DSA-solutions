
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==0){
            return false;
        }
        vector<int> v;
        ListNode* P;
        P=head;
        while(P!=nullptr){
            v.push_back(P->val);
            P=P->next;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]!=v[v.size()-i-1]){
                return false;
            }
            
        }
        return true;
    }
    
};