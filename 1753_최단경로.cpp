#include <cstdio>
#include <queue>
#include <vector>
#define MAX 20001
#define INF 234567

int V, E, start;

std::vector<std::pair<int, int>> map[MAX];
int distance[MAX];
std::priority_queue<std::pair<int, int>> q;

void solve() {
	distance[start] = 0;
	q.push(std::make_pair(distance[start], start));
	while(!q.empty()) {
		int dist = -q.top().first;
		int to = q.top().second;
		q.pop();
		if(dist > distance[to]) continue;
		for(int i = 0; i < map[to].size(); i++) {
			int v = map[to][i].first;
			int w = map[to][i].second;
			if(distance[v] > dist+w) {
				distance[v] = dist+w;
				q.push(std::make_pair(-distance[v], v));
			}
		}
	}
}
int main() {
	scanf("%d %d %d", &V, &E, &start);
	for(int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		map[u].push_back(std::make_pair(v, w));
	}
	for(int i = 1; i <= V; i++)
	    distance[i] = INF;
	solve();
	for(int i = 1; i <= V; i++) {
		if(distance[i]==INF) printf("INF\n");
		else printf("%d\n", distance[i]);
	}
	return 0;
}