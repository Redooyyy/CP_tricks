#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> graph[N];
bool visited[N];
void dfs(int vertex) {
  // NOTE: Take action on vertex after entering the vertex
  visited[vertex] = true;
  cout << vertex << " ";
  for (int child : graph[vertex]) {
    // NOTE: Take action on the child before entering the child node

    // cout << "ver : " << vertex << " child : " << child << endl;
    if (visited[child])
      continue;
    dfs(child);
    // NOTE: take action on child after exiting the child node
  }
  // NOTE: take action on vertex vertex before exiting the vertex
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

  // call dfs
  dfs(1); // normal call
  // handeling disconnected graph
  // counting how many connected graph in a forest
  int ct = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    ct++;
    dfs(i);
  }
  cout << endl;
}
