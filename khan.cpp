// Implementation of Khan's Algorithm
#include <bits/stdc++.h>
using namespace std;
// function to check if a given vertex has incoming edges
bool noedge(string x, unordered_map<string, unordered_set<string> > AL)
{
  int counter = 0;
  for (auto &i : AL) {
    if (i.second.find(x) != i.second.end()) {
      counter++;
    }
  }
  if (counter > 0) {
    return false;
  } else {
    return true;
  }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  cin.get();

  unordered_map<string, unordered_set<string> > AL;
  unordered_map<string,int> visited;
  vector<string> answer;

  for (int i = 0; i < n; i++) {
    string line; getline(cin, line);

    istringstream iss(line);
    string key; iss >> key;
    key.pop_back(); // get rid of the colon

    visited[key] = 0; // creating visited list
    string temp;
    while (iss >> temp) {
      AL[temp].insert(key);
    }

  }

  string start;
  cin >> start;
  // begin BFS / Khan's Algorithm
  queue<string> q;
  q.push(start);

  while (!q.empty()) {
    string u = q.front();
    q.pop();
    // push into the queue if there are no incoming edges
    if (noedge(u, AL) || u == start) {

       for (auto &i : AL[u]) {
        q.push(i); // push first and check later
      }
      // erases the vertex from the AL
      for (auto &i : AL[u]) {
        auto it = AL[i].find(u);
        if (it != AL[i].end()) AL[i].erase(it);
      }
      AL[u].clear();
    }
    // inputs the toposort into the list
    answer.push_back(u);
  }

  for (auto i : answer) {
    cout << i << endl;
  }

}
