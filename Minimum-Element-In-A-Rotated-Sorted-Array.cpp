// Binary Search O(logn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1,ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            //if left is sorted check
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);   // if left is sorted, nums[low] will be minimum
                low = mid+1;                //{3,4,5,1,2} = low = 0
            }
            else{   // right half is sorted
                ans = min(ans,nums[mid]);   // in right half mid will be minimum
                high = mid-1;
            }
        }
        return ans;
    }
};
// Little Optimization(if need to do your wish)'
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1,ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            // search space is already sorted then always arr[low] will be smaller in 
            // that search space
            if(nums[low]<=nums[high]){
                ans = min(ans,nums[low]);
                break;
            }
            //if left is sorted check
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);   // if left is sorted, nums[low] will be minimum
                low = mid+1;                //{3,4,5,1,2} = low = 0
            }
            else{   // right half is sorted
                ans = min(ans,nums[mid]);   // in right half mid will be minimum
                high = mid-1;
            }
        }
        return ans;
    }
};
