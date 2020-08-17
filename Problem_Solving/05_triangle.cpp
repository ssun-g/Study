#include<cstdio>
using namespace std;

void Tri_num(int);
void triPrint(int, int);

int tri[450]; //삼각수 저장
int triArr[100001]; //삼각수들의 합으로 표현하는 방법 저장
int triNum[100001]; //삼각수들의 합으로 표현할 수 있는 개수 저장

int n, p, end;

int main() {
	scanf("%d %d", &n, &p);

	tri[1] = 1;
	for (int i = 2; i <= 450; i++) {
		tri[i] = tri[i - 1] + i;
		if (tri[i] >= n) {
			if (tri[i] == n) end = i;
			else end = i - 1;
			break;
		}
	}
	Tri_num(end);
	if (p == 1) {
		triPrint(0, 1);
	}

	return 0;
}

void Tri_num(int ed) {
	triNum[1] = 1;
	triNum[2] = 1;
	triNum[3] = 2;
	if (n < 4) return;
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= ed; j++) {
			if (i < tri[j]) break;
			triNum[i] = (triNum[i] + triNum[i - tri[j]]) % 1000000;
			if (i == tri[j]) triNum[i]++;
		}
	}
	printf("%d\n", triNum[n]);
}

void triPrint(int sum, int ind) {
	if (sum > n) return;
	if (sum == n) {
		for (int i = 1; i < ind; i++) {
			printf("%d ", triArr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= end; i++) {
		if (ind > n) break;
		triArr[ind] = tri[i];
		triPrint(sum + tri[i], ind + 1);
	}
}