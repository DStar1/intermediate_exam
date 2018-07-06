#include <stdio.h>
#include <stdlib.h>//

int    count_of_2(int n)
{
	int cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		int i2 = i;
		while (i2 > 0) {
			if (i2 % 10 == 2)
				cnt++;
			i2 /= 10;
			// printf("i2 = %i\n", i2);
		}
	}
	return (cnt);
}

///test main
int main(int ac, char **av)
{
	(void)ac;
	printf("cnt = %i\n", count_of_2(atoi(av[1])));
}
