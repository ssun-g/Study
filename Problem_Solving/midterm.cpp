#include<cstdio>
using namespace std;

int result(int);

int inp[1001];
int ans[1001];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inp[i]);
	}

	printf("%d\n", result(n));

	return 0;
}

int result(int num) {
	ans[1] = inp[1];
	ans[2] = inp[1] - inp[2];

	for (int i = 3; i <= num; i++) {
		if (inp[i] >= 0) ans[i] = ans[i - 1] + inp[i];
		else ans[i] = ans[i - 1] - inp[i];
	}

	return ans[num];
}