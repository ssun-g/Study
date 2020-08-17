#include<cstdio>
#include<queue>
#include<vector>
#include<utility>
#include<functional>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> v;

int last_time = -1;
int short_time = 1000000000;
int work_time;
int cur_time;

int main() {
	int n;
	scanf("%d", &n);

	int start, end;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &start, &end);
		pq.push(make_pair(start, end));
	}

	while (!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}

	for (int i = 0; i < v.size(); i++) {
		if (last_time < v[i].first) {
			if (i + 1 < v.size()) {
				if (v[i].second < v[i + 1].first)
					cur_time = v[i].second - v[i].first;

				else
					cur_time = v[i + 1].first - v[i].first;;
			}
			else
				cur_time = v[i].second - v[i].first;

			work_time += v[i].second - v[i].first;
			last_time = v[i].second;
		}
		else {
			if (last_time < v[i].second) {
				if (i + 1 < v.size()) {
					if (v[i].second < v[i + 1].first)
						cur_time = v[i].second - last_time;

					else {
						cur_time = v[i].second - last_time;
						for (int j = i + 1; j < v.size(); j++) {
							if (v[i].second < v[j].second) {
								cur_time -= v[i].second - v[j].first;
								break;
							}
							cur_time -= v[j].second - v[j].first;
						}
					}
				}

				work_time += v[i].second - last_time;
				last_time = v[i].second;
			}
			else
				cur_time = 0;
		}

		if (short_time > cur_time) {
			short_time = cur_time;
		}
	}
	printf("%d\n", work_time - short_time);

	return 0;
}