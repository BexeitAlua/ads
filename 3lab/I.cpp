#include<iostream>
#include <vector>
using namespace std;

int binary_search(int target,int a[],int size){
    int left =0;
    int right = size -1;
    while(left < right){
        int mid = left+(right - left);
        if(a[mid]<target){
            left = mid +1;
        }
        else if(a[mid]>target){
            right = mid -1;
        }else {
            return mid;
        }
    }

}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    int res;


    if ( binary_search(k,a,n)==true){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}