// Implementation of Modified Dijkstra's
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

  // int n; cin >> n; // number of nodes
  // int m; cin >> m; // number of edges
  // int q; cin >> q; // number of queries
  // int s; cin >> s; // starting node

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

    ii temp = make_pair(c, b); // weight comes first
    AL[a].push_back(temp);
  }

  // try modified dijkstra
  vector<int> dist;
  dist.assign(n, 1e9); // set all initial vertex weights to INF
  dist[s] = 0;
  // priority given to weight which is put first
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push(make_pair(0,s));

  while (!pq.empty()) {
    ii min = pq.top();
    pq.pop();

    int d = min.first; // the current weight distance
    int u = min.second; // the current vertex

    // for whatever reason the distance increases, don't bother searching for relaxes
    if (dist[u] < d) continue;

    for (auto &i : AL[u]) {
      int v = i.first; // weight of neighbour
      int w = i.second; // vertex of neighbour

      if (dist[u] + v < dist[w]) { // if relaxable
        dist[w] = dist[u] + v; // relax it
        pq.push(make_pair(dist[w], w)); // add to queue
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
