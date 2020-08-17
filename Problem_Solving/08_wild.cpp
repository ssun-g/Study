#include<cstdio>
#include<algorithm>
using namespace std;

void spider(int);

int feed[100000];
int n, k, ans, dist, cnt;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &feed[i]);
	}
	sort(feed, feed + n);
	spider(k);

	return 0;
}

void spider(int num) {
	if (num == 2) {
		printf("%d\n", feed[n - 1] - feed[0]);
		return;
	}
	int left = 1;
	int right = feed[n-1] - feed[0];
	int mid = (left + right) / 2;

	while (left <= right) {
		int start = feed[0];
		cnt = 1;
		mid = (left + right) / 2; 
		for (int i = 1; i < n; i++) {
			dist = feed[i] - start;
			if (mid <= dist) {
				cnt++;
				start = feed[i];
			}
		}
		if (cnt >= k) {
			ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n", ans);
}