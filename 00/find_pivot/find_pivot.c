#include <stdio.h>
#include <stdlib.h>

int find_pivot(int *arr, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	int tmp = 0;
	for(int i = 0; i < n; i++)
	{
		// printf("tmp: %i, equ: %i\n", tmp, sum - tmp - arr[i]);
		if (tmp == sum - tmp - arr[i])
			return (i);
		tmp += arr[i];
	}
	return -1;
}

///test main
int main(int ac, char **av)
{
	int arr[ac];
	for(int i = 1; i < ac; i++)
	{
		arr[i - 1] = atoi(av[i]);
	}
	printf("%i\n", find_pivot(arr, ac - 1));
}
