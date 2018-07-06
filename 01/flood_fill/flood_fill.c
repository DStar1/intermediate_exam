#include "flood_fill.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void  recurse(char **tab, t_point size, int y, int x, char c)
{
	// Base cases
    // if (x < 0 || x >= size.x * 2 || y < 0 || y >= size.y)
    //     return;
	// if ((begin.x > 0 && begin.y > 0 && begin.x < size.x && begin.y < size.y) && (tab[begin.y][begin.x] == c || tab[begin.y][begin.x] == 'F'))
	if (tab[y][x] == c)
	{
		tab[y][x] = 'F';
		// begin.y += 1;
		recurse(tab, size, y + 1, x, c);
		// if (recurse(tab, size, begin, c)) return 1;
		// begin.y -= 1;
		recurse(tab, size, y - 1, x, c);
		// if (recurse(tab, size, begin, c)) return 1;
		// begin.x += 1;
		recurse(tab, size, y, x + 2, c);
		// if (recurse(tab, size, begin, c)) return 1;
		// begin.x -= 1;
		recurse(tab, size, y, x - 2, c);
		// if (recurse(tab, size, begin, c)) return 1;
	}
	// else
	// 	return 1;
	// return 0;

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.y][begin.x];
	recurse(tab, size, begin.y, begin.x, c);
	// for (int i = 0; tab[i]; i++)
	// {
	// 	printf("%s\n", tab[0]);
	// }

}


/*
void  flood_fill(char **tab, t_point size, t_point begin)
{
	int y, x, i, axis;
	char c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	axis = (size.y > size.x) ? size.y : size.x;
	for (i = 0; i < axis * axis * axis; i++)
	{
		for (y = 0; y < size.y; y++)
		{
			for (x = 0; x < size.x; x++)
			{
				if (tab[y][x] == 'F')
				{
					if (y > 0 && tab[y - 1][x] == c)
						tab[y - 1][x] = 'F';
					if (x > 0 && tab[y][x - 1] == c)
						tab[y][x - 1] = 'F';
					if (x < size.x - 1 && tab[y][x + 1] == c)
						tab[y][x + 1] = 'F';
					if (y < size.y - 1 && tab[y + 1][x] == c)
						tab[y + 1][x] = 'F';
				}
			}
		}
	}
}
*/
int main()
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	area = (char**)malloc(sizeof(char*) * (size.y + 1));
	area[5] = NULL;
	for (int i = 0; i < 5; i++)
	{
		area[i] = strdup(zone[i]);
		// printf("%s\n", area[i]);
	}

	// area[0] = strdup("1 1 1 1 1 1 1 1");
	// area[1] = strdup("1 0 0 0 1 0 0 1");
	// area[2] = strdup("1 0 0 1 0 0 0 1");
	// area[3] = strdup("1 0 1 1 0 0 0 1");
	// area[4] = strdup("1 1 1 0 0 0 0 1");
	printf("\n");
	flood_fill(area, size, begin);
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", area[i]);
	}
	return 0;
}
