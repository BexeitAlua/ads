#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

struct BST {
private:
	Node* root;

	void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->right);
		cout << node->val << " ";
		_inorder(node->left);
	}

	

	Node* _insert(Node* cur, int val) {
		if (!cur) {
			return new Node(val);
		}
		if (val > cur->val) {
			cur->right = _insert(cur->right, val);
		} else if (val < cur->val) {
			cur->left = _insert(cur->left, val);
		}
		return cur;
	}

	

	

	

public:
	BST() {
		this->root = NULL;
	}

	void inorder() {
		_inorder(root);
		cout << endl;
	}

	

	void insert(int val) {
		Node* newNode = _insert(root, val);
		if (!root) root = newNode;
	}

	

	

	

	void changeNodes(Node* cur, int& sum) {
		if (!cur) return;
		changeNodes(cur->right, sum);
		sum += cur->val;
		cur->val = sum;
		changeNodes(cur->left, sum);
	}

	void changeNodesOuter() {
		int sum = 0;
		changeNodes(root, sum);
	}

	
};

int main() {
	BST bst;
	int n;
	cin >> n;
	while (n--) {
		int node;
		cin >> node;
		bst.insert(node);
	}
	bst.changeNodesOuter();
	bst.inorder();

	return 0;
}