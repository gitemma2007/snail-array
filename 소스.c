#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("숫자를 입력하시오 : ");
	scanf_s("%d", &n);

	//int matrix[4][4] = { 0, {0} }; int n = 4;
	int** matrix = NULL;
	matrix= malloc(sizeof(int*)*n); 
	for (int i = 0; i < n; i++)
		matrix[i] = malloc(sizeof(int) * n);

	int k = 0,way,i, num = 1, row=0, col=0;
	while (k < n / 2 && num <=n*n) {
		way = 0;
		while (way < 4) {
			i = 0;
			while (i < n - (2 * k + 1)) {
				switch (way) {
				case 0:
					matrix[row + k][k + col++] = num;
					num++;
					i++;
					break;
				case 1:
					matrix[k+ row++][k+ col] = num;
					num++;
					i++;
					break;
				case 2:
					matrix[k+row][k+col--] = num;
					num++;
					i++;
					break;
				case 3:
					matrix[k+row--][k+col] = num;
					num++;
					i++;
					break;
				}
			}
			way++;
		}
		k++;

	}

	if (n % 2 != 0)
		matrix[k+ row][k+ col] = num;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%4d ", matrix[i][j]);
		printf("\n");
	}

	
	return 0;
}