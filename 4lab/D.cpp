#include<iostream>
#include<vector>
using namespace std;

struct node{
    node * right;
    node * left;
    int val;
    node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};
struct bst{
   private:
    node *root;
    node * add(int val,node * cur){
        if(!cur){
            return new node(val);
        }
        if(val>cur->val){
            cur->right = add(val,cur->right);
        }
        else if(val<cur->val){
            cur->left = add(val,cur->left);
        }
        return cur;
    } 
    int getSize(node *node){
        if(!node) return 0;
        return getSize(node->left)+getSize(node->right)+1;
    }
   public:
   bst(){
    this->root = NULL;
   }
   void _add(int val){
    node * temp = add(val,root);
    if(!root) {
        root = temp;
    }
   }
   int _getSize(){
    return getSize(root);
   }
   node * getRoot(){
    return root;
   }
   int getHeight(node *node){
    if (!node) return 0;
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return max(left,right)+1;
   }

   void getSum(node * cur,int lvl,vector<int>&v){
    if(!cur) return;
    v[lvl]+=cur->val;
    getSum(cur->left,lvl + 1,v);
    getSum(cur->right,lvl + 1,v);

   }

};


int main(){
    bst bst;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        bst._add(x);

    }
    vector<int> v (bst.getHeight(bst.getRoot()));
    bst.getSum(bst.getRoot(),0,v);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}