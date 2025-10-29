#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, r;
  int suite_number = 1;
  bool first_suite = true;

  while (cin >> n >> r) {
    if (n == 0 && r == 0) {
      break;
    }

    if (!first_suite) {
      cout << "\n"; // Print a blank line before each suite except the first
    }
    first_suite = false;

    vector<long long> arr(n + 1); // Using 1-based indexing for easier range handling
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }

    cout << "Suite " << suite_number << ":\n";
    suite_number++;

    for (int i = 0; i < r; ++i) {
      int query_type;
      cin >> query_type;

      if (query_type == 1) {
        int x, y;
        cin >> x >> y;
        // Swap adjacent pairs in the range [x, y]
        for (int j = x; j < y; j += 2) {
          swap(arr[j], arr[j + 1]);
        }
      } else if (query_type == 2) { // query_type == 2
        int a, b;
        cin >> a >> b;
        long long sum = 0;
        for (int j = a; j <= b; ++j) {
          sum += arr[j];
        }
        cout << sum << "\n";
      }
    }
  }

  return 0;
}