/*
Link: https://leetcode.com/problems/merge-intervals/

Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
};

bool comp(Interval i, Interval j) {
    return (i.start < j.start);
}

int main() {
    vector<Interval> arr = {{1, 3}, {2, 4}, {5, 7}, {8, 11}, {10, 13}};
    int n = arr.size();

    sort(arr.begin(), arr.end(), comp);

    int index = 0;                  //we will form an array on left side of arr tracked by "index" by bringing elements from right side tracked by "i"
    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) { //overlap
            arr[index].end = arr[i].end;    //merge and add to left side (change end of "index" to larger one)
        }
        else {
            index++;                    //building merged interval array on left side, bring next interval to index + 1 position
            arr[index] = arr[i];        //add element req no merge to left side as it is (index + 1 position)
        }
    }

    for (int i = 0; i <= index; i++) {
        cout << arr[i].start << "," << arr[i].end << "\n";
    }
}
