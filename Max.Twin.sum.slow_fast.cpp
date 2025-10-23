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
       ListNode* fast = head; 
       ListNode* slow = head; 
       int ans=0;
       while(fast && fast->next){
         slow = slow->next; 
         fast=fast->next->next; 
       }
       ListNode* nextNode=nullptr;
       ListNode* prev=nullptr; 
       while(slow){
         nextNode=slow->next; 
         slow->next = prev; 
         prev =slow; 
         slow = nextNode; 
       }
       ListNode* start =head;
       while(prev){
         ans=max(ans, start->val+prev->val); 
         prev = prev->next; 
         start = start->next; 
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
