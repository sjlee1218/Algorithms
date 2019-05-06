#include <stdio.h>

int main(void)
{
	int a;
	int i, j, k;
	scanf("%d", &a);
	for (i = 1; i <= a; i++)
	{
		for (k = a - i; k > 0; k--)
			printf(" ");
		for (j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
