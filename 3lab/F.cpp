#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> binary_search(int a[], int target,int size){
    int left = 0, right = size, mid, sum = 0;
    while (left < right){
        mid = left + (right - left) / 2;
        if (target == a[mid]){
            while (mid + 1 < size && a[mid + 1] == target){
                mid++;
            }
            break;
        }else if (target < a[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    while (mid > -1 && a[mid] > target){
        mid--;
    }
    for (int i = 0; i <= mid; i++){
        sum += a[i];
    }
    return make_pair(mid + 1, sum);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int p;
    cin >> p;
    while (p--){
        int power;
        cin >> power;
        pair<int, int> res = binary_search(a, power, n);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}