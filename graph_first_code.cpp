#include<iostream>
#include<vector>
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
void print(){
    for(int i=0;i<v;i++){
        cout<<i<<" :";
        for(int p : l[i]){
            cout<<p<<" ";
        }
        cout<<endl;
    }
}
};
int main(){
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.print();
    return 0;

}