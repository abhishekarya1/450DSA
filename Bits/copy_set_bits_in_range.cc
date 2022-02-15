/*

Link: https://www.geeksforgeeks.org/copy-set-bits-in-a-range/

Time Complexity: O(r)
Space Complexity: O(1)

*/

#include <iostream>
using namespace std;
int main() {
	unsigned x = 10, y = 13, l = 2, r = 3;

	//prepare mask
	unsigned mask_prep = 1 << (r - l + 1) - 1;

	//based on the observation that any number of the form
	// 2^n - 1 will have rightmost set bit of 2^n as 0 alongwith all bits to its right side as 1

	//shift to position and create mask from y
	unsigned mask = mask << (l - 1) & y;

	//apply mask
	x |= mask;

	cout << x;
}
