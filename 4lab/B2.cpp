#include<iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
    node(int val){
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    private:
        node* root;
        node* add(node* cur,int val){
            if(!cur) return new node(val);
            if(val < cur->val){
                cur->left =add(cur->left,val);
            }else if (val > cur->val) {
			    cur->right = add(cur->right, val);
		    }
            return cur;
        }
        int getSize(node* node) {
		    if (!node) return 0;
		    return getSize(node->left) + getSize(node->right) + 1;
	    }

	    node* search(node* cur, int target) {
		    if (!cur) return NULL;
		    if (cur->val == target) return cur;
		    if (cur->val > target) return search(cur->left, target);
		    if (cur->val < target) return search(cur->right, target);
	    }
    public:
        bst() {
		    this->root = NULL;
	    }
	    void _add(int val) {
		    node* temp = add(root, val);
		    if (!root) root = temp;
	    }
	    node* _search(int target) {
		    return search(root, target);
	    }

	    int _getSize(node* cur) {
		    return getSize(cur);
	    }
};

int main(){
    bst bst;
    int n,k;
    cin >> n;
    for( int i = 0; i < n; i++){
        int x;
        cin >> x;
        bst._add(x);
    }
   
    cin >> k;
    
    //Node* target = bst.search(k);
    //cout << bst.getSize(target);
    cout << bst._getSize(bst._search(k));
}