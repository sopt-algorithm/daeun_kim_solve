#include <cstdio>

int N, cnt;
int map[17][17];
enum dir{horizontal=0, vertical=1, diagnal=2};

void solve(int y, int x, int direction) {
	if(y==N && x==N) { cnt++; return; }
	switch(direction) {
		case horizontal:
			//오른쪽으로
			if(x+1<=N && !map[y][x+1])
				solve(y, x+1, horizontal);
			//대각선으로
			if(x+1<=N && y+1<=N && !map[y][x+1] && !map[y+1][x] && !map[y+1][x+1])
				solve(y+1, x+1, diagnal);
			break;
		case vertical:
			//아래로
			if(y+1<=N && !map[y+1][x])
				solve(y+1, x, vertical);
			//대각선으로
			if(x+1<=N && y+1<=N && !map[y][x+1] && !map[y+1][x] && !map[y+1][x+1])
				solve(y+1, x+1, diagnal);
			break;
		case diagnal:
			//오른쪽으로
			if(x+1<=N && !map[y][x+1])
				solve(y, x+1, horizontal);
			//아래로
			if(y+1<=N && !map[y+1][x])
				solve(y+1, x, vertical);
			//대각선으로
			if(x+1<=N && y+1<=N && !map[y][x+1] && !map[y+1][x] && !map[y+1][x+1])
				solve(y+1, x+1, diagnal);
			break;
	}
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	}
	solve(1,2, horizontal);
	printf("%d", cnt);
	return 0;
}