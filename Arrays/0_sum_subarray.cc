/*
Q: Check if there is any subarray that sums to 0.

Time Complexity: O(n), if hash operations take O(1) time
Space Complexity: O(1)
*/

#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main() {
	vector<int> arr = {1, 4, -2, -2, 5, -4, 3};
	int n = arr.size();

	unordered_set<int> s;           //to do find operation in O(1) time

	int preSum = 0;
	for (int i = 0; i < n; i++) {
		preSum += arr[i];                   //calculate prefix sum
		if (preSum == 0 || s.find(preSum) != s.end()) { 
		//check if it is 0 or seen earlier 
			// (if sum repeats then that means there is a subaray in between which contributed 0 to sum)
			cout << boolalpha << true;
			return 0;
		}
		else {
			s.insert(preSum);       //if not seen earlier; insert into hash
		}
	}

	cout << boolalpha << false;
}