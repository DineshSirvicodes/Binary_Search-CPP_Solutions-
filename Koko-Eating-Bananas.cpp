class Solution {
public:
    long long maxEl(vector<int> &piles){
        int  maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i<n ; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long totalHoursFind(vector<int> &piles, int hourly){
        long long n = piles.size();
        long long totalHours = 0;
        for(int i = 0 ; i<n ; i++){
            totalHours += ceil((double)(piles[i])/(double)(hourly));
        }
        return totalHours;
    }
    long long minEatingSpeed(vector<int>& piles, int h) {

        long long low = 1, high = maxEl(piles);
        while(low<=high){
            long long mid = (low+high)/2;
            long long totalH = totalHoursFind(piles,mid);
            if(totalH <= h){
                                 //ans = mid;
                high = mid-1;   // ele is possibe ans , but find min
            }else{
                low = mid+1;  // ele is too small 
            }
        }
        return low;               //return ans;
    }
};
