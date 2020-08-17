#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// for disable secure warning(freopen, ...)
#ifdef _WIN32
#pragma warning(disable:4996)
#endif

using namespace std;

typedef struct Interval {
	int start;
	int end;
	int id;

	Interval(int s, int e, int id)
		: start(s), end(e), id(id) {}

} Interval;

// for priority queue
bool operator<(Interval i1, Interval i2) {
	return i1.start > i2.start; // prior: smaller start
};

// for quick sort
int compare(const void *a, const void *b) {
	return *(int *)a < *(int *)b;
}

int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	cin >> n;

	int *counter = new int[n]();
	priority_queue<Interval> interval;

	int a, b, t;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> t;

		// change open range to closed range
		if (t == 0) {
			a++; b--;
		}

		// check if the range is valid
		if (a < b) {

			// push interval to priority queue
			Interval t(a, b, i);
			interval.push(t);
		}
	}

	// for every interval input, check the previous interval's validity and intersection
	// if interval is invalid save that index and erase totally
	// if intersection is exist, increase counter value for current interval and searched interval
	vector<Interval> cur_interval;
	while (!interval.empty()) {
		Interval t = interval.top();
		interval.pop();

		// if intersection is exist, increase counter
		// if the range is invalid, add index to remove vector for erase method
		vector<int> remove;
		for (unsigned int i = 0; i < cur_interval.size(); i++) {
			if (cur_interval[i].end < t.start)
				remove.push_back(i);
			else {
				counter[t.id]++;
				counter[cur_interval[i].id]++;
			}
		}

		// erase interval from last to first because
		for (int i = remove.size() - 1; i >= 0; i--)
			cur_interval.erase(cur_interval.begin() + i);

		cur_interval.push_back(t);
	}

	// sort for decrease order
	qsort(counter, n, sizeof(int), compare);

	// print result
	for (int i = 0; i < n; i++)
		cout << counter[i] << " ";
	cout << endl;

	delete[] counter;

	return 0;
}