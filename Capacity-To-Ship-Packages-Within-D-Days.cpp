// Brute Solution = gives TLE TC - O((sum-max)+1)*(n))
class Solution {
public:
    int daysCalculate(vector<int>&weights,int cap){
        int daysReq = 1, load = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(load+weights[i]>cap){
                daysReq = daysReq+1;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return daysReq;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(),weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        for(int i = maxi ; i<=sum; i++){        
            if(daysCalculate(weights,i)<=days){
                return i;
            }
        }
        return -1;
    }
};

//Optimal Sol - Binary Search TC - O(log(sum - maxi)*(N))
class Solution {
public:
    int daysCalculate(vector<int>&weights,int cap){
        int daysReq = 1, load = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(load+weights[i]>cap){
                daysReq = daysReq+1;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return daysReq;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(),weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int low = maxi, high = sum;
        while(low<=high){
            int mid = (low+high)/2;
            if(daysCalculate(weights,mid)<=days){      // if the mid->capacity at the moment , and the calculated days is <=days find minimum;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
