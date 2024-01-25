#include<bits/stdc++.h>

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
    void add_node(int x){
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
    
    int mode(){

    node *cur = this->head;
    map<int, int> m;
    map<int, int>::iterator it;

    for (int i = 0; i < this->size; i++) {
        m[cur->val]++;
        cur = cur->next;
    }

    int max = 0;
    vector<int> v;

    for (it = m.begin(); it != m.end(); it++) {
        if ((*it).second > max) {
            max = (*it).second;
        }
    }

    for (it = m.begin(); it != m.end(); it++) {
        if ((*it).second == max) {
            v.push_back((*it).first);
        }
    }

    sort(v.begin(), v.end());

    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    return max; }
};
int main(){
    ll *l = new ll();
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        l->add_node(x);
    }
    l->mode();
    }