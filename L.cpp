#include <iostream>
#include <algorithm>
#include <cassert>
#include <climits>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
};
 
 
 
int findMaxSum(int n, Node *head) {
    int max = INT_MIN;
    int currMax=0;
    Node * cur = head;
    while(cur!=NULL){
      currMax=currMax+cur->val;

    if(max<currMax) {
      max=currMax;
      }

      if(currMax<0){
        currMax=0;
      }
      cur=cur->next;

      
    }
return max;
 
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}