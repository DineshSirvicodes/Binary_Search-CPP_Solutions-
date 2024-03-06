// Brute SOl  TC - O(n*m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(matrix[i][j] == target) return true;
                // to return indexes
                // return {i,j}
            }
        }
        return false;
    }
};
// Better Sol - O (n * log2(m)) - Binary Search
class Solution {
public:
    bool bs(vector<int> &arr, int target){
        int low = 0 , high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return true;
            else if( arr[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        //int m = matrix[0].size();
        // to return the index
      //   for(int i = 0; i<n ; i++){
      //       int ind = bs(matrix[i],target)
      //       if(ind != -1)) return {i,ind};
      //   }
      // return {-1,-1};
        for(int i = 0; i<n ; i++){
            if(bs(matrix[i],target)) return true;
        }
        return false;
    }
};
// Optimal SOl - TC - O(n+m)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0  , col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col] == target) return true;
              // return {row,col} if index is wanted
            else if (matrix[row][col]<target){
                row++; // element will not be on that row
            }
            else {
                col--; // not on that col
            }
        }
        return false;
    }
};
