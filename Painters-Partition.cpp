// Problem solution for Painter's Partition and Split-Array Largest Sum same as of Book Allocation Problem
int FindPainters(vector<int> &boards,int painters){
    int person = 1 , personperboard = 0;
    for(int i = 0 ; i<boards.size(); i++){
        if(personperboard+boards[i]<=painters){
            personperboard+=boards[i];
        }
        else{
            person++;
            personperboard = boards[i];
        }
    }
    return person;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int NumofPainter = FindPainters(boards,mid);
        if(NumofPainter>k) low = mid+1;
        else high = mid-1;
    }
    return low;
}
