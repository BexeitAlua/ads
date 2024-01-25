#include<iostream>
using namespace std;
struct node{
    int val;
    node * right;
    node * left;
    node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
struct bst{
    private:
        node * root;
        node * add( node * cur,int val){
            if ( cur == NULL){
                cur = new node(val);
            }
            else if (val<cur->val){
                cur->left=add(cur->left,val);
            }
            else if (val>cur->val){
                cur->right = add(cur->right,val);
            }
            return cur;
        }
        int sizeTree(node * node){
            if(!node){
                return 0;
            }
            return sizeTree(node->left)+sizeTree(node->right)+1;
        }
        node * search(node * cur,int target){
            if(!cur){
                return NULL;
            }
            if(cur->val == target){
                return cur;
            }
            if(cur->val >target){
                return search(cur->left,target);
            }
            if(cur->val<target){
                return search(cur->right,target);
            }
    
        }
    public:
        bst(){
                this->root = NULL;
        }
        void _add(int val){
            node * temp = add(root,val);
        }
        node * _search(int target){
            return search(root,target);
        }
        int _sizeTree(node * cur){
            return sizeTree(cur);
        }    
};
int main(){
    bst bst;
    int n,k;
    cin>>n;
    for(int i  = 0;i<n;i++){
        int x;
        cin>>x;
        bst._add(x);
    }
    cin>>k;
    cout<<bst._sizeTree(bst._search(k));
    

    return 0;
}