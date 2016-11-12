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

int isPalindrome(int n)
{
	int n1 = n;
	int r = 0;
	while(n1 > 0) {
		r = r * 10 + n1 % 10;
		n1 /= 10;
	}
	return n == r;
}

int main() {
	for(int i = LIMIT - 1; i > 0; i--) {
		if(isPrime(i) && isPalindrome(i)) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
