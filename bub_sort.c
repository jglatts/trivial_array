#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void sort_ray(int ray[], int size)
{
	int temp;

	for (int i = 0; i < size - 1; ++i)
	{
		for (int x = 0; x < size - i - 1; ++x)
		{
			if (ray[x] > ray[x + 1])
			{
				temp = ray[x];
				ray[x] = ray[x + 1];
				ray[x + 1] = temp;
			}
		}
	}
}


void load_ray(int ray[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		ray[i] = rand() % 10;
	}
}

/* Logical error here, tweakage to be done */
int find_matches(int ray[], int size)
{
	int match_count = 0;

	for (int i = 0; i < size; ++i)
	{
		if (ray[i] == ray[i + 1])
		{
			printf("\n[%d] matches [%d]\n", ray[i], ray[i + 1]);
			match_count++;
		}
	}

	return match_count;
}


int main(int argc, char const *argv[])
{
	int size, matches;

	srand(time(NULL));
	printf("\nEnter Limit For Array\n--> ");
	scanf("%d", &size);
	int ray[size];

	load_ray(ray, size);
	sort_ray(ray, size);
	for (int i = 0; i < size; ++i)
	{
		printf("\n[%d] --> %d\n", i, ray[i]);
	}

	matches = find_matches(ray, size);

	printf("\n Found %d matches\n", matches);

	return 0;
}
