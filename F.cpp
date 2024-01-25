#include<iostream>
using namespace std;
struct node{
    node * next;
    int val;
    node(){
        this->val =0;
        this->next = NULL;
    }
    node(int val){
        this->val = val;
        this->next = NULL;
    }
    node(int val,node * next){
        this->val = val;
        this->next = next;
    }

};

struct ll{
    node*head;
    node*tail;
    int size;
    ll(){
        this->head=NULL;
        this->tail=NULL;
        this->size=0;
    }
    void add_back(int x){
        node * temp = new node(x);
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;
            this->size++;
        }else{
            this->tail->next= temp;
            this->tail=temp;
            this->size++;
        }
    }
    void add_front(int x){
        node*temp = new node(x);
        this->size++;
        if(this->head==NULL){
            this->head=temp;
            this->tail=temp;

        }else{
            temp->next = this->head;
            this->head = temp;
        }
    }
    void addIndex(int val,int index){
        if(index==0){
            this->add_front(val);
        }
        else if(index==this->size){
            this->add_front(val);
        }
        else{
            node * temp = new node(val);
            node * cur = this->head;
            for(int i = 1;i<index;i++){
                cur=cur->next;
            }
            temp->next = cur->next;
			cur->next = temp;
			this->size++;
        }
    }
    void print() {
		node *cur = this->head;
		while (cur != NULL) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};
int main(){
    ll *l = new ll();
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		l->add_back(x);
	}
	int i,k;
	cin>>i>>k;
	l->addIndex(k,i);
	l->print();
}