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
struct bst{
    private:
        node*root;
        node * add(int val,node * cur){
            if (!cur) {
			return new node(val);
		}
		if (val > cur->val) {
			cur->right = add(val,cur->right);
		} else if (val < cur->val) {
			cur->left = add(val,cur->left);
		}
		return cur;
	
        }

        void inorder(node * node){
            if (!node) return;
            inorder(node->right);
            cout<<node->val<<" ";
            inorder(node->left);
        }
    public:
        bst(){
            this->root = NULL;
        }
        void insert(int val){
            node * temp = add(val,root);
            if(!root){
                root = temp;
            }
        }  

        void _inorder(){
            inorder(root);
            cout<<endl;
        }

        void changeNodes(node * cur,int sum){
            if(!cur) return;
            changeNodes(cur->right,sum);
            sum+=cur->val;
            cur->val = sum;
            changeNodes(cur->left,sum);
        }

        void changeNodesOuter(){
            int sum =0;
            changeNodes(root,sum);
        }


};

int main(){
    bst bst;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        bst.insert(x);
    }
    bst.changeNodesOuter();
    bst._inorder();

    return 0;
}