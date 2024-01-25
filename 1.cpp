#include<iostream>

using namespace std;

struct ListNode{
    string val;
    ListNode* next;
    ListNode(){
        this->val ="";
        this->next = NULL;
    }
    ListNode(string val){
        this->val=val;
        this->next = NULL;
    }ListNode(string val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};
struct LinkedList{
    int size;
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void push_front(string val)
	{
		
		ListNode *temp = new ListNode(val);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
            
		}
		else
		{
		    temp->next = this->head;
		    this->head = temp;
		}
        size++;
	}
    void print() {
		ListNode *cur = head;
		while (cur != NULL) {
			cout << cur->val <<endl;
			cur = cur->next;
		}
		cout << endl;
	}
};
int main(){
    LinkedList *l = new LinkedList();
    int n;
    cin>>n;   
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="" || (l->head && l->head->val == s)) continue;
        else l->push_front(s);
        
    }
    cout<<"All in all: "<<l->size<<endl;
    cout<<"Students:"<<endl;
    l->print();
    return 0;
}