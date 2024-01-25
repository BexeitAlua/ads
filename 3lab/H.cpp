#include<iostream>
#include<vector>
using namespace std;
int binary_search(int target,int a[],int size){
    int left =0;
    int right = size -1;
    while(left<right){
        int mid = left + (right - left)/2;
        if(target>a[mid]){
            left = mid+1;
        }else if(target<a[mid]){
            right=mid -1;
        }
    }
    return left;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for (int i =0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int res[n];
    res[0]=v[0];
    for (int i=0;i<v.size();i++){
        res[i]=v[i]+ res[i-1];
    }
    for (int i =0;i<m;i++){
        int y;cin>>y;
        cout<<binary_search(y,res,n)+1<<endl;
    }


}