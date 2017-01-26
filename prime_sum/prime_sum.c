#include <stdio.h>

#define LIMIT 1000

int isPrime(int n)
{
	int c = 0;
	for(int i = 1; i <= n; i++)
		if(n % i == 0)
			c++;
	return c == 2;
}

int main()
{
	int i, c, s;
	i = c = s = 0;
	while(c < LIMIT)
	{
		if(isPrime(i)) {
			s += i;
			c++;
		}
		i++;
	}
	printf("%d\n", s);
	return 0;
}
