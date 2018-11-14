#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* load strings in 2-D array */
void load_ray(char names_ray[][30], int size)
{
	for (int i = 0; i < size ; ++i)
	{
		printf("Enter Comment...\n");
		scanf("%s", names_ray[i]);
	}
}


 
void check_matches(char names_ray[][30], int size)
{
	char find_match;

	printf("\nEnter a character to search for...\n --> ");
	scanf("%c", &find_match);  // remove ampersand when implementing

	//loop through all values and check each one
	// get ASCII numbers to properly check
	/*
	for (int i = 0; i < size; ++i)
	{
		/* code */
	}
	/*
}



/* sort strings, smallest to largest */
void sort_strings(char names_ray[][30], int size)
{
	char temp[size][30]; //same as generated 2-D array, will store the sorted array.
 
	/* Bubble sort to find smallest string */
	for (int s = 0; s < size - 1; ++s)
	{
		for (int value = 0; value < size - s - 1; ++value)
		{
			if (strlen(names_ray[value]) > strlen(names_ray[value + 1]))
			{
				// use strcpy() to copy the values
				strcpy(temp[value], names_ray[value]);
				strcpy(names_ray[value], names_ray[value + 1]);
				strcpy(names_ray[value + 1], temp[value]);
			}
		}
		
		//needs another for-loop to print here, ideally another helper function
		printf("\nLength of string[%d] --> %ld\n", s, strlen(names_ray[s]));
	}
}


int main(int argc, char const *argv[])
{
	int size, sort_compare;
	char sort_check[] = "SORT";
	char sort_inpt[5];

	printf("\nHow many comments are being added??\n --> ");
	scanf("%d", &size);

	/* declare a 2-D array of strings */
	char names[size][30];
	load_ray(names, size);
	check_matches(names, size);
	printf("\nEnter SORT to sort through strings\n --> ");
	scanf("%s", sort_inpt);
	sort_compare = strcmp(sort_inpt, sort_check);
	if (sort_compare == 0)
	{
		sort_strings(names, size);
	}
	
	/*
	for (int i = 0; i < size ; ++i)
	{
		printf("Enter Comment...\n");
		scanf("%s", names[i]);
	}
	*/

	// drop this in helper function()
	for (int x = 0; x < size; ++x)
	{
		printf("\n%s\n", names[x]);
	}

	return 0;
}
	
