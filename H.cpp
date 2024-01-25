#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if(head==NULL){
        head=node;
        return head;
    }
    if(p==0){
        node->next = head;
        head = node;
        return head;
    }
    Node * temp = head;
    while(p!=1){
        temp=temp->next;
        p--;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if(p==0){
        Node*node=head;
        head = node->next;
        delete(node);
        return head;
    }
    Node * temp = head;
    while(p!=1){
        temp=temp->next;
        p--;
    }
    Node *node = temp->next;
    temp->next = node->next;
    delete (node);
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    if(p1==p2){
        return head;
    }
    Node * move = head;
    for(int i =0;i<p1;i++){
        move = move->next;
    }
    Node * i = new Node(move->val);
    head = remove(head,p1);
    return insert(head,i,p2);
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node *prev = NULL, *cur = head;
  while (cur != NULL)
  {
    Node *nextt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nextt;
  }
  head = prev;
  return head;
}
 
void print(Node* head){
    /* write your code here */
     if (head == NULL)
  {
    cout << -1 << endl;
    return;
  }
  Node *cur = head;
  while (cur != NULL)
  {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
     if (x == 0)
    return head;
  Node *tail = head;
  while (tail->next != NULL)
  {
    tail = tail->next;
  }
  tail->next = head;
  while (x--)
  {
    head = head->next;
    tail = tail->next;
  }
  tail->next = NULL;
  return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    if (x == 0)
    return head;
  int sz = 0;
  Node *cur = head;
  while (cur != NULL) {
    cur = cur->next;
    sz++;
  }
  return cyclic_left(head, sz - x);
}
 
int main(){
    Node* head = NULL;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}