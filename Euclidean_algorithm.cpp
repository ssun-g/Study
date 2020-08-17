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

int GCD(int a, int b) { // main������ a>b�� �ǵ��� ���� �־��ش�.
	if (b == 0)
		return a; // else���� ���� ���� ���� 0�� �Ǹ� a���� return�Ѵ�.
	else
		return GCD(b, a%b); // ��Ŭ���� �˰���(����� ȣ����)
}