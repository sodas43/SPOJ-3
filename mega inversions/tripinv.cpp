#include <cstdio>
 
const int MAX  = 100000;
long long BIT[ MAX + 1 ];

void init()
{
	for(int i = 0; i <= MAX; i++ ) {
		BIT[ i ] = 0;
	}
}
 
void add(int pos,int dp)
{
	while( pos <= MAX ) {
		BIT[ pos ] += dp;
		pos += ( pos & -pos );
	}
}
 
unsigned long long query( int pos )
{
	unsigned long long ans = 0;
	while( pos > 0 ) {
		ans += BIT[ pos ];
		pos -= ( pos & -pos );
	}
	return ans;
}
 
int main( void )
{
	int N,K;
	unsigned long long ans = 0;
	scanf("%d",&N,&K);
	K = 3;
	int D[ N + 1 ],A[ N + 1 ];
	long long dp[ N + 1 ][ K + 1 ];
	for(int i = 1; i <= N; i++ ) {
		scanf("%d",&D[ i ] );
	}
	for( int i = N,j = 1; j <= N; j++,i-- ) {
		A[ j ] = D[ i ];
	}
	for(int i = 0; i <= N; i++ ) {
		dp[ i ][ 1 ] = 1;
	}
	for(int k = 2; k <= K; k++ ) {
		init();
		dp[ 1 ][ k ] =0;
		for(int i = 2; i <= N; i++ ) {
			add( A[ i - 1 ], dp[ i - 1][ k - 1] );
			dp[ i ][ k ] = query( A[ i ] - 1 );
		}
	}
	for(int i = 1; i <= N; i++ ) {
		ans += dp[ i ][ K ];
	}
	printf("%llu\n",ans);
	return 0;
}
