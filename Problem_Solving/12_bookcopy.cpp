#include<cstdio>
#include<algorithm>
using namespace std;

int n, sum, time, ans = 50001;
int check[100], book[100];

int go(int, int);

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &book[i]);
		sum += book[i];
	}

	if (!(sum % 3)) time = sum * 2 / 3;
	else time = sum * 2 / 3 + 1;

	go(0, 0);

	printf("%d\n", ans);

	return 0;
}

int go(int init, int s) {
	if (s == time) {
		ans = s;
		return 1;
	}
	if (s > time) {
		ans = min(ans, s);
		return 0;
	}
	for (int i = init; i < n; i++) {
		if (!check[i]) {
			check[i] = 1;
			if (go(i + 1, s + book[i])) return 1;
			check[i] = 0;
		}
	}
	return 0;
}