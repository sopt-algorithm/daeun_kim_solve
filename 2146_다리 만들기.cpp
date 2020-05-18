#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 101

int N, ans = 987654;
int map[MAX][MAX];
int visit[MAX][MAX];

int dirX[] = {+1, -1, 0, 0};
int dirY[] = {0, 0, +1, -1};

int min(int x, int y) {
	if(x > y) return y;
	else return x;
}
bool isValid(int x, int y) {
	return x>=0 && x<N && y>=0 && y<N;
}
void bfs(int y, int x, int num, int check, int count) {
    memset(visit, 0, sizeof(visit));
	queue<pair<pair<int,int>, int>> q;
	q.push(make_pair(make_pair(y, x), count));
	if(check==1) map[y][x] = num;
	visit[y][x] = 1;
	while(!q.empty()) {
		int x = q.front().first.second;
		int y = q.front().first.first;
		int cnt = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) {
			int nextX = x + dirX[i];
			int nextY = y + dirY[i];
			if(isValid(nextX, nextY) && !visit[nextY][nextX]) {
				if(map[nextY][nextX]==check) {
					q.push(make_pair(make_pair(nextY, nextX), cnt+1));
					visit[nextY][nextX] = 1;
					if(check==1) map[nextY][nextX] = num;
				} else if(check==0 && map[nextY][nextX]!=num) {
					ans = min(ans, cnt);
					return;
				}
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	}
	//섬 번호 부여(2, 3, 4, ...)
	int num = 2;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(map[i][j]==1) {
				bfs(i, j, num, 1, 0);
			    num++;
			}
		}
	}
	//바다와 닿는 부분
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(map[i][j]) {
				for(int k = 0; k < 4; k++) {
					int x = j + dirX[k];
					int y = i + dirY[k];
					if(isValid(x, y) && map[y][x]==0)
						bfs(y, x, map[i][j], 0, 1);
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}