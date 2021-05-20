#include<iostream>

using namespace std;
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) 
        return(l2); 
        else if (l2 == NULL) 
        return(l1);
       
        ListNode* dummyhead=new ListNode();
        ListNode* dummy=dummyhead;
      if(l1->val <= l2->val){
          ListNode* dummy2=new ListNode();
          dummy2->val=l1->val;
          l1=l1->next;
          dummyhead->next=dummy2;
          dummyhead=dummyhead->next;
      }else{
          ListNode* dummy2=new ListNode();
          dummy2->val=l2->val;
          l2=l2->next;
          dummyhead->next=dummy2;
          dummyhead=dummyhead->next;
      }
        
      while(l1!=nullptr && l2!=nullptr){
          ListNode* dummy2=new ListNode();
          if(l1->val <= l2->val){
              dummy2->val=l1->val;
              l1=l1->next;
          }
          else{
              dummy2->val=l2->val;
              l2=l2->next;
          }
          
          dummyhead->next=dummy2;
          dummyhead=dummyhead->next;
          
      }
        while(l1!=nullptr){
            ListNode* dummy2=new ListNode();
            dummy2->val=l1->val;
            l1=l1->next;
            dummyhead->next=dummy2;
            dummyhead=dummyhead->next;
            
        }
        while(l2!=nullptr){
            ListNode* dummy2=new ListNode();
            dummy2->val=l2->val;
            l2=l2->next;
            dummyhead->next=dummy2;
            dummyhead=dummyhead->next;
            
        }

        return dummy->next;
    }
    
};