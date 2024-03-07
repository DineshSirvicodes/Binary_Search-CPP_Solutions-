// Brute Sol = TC - O (n*m) * 4 - where 4 represents in  all 4 directions
// Go thru each elemnt in the matrix and check if the current element is greater than left, right , top and down then that element is the peak element

// Optimal SOl TC - O ( log2 (n*m)
class Solution {
public:
    int findMaxIndex(vector<vector<int>> &mat,int n,int m, int col){
        int maxVal = -1;
        int index = -1;
        for(int i = 0; i < n ; i++){ // iterating thru the entire col top to down
            if(mat[i][col]>maxVal){
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index; // this index in that col will have max value
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid = (low+high)/2; // col
            int maxRow = findMaxIndex(mat,n,m,mid);
            //int left = mid-1>=0 ? mat[maxRow][mid-1] : -1;
            // left = to be within boundary, then left = mat[maxrow][mid-1] or else -1
            //int right = mid+1<m ? mat[maxRow][mid+1] : -1;
            int left, right;
            if(mid-1>=0) {
                left = mat[maxRow][mid-1];
            }
            else{
                left = -1;
            } 
            if(mid+1<m){
                right = mat[maxRow][mid+1];
            }
            else {
                right = -1;
            }

            if( mat[maxRow][mid] > left && mat[maxRow][mid] > right){
                return {maxRow,mid};
            }
            else if (mat[maxRow][mid]<left){ // we are on right half the peak would be on 
                high  = mid-1 ;             // left , so eliminate right half
            }
            else low = mid+1;

        }
        return {-1,-1};
    }
};
