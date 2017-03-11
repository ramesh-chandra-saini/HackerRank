#include<bits/stdc++.h>
using namespace std;
struct Edge  {
    int u;
    int v;
    int weight;
} ;
bool __cmp(Edge A,Edge B){
    if(A.weight!=B.weight)
        return A.weight<B.weight;
    if(A.u!=B.u)
        return A.u<B.u;
    return A.v<B.v;
}
int main(){
    //freopen("in.txt","r",stdin);
    int N,M; cin >> N >> M;

    int adj[N+1][N+1];
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            adj[i][j]=INT_MAX;
    for(int i=1;i<=M;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u][v]=adj[v][u]=min(w,min(adj[u][v],adj[v][u]));
    }
    vector<Edge> edges;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(adj[i][j]!=INT_MAX)
                edges.push_back({i,j,adj[i][j]});
    sort(edges.begin(),edges.end(),__cmp);
  /*
    for(int i=0;i<edges.size();i++)
        cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].weight<<endl;
*/
    vector<pair<int,int> > dsu(N+1);
    for(int i=0;i<=N;i++)
        dsu[i].first=i,//parent
        dsu[i].second=1;//size
    //Krushkal
    long long ans = 0;
    for(int i=0;i<edges.size();i++){
         int u = edges[i].u;
         int v = edges[i].v;
         int w = edges[i].weight;

         //check for cycle;
         int root_u=u;
         while(dsu[root_u].first!=root_u)
            root_u = dsu[root_u].first;
         int root_v=v;
         while(dsu[root_v].first!=root_v)
            root_v = dsu[root_v].first;
        if(root_u==root_v)//cycle
            continue;
        ans+=w;//we need to add this edge
        if(dsu[root_u].second<=dsu[root_v].second){
            dsu[root_u].first=dsu[root_v].first;
            dsu[root_v].second+=dsu[root_u].second;
        }else{
            dsu[root_v].first=dsu[root_u].first;
            dsu[root_u].second+=dsu[root_v].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}
