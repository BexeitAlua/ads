#include<iostream>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;

    node(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

struct bst{
private:
    node * root;
    node * add(node * cur,int val){
        if(cur == NULL){
            cur = new node(val);
        }
        else if (val < cur->val){
            cur->left = add(cur->left,val);
        }
        else if(val>cur->val){
            cur->right = add(cur->right,val);
        }
        return cur;
    }
public:
        bst(){
            this->root = NULL;
        }
        void _add(int val){
            node * temp = add(root,val);
            if(!root){
                root = temp;
            }
        }
        bool route_found(string route){
            node * cur = root;
            for ( int i =0;i<route.size();i++){
                char c = route[i];
                if(c =='L'){
                    cur = cur->left;
                }else{
                    cur = cur->right;
                }
                if (!cur){
                    return false;
                }

            }
            return true;
        }

};


int main(){
    bst bst;
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        bst._add(x);
    }

    while(m--){
        string s;
        cin>>s;
        if(bst.route_found(s)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;

}