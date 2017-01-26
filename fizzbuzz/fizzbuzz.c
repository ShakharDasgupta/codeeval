#include <stdio.h>

void fizzbuzz(int x, int y, int n)
{
	int i;
	for(i = 1; i <= n; i++) {
		if(i % x == 0 && i % y == 0)
			printf("%s", "FB");
		else if(i % x == 0)
			printf("%s", "F");
		else if(i % y == 0)
			printf("%s", "B");
		else
			printf("%d", i);
		if(i < n)
			printf(" ");
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");
	int x, y, n;
	while(fscanf(fp, "%d %d %d", &x, &y, &n) != EOF)
		fizzbuzz(x, y, n);
	return 0;
}
