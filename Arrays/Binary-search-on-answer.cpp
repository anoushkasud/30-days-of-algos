// find a min/max number such that operating on the array with the number will result in number less than or equal to the given number
// operating : (+,-,*,/,%,etc)
// find the ((min speed)) needed to finish all the errands when errand distance is given in the array and given time is T

//out of all possible values in range(m,n) which is the most probable acepted min/max value

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int mid, int h){
    int hrs = 0;
    for(int i = 0;i<arr.size();i++){
        hrs += arr[i]/mid;
        if(arr[i]%mid != 0){
            hrs++;
        }
    }
    return hrs<=h;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;

    // find min val of k
    int s = 0, e = 1e9;
    while(s<e){                     
        int mid = (e-s)/2 + s;
        if(check(piles,mid,h)){
            e = mid;
        }
        else{
            s = mid+1;
        }
    } 
    cout<<s;
    return 0;
}
