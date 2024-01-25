#include<iostream>
using namespace std;
struct node{
    node * right;
    node * left;
    int val;
    node(int val){
        this->right = NULL;
        this->left = NULL;
        this->val = val;
    }
    };

    struct bst{
    private:
        node * root;
        node * add(int val,node * cur){
            if(!cur) return NULL;
            if(cur->val<val){
                cur->right = add(val,cur->right);
            }
            else if(cur->val>val){
                cur->left = add(val,cur->left);
            }
            return cur;
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
        int getHeight(node *node,int d){
            if(!node) return 0;
            int left = getHeight(node->left,d);
            int right = getHeight(node->right,d);
            d = max(d,left+right+1);
            return max(left,right)+1;
        }

        int findDistance(){
            int d =0;
            getHeight(root,d);
            return d;
        }

    };
    int main(){
        int n;
        cin>>n;
        bst bst;
        while(n--){
            int x;
            cin>>x;
            bst.insert(x);
        }
        cout<<bst.findDistance();

        return 0;
    }