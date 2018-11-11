#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Sort values in the array using bubble sort */
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


/* Generate random numbers, the even/odd comparison is to have a variety of digits */
void load_ray(int ray[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (i % 2 == 0)
		{
			ray[i] = rand() % 100;
		}
		else
		{
			ray[i] = rand() % 10;
		}
	}
}


/* Change a certain value of the array */
void examine_value(int ray[], int size)
{
	int idx, new_value;

	printf("Enter an index To examine...\n --> ");
	scanf("%d", &idx);
	printf("Index[%d] --> %d\n", idx, ray[idx]);
	printf("Enter a new value\n --> ");
	scanf("%d", &new_value);
	ray[idx] = new_value;
	printf("Index[%d] --> %d\n", idx, ray[idx]);

}


/* Logical error here, tweakage to be done */
int find_matches(int ray[], int size)
{
	int match_count = 0;

	for (int i = 0; i < size - 1; ++i)
	{
		if (ray[i] == ray[i + 1])
		{
			printf("\n[%d] matches [%d]\n", ray[i], ray[i + 1]);
			match_count++;
		}
	}

	return match_count;
}


/* WIP--> working on indenting the text in 3 columns */
void print_ray(int ray[], int size)
{
	int format = size / 3;	// 1st column
	int mid_format = format * 2; // 2nd column
	int last_format = format * 3; // 3rd column

	printf("%d\n", format);
	printf("%d\n", mid_format);
	printf("%d\n", last_format);

	for (int i = 0; i <= size; ++i)
	{
		printf("\t[%d]->%d\t", i, ray[i]);
		/*
		if ( i >= mid_format)
		{
			printf("\t\t[%d] --> %d\t\t", i, ray[i]);
		}
		else if (i >= last_format)
		{
			printf("\t\t[%d] --> %d\t\t", i, ray[i]);
		}
		else
		{
			printf("\t[%d] --> %d\t", i, ray[i]);
		}
		*/
	}

}


int main(int argc, char const *argv[])
{
	int size, matches, compare, find_compare;
	char check[] = "SORT";
	char find_check[] = "FIND";
	char usr_input[5];
	char find_input[5];

	printf("%s\n", *argv);
	printf("%d\n", argc);

	srand(time(NULL));
	printf("\nEnter Limit For Array\n--> ");
	scanf("%d", &size);
	int ray[size];

	load_ray(ray, size);
	for (int i = 0; i < size; ++i)
	{
		printf("\n[%d] --> %d\n", i, ray[i]);
	}

	matches = find_matches(ray, size);

	printf("\n Found %d matches\n", matches);
	printf("Enter SORT to sort through values\n --> ");
	scanf("%s", usr_input);
	compare = strcmp(usr_input, check);
	if (compare == 0)
	{
		sort_ray(ray, size);
		print_ray(ray, size);
	}

	printf("Enter FIND to examine a value\n --> ");
	scanf("%s", find_input);
	find_compare = strcmp(find_input, find_check);
	if (find_compare == 0)
	{
		examine_value(ray, size);
	}

	print_ray(ray, size);

	return 0;
}
