// Implementation of Bellman Ford Algorithm
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> iii;

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n, m, q, s;
  n = 1; m = 1; q = 1; s = 1;

  while (cin >> n >> m >> q >> s, (n || m || q || s)) {

    vector<iii> EL;
    EL.assign(m, iii());
    // creates the edge list
    for (int i = 0; i < m; i++) {
      int a; cin >> a; // from this
      int b; cin >> b; // to this
      int c; cin >> c; // weight

      EL.emplace_back(a, b, c);
    }
    // weight distance array that also serves as visited array
    vector<int> dist;
    dist.assign(n, 1e9);

    dist[s] = 0; // set starting distance to be 0

    for (int i = 0; i < n - 1; i++) { // loop n - 1 times
      bool relaxed = false;

      for (auto &[u, v, w] : EL) {
        if (dist[u] == 1e9) continue; // skip vertices not yet explored
        if (dist[u] + w < dist[v]) { // if can be relaxed
          relaxed = true;
          dist[v] = dist[u] + w; // relaxing
        }
      }
      if (!relaxed) break; // optimisation step
    }

    for (int i = 0; i < q; i++) {
      int query; cin >> query;

      if (dist[query] != 1e9) {
        cout << dist[query] << endl;
      } else {
        cout << "Impossible" << endl;
      }
    }

  cout << endl;
  }

}
