/*
Q: Given an array of 0s and 1s. Segragate them into two halves having only 0s and only 1s on each side.
Alternate Form: Given an array of negative and positive numbers. Segragate them into two halves having only positives and only negatives on each side.

Time Complexity: O(n)
Space Complexity: O(1)

Alternate naive O(n) solution: Traverse array and count the number of elements in each category. Traverse a second time and place elements accordingly.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[] = {1, 0, 1, 0, 1, 1, 0, 0};
	int n = sizeof(arr) / sizeof(arr[0]);

	int low = 0, high = n - 1;			//two pointers
	while (low < high) {
		if (arr[low] == 1) {			//unexpected element
			swap(arr[low], arr[high]);	//swap
			high--;						//since we swapped, we can be sure that 1 is placed on right side
		}
		else {
			low++;						//no swap means 0 was encountered
		}
	}

	for (auto e : arr) {
		cout << e << " ";
	}

	return 0;
}