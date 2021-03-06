#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

int main( void )
{
	freopen("test.in","wt",stdout);
	srand( time( NULL ) );
	int T = rand() % 30 + 1;
	printf("%d\n", T );
	for( int i = 0; i < T; i++ ) {
		int N = rand() % 1024 + 1;
		int Q = rand() % 100000 + 1;
		printf("%d\n", N );
		for( int i = 0; i < Q; i++ ) {
			int t = rand() % 2;
			if( t == 0 ) {
				printf("SET");
				int x = rand() % N, y = rand() % N, val = rand() % 1000;
				printf(" %d %d %d\n", x, y, val );
			} else {
				printf("SUM");
				int x1 = rand() % N ,y1 = rand() % N,x2 = rand() % N,y2 = rand() %N;
				if( x1 > x2 ) swap( x1, x2 );
				if( y1 > y2 ) swap( y1, y2 );
				printf(" %d %d %d %d\n", x1, y1, x2, y2 );
			}
		}
		printf("END\n");
	}
	return 0;
}
