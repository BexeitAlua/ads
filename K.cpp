#include<bits/stdc++.h>

using namespace std;

struct node{
    pair<bool, char> p;
    node * next;
    node * prev;

    node(char val){
        p.first = true;
        p.second = val;
        next = NULL;
        prev = NULL;
    }
};

struct ll{
    node * head;
    node * tail;
    int size;
    ll(){
        this->size = 0;
        head = NULL;
        tail = NULL;
    }
    void add_node(int x){
		node *temp = new node(x);
		if (this->head == NULL)
		{
			head = temp;
			tail = temp;
            this->size++;
		}
		else
		{
			tail->next = temp;
            temp->prev = tail;
            tail = temp;
            this->size++;
		}
    }
    void check(){
        node * cur = head;
        while(cur -> next != NULL){
            if(cur -> p.second == tail -> p.second){
                cur -> p.first = false;
                tail -> p.first = false;
            }
            cur = cur -> next;
        }
        cur = head;
        while(cur != NULL){
            if(cur -> p.first == true){
                cout << cur -> p.second << " ";
                return;
            }
            cur = cur -> next;
        }
        cout << -1 << " ";
    }


};

int main(){
    ll* l = new ll();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin>>x;
        while(x--){
            char c;
            cin>>c;
            l->add_node(c);
            l->check();
        }
        cout<<endl;
        l->head = NULL;
    }
}