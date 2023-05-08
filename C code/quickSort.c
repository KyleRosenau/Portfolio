#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 1000 // Maximum number of elements in the array

/* Function prototypes */
void quicksort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

/* Main function */
int main() {
    int i, n, arr[MAX_ELEMENTS];
    FILE* fp;

    /* Open the txt file */
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        /* Display an error message if the file can't be opened */
        printf("Failed to open file\n");
        return 1;
    }

    /* Read in the numbers from the txt file */
    i = 0;
    while (fscanf(fp, "%d", &arr[i]) != EOF && i < MAX_ELEMENTS)
        i++;
    n = i;

    /* Close the txt file */
    fclose(fp);

    /* Sort the array using quicksort */
    quicksort(arr, 0, n - 1);

    /* Print the sorted array */
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("\n%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/* Quicksort function */
void quicksort(int arr[], int left, int right) {
    int index;

    /* Base case: array has only one element */
    if (left >= right)
        return;

    /* Partition the array */
    index = partition(arr, left, right);

    /* Sort the left partition */
    quicksort(arr, left, index - 1);

    /* Sort the right partition */
    quicksort(arr, index + 1, right);
}

/* Partition function */
int partition(int arr[], int left, int right) {
    int pivot, temp, i, index;

    /* Choose the pivot as the rightmost element */
    pivot = arr[right];

    /* Move all elements less than the pivot to the left side of the array */
    index = left;
    for (i = left; i < right; i++) {
        if (arr[i] < pivot) {
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
            index++;
        }
    }

    /* Move the pivot to its final position */
    arr[right] = arr[index];
    arr[index] = pivot;

    /* Return the final position of the pivot */
    return index;
}
