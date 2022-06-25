/*
*   Find the  height and depth of a tree using DFS
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
bool vis[N];
vector<int> g[N];

int depth[N];
int height[N];

void dfs(int vertex)
{
    //vis[vertex] = true;
    cout<<"Par "<<vertex<<": ";
    //after entering a vertex
    for(auto child : g[vertex])
    {
        depth[child] = depth[vertex]+1;
        //after entering a child
        // if(vis[child])
        //     continue;
        cout<<child<<" ";
        dfs(child);
        //before exiting the child
        height[vertex] = max(height[child]+1,height[vertex]);
    }
    //before exiting the vertex

    cout<<endl;

}

int main()
{
    int m;
    cin>>m;
    
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        //g[v2].push_back(v1);
    }

    for(int i=1;i<=m;i++)
    {
        dfs(i);
    }

    // for(int i=1;i<=m;i++)
    // {
    // //     cout<<"Par "<<i<<":"<<endl;
    // //     for(auto child: g[i])
    // //         cout<<child<<" ";
    // }
        for(int i=1;i<=m;i++)
        {
            cout<<depth[i]<<" "<<height[i]<<endl;
        }
        cout<<endl;
    

    return 0;
}