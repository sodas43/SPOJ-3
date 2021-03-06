#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

#define MAX 5000

using namespace std;

typedef pair<int,int> pii;

vector<int> nodes, scc[MAX+1],vertices;
bool found = false;
int cnt = 0;

void dfs(vector<int> graph[],bool visited[],int s,int cnt)
{
	if(visited[s]) {
		return;
	}
	visited[s]=true;
	if( found ) {
		scc[ cnt ].push_back( s );
	} else {
		vertices.push_back( s );
	}
	for(int i=0; i<graph[s].size(); i++) {
		dfs(graph,visited,graph[s][i],cnt);
	}
}

void SCC(vector<int> graph[],int V)
{
	bool visited[V+1];
	for(int i=1; i<=V; i++) {
		visited[i]=false;
	}
	if(!found) {
		for(int i=1; i<=V; i++) {
			if(!visited[i]) {
				dfs(graph,visited,i,cnt);
				vertices.push_back(i);
			}
		}
	} else {
		cnt = 0;
		for(int i=vertices.size() - 1; i >= 0; i--) {
			dfs(graph,visited,vertices[i],cnt);
			if( scc[ cnt ].size() > 0 ) {
				cnt++;
			}
		}
	}
}

void init()
{
	nodes.clear();
	vertices.clear();
	for(int i=0; i<=MAX; i++) {
		scc[i].clear();
	}
}

int main(void)
{
	while( true ) {
		int V,E,u,v;
		cnt = 0;
		init();
		found = false;
		scanf("%d",&V);
		if( !V ) {
			break;
		}
		scanf("%d",&E);
		int CC[V+1];
		pii edges[E];
		bool incomp[V+1];
		vector<int> graph[V+1],trans[V+1];
		for(int i=0; i<E; i++) {
			scanf("%d%d",&u,&v);
			edges[ i ] = make_pair(u,v);
			graph[u].push_back(v);
			trans[v].push_back(u);
		}
		SCC(trans,V);
		found = true;
		SCC(graph,V);
		for(int i=0; i<=V; i++) {
			incomp[ i ] = true;
			CC[ i ] = 0;
		}
		for(int i=0; i<cnt; i++) {
			for(int j=0; j<scc[i].size(); j++) {
				CC[ scc[i][j] ] = i;
			}
		}
		for(int i=0; i<E; i++ ) {
			if( CC[ edges[i].first ] != CC[ edges[i].second ] ) {
				incomp[ CC[ edges[i].first ] ] = false;
			}
		}
		for(int i=1; i<=V; i++) {
			if( incomp[ CC[ i ] ] ) {
				nodes.push_back( i );
			}
		}
		if( nodes.size() ) {
			sort(nodes.begin(),nodes.end());
			printf("%d",nodes[0]);
			for(int i=1; i<nodes.size(); i++) {
				printf(" %d",nodes[i]);
			}
			printf("\n");	
		}
	}
	return 0;
}	
