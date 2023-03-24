#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    unordered_map<int, vector<int> > adjList;
    bool direction;
public:
    Graph(bool direction){
        this->direction = direction;
    }
    void addEdge(int a, int b){
        adjList[a].push_back(b);// directed
        if(direction == 0){ //undirected
            adjList[b].push_back(a);
        }
    }
    void print(){
        for(auto i:adjList){
            cout<<i.first<<':';
            for(auto j:i.second){
                cout<<j<<' ';
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(0);
    g.addEdge(1,2);
    g.addEdge(4,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(2,0);
    g.print();
    return 0;
}
