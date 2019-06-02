// Implementation of Modified Dijkstra's with a custom priority queue
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool compare(ii A, ii B)
{
  return A.second > B.second;
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n, m, q, s;
  n = 1; m = 1; q = 1; s = 1;

  while (cin >> n >> m >> q >> s, (n || m || q || s)) {

  // make AL
  vector< vector<ii> > AL;
  AL.assign(n, vector<ii>());

  for (int i = 0; i < m; i++) {
    int a; cin >> a; // from this
    int b; cin >> b; // to this
    int c; cin >> c; // weight

    AL[a].emplace_back(b,c); // try with weight second
  }

  // try modified dijkstra
  vector<int> dist;
  dist.assign(n, 1e9);
  dist[s] = 0;

  priority_queue<ii, vector<ii>, function<bool(ii, ii)>> pq(compare);
  pq.push(make_pair(s,0));

  while (!pq.empty()) {
    ii min = pq.top();
    pq.pop();

    int u = min.first; // the current weight distance
    int d = min.second; // the current vertex

    // for whatever reason the distance increases, don't bother searching for relaxes
    if (dist[u] < d) continue;

    for (auto &i : AL[u]) {
      int v = i.first; // vertex of neighbour
      int w = i.second; // weight of neighbour

      if (dist[u] + w < dist[v]) { // if relaxable
        dist[v] = dist[u] + w; // relax it
        pq.push(make_pair(v, dist[v])); // push vertex into the pq
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int query; cin >> query;

    if (dist[query] != 1e9) {
      cout << dist[query] << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  // introduced loop
    cout << endl;
  }

}
