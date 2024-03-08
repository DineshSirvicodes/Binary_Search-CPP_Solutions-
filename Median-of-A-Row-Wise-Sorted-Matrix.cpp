// Brute force TC -  O(row*col * log(row*col)), SC - O(row*col)
// go thru each matrix element and store it in a array of size n*m and sort the array, and then find the array of size(n*m)/2 as the array will be odd so doing half is the ans 
int Findmedian(int arr[3][3], int row, int col)
{
  int median[row * col];
  int index = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      median[index] = arr[i][j];
      index++;
    }
  }
 
  return median[(row * col) / 2];
}

// Optimal SOl - TC -  O(row*log col) , SC - O(1)
int upperBound(vector<int> & arr, int x , int n ){
    int low = 0 , high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>x){
            ans = mid;
            high = mid-1; // maybe an answer but needed a small value on left
        }
        else low = mid+1; // go to right
    }
    return ans;
}

int countSmallEquals(vector<vector<int>> &matrix,int n , int m, int x){
    int cnt = 0;
    for(int i = 0 ; i<n ; i++){
        cnt+=upperBound(matrix[i],x,m);
    }
    return cnt;
}


int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MIN; int high = INT_MIN;
    n = matrix.size();
    m = matrix[0].size();
    for(int i = 0; i<n ; i++){
        low = min(low,matrix[i][0]); // low is min of first col and high is max of last col
        high = max(high,matrix[i][m-1]);
    }
    int req = (n*m)/2;
    while(low<=high){
        int mid = (low+high)/2;
        int smallEqual = countSmallEquals(matrix,n,m,mid);
        if(smallEqual <= req){
            low = mid+1; // the count is <= req we need > req
        }
        else high = mid-1;
    }
    return low;

}
