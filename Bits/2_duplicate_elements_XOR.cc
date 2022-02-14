#include <bits/stdc++.h>
using namespace std;

void nonDup(int* arr, int& n) {
    unsigned XOR = arr[0];
    for (int i = 1; i < n; i++) {
        XOR ^= arr[i];
    }

    unsigned x = 0, y = 0;
    unsigned rightmost_bit = XOR & ~(XOR - 1);   //turns on only the righmost bit in xor

    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmost_bit) {       //number having rightmost bit place set
            x = x ^ arr[i];
        }
        else {                              //rightmost bit place is not set
            y = y ^ arr[i];
        }
    }

    cout << x << " " << y;
}

int main() {
    int arr[] = { 2, 3, 7, 9, 11, 2, 3, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    nonDup(arr, n);
}