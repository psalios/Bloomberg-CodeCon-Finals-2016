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

const int MAXN = 110;

int N,M,K;
int counter = 1, pos = 0;
int table[55][MAXN][MAXN];

void dot(int x,int y,int c){
    table[counter][x][y] = c;
}

void square(int x1,int y1,int x2,int y2,int c){

    if( y1 > y2 )
        swap( y1, y2 );
    if( x1 > x2 )
        swap( x1, x2 );

    for(int i=y1;i<=y2;i++)
        table[counter][x1][i] = table[counter][x2][i] = c;
    for(int i=x1;i<=x2;i++)
        table[counter][i][y1] = table[counter][i][y2] = c;

}

void gemose(int x,int y,int c){

    if( table[counter][x][y] == c )
        return;

    int prev = table[counter][x][y];
    table[counter][x][y] = c;

    if( x>0 && table[counter][x-1][y] == prev )
        gemose( x-1, y, c );

    if( x < N-1 && table[counter][x+1][y] == prev )
        gemose( x+1, y, c );

    if( y > 0 && table[counter][x][y-1] == prev )
        gemose( x, y-1, c );

    if( y<M-1 && table[counter][x][y+1] == prev )
        gemose( x, y+1, c );

}

void undo(){

    if( pos > 0 )
        pos--;

}

void redo(){

    if( pos < counter-1 )
        pos++;
}


int main(){

//	freopen("input.txt", "r", stdin );

	scanf( "%d,%d,%d", &N, &M, &K );
    while( K-- ){

        string str; cin>>str;
        if( str[0] == 'u' ){
            undo();
            continue;
        }
        else if( str[0] == 'r' ){
            redo();
            continue;
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                table[counter][i][j] = table[pos][i][j];
        pos = counter;

        if( str[0] == 'd' ){
            int x,y,c; scanf( "%d %d %d;", &x, &y, &c );
            dot( x, y, c );
        }
        else if( str[0] == 's' ){
            int x1, y1, x2, y2, c; scanf( "%d %d %d %d %d;", &x1, &y1, &x2, &y2, &c );
            square( x1, y1, x2, y2, c );
        }
        else if( str[0] == 'f' ){
            int x,y, c; scanf( "%d %d %d;", &x, &y, &c );
            gemose( x, y, c );
        }
        counter++;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M-1;j++)
            cout<<table[pos][i][j]<<' ';
        cout<<table[pos][i][M-1]<<'\n';
    }

	return 0;
}

