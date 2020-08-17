#include<stdio.h>

int main() {
	int arr[10][10] = { 0 };
	int n, m, i, j, k, l, tmp;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &m);

		for (j = 0; j < m; j++) {
			for (k = 0; k < m; k++) {
				scanf("%d", &arr[j][k]);
			}
		}

		for (k = 0; k < m; k++) {
			for (j = 0; j < m; j++) {
				if (arr[j][k] == 1) {
					for (l = 0; l < m; l++) {
						if (arr[k][l] == 1) {
							arr[j][l] = 1;
						}
					}
				}
			}
		}
		
		for (k = 0; k < m; k++) {
			for (l = 0; l < m; l++) {
				printf("%d ", arr[k][l]);
			}
			printf("\n");
		}
	}

	return 0;
}