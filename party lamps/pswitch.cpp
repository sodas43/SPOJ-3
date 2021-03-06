#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[] = { 1,2,3,4 };

string produce( int i )
{
	string str;
	while( i > 0 ) {
		str += i % 2 + '0';
		i /= 2;
	}
	return str;
}

bool find( vector< string > v, string str )
{
	for( int i = 0; i < v.size(); i++ ) {
		if( v[ i ] == str ) {
			return false;
		}
	}
	return true;
}

int main( void )
{
	int N,C,k;
	bool found = false;
	scanf("%d%d", &N, &C );
	vector< string > vec;
	bool on[ N + 1 ], off[ N + 1 ];
	for( int i = 1; i <= N; i++ ) {
		on[ i ] = false;
		off[ i ] = false;
	}
	for( int i = 1;; i++ ) {
		scanf("%d", &k );
		if( k == -1 ) {
			break;
		}
		on[ k ] = true;
	}
	for( int i = 1;; i++ ) {
		scanf("%d", &k );
		if( k == -1 ) {
			break;
		}
		off[ k ] = true;
	}
	for( int i = 0; i < 1 << 4; i++ ) {
		string cmd = produce( i );
		int ones = 0;
		bool L[ N + 1 ];
		for( int i = 0; i <= N; i++ ) {
			L[ i ] = true;
		}
		for( int i = cmd.length(); i < 4; i++ ) {
			cmd += '0';
		}
		for( int i = 0; i < 4; i++ ) {
			if( cmd[ i ] == '1' ) {
				ones++;
				if( arr[ i ] == 1 ) {
					for( int i = 1; i <= N; i++ ) {
						L[ i ] = !L[ i ];
					}
				}
				else if( arr[ i ] == 2 ) {
					for( int i = 1; i <= N; i += 2) {
						L[ i ] = !L[ i ];
					}
				}
				else if( arr[ i ] == 3 ) {
					for( int i = 2; i <= N; i += 2 ) {
						L[ i ] = !L[ i ];
					}
				}
				else if( arr[ i ] == 4 ) {
					for( int i = 1; i <= N; i += 3 ) {
						L[ i ] = !L[ i ];
					}
				}
			}
		}
		if( ones > C ) {
			continue;
		}
		bool status = true;
		for( int i = 1; i <= N; i++ ) {
			if( on[ i ] && !L[ i ] ) {
				status = false;
			}
			else if( off[ i ] && L[ i ] ) {
				status = false;
			}
		}
		if( status ) {
			string n;
			for( int i = 1; i <= N; i++ ) {
				n += L[ i ] + '0';
			}
			if( find( vec, n ) ) {
				vec.push_back( n );
			}
		}
	}
	if( !vec.size() ) {
		printf("Impossible\n");
	} else {
		sort( vec.begin(), vec.end() );
		for( int i = 0; i < vec.size(); i++ ) {
			cout << vec[ i ] << endl;
		}
	}
	return 0;
}
