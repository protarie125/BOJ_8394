#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

vi memo;
int solve(int n) {
	if (memo[n] < 0) {
		memo[n] = (solve(n - 1) + solve(n - 2)) % 10;
	}

	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	n %= 60;

	memo = vi(n + 2, -1);
	memo[0] = 1;
	memo[1] = 1;

	cout << solve(n);

	return 0;
}