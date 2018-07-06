#include <stdio.h>
#include <stdlib.h>//

void    equation(int n)
{
	int a,b,c = 0;
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			for (c = 0; c < 10; c++)
			{
				if ((a * 10 + b) + (c * 10 + a) == n)
					printf("A = %i, B = %i, C = %i\n", a, b, c);
			}
		}
	}
	return;
}

///test main
int main(int ac, char **av)
{
	(void)ac;
	equation(atoi(av[1]));
}
