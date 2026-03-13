#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class graph{
int v;
list<int> *l;

public:

graph(int v){
    this->v=v;
    l=new list<int>[v];
}

void addEdge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
}

bool dfs(int start,int par,vector<bool>& vis){

    vis[start]=true;

    for(int i:l[start]){   // FIXED
        if(!vis[i]){
            if(dfs(i,start,vis)){
                return true;
            }
        }
        else if(i!=par){   // FIXED
            return true;
        }
    }
    return false;
}

bool iscycle(){

    vector<bool> vis(v,false);

    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis)){
                return true;
            }
        }
    }
    return false;
}

};

int main(){

    graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    cout<<g.iscycle();

    return 0;
}