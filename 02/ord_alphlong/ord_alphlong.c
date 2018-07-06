#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_capital(char c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\0')
		return (1);
	return(0);
}

int		count_words(char *str)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
			// printf("cnted\n");
	while (str[i])
	{
		if (is_separator(str[i + 1]) == 1 &&
				is_separator(str[i]) == 0)
			words++;
		i++;
	}
	return (words);
}

char	**split_words(char *str)
{
	int		words;
	int		i;
	int		arr_word;
	char	**array;

	array = (char**)malloc(sizeof(char*)*count_words(str)+1);
	for (int glob = 0; glob < 2; glob++)
	{
		i = 0;
		words = 0;
		arr_word = 0;
		while (str[i])
		{
			if (!is_separator(str[i]))
			{
				if (glob == 1) array[words][arr_word] = str[i];
				arr_word++;
			}
			if (is_separator(str[i + 1]) == 1 &&
					is_separator(str[i]) == 0)
			{
				if (glob == 0) array[words] = (char*)malloc(sizeof(char) * arr_word + 1);
				if (glob == 1) array[words][arr_word] = '\0';
				words++;
				arr_word = 0;
			}
			i++;
		}
	}
	return (array);
}

int word_len(char *str)
{
	int i;
	for (i = 0; str[i]; i++)
		;
	return (i);
}

int str_cmp(char *str1, char *str2)
{
	int i = 0;
	while ((str1[i] && str2[i]) && (str1[i] + (is_capital(str1[i]) * 32)) == (str2[i] + (is_capital(str2[i]) * 32)))
	{
		i++;
	}
	return ((str1[i] + (is_capital(str1[i]) * 32)) - (str2[i] + (is_capital(str2[i]) * 32)));
}

void str_swap(char **str1, char **str2)
{
	int i = 0;
	char *tmp;
	tmp = *str2;
	*str2 = *str1;
	*str1 = tmp;
}

void ord_alphalong(char *str)
{
	// Real start
	char **word_arr = split_words(str);
	for (int i = 0; word_arr[i + 1]; i += 0)
	{
		int result = str_cmp(word_arr[i], word_arr[i + 1]);
		if (result > 0){
			// printf("result = %d, swap %s with %s\n", result, word_arr[i], word_arr[i + 1]);
			str_swap(&word_arr[i], &word_arr[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	// for (int i = 0; word_arr[i]; i++)
	// {
	// 	printf("%s\n", word_arr[i]);
	// }
	int j = 0;
	int cnt = 0;
	int first = 1;
	int first_print = 1;
	while (word_arr[cnt])
	{
		first = 1;
		for (int i = 0; word_arr[i]; i++)
		{
			if (word_len(word_arr[i]) == j)
			{
				if (first)
				{
					if (first_print) {
						printf("%s", word_arr[i]);
						first_print = 0;
					}
					else
						printf("\n%s", word_arr[i]);
					first = 0;
				}
				else
					printf(" %s", word_arr[i]);
				cnt++;
			}
		}
		j++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ord_alphalong(av[1]);
	}
	printf("\n");//
	// write(1, "\n", 1);
	return (0);
}
