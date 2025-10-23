#include<iostream> 
#include<deque> 


using namespace std; 

struct ListNode{
  int val; 
  ListNode* next; 
  ListNode(): val(0), next(nullptr){}
  ListNode(int _val): val(_val), next(nullptr){}
  ListNode(int _val, ListNode* _next): val(_val), next(_next){}
  
}; 
class Solution{
public: 
     int pairSum(ListNode* head) {
       ListNode* curr = head; 
       int ans =0; 
       deque<int> dq; 
       while(curr){
         dq.push_back(curr->val); 
         curr = curr->next; 
       }
       while(!dq.empty()){
         int left = dq.front(); 
         int right=dq.back(); 
         ans=max(ans, left+right); 
         dq.pop_front(); 
         dq.pop_back(); 
       }
       return ans; 
     }
};
int main(){
  ListNode* head = new ListNode(5); 
  head->next =new ListNode(4); 
  head->next->next =new ListNode(2); 
  head->next->next->next=new ListNode(1); 
  Solution sol; 
  cout <<sol.pairSum(head) <<endl; 
  return 0; 
}
