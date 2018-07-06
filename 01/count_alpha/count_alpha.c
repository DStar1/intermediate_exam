#include <stdio.h>

void count_alpha(char *str)
{
	int c[26] = {0};
	int c_cnt[26] = {0};
	int cnt = 0;
	int n = 0;
	int first = 1;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			for (n = 0; n < cnt; n++)
			{
				if (str[i] == c[n])
				{
					c_cnt[n]++;
					break;
				}
			}
			if (n == cnt)
			{
				c[cnt] = str[i];
				c_cnt[cnt]++;
				cnt++;
			}
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		if (first)
		{
			printf("%i%c", c_cnt[i], c[i]);
			first = 0;
		}
		else
			printf(", %i%c", c_cnt[i], c[i]);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		count_alpha(av[1]);
	}
	printf("\n");
	return 0;
}
