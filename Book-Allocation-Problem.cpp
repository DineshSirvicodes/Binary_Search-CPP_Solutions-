// Brute Solution TC - O((sum-max+1)*N) 
#include<bits/stdc++.h>
int findStudents(vector<int> &arr,int pages){
    int student = 1, pagesperStudent = 0;
    for(int i = 0 ; i<arr.size() ; i++){
        if(pagesperStudent + arr[i] <= pages){
            pagesperStudent+=arr[i];
        }
        else{
            student++;
            pagesperStudent = arr[i];
        }
    }
    return student;
}


int findPages(vector<int>& arr, int n, int m) {
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    if(m>arr.size()) return -1;
    for(int pages = low ; pages<high; pages++){
        int cntStudents = findStudents(arr,pages);
        if(cntStudents = m){
            return pages;
        }
    }
}
//Optimal Solution TC - O(N*log(sum-max+1)
#include<bits/stdc++.h>
int findStudents(vector<int> &arr,int pages){
    int student = 1;
    long long  pagesperStudent = 0;
    for(int i = 0 ; i<arr.size() ; i++){
        if(pagesperStudent + arr[i] <= pages){
            pagesperStudent+=arr[i];
        }
        else{
            student++;
            pagesperStudent = arr[i];
        }
    }
    return student;
}


int findPages(vector<int>& arr, int n, int m) {
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    if(m>arr.size()) return -1;
    while(low<=high){
        int mid = (low+high)/2;  // pages 
        int cntStudents = findStudents(arr,mid);
        if(cntStudents > m){
            low = mid+1;
        }
        else{
            
            high = mid-1; //  to find min pages to be allocated
        }
    }
    return low;
    
}
