#include<bits/stdc++.h>
using namespace std;

struct MinHeap {
    vector<long long> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    void insert(long long value) {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while (i != 0 && this->heap[parent(i)] >= this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }
    long long extactMin() {
        if (this->heap.size() == 0) return INT_MAX;
        if (this->heap.size() == 1) {
            long long root = this->heap[0];
            this->heap.pop_back();
            return root;
        }
        long long root = this->heap[0];
        this->heap[0] = this->heap[this->heap.size() - 1];
        this->heap.pop_back();
        this->heapify(0);
        return root;
    }
    void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
};

int main() {
    MinHeap m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m.insert(x);
    }
    long long sum = 0;
   while(m.heap.size()!=1){
    long long x  = m.extactMin();
    long long y = m.extactMin();
    m.insert(x+y);
    sum+=x+y;
   }

   cout<<sum;
    return 0;
}