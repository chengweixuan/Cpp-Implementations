// Effective floodfill algorithm used to solve Sheba's Amoebas
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> grid;

int for_x[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int for_y[] = {-1, -1, -1, 0, 0, 1, 1, 1};


void fill(int y, int x, int n, int m)
{
  // x linked to n
  // y linked to m
  if (x < 0 || y < 0 || x > (n - 1) || y > (m - 1) || grid[y][x] == '.') {
    return;
  }
  grid[y][x] = '.';

  for (int i = 0; i < 8; i++) {
    fill(y + for_y[i], x + for_x[i], n, m);
  }

}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);
  int m; cin >> m; // no of rows
  cin.get();
  int n; cin >> n; // no of columns
  cin.get();

  for (int i = 0; i < m; i++) {
    string line;
    getline(cin, line);

    grid.push_back(line);
  }

  int counter = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '#') {
        counter++;
        fill(i, j, n, m);
      }
    }
  }

  cout << counter;

}
