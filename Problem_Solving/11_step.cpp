#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
pair<int, int> p, a ,b;
vector<pair<int, int>> spot, step;

void make_func();
int step_func();

int f, g, idx;

int main() {
	scanf("%d", &f);
	for (int i = 0; i < f; i++) {
		scanf("%d%d", &p.first, &p.second);
		spot.push_back(p);
	}

	scanf("%d", &g);
	for (int i = 0; i < g; i++) {
		scanf("%d%d", &p.first, &p.second);
		spot.push_back(p);
	}
	scanf("%d%d", &a.first, &b.first);
	sort(spot.begin(), spot.end());

	make_func();
	printf("%d\n", step_func());

	return 0;
}

void make_func() {
	step.push_back(spot[0]);
	for (int i = 1; i < spot.size(); i++) {
		if (step[idx].second <= spot[i].second) {
			if (step[idx].second == spot[i].second) {
				step.pop_back();
				idx--;
			}
			step.push_back(spot[i]);
			idx++;
		}
	}
}

int step_func() {
	long long sum = 0;
	int init, end;
	bool flag = true;
	for (int i = 0; i < step.size(); i++) {
		if (a.first < step[0].first) init = -1;
		if (b.first < step[0].first) end = 0;
		if (step[i].first <= a.first) {
			a.second = max(a.second, step[i].second);
			init = i;
		}
		if (step[i].first <= b.first) {
			b.second = max(b.second, step[i].second);
			end = i;
		}
	}
	if (step[step.size() - 1].first < a.first && step[step.size() - 1].first < b.first) sum = ((b.first - a.first + 1) * a.second) % 10007;
	for (int i = init + 1; i <= end; i++) {
		if (i == end && step[i].first <= b.first) {
			if (step[i].first < b.first)
				sum = (sum + ((b.first - step[i].first + 1) % 10007) * (b.second % 10007)) % 10007;
			else sum = (sum + b.second) % 10007;
		}
		if (flag && a.first < step[i].first) {
			sum = (sum + ((step[i].first - a.first) % 10007) * (a.second % 10007)) % 10007;
			flag = false;
		}
		else {
			sum = (sum + ((step[i].first - step[i - 1].first) % 10007) * (step[i - 1].second % 10007)) % 10007;
		}
	}
	return sum;

}