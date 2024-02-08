// For coding rounds
#include<bits/stdc++.h>
int lowerBound(vector<int> arr, int n, int x) {
	return lower_bound(arr.begin(),arr.end(),x) - arr.begin();
}
//Binary Search method
int lowerBound(vector<int> arr, int n, int x) {
	int low = 0, high = n-1;
	int ans = n;
	while(low<=high){
		int mid = (low+high)/2;
		if(arr[mid]>=x){
			// maybe an answer
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid+1;
		}
	}
	return ans;
}
