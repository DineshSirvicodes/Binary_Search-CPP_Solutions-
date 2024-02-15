#Optimal Sol 1
Sol1 - using sqrt() function to find sqroot of a number
#include<bits/stdc++.h>
int floorSqrt(int n)
{
    return(sqrt(n));
}

#Optimal Sol 2 -- Binary Search

int floorSqrt(int n)
{
    long long low = 1, high = n ;
    
    while(low<=high){
        long long mid = (low+high)/2;
        
        if((long long)mid*mid<= (long long)n){
            low = mid+1;
        }
        
        else{
            high = mid-1;
        }
    }
    return high;
}

