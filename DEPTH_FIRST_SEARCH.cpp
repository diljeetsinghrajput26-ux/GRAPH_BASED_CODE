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
    l=new list<int> [v];
}

void addEdge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
}


void dfshelper(int u,vector<bool> &vis){
             cout<<u<<" ";
             vis[u]=true;
             for(int v : l[u]){
                     if(!vis[v]){
                          dfshelper(v,vis);
                                    }
                                }
                       }

void dfs(){
      int src=1;
      vector<bool> vis(5,false);
       dfshelper(src,vis);
              }

};
int main(){
    graph g(6);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(2,5);
    g.dfs();
    return 0;

}