#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleCapacity(int capacity, const vector<int>& islands, int f) {
    int flightsRequired = 0;
    for (size_t i = 0; i < islands.size(); i++) {
        flightsRequired += (islands[i] + capacity - 1) / capacity;
    }
    return flightsRequired <= f;
}

int findMinimumCapacity(int n, int f, const vector<int>& islands) {
    int left = 1;
    int right = 1e9; 
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossibleCapacity(mid, islands, f)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> islands(n);

    for (int i = 0; i < n; i++) {
        cin >> islands[i];
    }

    int minimumCapacity = findMinimumCapacity(n, f, islands);
    cout << minimumCapacity << endl;

    return 0;
}


