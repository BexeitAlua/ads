#include <iostream>
using namespace std;

struct node {
    string word;
    node* next;

    node(string val) {
        this->word = val;
        this->next = NULL;
    }
};

struct ll {
    int size;
    node* head;
    node* tail;

    ll() {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void add_node(string x) {
        node* temp = new node(x);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void shift_ll() {
        node *temp = this->head;
        this->head = this->head->next;
        this->tail->next = temp; 
        this->tail = temp;
        this->tail->next = NULL;
    }
    void print() {
		node *cur = this->head;
		while (cur != NULL) {
			cout << cur->word << " ";
			cur = cur->next;
		}
		cout << endl;
	}
        };

int main() {
    ll l;

    int n;
    cin >> n;
    int k;
    cin >> k;

    while (n--) {
        string x;
        cin >> x;
        l.add_node(x);
    }

    while(k--){
        l.shift_ll();
    }
    l.print();
    
    return 0;
}
