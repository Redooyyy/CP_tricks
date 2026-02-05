#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

long long my_pow(int a, int b) {
  if (b == 0)
    return 1;
  long long int store = my_pow(a, b / 2);
  if (b & 1) {
    return a * store * store;
  } else {
    return store * store;
  }
}
long long withModulo(int a, int b) {
  if (b == 0)
    return 1;
  long long int store = my_pow(a, b / 2);
  if (b & 1) {
    return (a * (store * 1LL * store) % M) % M; // formula in my note
  } else {
    return (store * 1LL * store) % M;
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  // cout << my_pow(a, b);
  cout << withModulo(a, b);
}
