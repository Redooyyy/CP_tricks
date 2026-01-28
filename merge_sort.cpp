#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N];

// merge algo
void my_merge(int l, int r, int mid) {
  int l_sz = mid - l + 1;
  int left[l_sz + 1]; // one extra for INT_MAX
  int r_sz = r - (mid + 1) + 1;
  int right[r_sz + 1]; // one extra for INT_MAX

  // copy array keeping indexes same as real one
  for (int i = 0; i < l_sz; i++) {
    left[i] = arr[i + l];
  }
  for (int i = 0; i < r_sz; i++) {
    right[i] = arr[mid + 1 + i];
  }

  // keep last indx value to maximum
  right[r_sz] = left[l_sz] = INT_MAX;

  // merge
  int l_indx = 0, r_indx = 0;
  for (int i = l; i <= r; i++) {
    if (left[l_indx] <= right[r_indx]) {
      arr[i] = left[l_indx++];
    } else {
      arr[i] = right[r_indx++];
    }
  }
}

// merge sort(spliting)
void mergeSort(int l, int r) {
  if (l == r)
    return;
  int mid = (l + r) / 2;

  mergeSort(l, mid);
  mergeSort(mid + 1, r);

  my_merge(l, r, mid);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  mergeSort(0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
