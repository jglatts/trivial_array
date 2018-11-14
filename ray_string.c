#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void load_ray(char names_ray[][30], int size)
{
	for (int i = 0; i < size ; ++i)
	{
		printf("Enter Comment...\n");
		scanf("%s", names_ray[i]);
	}
}


int main(int argc, char const *argv[])
{
	int size;

	printf("How many comments are being added??\n --> ");
	scanf("%d", &size);

	/* declare a 2-D array of strings */
	char names[size][30];
	load_ray(names, size);
	
	/*
	for (int i = 0; i < size ; ++i)
	{
		printf("Enter Comment...\n");
		scanf("%s", names[i]);
	}
	*/

	for (int x = 0; x < size; ++x)
	{
		printf("\n%s\n", names[x]);
	}

	return 0;
}
	
