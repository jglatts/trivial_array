/*
Array & Stack practice
10/25/18
JDG
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*---- Prototypes ----*/
void load_array(int[], int);
void print_ray(int[], int);
void find_index(int[], int);
void user_change_array(int[], int, int, int			);


int main(int argc, char const *argv[])
{
	int user_check; 
	int my_array[3];

	srand(time(NULL));

	printf("\nHow Big Should Our Array Be!?!?\n");
	scanf("%d", &user_check);


	load_array(my_array, user_check);

	return 0;

}


/*---- Fill the array up with random numbers ----*/
void load_array(int the_array[], int size)
{
	int i, how_big, random_number;

	for (i = 0; i < size; i++)
	 {
		random_number = rand();
		the_array[i] = random_number;	 	
		printf("\nIndex: %d Added: %d\n", i, random_number);
	 } 

	 how_big = sizeof(the_array) / sizeof(int);
	 printf("\n\n\nFound -> %d elemnts in the array\n\n\n", how_big);

	 print_ray(the_array, how_big);

	 find_index(the_array, size);
}


/*---- Trying to display the values all nicely. WIP ----*/
void print_ray(int test_array[], int test_size)
{
	int i;

	for (i = 0; i < test_size; ++i)
	{
		printf("\n TEST Retrieve: %d\n", test_array[i]);
	}

}


/*---- Have the user pick which index to change ----*/
void find_index(int ar_test[], int test_size)
{
	int get_index, new_value;

	printf("\n==================================================================\n");
	printf("\t\tEnter An Index To Examine A Value");
	printf("\n==================================================================\n");
	scanf("%d", &get_index);

	if (ar_test[get_index])
	{
		printf("\nIndex: %d --> Value: %d\n", get_index, ar_test[get_index]);
		printf("Enter A New Value for This Index\n");
		printf("Or Enter 0 to leave it be...\n");
		scanf("%d", &new_value);
		if (new_value == 0)
		{
			return;
		}
		else
		{
			user_change_array(ar_test, get_index, new_value, test_size);
		}
	}
	else
	{
		printf("\nA value at that index does not exist...\n");
	}

}


/*---- Change the value, then ask to display all values again ----*/
void user_change_array(int ray[], int idx, int value, int size)
{
	int check;

	ray[idx] = value;
	printf("\nIdx: %d, Value Changed -> %d\n", idx, ray[idx]);
	printf("Do you want to view all elemnts?\n");
	printf("Hit 1 for yes...\n");
	scanf("%d", &check);
	if (check == 1)
	{
		print_ray(ray, size);
	}
	else
	{
		return;
	}

}
