/*
Maximum sum contiguous subarray: Kadane's Algorithm

- Works only for array having mixed +ve and -ve numbers
- when only +ve or -ve numbers are there, element having maximum value is the max sum subarray
- it is both Greedy and DP approach simultaneously

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr) / sizeof(arr[0]);

	int curSum = 0, maxSum = 0;
	for (int i = 0; i < n; i++) {
		curSum += arr[i];				//sum current
		if (curSum > maxSum) {			//track maximum sum
			maxSum = curSum;
		}

		if (curSum < 0) {			//if curSum becomes < 0 at any point, we won't carry it to forward sum
			curSum = 0;
		}
	}

	cout << maxSum;

	return 0;
}