class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int up = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(lb == nums.size() || nums[lb] != target)  return {-1,-1}; // if lb is pointing at the end + 1 ind of the array or
        return {lb,up-1};                   // target is not there in the array return -1,-1
    }
};

TC - 2 * O(logn)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;                 
                }
                last = i;
            }             
        }
        return {first,last};
    }
};

TC - O(N) 

// Plain Binary Search Concepts
class Solution {
public:
    int firstOcc(vector<int>& nums,int target){
        int low = 0, high = nums.size()-1;
        int first = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;  // can be the first but need to find the first index
                high = mid-1;  // to find small index
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return first;
    }
    int lastOcc(vector<int> &nums, int target){
        int low = 0, high = nums.size()-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                last = mid; // maybe the answer but needed the last index bigger index
                low = mid+1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstNo = firstOcc(nums,target);
        if(firstNo == -1) return {-1,-1};
        int lastNo = lastOcc(nums,target);
        return {firstNo,lastNo};
    }
};
TC= 2*O(logn) // 2 times binary search for first and last
Sc = o(1)
