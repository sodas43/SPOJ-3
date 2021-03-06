#include <cstdio>
#include <algorithm>
 
#define INF 100000000
 
using namespace std;
 
int main( void )
{
	int T;
	scanf("%d",&T);
	while( T-- ) {
		int N,K;
		long long ans_risk = INF,ans_time = INF;
		scanf("%d%d",&N,&K);
		int risk[ N + 1 ][ N + 1 ], cost[ N + 1 ][ N + 1 ];
		long long dp[ N + 1 ][ K + 1 ];
		for( int i = 1; i <= N; i++ ) {
			for( int j = 1; j <= N; j++ ) {
				scanf("%d",&cost[ i ][ j ]);
			}
		}
		for( int i = 1; i <= N; i++ ) {
			for( int j = 1; j <= N; j++ ) {
				scanf("%d",&risk[ i ][ j ] );
			}
		}
		for( int i = 0; i <= K; i++ ) { 
			dp[ 1 ][ i ] = 0;
		}
		for( int j = 1; j<= K; j++ ) {
			for( int i = 2; i <= N; i++ ) {
				dp[ i ][ j ] = INF;
				for( int k = i - 1; k >= 1; k-- ) {
					if( cost[ k ][ i ]  <= j ) {
						dp[ i ][ j ] = min ( dp[ i] [ j ], dp[ k ][ j - cost[ k ][ i ] ] + risk[ k ][ i ] );
					}
				}
			}
		}
		for( int i = K; i >= 0; i-- ) {
			if( dp[ N ][ i ] <= ans_risk ) {
				ans_time = i;
				ans_risk = dp[ N ][ i ];
			}
		}
		if( ans_risk == INF ) {
			printf("-1\n");
		} else {
			printf("%lld %lld\n",ans_risk,ans_time); 
		}
	}
	return 0;
}
