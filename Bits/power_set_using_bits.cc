/*

Link: https://www.geeksforgeeks.org/power-set/

Time Complexity: O(n^2 * n)
Space Complexity: O(1)
*/

#include <iostream>
#include<cmath>
using namespace std;

int main() {
	char set[] = {'a', 'b', 'c'};
	int n = sizeof(set) / sizeof(set[0]);

	//power_set_size
	int power_set = pow(2, n);

	//generate bits and map to set elements
	for (int i = 0; i < power_set; i++) {
		for (int j = 0; j < n ; j++) {  //check each bit position in bits
			if (i & (1 << j)) {         //if jth bit position is set, display corresponding element in set
				cout << set[j];
			}
		}
		cout << "\n";
	}
}