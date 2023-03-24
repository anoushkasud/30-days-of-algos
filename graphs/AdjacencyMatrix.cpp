#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int> > adjMat(n,vector<int> (n,0));
    cout<<"add edges: ";
    int a,b;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        adjMat[a][b] = 1;
        // for undirected graph add adjMat[b][a] = 1
        // for weighted graph add weight instead of 1
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<adjMat[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}

//space complexity = O(n*n)
