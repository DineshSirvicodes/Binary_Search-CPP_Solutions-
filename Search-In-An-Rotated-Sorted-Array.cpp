// Brute Solution TC = O(N)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};

// Optimal Solution - Binary Search TC - O(logn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() - 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            //left sorted check
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;  // if we find the target in left side
                } else{
                    low = mid+1;
                }
            }
            // right sorted check
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;    //if we find the target on right side
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
