// creating a custom comparator for set
#include <bits/stdc++.h>
using namespace std;

bool compare(int A, int B)
{
  return A > B;
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n; // number count

  set<int,decltype(&compare)> order(&compare);

  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    order.insert(a);
  }

  cout << endl;
  for (auto i : order) {
    cout << i << " ";
  }

  cout << endl;

  cout << *order.begin();
  cout << " ";
  cout << *--order.end();

}
