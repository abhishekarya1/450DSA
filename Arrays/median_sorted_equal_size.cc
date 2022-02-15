/*

Link: https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

Time Complexity: O(logn)
Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int median(int* arr, int n) {
	if (n & 1)
		return arr[n / 2];
	else
		return (arr[n / 2] + arr[n / 2 - 1]) / 2;
}

int getMedian(int* arr1, int* arr2, int n) {
	if (n <= 0)
		return -1;
	if (n == 1)
		return (arr1[0] + arr2[0]) / 2;

	//formula
	if (n == 2)
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;

	int m1 = median(arr1, n);
	int m2 = median(arr2, n);

	if (m1 == m2)
		return m1;

	// if m1 < m2 then median must exist in arr1[m1....] and arr2[....m2]
	// n/2+1 because in the original call we were 1 ahead of last index (n-1 being last index and n being third argument to method)
	if (m1 < m2)
	{
		if (n % 2 == 0)
			return getMedian(arr1 + n / 2 - 1, arr2, n / 2 + 1);
		return getMedian(arr1 + n / 2, arr2, n / 2 + 1);
	}

	// if m1 > m2 then median must exist in arr1[....m1] and arr2[m2...]
	if (n % 2 == 0)
		return getMedian(arr2 + n / 2 - 1, arr1, n / 2 + 1);
	return getMedian(arr2 + n / 2, arr1, n / 2 + 1);
}

int main() {
	int arr1[] = {1, 2, 3, 6};
	int arr2[] = {4, 6, 8, 10};

	int n = sizeof(arr2) / sizeof(arr2[0]);

	cout << getMedian(arr1, arr2, n);
}