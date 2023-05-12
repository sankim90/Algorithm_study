#include <iostream>
#include <vector>
using namespace std;

int N, M;
//vector<bool> visit;
bool visit[10];
vector<int> vec;
void dfs() {
	if (vec.size() == M) {
		for (int i = 0; i < M; i++) printf("%d ", vec[i]+1);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true; 
			vec.push_back(i);
			dfs(); //간단히 애 종료되면 다음 꺼... return되서 다음 줄 실행이지
			visit[i] = false; 
			vec.pop_back();
		}
	}
}

int main(void) {
	cin >> N >> M;
	//visit = vector<bool>(N + 1, false);

	dfs();
}
