#include<iostream>
#include<vector>
using namespace std;
struct heap{
    vector<long long> heap;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2 * i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    void add(long long val){
        this->heap.push_back(val);
        int i = this->heap.size()-1;
        while(i!=0 && this->heap[parent(i)]>=this->heap[i]){
            swap(this->heap[parent(i)],this->heap[i]);
            i = parent(i);
        }
    }

    long long get_min(){
        if(this->heap.size()==0) return INT_MAX;
        if(this->heap.size()==1){
            long long root = this->heap[0];
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

};
int main(){
    heap h;
    int n;
    cin>>n;
    for(int i;i<n;i++){
        int x;
        cin>>x;
        h.add(x);
    }

    long long sum =0;
    while(h.heap.size()!=1){
        long long x =h.get_min();
        long long y =h.get_min();
        h.add(x+y);
        sum+=x+y;
    }
    cout<<sum;
    return 0;
}