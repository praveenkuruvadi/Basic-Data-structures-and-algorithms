#include <iostream>

using namespace std;

int minwgt;
int ver=10;
int weight[25][25],parent[25];

int findset(int i)
{
	while(parent[i])
        i=parent[i];
	return i;
}

int uni(int t1,int t2)
{
	if(t1!=t2)
	{
		parent[t2]=t1;
		return 1;
	}
	return 0;
}
void kruskal()
{
    int spanedges = 1;
    int t1,t2,a,b;
    int temp;
    while(spanedges < ver)
	{
		for(int i=1,minwgt=1000;i<=ver;i++)
		{
			for(int j=1;j <= ver;j++)
			{
				if(weight[i][j] < minwgt)
				{
					minwgt=weight[i][j];
					a=i;
					b=j;
					temp = minwgt;
				}
			}
		}
		t1=findset(a);
		t2=findset(b);
		if(uni(t1,t2))
		{
		    spanedges++;
			cout<<"v1= "<<a<<", "<<"v2= "<<b<<", "<<"weight= "<<temp<<endl;
		}
		weight[a][b]=weight[b][a]=1000;
	}
}

int main()
{
	//cout<<"enter number of vertices"<<endl;
    //cin>>ver;
	cout<<"enter weighted adjacency matrix (maxlimit = 1000)"<<endl;
	for(int i=1;i<=ver;i++)
	{
		for(int j=1;j<=ver;j++)
		{
			cin>>weight[i][j];
			if(weight[i][j]==0)
            {
                weight[i][j]=1000;
            }
		}
	}
	cout<<"The edges of MST are"<<endl;
	kruskal();

    return 0;
}
