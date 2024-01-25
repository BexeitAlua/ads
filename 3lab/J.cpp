#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n,h;
    cin>>n>>h;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int left = 1, right = 0, mid;
    for (int i = 0; i < v.size(); i++) {
        right = max(right, v[i]);
    }
    while (left < right) {
        mid = left + (right - left) / 2;
        int requiredFlights = 0;
        for (int i = 0; i < n; i++) {
        requiredFlights += (v[i] + mid - 1) / mid;
        }
        if (h >= requiredFlights) {
    yy    right = mid;
        }
        else {
        left = mid + 1;
        }
    }
    cout << left;
    return 0;
}