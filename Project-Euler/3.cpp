/* 
chirag11032000
Chirag Thakur
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template < typename T >
using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;

template < typename T >
using min_priority_queue = priority_queue < T, vector < T >, greater < T > >;

typedef long long ll;
typedef double db;
typedef pair < ll, ll > pll;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const db PI = acos(-1);
const ll MOD = 1e9 + 7, INF = LLONG_MAX;
const ll N = 1e5 + 10;

void test_case();

int main() {
	fast_io();
	test_case();
	cerr << "Time taken: " << int((clock() * 1000.) / CLOCKS_PER_SEC) << "ms\n";
	return 0;
}

void test_case() {
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ans = max(ans, i);
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n != 1) {
		ans = max(ans, n);
	}
	cout << ans << "\n";
}