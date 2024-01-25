#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct hp{
	vector<long long> heap;

	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return 2*i +1;

	}
	int right(int i){
		return 2*i + 2;
	}

	void add(long long val){
		this->heap.push_back(val);
		int i = this->heap.size()-1;
		while(i>0 && this->heap[parent(i)]<this->heap[i]){
			swap(this->heap[parent(i)],this->heap[i]);
			i = parent(i);
		}
	}
	void heapify(int i){
		int l = this->left(i);
		int r = this->right(i);
		int biggest = i;
		if(l<this->heap.size() && this->heap[l]>this->heap[biggest]){
			biggest = l;
		}
		if(r<this->heap.size() && this->heap[r]>this->heap[biggest]){
			biggest = r;
		}
		if(biggest!=i){
			swap(this->heap[i],this->heap[biggest]);
			this->heapify(biggest);
		}
	}

	long long get_max(){
		if(this->heap.size() == 0) return INT_MAX;
		if(this->heap.size()==1){
			long long root= this->heap[0];
			this->heap.pop_back();
			return root;
		}
		long long root  = this->heap[0];
		this->heap[0] = this->heap[this->heap.size()-1];
		this->heap.pop_back();
		this->heapify(0);
		return root;

	}
};

int main(){
	hp h;
	int n,k;
	cin>>n>>k;
	while(n--){
		long long row;
		cin>>row;
		h.add(row);
	}

	long long sum=0;
	while(k--){
		long long maxRow = h.get_max();
		sum+=maxRow;
		h.add(maxRow-1);
	}
	cout<<sum;

	return 0;
}