inline int pos(int &x) {
	return 2 * x;
}

inline int neg(int &x) {
	return 2 * x + 1;
}

struct TwoSat {
	int n;
	vector < vector < int > > g, gR;
	vector < bool > seen, assignment;
	vector < int > comp;
	stack < int > stk;

	// sz denotes the number of boolean variables in 2-SAT problem
	TwoSat(int sz) { 
		assignment.resize(sz, false);
		sz <<= 1;
		n = sz;
		g.resize(sz);
		gR.resize(sz);
		seen.assign(sz, false);
		comp.assign(sz, - 1);
	}

	// Call this to add edge (0 - based)
	// If (ind & 1) -> node represented is -(ind / 2)
	// Else -> node represented is (ind / 2)
	void addEdge(int u, int v) {
		g[u].emplace_back(v);
		gR[v].emplace_back(u);
	}

	void dfs1(int u) {
		seen[u] = true;
		for (auto &v : g[u]) {
			if (!seen[v]) {
				dfs1(v);
			}
		}
		stk.push(u);
	}

	void dfs2(int u, int ctr) {
		comp[u] = ctr;
		for (auto &v : gR[u]) {
			if (comp[v] == -1) {
				dfs2(v, ctr);
			}
		}
	}

	// Returns true if solution of 2-SAT exists
	// After this is called, assignment[i] contains value (0 / 1) assigned to boolean variable i
	bool solve2Sat() {
		for (int i = 0; i < n; ++i) {
			if (!seen[i]) {
				dfs1(i);
			}
		}
		int ctr = 0;
		while (!stk.empty()) {
			int u = stk.top();
			stk.pop();
			if (comp[u] == -1) {
				dfs2(u, ++ctr);
			}
		}
		for (int i = 0; i < n; i += 2) {
			if (comp[i] == comp[i ^ 1]) {
				return false;
			}
			assignment[i / 2] = !(comp[i] < comp[i ^ 1]);
		}
		return true;
	}
};

/*
*** Sample Problems ***
- https://codeforces.com/contest/776/problem/D
- https://www.codechef.com/problems/ADAMTR
*/