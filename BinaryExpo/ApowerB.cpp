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
  long long int store = withModulo(a, b / 2);
  if (b & 1) {
    return (a * ((store * 1LL * store) % M)) % M; // formula in my note
  } else {
    return (store * 1LL * store) % M;
  }
}

// Iterative appeoach
// Time complexity low and optimized!! Theory on my note
long long binExpoIter(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * 1LL * a) % M;
    }
    a = (a * 1LL * a) % M;
    b >>= 1;
  }
  return ans;
}

int main() {
  int a, b;
  cin >> a >> b;
  // cout << my_pow(a, b);
  cout << withModulo(a, b) << endl;
  cout << "Iterative " << binExpoIter(a, b);
}
