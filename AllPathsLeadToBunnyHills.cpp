#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

const int MAXN = 30;

int N,M;
int table[MAXN][MAXN];
int vis[MAXN][MAXN];

int res = 0;
void dfs(int x,int y,int slope,int temp){

	vis[x][y] = 1;

	res = max( res, temp );

    if( x > 0 && !vis[x-1][y] ){
		if( slope==-1 || slope==(table[x][y]-table[x-1][y]) )
			dfs( x-1, y, table[x][y]-table[x-1][y], temp+1 );
	}
	if( y > 0 && !vis[x][y-1] ){
		if( slope==-1 || slope==(table[x][y]-table[x][y-1]) ){
			dfs( x, y-1, table[x][y] - table[x][y-1], temp+1 );
		}
	}
	if( x<N-1 && !vis[x+1][y] ){
		if( slope==-1 || slope==(table[x][y]-table[x+1][y]) )
			dfs( x+1, y, table[x][y]-table[x+1][y], temp+1 );
	}
	if( y<M-1 && !vis[x][y+1] ){
		if( slope==-1 || slope==(table[x][y]-table[x][y+1]) )
			dfs( x, y+1, table[x][y]-table[x][y+1], temp + 1 );
	}

	vis[x][y] = 0;

}

int main(){
	cin>>N>>M;

	int x,y; cin>>x>>y;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>table[i][j];
	dfs( x, y, -1, 0 );

	cout<<res<<'\n';

	return 0;
}

