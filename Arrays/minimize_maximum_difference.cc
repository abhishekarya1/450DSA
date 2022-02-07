/*
Minimize the maximum difference between the heights.

Time Complexity: O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[] = {1, 10, 14, 14, 14, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 6;

	sort(arr, arr + n);                  //sort the array

	int minDiff = arr[n - 1] - arr[0];                  //default difference
	int maxE, minE;
	for (int i = 1; i < n; i++) {
		maxE = max(arr[n - 1] - k, arr[i - 1] + k);     //take two neighbouring elements, arr[i-1] and arr[i] since we start from index i = 1
		minE = min(arr[0] + k, arr[i] - k);             //possible max in this pair is the right one minus k, but track if it becomes greater than arr[n-1]-k at any point
		//similarly for minimum
		if (minE < 0) {                                 //can't handle negative numbers
			continue;
		}

		minDiff = min(minDiff, maxE - minE);
	}

	cout << minDiff;

	return 0;
}