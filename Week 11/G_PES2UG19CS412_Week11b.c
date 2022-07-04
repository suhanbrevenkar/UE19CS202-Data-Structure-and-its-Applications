#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	int x,y;
	int visit[n];
	int q[100];
	int f=-1,r=-1;

	for(int x=0;x<=n;x++)
	{
		visit[x]=0;
	}

	visit[v]=1;
	r++;
	q[r]=v;

	if(f==-1)
		f=0;

do
{
	y=q[f];
	if(f==r)
		f=r=-1;
	else
		f++;

	for(int i=0;i<=n;i++)
	{
		if((graph[y][i]==1) && (visit[i]==0))
		{
			visit[i]=1;
			r++;
			q[r]=i;

			if(f==-1)
				f=0;
		}
	}
}while(f!=-1);

if(visit[u]==1)
	return 1;

else
	return 0;
}
