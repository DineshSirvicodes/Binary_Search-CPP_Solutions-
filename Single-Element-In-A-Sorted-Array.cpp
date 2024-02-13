class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];  // if first is not equal to second then it is our element
        if(nums[n-1] != nums[n-2]) return nums[n-1]; // if last is not equal to second last

        int low = 1, high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];  
            }
                // odd          // even                             // even         //odd
            if((mid%2 == 1 && nums[mid - 1] == nums[mid]) || (mid%2 == 0 && nums[mid] == nums[mid+1])){
                low = mid+1; // eliminate left half as the element is on right
            }
            else{
                high = mid-1 ; // eliminate right half as element is on left
            }

        }
        return -1;
    }
};
