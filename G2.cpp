#include <iostream>
using namespace std;

struct node {
    node* right;
    node* left;
    int val;
    node(int val) {
        this->right = NULL;
        this->left = NULL;
        this->val = val;
    }
};

struct bst {
private:
    node* root;

    node* add(int val, node* cur) {
        if (!cur) {
            return new node(val);
        }
        if (cur->val < val) {
            cur->right = add(val, cur->right);
        } else if (cur->val > val) {
            cur->left = add(val, cur->left);
        }
        return cur;
    }

public:
    bst() {
        this->root = NULL;
    }

    void insert(int val) {
        root = add(val, root);
    }

    int getHeight(node* node) {
        if (!node) {
            return 0;
        }
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return max(left, right) + 1;
    }

    int findDistance(node* node) {
        if (!node) {
            return 0;
        }
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        int leftDistance = findDistance(node->left);
        int rightDistance = findDistance(node->right);
        return max(max(leftDistance, rightDistance), leftHeight + rightHeight);
    }

    int findDistance() {
        return findDistance(root) +1;
    }
};

int main() {
    int n;
    cin >> n;
    bst bst;
    while (n--) {
        int x;
        cin >> x;
        bst.insert(x);
    }
    cout << bst.findDistance();

    return 0;
}
