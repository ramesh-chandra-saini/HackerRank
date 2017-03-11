#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M; cin >> N >> M;
    int adj[N+1][N+1];//adjacency matrix
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            adj[i][j]=INT_MAX;
    for(int i=1;i<=M;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u][v]=adj[v][u]=min(w,min(adj[u][v],adj[v][u]));
    }
    int S; cin >> S;//starting node
   // prepare DSU
    vector<pair<int,int> > dsu(N+1);
    for(int i=0;i<=N;i++)
        dsu[i].first=i,//parent
        dsu[i].second=1;//size

    //prim's Algo
    set<pair<int,pair<int,int> > > edges;
    set<pair<int,pair<int,int> > > ::iterator it;
    for(int i=1;i<=N;i++){
        if(adj[S][i]!=INT_MAX){
            edges.insert({adj[S][i],{S,i}});
            adj[S][i]=adj[i][S]=INT_MAX;
        }
    }
    long long ans = 0,u,v;
    while(!edges.empty()){

        it=edges.begin(); //min weight edge
        edges.erase(it);//remove it from set
        u=it->second.first;
        v=it->second.second;
      
        //check for cycle;
         int root_u=u;
         while(dsu[root_u].first!=root_u)
            root_u = dsu[root_u].first;
         int root_v=v;
         while(dsu[root_v].first!=root_v)
            root_v = dsu[root_v].first;
        if(root_u==root_v)//cycle
            continue;
        ans+=it->first;//we need to add this edge
        
        if(dsu[root_u].second<=dsu[root_v].second){
            dsu[root_u].first=dsu[root_v].first;
            dsu[root_v].second+=dsu[root_u].second;
        }else{
            dsu[root_v].first=dsu[root_u].first;
            dsu[root_u].second+=dsu[root_v].second;
        }
        for(int i=1;i<=N;i++){ //insert all new edges
            if(adj[v][i]!=INT_MAX){
                edges.insert({adj[v][i],{v,i}});
                adj[v][i]=adj[i][v]=INT_MAX;//to avoid again insertion into set
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}
