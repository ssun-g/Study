#include<stdio.h>

int GCD(int, int);

int main(void) {
	int num1, num2;
	scanf("%d%d", &num1, &num2);

	if (num1 > num2)
		printf("%d\n", GCD(num1, num2));
	else if (num2 > num1)
		printf("%d\n", GCD(num2, num1));

	return 0;
}

int GCD(int a, int b) { // main문에서 a>b가 되도록 값을 넣어준다.
	if (b == 0)
		return a; // else문에 의해 작은 값이 0이 되면 a값을 return한다.
	else
		return GCD(b, a%b); // 유클리드 알고리즘(재귀적 호출방법)
}