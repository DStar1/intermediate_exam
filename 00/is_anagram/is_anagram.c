#include <stdio.h>
#include <stdlib.h>

int is_anagram(char *a, char *b)///optimized solution
{
	int arr[126] = {0};

	for (int i = 0; a[i]; i++){
		arr[(int)a[i]]++;
	}
	for (int i = 0; b[i]; i++){
		arr[(int)b[i]]--;
	}
	for (int i = 0; i < 126; i++)
		if (arr[i] != 0)
			return 0;
	return 1;
}

/************
  Test Main
************/

#include <stdio.h>
int main() {
	char* a = "abcdef";
	char* b = "fabcde";

	printf("%d\n", is_anagram(a, b));

	char* c = ".123?.";
	char* d = "?321..";

	printf("%d\n", is_anagram(c, d));

	char* e = "abca";
	char* f = "bcab";

	printf("%d\n", is_anagram(e, f));

	char* g = "aaaaaaaaaa";
	char* h = "aaaaaaaaaa";

	printf("%d\n", is_anagram(g, h));

	return 0;
}

/*
///test main
int main(int ac, char **av)
{
	(void)ac;
	printf("%i\n", is_anagram(av[1], av[2]));
}
*/
