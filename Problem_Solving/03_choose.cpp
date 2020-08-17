#include<cstdio>
using namespace std;

int dp[10001][10001];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= 10000; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 1000000;
		}
	}
	printf("%d\n", dp[n][k]);

	return 0;
}