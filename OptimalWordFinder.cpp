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

int main(){

	char c;

	while( cin>>c ){
		int value;
		cin>>value;
		table.push_back( make_pair( value, c ) );
	}

	sort( table.begin(), table.end() );

	bool odd = true;
	int res = 0, counter = 0;
	while( counter < 8 ){

		bool found = false;
		for(int i=table.size()-1;i>=0;i--)
			if( !vis[i] && (odd==(table[i].first%2) ) ){
				res += table[i].first;
				vis[i] = true;
				counter++;
				odd = 1 - odd;
				found = true;
				break;
			}
		if( !found )
			break;

	}
	cout<<res<<'\n';

	return 0;
}
