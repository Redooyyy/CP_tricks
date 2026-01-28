/*
Given N strings, print unique strings in lexographical order with their
frequency

CONSTAINS
1<=N<=10^5
|S|<=100
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> m;

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    m[s] = m[s] + 1; // m[n] gives the value which is by default 0 just +1
                     // whwnever it appears again!! also can use m[s]++
  }

  for (auto val : m) {
    cout << val.first << " " << val.second << endl;
  }
}
