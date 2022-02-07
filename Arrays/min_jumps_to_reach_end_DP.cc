int jump(vector<int>& arr) {
    int n = arr.size();

    //initialise jumps array with unreachable elements
    int jumps[n];
    for (int i = 0; i < n; i++) jumps[i] = INT_MAX;

    //first element needs no steps
    jumps[0] = 0;

    //populate jumps[] for each element starting from index 1
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (i <= arr[j] + j) {                          //i is reachable from j
                jumps[i] = min(jumps[i], jumps[j] + 1);     //(steps till j) + (1) steps to reach i from start
            }
        }
    }

    return jumps[n - 1];
}
