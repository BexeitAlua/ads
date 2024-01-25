#include<iostream>
using namespace std;
int binaryIncSearch(int a[],int target,int size){
    int left =0,right = size -1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(target<a[mid]){
            right = mid - 1;
        }else if(target>a[mid]){
            left = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}
int binaryDecSerach(int a[],int target,int size){
    int left = 0, right = size -1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(target>a[mid]){
            right = mid -1;
        }else if (target<a[mid]){
            left = mid +1;
        }else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m,k;
    cin>>m>>k;
    int b[m][k];
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin>>b[i][j];
        }
    }

    int index;
    for (int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(j % 2==0){
                index = binaryIncSearch(b[j],a[i],k);
            }else{
                index = binaryDecSerach(b[j],a[i],k);
            }
            if (index!= -1){
                cout<<j<<" "<<index<<endl ;    
                break;      
                }else if(index == -1 ) {
                    cout<<-1<<endl;
                    break;
                }

        }
    }

    return 0;
}