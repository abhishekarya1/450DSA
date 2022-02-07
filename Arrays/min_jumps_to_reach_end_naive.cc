int jump(vector<int>& arr) {
    int start = 0, end = 0, maxReach = start + arr[0], steps = 0;
    int n = arr.size();

    while (end < n - 1) {                              //last element is excluded because if (end == n-1) then we have reached the end
        maxReach = 0;                                  //reset max of new window
        for (int i = start; i <= end; i++) {           //traverse window and
            maxReach = max(arr[i] + i, maxReach);      //find max reachable index in window
        }
        start = end + 1;                                //move window
        end = maxReach;
        steps++;                                        //increment step    
    }

    return steps;
}