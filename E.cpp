#include<iostream>
using namespace std;

struct node{
    string name;
    node * next;
    node(){
        this->name = "";
        this->next = NULL;
    }
    node(string name){
        this->name = name;
        this->next = NULL;
    }
    node(string name,node*next){
        this->name = name;
        this->next = next;
    }
};

struct ll {
    node * head;
    node * tail;
    int size;
    
    ll(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void add_node(string x){
        node * temp = new node(x);
        if(this->head == NULL){
            this->head = temp;
            this->tail = temp;
            this->size++;
        } else{
            this->tail->next= temp;
            this->tail = temp;
            this->size++;
        }


    }
    void print() {
		node *cur = head;
		while (cur != NULL) {
			cout << cur->name <<endl;
			cur = cur->next;
		}
		cout << endl;
	}


};

int main(){
    ll *l = new ll();
    int n;
    cin>>n;   
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="" || (l->head && l->head->name == s)) continue;
        else l->add_node(s);
        
    }
    cout<<"All in all: "<<l->size<<endl;
    cout<<"Students:"<<endl;
    l->print();
    return 0;
}