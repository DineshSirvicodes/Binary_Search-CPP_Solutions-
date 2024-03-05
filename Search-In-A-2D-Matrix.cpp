// Brute Sol 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0 ; i<matrix.size(); i++){
            for(int j = 0 ; j<matrix[0].size(); j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};

// Better Sol - Binary Search while iteration of each row , and considerating it a single array TC - O(N) + O (log2(m)) where m is col size
class Solution {
public:
    bool bs(vector<int>&nums, int target){
        int low = 0 , high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return true;
            else if( target > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(int i = 0 ; i<matrix.size(); i++){
            if(matrix[i][0]<=target && target <= matrix[i][n-1]){
                return bs(matrix[i],target);
            }
        }
        return false;
    }
};

// Optimal Sol - TC - O(log2(n*m)) 
// n - row , m - col
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // row
        int m = matrix[0].size(); // col
        int low = 0 , high = (n*m)-1; // last index of the matrix
        while(low<=high){
            int mid = (low+high)/2;
            int row = mid/m; // find 1d to 2d coordinate points
            int col = mid%m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};
