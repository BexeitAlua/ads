#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubarrayLength(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0;
    int min_length = INT_MAX;
    int current_sum = 0;

    for (int right = 0; right < n; right++) {
        current_sum += arr[right];

        while (current_sum >= k) {
            min_length = min(min_length, right - left + 1);
            current_sum -= arr[left];
            left++;
        }
    }

    return min_length == INT_MAX ? 0 : min_length;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = minSubarrayLength(arr, k);
    cout << result << endl;

    return 0;
}





