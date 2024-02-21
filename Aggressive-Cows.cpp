#include<bits/stdc++.h>
bool canwePlace(vector<int> &stalls, int dist , int cows){
    int cntCows = 1; // no of cows places
    int last = stalls[0]; // last cow position
    for(int i = 1 ; i<stalls.size(); i++){
        if(stalls[i]-last >=dist){
            cntCows++;  // place next cow
            last = stalls[i]; // update last cow location
        }
        if(cntCows>=cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low = 1 , high = stalls[n-1] - stalls[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canwePlace(stalls,mid,k)== true){
            // ans = mid;
            low = mid + 1;
        }else{
            high = mid-1;
        }
    }
    return high;  // or return ans;
}
