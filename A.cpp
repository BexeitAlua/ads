#include<iostream>
#include<limits.h>
#include<cmath>

using namespace std;

struct node{
    int val;
    node* next;
    node(){
        this->val = 0;
        this->next = NULL;
    }
    node(int val){
        this->val = val;
        this->next = NULL;
    }node(int val, node* next){
        this->val = val;
        this->next = next;
    }
};
struct ll{
    int size;
    node* head;
    node* tail;
    ll(){
        this-> size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void push_back(int x){
		node *temp = new node(x);
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
    int getNearsetNum(int x){
        node* test = this->head;
        int index = 0;
        int difference = INT_MAX;
        for(int i = 0; i < this->size;i++){
            if(abs(x-test->val)<difference){
                difference = abs(x-test->val);
                index = i;
            }
            test = test->next;
        }
        return index;
    }
};
int main(){
    ll *l = new ll();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        l->push_back(x);
    }
    int k;
    cin>>k;
    int f = l->getNearsetNum(k);
    cout<<f;
    return 0;
}