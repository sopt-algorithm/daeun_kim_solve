#include <cstdio>
#include <queue>
using namespace std;
#define MAX 101

int N, M;
int map[MAX][MAX];
int visit[MAX];
queue<int> q;

void bfs() {
	q.push(1);
	visit[1] = 1;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(int i = 1; i <= N; i++) {
			if(!visit[i] && map[node][i]){
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		map[x][y] = map[y][x] = 1;
	}
	bfs();
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(visit[i]) cnt++;
	}
	printf("%d", cnt-1);
	return 0;
}