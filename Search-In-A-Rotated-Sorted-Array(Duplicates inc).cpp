// Brute Solutiion TC O(n)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] == target) return true;
        }
        return false;
    }
};

// Optimal solution TC - O(logN) average case ,  worst case O(N/2) shrinking search space nearly half
//, when the condition is arr[low] == arr[mid] == arr[high]
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;
            // Edge case
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;  // shrink the search space
                continue;   // check again if this condition arises
            }
            // check left half as sorted or not
            if(nums[low]<=nums[mid]){
                //if element is found on left half
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }else{ // if found on right half
                if(nums[mid]<=target && target<=nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }

        }
        return false;
    }
};
