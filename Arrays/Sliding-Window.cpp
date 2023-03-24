// Sliding window technique can be used to replace nested loops with a single loop to reduce time complexity
// Usually used to find the subarray with maximum/minimum sum

// Reduces O(n*k) time complexity to O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    //find out the maximum sum

    int sum = 0,mx = 0;
    
    // //naive approach
    // for(int i = 0;i<arr.size()-k+1;i++){
    //     for(int j = i;j<k+i;j++){
    //         sum += arr[j];
    //     }
    //     mx = max(mx,sum);
    //     sum = 0;
    // }
    // cout<<mx;
    
    // sliding window
    for(int i = 0;i<k;i++){
        sum += arr[i];
    }
    mx = max(mx,sum);
    for(int i = 1;i<arr.size()-k +1;i++ ){
        // add next element and remove last element
        sum -= arr[i-1] - arr[i+k-1];
        mx = max(mx,sum);
    }
    cout<<mx;

    return 0;
}
