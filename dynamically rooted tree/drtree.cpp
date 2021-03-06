#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 100100
#define LOG 17

using namespace std;

typedef long long ll;

ll sum[ MAXN + 1 ][ LOG + 1 ], par[ MAXN + 1 ][ LOG + 1 ], S[ MAXN + 1 ];
int depth[ MAXN + 1 ], p[ MAXN + 1 ], root, label[ MAXN + 1 ];
vector< int > graph[ MAXN + 1 ];

void dfs( int s, int d, bool visited[] )
{
	depth[ s ] = d;
	S[ s ] = label[ s ];
	visited[ s ] = true;
	for( int i = 0; i < graph[ s ].size(); i++ ) {
		int v = graph[ s ][ i ];
		if( !visited[ v ] ) {
			dfs( v, d + 1, visited );
			S[ s ] += S[ v ];
		}
	}
}

void init( int N )
{
	for( int i = 2; i <= N; i++ ) {
		par[ i ][ 0 ] = p[ i ];
		sum[ i ][ 0 ] = S[ p[ i ] ] - S[ i ];
		for( int j = 1; 1 << j <= N; j++ ) {
			par[ i ][ j ] = -1;
			sum[ i ][ j ] = 0;
		}
	}
	par[ root ][ 0 ] = -1;
	sum[ root ][ 0 ] = 0;
	for( int j = 1; 1 << j <= N; j++ ) {
		for( int i = 1; i <= N; i++ ) {
			par[ i ][ j ] = par[ par[ i ][ j - 1 ] ][ j - 1 ];
			sum[ i ][ j ] = sum[ i ][ j - 1 ] + sum[ par[ i ][ j - 1 ] ][ j - 1 ];
		}
	}
}

ll query( int u )
{
	int lg = 0, R = root;
	if( R == u ) {
		return S[ 1 ];
	}
	ll val = S[ R ];
	while( 1 << lg <= depth[ R ] ) lg++;
	lg--;
	for( int i = lg; i >= 0; i-- ) {
		if( depth[ R ] - ( 1 << i ) > depth[ u ] ) {
			val += sum[ R ][ i ];
			R = par[ R ][ i ];
		}
	}
	if( p[ R ] != u ) {
		return S[ u ];
	}
	return S[ 1 ] - val;
}

int main( void )
{
	int N, Q, s;
	scanf("%d", &N );
	bool visited[ N + 1 ];
	for( int i = 1; i <= N; i++ ) {
		scanf("%d", &label[ i ] );
		visited[ i ] = false;
	}
	root = 1;
	p[ root ] = -1;
	for( int i = 2; i <= N; i++ ) {
		scanf("%d", &s );
		p[ i ] = s;
		graph[ s ].push_back( i );
	}
	dfs( 1, 0, visited );
	init( N );
	scanf("%d", &Q );
	while( Q-- ) {
		scanf("\n");
		char c;
		c = getchar_unlocked();
		scanf("%d", &s );
		if( c == 'R' ) {
			root = s;
		} else {
			printf("%lld\n", query( s ) );
		}
	}
	return 0;
}
