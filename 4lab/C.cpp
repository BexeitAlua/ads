#include<iostream>
using namespace std;
struct node{
    int val;
    node* right;
    node * left;
    node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};
struct bst{
    node * root;
private:
    void inorder(node * node){
        if(!node){
            return;
        }
        inorder(node->left);
        cout<< node->val<<" ";
        inorder(node->right);
    }
    void preorder(node * node){
        if(!node){
            return;
        }
        cout<<node->val<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(node * node){
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout<<node->val<<" ";
    }
    node * add(node *cur, int val){
        if(!cur){
            return new node(val);
        }
        if(val>cur->val){
            cur->right = add(cur->right,val);

        }
        else if(val<cur->val){
            cur->left = add(cur->left,val);
        }
        return cur;
    }
    node * find(node * cur,int val){
        if(cur == NULL) return NULL;
        if(cur->val == val) return cur;
        if(cur->val<val) return find(cur->right,val);
        if(cur->val>val) return find(cur->left,val);
    }
public:
    void _add(int val) {
		node* temp = add(root, val);
		if (!root) root = temp;
	}
    bst() {
		this->root = NULL;
	}

	void _inorder() {
		inorder(root);
		cout << endl;
	}
	
	void _preorder(node*cur) {
		preorder(cur);
		cout << endl;
	}
	
	void _postorder(node* cur) {
		postorder(cur);
		cout << endl;
	}
    node* _find(int target) {
		return find(root, target);
	}

};

int main(){
    bst bst;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        bst._add(x);
    }
    int k;
    cin>>k;
    node * target = bst._find(k);
    bst._preorder(target);
    return 0;


}