#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long A[1000000];
long long ans=0;

void merge(int p,int q,int r,int N)
{
	queue<int> q1,q2,q3;
	for(int i=p; i<=q; i++) q1.push(A[i]);
	for(int i=q+1; i<=r && i<N; i++) q2.push(A[i]);
	while(!q1.empty() && !q2.empty()) {
		if(q1.front()<=q2.front()) {
			q3.push(q1.front());
			q1.pop();
		} else {
			ans+=q1.size();
			q3.push(q2.front());
			q2.pop();
		}
	}
	while(!q1.empty()) {
		q3.push(q1.front());
		q1.pop();
	}
	while(!q2.empty()) {
		q3.push(q2.front());
		q2.pop();
	}
	int i=p;
	while(!q3.empty()) {
		A[i++]=q3.front();
		q3.pop();
	}
}

void mergesort(int p,int q,int N)
{
	if(p<q) {
		int mid=(p+q)/2;
		mergesort(p,mid,N);
		mergesort(mid+1,q,N);
		merge(p,mid,q,N);
	}
}

int main(void)
{
	int T;
	cin >> T;
	for(int k=0; k<T; k++) {
		int N;
		ans=0;
		cin >> N;
		for(int i=0; i<N; i++) {
			cin >> A[i];
		}
		//merge(0,N/2,N-1);
		mergesort(0,N-1,N);
		/*for(int i=0; i<N; i++) {
			cout << A[i] << " ";
		} cout << endl; */
		cout << ans << endl;
		N=0;
	}
	return 0;
}
