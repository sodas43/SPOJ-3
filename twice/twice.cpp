#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
 
#define MOD 321434213421556LL
#define A 26
 
#define pb push_back

using namespace std;
 
typedef long long ll;
 
char text[ 201000 ];
 
bool rabink( char* text, int N, int K )
{
	vector< ll > H;
	ll hash = 0, mult = 1;
	for( int i = 0; i < K; i++ ) {
		hash = ( ( hash * A ) % MOD + text[ i ] ) % MOD;
	}
	H.pb( hash );
	for( int i = 0; i < K - 1; i++ ) {
		mult = mult*A % MOD;
	}
	for( int i = K; i < N; i++ ) {
		hash = ( hash - ( mult*text[ i - K ] % MOD ) ) % MOD;
		hash = hash * A % MOD;
		hash = ( hash + text[ i ] ) % MOD;
		H.pb( hash );
	}
	sort( H.begin(), H.end() );
	for( int i = 0; i < ( int )H.size() - 1; i++ ) {
		if( H[ i ] == H[ i + 1 ] ) return true;
	}
	return false;
}
 
int main( void )
{
	int N, ans = 0, cnt = 0;
	scanf("%d%s", &N, text );
	N = strlen( text );
	int lo = 1, hi = N - 1;
	for( int i = 0; i < N; i++ ) {
		text[ i ] -= 'a';
	}
	while( lo <= hi ) {
		int mid = ( lo + hi ) / 2;
		if( rabink( text, N, mid ) ) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	printf("%d\n", ans );
	return 0;
}
