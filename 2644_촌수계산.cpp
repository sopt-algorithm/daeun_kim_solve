#include <cstdio>

struct Node { int ppl[101] = {0}; int idx = 1;};

int N, M, a, b, parent, child;
Node arr[101];
int answer;

void dfs(int start, int ans, int visit[]) {
    visit[start] = 1;
	if(start==b) { answer = ans++; return; }
	for(int i = 0; i < arr[start].idx; i++) {
	    if(arr[start].ppl[i]==0 || visit[arr[start].ppl[i]]) continue;
		dfs(arr[start].ppl[i], ans+1, visit);
	}
}
int main() {
	scanf("%d", &N);
	int visit[N+1] = {0, };
	scanf("%d %d", &a, &b);
	scanf("%d", &M);
	while(M--) {
		scanf("%d %d", &parent, &child);
		arr[child].ppl[0] = parent;
		int index = arr[parent].idx;
		arr[parent].ppl[index] = child;
		arr[parent].idx += 1;
	}
	if(a==b) { printf("%d", 0); return 0; }
	dfs(a, 0, visit);
	printf("%d", (answer!=0) ? answer : -1);
	return 0;
}