#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> v, int target) {
	int left = 0, right = v.size()-1;
    int res = -1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target < v[mid]) {
			right = mid - 1;
		} else if (target >= v[mid]) {
            res = mid;
			left = mid + 1;
		} 
	}
	return res + 1;
}
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    while(q--){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > r2 || l2 > r1){
            cout<<binary_search(v,r1)-binary_search(v,l1-1) + binary_search(v,r2)-binary_search(v,l2-1)<<endl;
        }else{
            int minn = min(l1,l2);
            int maxx = max(r1,r2);
            cout<<binary_search(v,maxx)-binary_search(v,minn-1)<<endl;
        }
    }
    return 0;
}