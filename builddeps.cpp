// Implementation of toposort with DFS
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, unordered_set<string> > AL;
unordered_map<string,int> visited;

vector<string> answer;
// gives a toposort from one starting vertex
void toposort(string start)
{
  if (visited[start] == 1) return;

  visited[start] = 1;

  for (auto &i : AL[start]) {
    toposort(i);
  }

  answer.push_back(start);
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  cin.get(); // consume line
  // creates adjacency list
  for (int i = 0; i < n; i++) {
    string line; getline(cin, line);

    istringstream iss(line);
    string key; iss >> key;

    key.pop_back();
    string temp;
    visited[key] = 0;

    while (iss >> temp) {
      AL[temp].insert(key);
    }

  }

  string start;
  cin >> start;
  // DFS for a toposort
  toposort(start);
  // reverses the list for a correct toposort
  reverse(answer.begin(), answer.end());

  for (auto i : answer) {
    cout << i << endl;
  }

}
