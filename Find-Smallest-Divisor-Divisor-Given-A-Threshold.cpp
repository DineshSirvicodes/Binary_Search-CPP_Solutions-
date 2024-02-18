
// TC - O (log2(maxi)*N)  where N is the size of the array
class Solution {
public:
    int div(vector<int> &nums,int divisor){
        int sum = 0;
        for(int i = 0 ; i<nums.size(); i++){
            sum+=ceil((double)(nums[i])/(double)(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = (low+high)/2;
            if( div(nums,mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
