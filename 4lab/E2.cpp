#include <iostream>
#include <vector>
#include <algorithm>
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

	

	node* search(node* cur, int target) {
		if (!cur) return NULL;
		if (cur->val == target) return cur;
		else {
			node* found = search(cur->left, target);
			if (found == NULL) {
				found = search(cur->right, target);
			}
			return found;
		}
		return NULL;
	}

public:
	bst() {
		this->root = NULL;
	}

	

	void insert(int val) {
		node* newNode = add(root, val);
		
		if (root == NULL) root = newNode;
	}

	

	node* _search(int target) {
		return search(root, target);
	}

	node* getRoot() {
		return root;
	}

	void setRoot(node* root) {
		this->root = root;
	}

	

	int getHeight(node* node) {
		if (!node) return 0;
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		return max(left, right) + 1;
	}

	
};

void dfs(node* node, int lvl, vector<int>& v) {
	if (!node) return;
	v[lvl]++;
	dfs(node->left, lvl + 1, v);
	dfs(node->right, lvl + 1, v);
}

int main() {
	bst bst;
	int n;
	cin >> n;
	n--;
	bst.setRoot(new node(1));
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		node* parent = bst._search(x);
		if (z == 0) {
			parent->left = new node(y);
		} else {
			parent->right = new node(y);
		}
	}
	int levels = bst.getHeight(bst.getRoot());
	vector<int> v(levels);
	dfs(bst.getRoot(), 0, v);
	sort(v.begin(), v.end());
	cout << v[v.size() - 1];

	return 0;
}