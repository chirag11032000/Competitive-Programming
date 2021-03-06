#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
  int n;
  cin >> n;
  vector<int> V(n);
  int diff = 0;
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
    if (V[i] & 1) {
      if (V[i] > 0) {
        ++diff;
      } else {
        --diff;
      }
      int tmp = V[i];
      V[i] /= 2;
      if (abs(diff) == 2) {
        if (tmp > 0) {
          ++V[i];
        } else {
          --V[i];
        }
        diff = 0;
      }
    } else {
      V[i] /= 2;
    }
    cout << V[i] << "\n";
  }
  assert(diff == 0);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
