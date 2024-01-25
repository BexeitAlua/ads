#include<iostream>
using namespace std;

struct node {
	int val;
	int num;
	node* left;
	node* right;

	node(int val) {
		this->val = val;
		this->num = 1;
		this->left = NULL;
		this->right = NULL;
	}
};

struct BST {
private:
	node* root;


	node* _insert(node* cur, int val) {
		if (!cur) {
			return new node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}
    int _rightmost(node* cur) {
		if (!cur) return -1;
		if (!cur->right) return cur->val;
		return _rightmost(cur->right);
	}


	node* _remove(node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) {
			if (!cur->right && !cur->left) {
				delete cur;
				return NULL;
			} else if (cur->left && !cur->right) {
				node* temp = cur->left;
				delete cur;
				return temp;
			} else if (cur->right && !cur->left) {
				node* temp = cur->right;
				delete cur;
				return temp;
			} else if (cur->right && cur->left) {
				cur->val = _rightmost(cur->left);
				cur->left = _remove(cur->left, cur->val);
			}
		} else if (cur->val < target) {
			cur->right = _remove(cur->right, target);
			return cur;
		} else if (cur->val > target) {
			cur->left = _remove(cur->left, target);
			return cur;
		}
		return cur;
	}

	

	node* _search(node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) return cur;
		if (cur->val > target) return _search(cur->left, target);
		if (cur->val < target) return _search(cur->right, target);
	}

public:
	BST() {
		this->root = NULL;
	}

	void insert(int val) {
		node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	void remove(int target) {
		root = _remove(root, target);
	}

	node* search(int target) {
		return _search(root, target);
	}

	
};

int main() {
	BST bst;
    int n;
    cin >> n;
    while(n--){
        string s;
        int x;
        cin >> s >> x;
        if(s=="insert"){
			
            if(!bst.search(x)){
				bst.insert(x);
			}else{
				bst.search(x)->num += 1;
			}
        }
        if(s=="delete"){
			
            if(bst.search(x)->num > 0){
				bst.search(x)->num -= 1;
			}else{
            	bst.remove(x);
			}
        }
        if(s == "cnt"){
			if(!bst.search(x)){
				cout<<0<<endl;
			}else{
				cout << bst.search(x)->num<<endl;
			}
		}
    }
	return 0;
}