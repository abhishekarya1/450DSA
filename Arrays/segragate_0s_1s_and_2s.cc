/*
Q: Given an array of 0s, 1s, and 2s. Segragate them into three halves.

Dutch National Flag Algorithm by Dijkstra

Time Complexity: O(n)
Space Complexity: O(1)

Alternate naive O(n) solution: Traverse array and count the number of elements in each category. Traverse a second time and place elements accordingly.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[] = {1, 0, 2, 0, 2, 1, 0, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {				//notice range
		switch (arr[mid]) {
		case 0:
			swap(arr[mid], arr[low]);	//set 0 to low, we trust element coming from low after swap will always be 1 so we increment mid too
			low++;
			mid++;
			break;
		case 1:
			mid++;						//already 1
			break;
		case 2:
			swap(arr[mid], arr[high]);	//set 2 to high
			high--;	
			break;
		}
	}

	for (auto e : arr) {
		cout << e << " ";
	}

	return 0;
}