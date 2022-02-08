/*
Q: Rearrange an array such that positive and negative numbers occur at alternate positions.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3};
	int n = arr.size();

	//rearrange in O(n) time
	int l = 0, h = n - 1;
	while (l < h) {
		if (arr[l] < 0) {
			swap(arr[l], arr[h]);
			h--;
		}
		else {
			l++;
		}
	}

	if (arr[l] < 0) {};     //l is at leftmost negative element; do nothing
	else if (arr[l] > 0) {
		l += 1;             //l is at rightmost positive element; increment l by 1 to point it to negative elements
	}

	//l holds the index of leftmost negative number
	//swap alternate elements
	for (int i = l + 2, s = 1; i < n && s < n; i += 2, s += 2) {
		swap(arr[i], arr[s]);
	}

	for (auto e : arr) {
		cout << e << " ";
	}
}