#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> result;

void scribe(int, int, int);

int n, k, sum, ind;
int page[5000], people[10];
int MAX;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &page[i]);
		MAX = max(MAX, page[i]);
	}

	if (n <= k) {
		printf("%d\n", MAX);
	}
	else {
		scribe(0, n, k);
		sort(result.begin(), result.end());
		printf("%d\n", result[0]);
	}

	return 0;
}

void scribe(int init, int part, int num) {
	for (int i = init; i < n ; i++) {
		sum = 0;
		if (n - 1 - i < num - 1) return;
		if (num == 1) {
			for (int j = init; j < n; j++) {
				sum += page[j];
			}
			people[ind] = sum;
			result.push_back(*max_element(people, people + k));
			return;
		}

		for (int k = init; k <= i; k++) {
			sum += page[k];
		}
		people[ind++] = sum;

		scribe(i + 1, part - 1, num - 1);
		ind--;
	}
}