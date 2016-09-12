#include<iostream>
using namespace std;

int adj[10][10];
int ver=10;
int vertices;
int visit[10];

void dfs(int i)
{
    cout<<i<<">>";
    visit[i]=1;
    for(int j=0;j<vertices;j++)
    {
        if((visit[j]!=1)&&(adj[i][j]==1))
            dfs(j);
    }
}

int main()
{
    cout<<"Enter number of vertices" <<endl;
    cin>>vertices;
    cout<<"enter adjacency matrix"<<endl;
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cin>> adj[i][j];
        }
    }

    for(int i=0;i<vertices;i++)
    {
        visit[i]=0;
    }
    cout<<"DFS is:"<<endl;
    for (int i=0; i<vertices; i++)
    {
        if (visit[i]==0)
            dfs(i);
    }
}


