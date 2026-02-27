#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

bool dfs(int vertex, int parent) {

  vis[vertex] = true;
  bool isExist = false;
  for (int child : graph[vertex]) {
    if (vis[child] && child == parent)
      continue;
    if (vis[child])
      return true;
    isExist |= dfs(child, vertex);
  }
  return isExist;
}

int main() {

  int n, e;
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  bool hasCycle = false;

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    if (dfs(i, -1)) {
      hasCycle = true;
      break;
    }
  }

  cout << ((hasCycle) ? "Has Cycle" : "Has no loop") << endl;

  return 0;
}
