inline void add(int &a, int b, int mod = MOD) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

inline void sub(int &a, int b, int mod = MOD) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

inline int mul(int a, int b, int mod = MOD) {
	return int((1LL * a * b) % mod);
}

inline int power(int a, long long b, int mod = MOD) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, a, mod);
		}
		a = mul(a, a, mod);
		b >>= 1;
	}
	return res;
}

inline int inv(int a, int mod = MOD) {
	a %= mod;
	if (a < 0) {
		a += mod;
	}
	int b = mod, u = 0, v = 1;
	while (a) {
		int t = b / a;
		b -= t * a;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	assert(b == 1);
	if (u < 0) {
		u += mod;	
	}
	return u;
}