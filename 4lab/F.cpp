#include<iostream>
#include<vector>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;

	node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

struct bst {
private:
	node* root;

	

	node* add(node* cur, int val) {
		if (!cur) {
			return new node(val);
		}
		if (val > cur->val) {
			cur->right = add(cur->right, val);
		} else if (val < cur->val) {
			cur->left = add(cur->left, val);
		}
		return cur;
	}	

public:
	bst() {
		this->root = NULL;
	}

	
	void insert(int val) {
		node* newNode = add(root, val);
		if (!root) root = newNode;
	}

	

	node* getRoot() {
		return root;
	}

	
    int numTriangle(node* cur){
        if(cur == NULL) return 0;
        int count = cur->right != NULL and cur->left!= NULL;
        return count + numTriangle(cur->right) + numTriangle(cur->left);
    }

	
};

int main() {
	bst bst;
	int n;
	cin >> n;
	while (n--) {
		int node;
		cin >> node;
		bst.insert(node);
	}
	cout << bst.numTriangle(bst.getRoot());

	return 0;
}