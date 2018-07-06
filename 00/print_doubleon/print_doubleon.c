#include <stdio.h>
#include <stdlib.h>//

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i = 0, j = 0;
	int first = 1;
	while (i < na && j < nb)
	{
		// printf("i: %i, j: %i\n", i, j);
		if (a[i] == b[j])
		{
			if (first){
				printf("%i", a[i]);
				first = 0;
			}
			else
				printf(", %i", a[i]);
			j++;
			i++;
		}
		else{
			if (a[i] < b[j])
				i++;
			else// if (a[i] > b[j])
				j++;
		}
	}
	printf("\n");
	return;
}

///test main
int main()
{
	int a[] = {1, 2, 10, 15};
	int b[] = {2, 20, 40, 70};
	int na = 4;
	int nb = 4;
	print_doublon(a, na, b, nb);

	int a1[] = { -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000 };
	int b1[] = {  2,  4,  5,  6,  7, 10,  40,  70 };
	int na1 = 11;
	int nb1 = 8;
	print_doublon(a1, na1, b1, nb1);

	int a2[] = {100,  200, 300 };
	int b2[] = {   1,    2,   3, 4 };
	int na2 = 3;
	int nb2 = 4;
	print_doublon(a2, na2, b2, nb2);
	return 0;
}
