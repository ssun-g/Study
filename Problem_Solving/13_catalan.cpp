#include<cstdio>
using namespace std;

int catalan[19];

int main() {
	int n;
	scanf("%d", &n);

	catalan[0] = 1;
	catalan[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			catalan[i] = catalan[i] + (catalan[j] * catalan[i - 1 - j]);
		}
	}
	printf("%d\n", catalan[n]);

	return 0;
}