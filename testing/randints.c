#include <stdio.h>

int	all_unique(int *arr)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i != j && arr[i] == arr[j])
				return (0);
	return (1);
}

int	main()
{
	int	*ptr;
	int	arr[4];

	ptr = arr;
	for (int x = 1; x <= 4; x++)
	{
		for (int y = 1; y <= 4; y++)
		{
			for (int z = 1; z <= 4; z++)
			{
				for (int i = 1; i <= 4; i++)
				{
					arr[0] = x;
					arr[1] = y;
					arr[2] = z;
					arr[3] = i;
					if (all_unique(ptr))
						printf("%i %i %i %i\n", x, y, z, i);
				}
			}
		}
	}
}