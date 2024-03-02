// Brute Sol TC - O(n1+n2) SC - O(n)
double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

// Better Solution: Reducing Space Complexity
double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;       // eg N1 + N2 = 10 , so ind1 = 4 , ind2 = 5
    int ind1 = ind2 - 1;
    int cnt = 0;   // third array index referencer
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;  // for odd 
    }

    return (double)((double)(ind1el + ind2el)) / 2.0; // for even
}

// Optimal Sol  Binary Search  TC - O(logn1/logn2) = O(log(n1+n2))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        //if n1 is bigger swap the arrays:
        if (n1 > n2) return findMedianSortedArrays(b, a); // we want the a array to be small and 
                                            //perform BS on this
        int low = 0 , high = n1;
        int n = n1+n2;
        int left = (n1+n2+1)/2;  // picking up elements to divide the left and right segments
        while(low<=high){
            int mid1 = (low+high)>>1; // (low+high)/2
            int mid2 = left - mid1; //(right side)
            int l1 = INT_MIN,l2 = INT_MIN; // l1 for arr1 and l2 for arr2
            int r1 = INT_MAX, r2 = INT_MAX; // r1 for arr1 and r2 for arr2
            if(mid1<n1) r1 = a[mid1]; // should not exceed the boundaries
            if(mid2<n2) r2 = b[mid2];
            
            if(mid1-1>=0) l1 = a[mid1-1]; // should not exceed the boundaries
            if(mid2-1>=0) l2 = b[mid2-1];

            if(l1 <= r2 && l2<=r1) { // this condition will satisfy the left part as smaller to right part
                // odd size n1+n2
                if(n%2 == 1) return max(l1,l2); // l1 and l2 will have bigger values
                return (double)(max(l1,l2)+min(r1,r2))/2.0; // even size
            }
            else if (l1>r2) high = mid1-1;
            else low = mid1+1; // l2>r1
        }
        return 0; // dummy statement
    }
};

