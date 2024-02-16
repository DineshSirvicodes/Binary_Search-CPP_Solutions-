// Tc - O(logN)
// return 1 if mid^n == m
// return 2 if mid^n > m
//return 0 if mid^n < m
int func(int mid, int n , int m){
    long long ans = 1;
    for(int i = 1 ; i<=n ; i++){
        ans = ans * mid; // each time mid is multiply n times
        if(ans > m) return 2; // and each step we check if the mid on multiply 
    }                           // exceeds the m then stop by return 2
    if(ans == m) return 1; // if the mid^n on calc == m return 1
    return 0;               // else return 0 ie mid^n < m

}

int NthRoot(int n, int m) {
  int low = 1, high = m;
  while(low<=high){
      int mid = (low+high)/2;
      int midN = func(mid,n,m);
      if(midN == 1){
          return mid;
      }
      else if(midN == 0) low = mid+1; // mid^n is smaller
      else high = mid-1; // means the mid^n exceeded the m so no answer
  }
  return -1;
}
