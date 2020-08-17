#include<stdio.h>
#include<math.h>

void prime_num(int);

int main(void) {
	int num;
	scanf("%d", &num);

	prime_num(num);

	return 0;
}

void prime_num(int n) {
	int i, cnt = 0;

	for (i = 1; i <= sqrt(n) + 1; i++) {
		if (n%i == 0) cnt++;
	}

	if (cnt >= 2) printf("False ");
	else printf("True ");
}