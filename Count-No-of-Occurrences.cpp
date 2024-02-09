int firstOcc(vector<int>& arr,int n ,int k){
        int low = 0, high = n-1;
        int first = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == k){
                first = mid;  // can be the first but need to find the first index
                high = mid-1;  // to find small index
            }
            else if(arr[mid]<k){
                low = mid+1;
            }
            else high = mid-1;
        }
        return first;
    }
    int lastOcc(vector<int> &arr,int n, int k){
        int low = 0, high =n-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == k){
                last = mid; // maybe the answer but needed the last index bigger index
                low = mid+1;
            }
            else if(arr[mid]<k) low = mid+1;
            else high = mid-1;
        }
        return last;
    }
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOcc(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOcc(arr, n, k);
    return {first, last};
}
int count(vector<int>& arr, int n, int k) {
	// Write Your Code Here
	pair<int,int> ans = firstAndLastPosition(arr,n,k);
	if(ans.first == -1) return 0;
	return (ans.second - ans.first+1);

}

Second method 
int count(vector<int>& arr, int n, int x) {
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int up = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    if (lb == n || arr[lb] != x) return 0;
    return up - lb;
}
