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
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  int st = 1, en = n;
  while (st + 1 <= n && A[st + 1] > A[st]) {
    ++st;
  }
  while (en - 1 >= 1 && A[en - 1] < A[en]) {
    --en;
  }
  long long prs = 0;
  for (int i = 1; i <= st; ++i) {
    int nxt = upper_bound(A.begin() + en, A.end(), A[i]) - A.begin();
    if (nxt <= n) {
      if (nxt != i + 1) {
        prs += n - nxt + 1;
      } else {
        prs += n - nxt;
      }
    }
  }
  prs += n - en + 1;
  prs += st;
  if (st == n) {
    prs -= 2;
  }
  cout << prs << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
