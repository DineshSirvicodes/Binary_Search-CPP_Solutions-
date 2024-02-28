// Optimal Solution 
int numberofGasStations(long double dist , vector<int> &arr){
	int cnt = 0;
	for(int i = 1 ; i<arr.size(); i++){
		int numberinbetween = ((arr[i]-arr[i-1])/dist);
		if((arr[i]-arr[i-1])/dist == numberinbetween*dist){
			numberinbetween--;  // for 0.5 when 1/0.5 gives exact as 2 
								// for 0.4 gives 2.something so round to 2
		}
		cnt+=numberinbetween;
	}
	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double low = 0;
	long double high = 0;
	for(int i = 0 ; i<n-1; i++){
		high = max(high,(long double)(arr[i+1]-arr[i]));
	}
	long double diff = 1e-6;
	while(high - low > diff){
		long double mid = (low+high)/(2.0);
		int cnt = numberofGasStations(mid,arr);
		if(cnt>k){ 
			low = mid;
		}
		else{
			high = mid;
		}
	}
	return high;
}
