#include<bits/stdc++.h>
using namespace std;
#define V 5

int primMST(int graph[V][V])
{
    int key[V],res=0;
    fill(key,key+V,INT_MAX);
    key[0] = 0;
    bool mSet[V] = {0};
    
    for(int count = 0 ; count < V ; count++)
    {
        int u = -1;
        for(int i=0 ; i<V ; i++)
        {
            if(!mSet[i] && (u == -1 || key[i]<key[u]))
                u = i;
        }
        mSet[u] = true;
        res += key[u];
        for(int v=0 ; v<V ; v++)
        {
            if(graph[u][v] != 0 && !mSet[v])
                key[v] = min(key[v],graph[u][v]);
        }
    }
    return res;
}

int main()
{
    //Adjacency Matrix Input
    int graph[V][V];
    for(int i=0 ; i<V ; i++)
    {
        for(int j=0 ; j<V ; j++){
            cin>>graph[i][j];
        }
    }
    int res = primMST(graph);
    cout<<res;
    return 0;
}