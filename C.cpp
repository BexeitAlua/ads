#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        this->val = 0;
        this->next = nullptr;
    }
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};

int main(){
    ListNode *head = nullptr;
    ListNode *cur = nullptr;
    int n;
    cin>>n;     
    for(int i = 0; i < n;i++){
        int x;
        cin>>x;
        if(i == 0){
            //head = new ListNode(n);
            head->val = x;
            cur->val = x;
            cout<<cur->val<<" ";
        }else if(i % 2 == 0){
            //ListNode *l = new ListNode();
            cur-> next = new ListNode(n);
            cur = cur->next;
            cout<<cur->val<<" ";
        }else{
            continue;
        }
    }
    return 0;
}
