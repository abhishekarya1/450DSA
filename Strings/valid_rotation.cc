/*
Link: https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

#include <iostream>
#include<vector>
using namespace std;

bool isRotn(string str, string rotn, int n, int i) {
    for (int j = 0; j < n; j++, i++) {
        if (rotn[j] != str[i % n]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str = "abhishek";
    string rotn = "hekabhis";

    int n = str.length();
    int m = rotn.length();

    if (n != m) return -1;

    vector<int> v;

    //find all positions of first element in rotn in str
    for (int i = 0; i < n; i++) {
        if (rotn[0] == str[i]) {
            v.push_back(i);
        }
    }

    //traverse and compare str and rotn for every position after positions determined above
    for (int i = 0; i < v.size(); i++) {
        if (isRotn(str, rotn, n, v[i]) == true) {
            cout << "Rotation";
            return 0;
        }
    }
    cout << "Not Rotation";
}
