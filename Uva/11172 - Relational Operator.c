#include <stdio.h>


int main() {
	int n, num1, num2, i;

	while(scanf("%d", &n) == 1) {
		for (i = 0; i < n; i++) {
			scanf("%d%d", &num1, &num2);

			if (num1 > num2) {
				printf(">\n");
			}
			else if (num1 < num2) {
				printf("<\n");
			}
			else {
				printf("=\n");
			}
		}
	}

	return 0;
}
