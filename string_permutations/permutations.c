#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void permute(char **permutations, int *count, char *string, int start, int end)
{
	if(start == end) {
		*(permutations + *count) = (char *)malloc(sizeof(char) 
				* (strlen(string) + 1));
		strcpy(*(permutations + (*count)++), string);
	}
	else {
		int i;
		for(i = start; i < end; i++) {
			swap(string + start, string + i);
			permute(permutations, count, string, start + 1, end);
			swap(string + start, string + i);
		}
	}
} 

int factorial(int n)
{
	if(n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int compare(void const *a, void const *b)
{
	return strcmp(*(char *const *)a, *(char *const *)b);
}

void print_unique(char **strings)
{
	char *string = *strings;
	printf("%s", string);
	int c = 1;
	while(*(strings + c) != NULL) {
		if(strcmp(*(strings + c), string) != 0) {
			string = *(strings + c);
			printf(",%s", string);
		}
		c++;
	}
	printf("\n");
}

char print_permutations(char *string)
{
	int len = strlen(string);
	int fact = factorial(len);
	char **permutations = (char **)malloc(sizeof(char *) * (fact + 1));
	int count = 0;
	permute(permutations, &count, string, 0, strlen(string));
	*(permutations + fact) = NULL;
	qsort(permutations, fact, sizeof(char *), compare);
	print_unique(permutations);
	free(permutations);
}

int main(int argc, char **argv)
{
	if(argc != 2) {
		printf("usage: %s file\n", *argv);
		return 1;
	}
	FILE *file = fopen(argv[1], "r");
	char *line = NULL;
	size_t len = 0;
	int read;
	while((read = getline(&line, &len, file)) != -1) {
		if(line[read - 1] == '\n')
			line[read - 1] = '\0';
		print_permutations(line);
	}
	free(line);
	fclose(file);
	return 0;
}
