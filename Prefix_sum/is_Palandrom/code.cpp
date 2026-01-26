/*
Luffy with his crew is on the way to Dressrosa, where he will be fighting one
of the warlords of the sea Doflamingo. But now he is getting bored and wants do
a fun activity. He is very much obsessed with palindromes. Given a string S of
lower case English alphabet of length N and two Integers L and R he wants to
know whether all the letters of the substring from index L to R (L and R
included) can be rearranged to form a palindrome or not. He wants to know this
for Q values of L and R and needs your help in finding the answer.

Palindrome is a string of characters which when reversed reads same as the
original String.

CONSTRAINTS:
1 <= t <= 10
1 ≤ N, Q ≤ 100000
1 <= L <= R<=N
'a'<= S[i]<= 'z' for 1 <= i <= N

OUTPUT =>
_ _ _ _ _ _ _ _ _ _ _ _ _ _ _
Input       |      Output    |
- - - - - - - - - - - - - - -
2           |        NO      |
5 5         |        NO      |
abcec       |        YES     |
1 2         |        NO      |
2 5         |        NO      |
3 5         |        YES     |
1 5         |        NO      |
1 4         |        YES     |
5 5         |        YES     |
aabbc       |        YES     |
1 2         |                |
2 5         |                |
3 5         |                |
1 5         |                |
1 4         |                |
- - - - - - - - - - - - - - -

Question Link : unavailble;
*/

// NOTE: bruteforce approach
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    while (q--) {
      int l, r;
      cin >> l >> r;
      int hsh[26];
      for (int i = 0; i < 26; i++) {
        hsh[i] = 0;
      }
      l--;
      r--;
      for (int i = l; i <= r; i++) {
        hsh[s[i] - 'a']++;
      }
      int odd = 0;
      for (int i = 0; i < 26; i++) {
        if (hsh[i] % 2 != 0)
          odd++;
      }

      if (odd > 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
*/

// NOTE:Optimized approach

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hsh[N][26];

int main() {
  int t;
  cin >> t;

  while (t--) {
    // must reset the hsh array for every test cases
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 26; j++) {
        hsh[i][j] = 0;
      }
    }
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
      hsh[i + 1][s[i] - 'a']++; // convert into 1 based array so hsh[i+1];
    }

    // prefix sum
    for (int i = 0; i < 26; i++) {
      for (int j = 1; j <= n; j++) {
        hsh[j][i] += hsh[j - 1][i];
      }
    }

    while (q--) {

      int l, r;
      cin >> l >> r;
      int odd = 0;
      for (int i = 0; i < 26; i++) {
        int charCount = hsh[r][i] - hsh[l - 1][i];
        if (charCount % 2 != 0)
          odd++;
      }
      if (odd > 1)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
