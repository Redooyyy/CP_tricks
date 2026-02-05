#include <bits/stdc++.h>
using namespace std;

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

int main() {
  int a, b;
  cin >> a >> b;
  cout << my_pow(a, b);
}
