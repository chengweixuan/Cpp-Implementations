// implementation of a custom comparator for map
// is only able to custom sort by key, and not satalite data
#include <bits/stdc++.h>
using namespace std;

typedef pair<string,int> si;

bool compare(string A, string B)
{
  return A > B;
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; // number of inserts

  map<string, int, decltype(&compare)> order(&compare);

  for (int i = 0; i < n; i++) {
    string key; cin >> key;
    int value; cin >> value;

    order[key] = value;
  }

  cout << endl;
  for (auto i : order) {
    cout << i.first << ": " << i.second << " ";
  }
  cout << endl << endl;

  cout << order.begin()->first << ": " << order.begin()->second;
  cout << " ";
  cout << (--order.end())->first << ": " << (--order.end())->second;
}
