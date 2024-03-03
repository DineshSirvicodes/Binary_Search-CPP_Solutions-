// Tc - O(log(min(n1,n2)))
#include<bits/stdc++.h>
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    if(n1>n2) return kthElement(b,a,n2,n1,k);
    int low = max(0,k-n2);  // min we need 0 or k-n2 from arr1 if n1 > k
    int high = min(k,n1); // at max we need to pick up k or n1 elements 
    int left = k; // considering the left part to be small 
    while(low<=high){
        int mid1 = (low+high)>>1;
        int mid2 = (left - mid1);  
        int l1 = INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX,r2 = INT_MAX;

        if(mid1<n1) r1 = a[mid1];
        if(mid2<n2) r2 = b[mid2];

        if(mid1-1>=0) l1 = a[mid1-1]; // l1 and l2 should not go below 0
        if(mid2-1>=0) l2 = b[mid2-1]; //  ie not exceed boundary

        if(l1<=r2 && l2<=r1) return max(l1,l2);
        else if (l1>r2) high = mid1-1;
        else low = mid1+1;

    }
    return 0;
}
