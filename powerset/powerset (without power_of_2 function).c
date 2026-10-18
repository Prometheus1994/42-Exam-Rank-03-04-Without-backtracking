#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	while (i < 1 << (argc - 2))
	{
		int j = 0;
		int sum = 0;
		int solutions1 = 0;
		while (j < argc - 2)
		{
			sum += (i >> j & 1) * atoi(argv[j + 2]);
			solutions1 += i >> j & 1;
			j++;
		}
		if (atoi(argv[1]) == sum)
		{
			j = 0;
			int solutions2 = 0;
			while (j < argc - 2)
			{
				if (i >> j & 1)
				{
					printf("%s", argv[j + 2]);
					solutions2++;
					if (solutions1 != solutions2)
						printf(" ");
				}
				j++;
			}
			printf("\n");
		}
		i++;
	}
}