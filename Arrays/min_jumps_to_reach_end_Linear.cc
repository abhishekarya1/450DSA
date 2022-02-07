/*
Leetcode: https://leetcode.com/problems/jump-game-ii/

Approach: Ladder and stairs concept
Time Complexity: O(n)
Space Complexity: O(1)
*/

int jump(vector<int>& arr) {
	int n = arr.size();

	int stairs = arr[0], ladder = 0 + arr[0];
	int jumps = 0;

	for (int i = 1; i < n; i++) {
		if (i == n - 1) {
			jumps++;
			return jumps;
		}
		if (arr[i] + i > ladder) {		//ladder is max reach, take whichever maximizes
			ladder = arr[i] + i;
		}

		stairs--;						//keep moving 1 step ahead

		if (stairs == 0) {				//if stairs are exhausted, then change ladders
			jumps++;					//jump to another ladder
			stairs = ladder - i;		//deduct steps already taken overlapping this ladder
		}
	}

	return jumps;
}