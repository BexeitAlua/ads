#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct heap{
    vector<int> heap;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2 * i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    void add(int val){
        this->heap.push_back(val);
        int i = this->heap.size()-1;
        while(i!=0 && this->heap[parent(i)]>=this->heap[i]){
            swap(this->heap[parent(i)],this->heap[i]);
            i = parent(i);
        }
    }

    int get_min(){
        if(this->heap.size()==0) return INT_MAX;
        if(this->heap.size()==1){
            int root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size()-1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void heapify(int i){
        int l = this->left(i);
        int r = this->right(i);
        int smallest =i;
        if(l<this->heap.size()&&this->heap[l]<this->heap[smallest]){
            smallest = l;
        }
        if(r<this->heap.size()&&this->heap[r]<this->heap[smallest]){
            smallest = r;
        }
        if(smallest!=i){
            swap(this->heap[i],this->heap[smallest]);
            this->heapify(smallest);
        }

    }
    int minimum(){
        return this->heap[0];
    }
    bool empty(){
        return this->heap.size()==0;
    }
    int size(){
        return this->heap.size();
    }

};
bool check(vector<int> heap,int m){
    for(int i =0;i<heap.size(); i ++){
        if(i<m) return true;
    return false;
    }}
int main(){
    heap h;
    int n,k;
    cin>>n>>k;
    for(int i;i<n;i++){
        int x;
        cin>>x;
        h.add(x);
    }

    int res =0;
    while(h.minimum()<k && h.size()>1){
        res++;
        int min = h.get_min();
        int sec_min = h.get_min();
        h.add(min + 2*sec_min);

    }
    if(h.heap.size()==1 && h.get_min()<k){
        cout<<-1<<endl;
    }
    else{
        cout<<res<<endl;
    }
    return 0;
}