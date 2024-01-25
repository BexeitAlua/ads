#include<iostream>
#include<vector>
#include<algorithm>
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
    node * root;

    node * add(int val,node * cur){
        if (!cur) return NULL;
        if(cur->val>val){
            cur->left = add(val,cur->left);
        }
        else if(cur->val<val){
            cur->right = add(val,cur->right);
        }
        return cur;
    }
    node * search(node * cur,int target){
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
    bst(){
        this->root = NULL;
    }
    void _add(int val){
        node* temp = add(val,root);
        if(root==NULL){
            root = temp;
        } 
    }
    node * _search(int target){
        return search(root,target);
    }
    void setRoot(node * root){
        this->root = root;
    }
    int getHeight(node * node){
        if(!node) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        return max(left,right)+1;
    }
    node * getRoot(){
        return root;
    }

    
};
void dfs(node * node,int lvl,vector<int> v){
        if(!node)return;
        v[lvl]++;
        dfs(node->left,lvl+1,v);
        dfs(node->right,lvl+1,v);
    }
    

int main(){
    bst bst;
    int n;
    cin>>n;
    n--;
    bst.setRoot(new node(1));
    while (n--){
        int x,y,z;
        cin>>x>>y>>z;
        node * parent = bst._search(x);
        if(z == 0){
            parent->left= new node(y);
        }
        else{
            parent->right = new node(y);
        }
    }
    int levels = bst.getHeight(bst.getRoot());
    vector<int> v(levels);
    dfs(bst.getRoot(),0,v);
    sort(v.begin(),v.end());
    cout<<v[v.size()-1];

    return 0;
}