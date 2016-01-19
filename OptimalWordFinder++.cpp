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

vector<pair<int,char> >table;
int vis[100];

bool vowel(char ch){

	if( ch=='A' )
		return true;
	if( ch=='E' )
		return true;
	if( ch=='I' )
		return true;
	if( ch=='O' )
		return true;
	if( ch=='U' )
		return true;
	return false;
}

int best = 0;
void solve(int temp, int counter,int consonants, bool odd ){

	best = max( best, temp );

	if( counter == 8 )
		return;

	for(int i=0;i<table.size();i++)
		if( !vis[i] && (odd==(table[i].first%2) ) ){
			if( (consonants<2) || (consonants==2 && vowel(table[i].second) ) ){
				vis[i] = 1;

				if( vowel( table[i].second ) )
					solve( temp+table[i].first, counter + 1, 0, 1-odd );
				else
					solve( temp+table[i].first, counter+1, consonants+1, 1-odd );

				vis[i] = 0;
		}
	}

}

int main(){

	char c;

	while( cin>>c ){
		int value;
		cin>>value;
		table.push_back( make_pair( value, c ) );
	}

	sort( table.begin(), table.end() );

	bool odd = true;
	int res = 0, counter = 0, consonants = 0;
	solve( 0, 0, 0, true );
	cout<<best<<'\n';

	return 0;
}
