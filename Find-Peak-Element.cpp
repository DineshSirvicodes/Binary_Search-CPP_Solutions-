// Brute solution - TC O(n)
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        if (( i == 0 || arr[i-1]<arr[i]) && 
            ( i == n-1 || arr[i]>arr[i+1]))
        {
            return i;
        }
    }
    return -1;
    
}

// Optimal solution Binary search TC - O(logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // Edge cases
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int low = 1 , high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            // mid is greater than left and greater than right
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                low = mid+1;        // increasing curve mid is on left, so peak is on right
            }   
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
