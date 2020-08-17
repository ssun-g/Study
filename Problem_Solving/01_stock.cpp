#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct Data {
	int data;
	int profit;
	int Max;
	int Min;
}Data;

struct Data stock(int, int);
Data my;

int arr[1000001];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d\n", stock(1, n).profit);

	return 0;
}

struct Data stock(int left, int right) {
	Data l, r;
	int mid;

	if (left == right) {
		my.data = -999999999;
		my.Max = arr[left];
		my.Min = arr[left];

		return my;
	}

	else {
		mid = (left + right) / 2;
		l = stock(left, mid);
		r = stock(mid + 1, right);

		my.data = max(max(l.data, r.data), r.Max - l.Min);
		my.profit = max(my.profit, r.data + l.data);
		my.Max = max(l.Max, r.Max);
		my.Min = min(l.Min, r.Min);

		return my;
	}
}