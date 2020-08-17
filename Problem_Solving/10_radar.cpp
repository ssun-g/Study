#include<cstdio>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

pair<int, int> p[10001];
int center[10001];
int n, d, cnt = 1, idx;

int main() {
	for (int i = 0; i < 10001; i++)
		center[i] = 10001;

	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		int left = p[i].first - d;
		int right = p[i].first + d;

		if (p[i].second == d || (p[i].second == (d*-1))) center[i] = p[i].first;
		else {
			while (left <= right) {
				int mid = (left + right) / 2;
				if (sqrt((p[i].first - mid)*(p[i].first - mid)) + ((p[i].second*p[i].second)) <= d) {
					right = mid - 1;
					center[i] = min(center[i], mid);
				}
				else left = mid + 1;
			}
		}
	}
	sort(center, center + n);
	bool flag = false;
	int ct = center[0];

	for (int i = 0; i < n; i++) {
		if (p[i].second > d) {
			flag = true;
			break;
		}
		if (sqrt(((p[i].first - ct)*(p[i].first - ct)) + ((p[i].second)*(p[i].second))) > d) {
			for(int j = idx + 1; j<n; j++){
				if (center[idx] != center[j]) {
					idx = j;
					break;
				}
			}
			ct = center[idx];
			cnt++;
		}
	}
	if (flag) printf("-1\n");
	else printf("%d\n", cnt);
	return 0;
}