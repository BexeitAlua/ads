#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};
struct LinkedList{
    int size;
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        this-> size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void push_back(int x){
		ListNode *temp = new ListNode(x);
		if (this->head == NULL)
		{
			this->head = temp;
			this->tail = temp;
            this->size++;
		}
		else
		{
			this->tail->next = temp;
            this->tail = temp;
            this->size++;
		}
    }
    void push_front(int x){
        ListNode *temp = new ListNode(x);
        this->size++;
        if (this->head == NULL)
		{
			this->head = temp;
			this->tail = temp;
		}else
		{
			temp->next = this->head;
			this->head = temp;
		}

    }
    void addAtIndex(int index, int val)
	{
		if (index == 0)
		{
			this->push_front(val);
		}
		else if (index == this->size)
		{
			this->push_front(val);
		}
		else
		{
			ListNode *temp = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next = temp;
			this->size++;
		}
	}
	void print() {
		ListNode *cur = this->head;
		while (cur != NULL) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}

};

int main(){
	LinkedList *l = new LinkedList;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		l->push_back(x);
	}
	int i,k;
	cin>>i>>k;
	l->addAtIndex(k,i);
	l->print();
}