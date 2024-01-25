#include<iostream>
using namespace std;

struct node{
string val;
node * next;
node * prev;
node(){
    this->val = "";
    this->next = NULL;
    this->prev = NULL;

}
node(string val){
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
}

node(string val,node*next,node*prev){
    this->val = val;
    this->next = next;
    this->prev = prev;
}
};

struct dll{
    node*head;
    node *tail;
    int size;

    dll(){
        this->head = NULL;
        this->tail = tail;
        this->size = 0;
    }
    void add_back(string x){
    this->size++;
    node  * temp = new node(x);


    if(this->head==NULL){
        this->head =  temp;
        this->tail = temp;
    }else{
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
    }
    void add_front(string x){
        this->size++;
        node * temp = new node(x);
        if(this->head == NULL){
            this->head = temp;
            this->tail = temp;
        }else{
            temp->next = this->head;
            this->head->prev = temp;
            this->head = temp;
        }

    }
    void erase_front(){
        if(size>1){
            cout<<head->val<<endl;
            this->head = this->head->next;
            this->head->prev = NULL;
            this->size--;
        } else if(size ==1){
            cout<<head->val<<endl;
            clear();
        }else{
            cout<<"error"<<endl;
        }

    }
    void erase_back(){
        if(size>1){
            cout<<tail->val<<endl;
            this->tail=this->tail->prev;
                this->tail->next=NULL;
                this->size--;
        }else if(size==1){
            cout<<this->tail->val<<endl;
            clear();
        }else{
            cout<<"error"<<endl;
        }
    }

    void clear(){
        head=NULL;
        tail = NULL;
        size =0;
    }

};
int main(){
    dll * l = new dll();
    while(true){
        string s;
        cin>>s;
        if(s=="add_front"){
            string s1;
            cin>>s1;
            l->add_front(s1);
            cout<<"ok"<<endl;
        }
        if(s=="add_back"){
            string s1;
            cin>>s1;
            l->add_back(s1);
            cout<<"ok"<<endl;
        }
        if(s=="erase_front"){
            l->erase_front();
        }
        if(s=="erase_back"){
            l->erase_back();
        }
        if(s=="front"){
            if(l->size>0){
                cout<<l->head->val<<endl;
            }else{
                cout<<"error"<<endl;
            }
        }
        if(s=="back"){
            if(l->size>0){
                cout<<l->tail->val<<endl;
            }else{
                cout<<"error"<<endl;
            }
        }
        if(s=="clear"){
            l->clear();
        cout<<"ok"<<endl;
        }
        if(s == "exit"){
            cout<<"goodbye";
            return 0;
        }
    }
    return 0;
}