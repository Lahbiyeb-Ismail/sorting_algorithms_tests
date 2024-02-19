#include "sort.h"

/**
 * swap - Swaps the elements at two indices in an integer array.
 *
 * @array: Pointer to the integer array.
 * @idx1: Index of the first element to be swapped.
 * @idx2: Index of the second element to be swapped.
 *
 * Description:
 *   This function swaps the elements located at two specified
 * indices in an integer array.
 *
 * Prototype:
 *   void swap(int *array, int idx1, int idx2);
 *
 * Return:
 *   This function does not return a value; it modifies
 * the array in place.
 */
void swap(int *array, int idx1, int idx2)
{
	int tmp;

	/* Check if both indices are within the bounds of the array */
	if (array != NULL && idx1 >= 0 && idx2 >= 0)
	{
			/* Perform the swap of elements at idx1 and idx2 */
		tmp = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = tmp;
	}
}

/**
 * counting_sort - Sorts an array of integers using the
 * Counting Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description:
 *   This function sorts an array of integers in non-decreasing order using
 *   the Counting Sort algorithm. The algorithm counts the occurrences of
 *   each element in the array and then uses this information to determine
 *   the correct position of each element in the sorted array.
 *
 * Prototype:
 *   void counting_sort(int *array, size_t size);
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *counter = NULL, k = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;

	for (j = 0; j <= k; j++)
		counter[j] = 0;

	for (i = 0; i < size; i++)
		counter[array[i]] += 1;

	for (j = 0; j < k; j++)
	{
		counter[j + 1] += counter[j];
		printf("%d, ", counter[j]);
	}

	counter[j + 1] += counter[j];
	printf("%d\n", counter[j + 1]);

	for (i = 0; i < size; i++)
	{
		j = counter[array[i]] - 1;
		if (array[i] != array[j])
			swap(array, i, j);
	}

	free(counter);
}
