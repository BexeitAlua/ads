#include <iostream>
using namespace std;

int binaryIncreasingSearch(int ar[], int target, int size) {
	int left = 0, right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target < ar[mid]) {
			right = mid - 1;
		} else if (target > ar[mid]) {
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int binaryDecreasingSearch(int ar[], int target, int size) {
	int left = 0, right = size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (target > ar[mid]) {
			right = mid - 1;
		} else if (target < ar[mid]) {
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	int ar1[n];
	for (int i = 0; i < n; i++) {
		cin >> ar1[i];
	}
	int a,b;
	cin >> a >> b;
	int ar2[a][b];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> ar2[i][j];
		}
	}
	int index;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			if (j % 2 != 0) {
				index = binaryIncreasingSearch(ar2[j], ar1[i], b);
			} else {
				index = binaryDecreasingSearch(ar2[j], ar1[i], b);
			}
			if (index != -1) {
				cout << j << " " << index << endl;
				break;
			} else if (index == -1 && j == a - 1) {
				cout << -1 << endl;
				break;
			}
		}
	}
	return 0;
}